#ifndef ASU_H
#define ASU_H

#include <iostream>
#include <limits>
#include <tgmath.h>
#include <iomanip>

#include "symops.hpp"
#ifndef WMATH_H
#include "wmath.hpp"
#endif //WMATH_H

using std::array;
using std::numeric_limits;

using wmath::universal_encode_uint64;
using wmath::universal_decode_uint64;
using wmath::zigzag_encode;
using wmath::zigzag_decode;

namespace SYMMETRY{
  typedef array<array<double,3>,3> Matrix3D;
  typedef array<array<double,3>,3> DirectCell;
  typedef array<array<double,3>,3> ReciprocalCell;
  typedef array<double,3> Vector3D;
  typedef array<int,3> MillerIndex;

  static const size_t bits_per_miller=numeric_limits<size_t>::digits/3;    
  static const double deg2rad = M_PI/180.0;
  static const double rad2deg = 180.0/M_PI;
 

  /* This function f(h,k,l) maps the three values h,k,l to an uint64.
   * This 64 bit value is used to define an ordering close to the one
   * a human would choose. This ordering is, in a nutshell:
   * prefer low indices and
   * prefer positive numbers.
   * It can also be used to encode the millerindex for storage or
   * somewhat lousy compression
   */
  const inline size_t encode(const MillerIndex& a){
    uint64_t i=0,j=0,k=0;
    const uint64_t hc = universal_encode_uint64(zigzag_encode(-a[0]),i);
    const uint64_t kc = universal_encode_uint64(zigzag_encode(-a[1]),j);
    const uint64_t lc = universal_encode_uint64(zigzag_encode(-a[2]),k);
    return ((uint64_t(1)<<63)^(hc>>1)^(kc>>(i+1))^(lc>>(i+j+1)))>>(64-i-j-k-1); 
  }

  /* This is the reverse hashing function, see hash(const MillerIndex&)
   * for a more detailed description.
   */
  const inline array<int,3> decode(const size_t &h){
    uint64_t i=0,j=0;
    const uint64_t lz = __builtin_clzll(h)+1;
    return {{
             -zigzag_decode(uint32_t(universal_decode_uint64(h<<lz,i))),
             -zigzag_decode(uint32_t(universal_decode_uint64(h<<(lz+i),j))),
             -zigzag_decode(uint32_t(universal_decode_uint64(h<<(lz+i+j))))
           }};
  }
  /* This function uses the hash define an ordering and choose
   * the one which compares lowest.
   */
  bool isred(const MillerIndex &a, const MillerIndex &b){
    return encode(a)<encode(b);
  }
  /* simply multiplication of matrix and vector
   */
  inline Vector3D operator*(const ReciprocalCell& r,const MillerIndex& a){ 
    return {{r[0][0]*a[0]+r[0][1]*a[1]+r[0][2]*a[2],
             r[1][0]*a[0]+r[1][1]*a[1]+r[1][2]*a[2],
             r[2][0]*a[0]+r[2][1]*a[1]+r[2][2]*a[2]}};
  }
/* this is probably wrong ... thats why it is commented out
  inline Vector3D operator*(const ReciprocalCell& r,const MillerIndex& a){
    return {{r[0][0]*a[0]+r[0][1]*a[0]+r[0][2]*a[0],
             r[0][0]*a[1]+r[0][1]*a[1]+r[0][2]*a[1],
             r[0][0]*a[2]+r[0][1]*a[2]+r[0][2]*a[2]
             }};
  }
*/
  inline double norm_squared(const Vector3D& v){
    return v[0]*v[0]+v[1]*v[1]+v[2]*v[2];
  }
  /* Test all symmetry related indices and choose the one whose
   * hash value compares lowest.
   */
  inline MillerIndex asu(const MillerIndex &v, size_t s, bool friedel){ 
    array<int,3> a=v; // implicit identity
    for (size_t i=nop[s-1]; i!=nop[s]; ++i){
      array<int,3> b =
      {{
        a[0]*tab[i][0][0]+a[1]*tab[i][1][0]+a[2]*tab[i][2][0],
        a[0]*tab[i][0][1]+a[1]*tab[i][1][1]+a[2]*tab[i][2][1],
        a[0]*tab[i][0][2]+a[1]*tab[i][1][2]+a[2]*tab[i][2][2]
      }};
      if (isred(b,a)) a=b;
      if (friedel){
        b[0]=-b[0];
        b[1]=-b[1];
        b[2]=-b[2];
        if (isred(b,a)) a=b;
      }
    }
    return a;
  }

  inline size_t asu_hashed(const array<int,3> &v, size_t s, bool friedel){
    return encode(asu(v,s,friedel));
  }

  /* calculate the resolution of the observed peak with given miller index
   * and given reciprocal cell
   */
  const inline double res(const ReciprocalCell &r,
                          const MillerIndex &a){
    Vector3D G = r*a;
    return 1.0/sqrt(norm_squared(G));
  }

  /* old ewald offset in strange units
  const void inline res_ewald(const MillerIndex& a,
                              const ReciprocalCell& r,
                              const double l,
                              double& d,
                              double& o
      ){
    const Vector3D G = a*r;
    const double sng = norm_squared(G);
    d = l/sqrt(sng); 
    o = l+2*l*G[2]/(sng*sqrt(sng));
  }
  */
  
  /* calculate the offset of the ewalds sphere in radians
   * this is basically how well is braggs law fulfilled
   * using the reciprocal cell and the miller index
   */
  const void inline res_ewald(const ReciprocalCell& r,
                              const MillerIndex& a,
                              const double l,
                              double& d,
                              double& o
      ){
    const Vector3D G = r*a;
    const double sng = norm_squared(G);
    const double ng  = sqrt(sng);
    d = 1.0/ng;
    o = asin(G[2]/ng)+asin(ng*l/2);
  }

  /* calculate the resolution of the observed reflection
   * given its miller index and the cell parameters
   */
  const inline double res(const array<int,3> &r,
                          const double &a,
                          const double &b,
                          const double &c,
                          const double &alpha,
                          const double &beta,
                          const double &gamma
                      ){
    const int h = r[0];
    const int k = r[1];
    const int l = r[2];
    const double sin_alpha = sin(alpha);
    const double sin_beta  = sin(beta);
    const double sin_gamma = sin(gamma);
    const double sin_alpha_2=sin_alpha*sin_alpha;
    const double sin_beta_2 =sin_beta *sin_beta ;
    const double sin_gamma_2=sin_gamma*sin_gamma;
    const double cos_alpha = cos(alpha);
    const double cos_beta  = cos(beta);
    const double cos_gamma = cos(gamma);
    const double cos_alpha_2=cos_alpha*cos_alpha;
    const double cos_beta_2 =cos_beta *cos_beta ;
    const double cos_gamma_2=cos_gamma*cos_gamma;
    const double nominator = 1
      -cos(alpha)*cos(alpha)
      -cos(beta )*cos(beta )
      -cos(gamma)*cos(gamma)
      +2*cos(alpha)*cos(beta)*cos(gamma);
    const double denominator =
       h*h/(a*a)*sin_alpha_2
      +k*k/(b*b)*sin_beta_2
      +l*l/(c*c)*sin_gamma_2
      +2*k*l/(b*c)*(cos_beta*cos_gamma-cos_alpha)
      +2*h*l/(a*c)*(cos_alpha*cos_gamma-cos_beta)
      +2*h*k/(a*b)*(cos_alpha*cos_beta-cos_gamma);
    return sqrt(nominator/denominator);
  }
  
  /* convert the cell parameters to a matrix representation of the unit cell
   */
  const inline DirectCell get_cell(
    const double &a,
    const double &b,
    const double &c,
    const double &alpha,
    const double &beta,
    const double &gamma
  ){
    array<array<double,3>,3> cell;
    cell[0][0] = a*a;
    cell[1][1] = b*b;
    cell[2][2] = c*c;
    cell[0][1] = a*b*cos(deg2rad*gamma);
    cell[0][2] = a*c*cos(deg2rad*beta);
    cell[1][2] = b*c*cos(deg2rad*alpha);
    cell[2][0] = cell[0][2];
    cell[1][0] = cell[0][1];
    cell[2][1] = cell[1][2];
    return cell;
  }
  
  // m[0][0] m[0][1] m[0][2]
  // m[1][0] m[1][1] m[1][2]
  // m[2][0] m[2][1] m[2][2]

  /* calculate matrix inverse
   */
  const inline void inverse(Matrix3D &m){
    const double d = 1.0/(
       m[0][0]*m[1][1]*m[2][2]
      +m[0][1]*m[1][2]*m[2][0]
      +m[0][2]*m[1][0]*m[2][1]
      -m[0][2]*m[1][1]*m[2][0]
      -m[0][0]*m[1][2]*m[2][1]
      -m[0][1]*m[1][0]*m[2][2]
                         );
    m=
    {{
      {{d*(m[1][1]*m[2][2]-m[1][2]*m[2][1]),
        d*(m[1][0]*m[2][2]-m[1][2]*m[2][0]),
        d*(m[1][0]*m[2][1]-m[1][1]*m[2][0])
      }}, // m[0][0..2]
      {{d*(m[0][1]*m[2][2]-m[0][2]*m[2][1]),
        d*(m[0][0]*m[2][2]-m[0][2]*m[2][0]),
        d*(m[0][0]*m[2][1]-m[0][1]*m[2][0])
      }}, // m[1][0..2]
      {{d*(m[0][1]*m[1][2]-m[0][2]*m[1][1]),
        d*(m[0][0]*m[1][2]-m[0][2]*m[1][0]),
        d*(m[0][0]*m[1][1]-m[0][1]*m[1][0])
      }},  // m[1][0..2]
    }};
  }

  /* calculate reciprocal unit cell representation by first getting
   * the direct cell representation and then inverting it
   */
  const inline ReciprocalCell get_reciprocal_cell(
    const double &a,
    const double &b,
    const double &c,
    const double &alpha,
    const double &beta,
    const double &gamma
  ){
    DirectCell cell = get_cell(a,b,c,alpha,beta,gamma);
    inverse(cell);
    return cell;
  }
  template<typename T>
  const inline T norm(const array<T,3> &v) {
    return sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
  }
  template<typename T>
  const inline T squared_norm(const array<T,3> &v) {
    return v[0]*v[0]+v[1]*v[1]+v[2]*v[2];
  } 
}

namespace std {
  /* operator for easier input of miller index
   */
  inline istream& operator>>(istream& stream, SYMMETRY::MillerIndex& hkl){
    return stream >> hkl[0] >> hkl[1] >> hkl[2] ;
  }
  /* operator for easier output of a miller index
   */
  inline ostream& operator<<(ostream& stream, const SYMMETRY::MillerIndex& hkl){
    stream << setw(7) << hkl[0] << " " << setw(7) << hkl[1] << " " << setw(7) << hkl[2];
    return stream;
  }
  /* astar[0] bstar[0] cstar[0] astar[1] bstar[1] cstar[1] astar[2] bstar[2] cstar[2]
  inline istream& operator>>(istream& stream, SYMMETRY::Matrix3D& matrix){
    return stream >> matrix[0][0] >> matrix[0][1] >> matrix[0][2]
                  >> matrix[1][0] >> matrix[1][1] >> matrix[1][2]
                  >> matrix[2][0] >> matrix[2][1] >> matrix[2][2];
  }
  */
  /* operator for reading a reciprocal cell from textual input in the order:
   * astar[0] astar[1] astar[2] bstar[0] bstar[1] bstar[2] cstar[0] cstar[1] cstar[2]
   */
  inline istream& operator>>(istream& stream, SYMMETRY::Matrix3D& matrix){
    return stream >> matrix[0][0] >> matrix[1][0] >> matrix[2][0]
                  >> matrix[0][1] >> matrix[1][1] >> matrix[2][1]
                  >> matrix[0][2] >> matrix[1][2] >> matrix[2][2];
  }
  /* operator for output of a reciprocal cell
   */
  inline ostream& operator<<(ostream& stream, SYMMETRY::Matrix3D& matrix){
    return stream << setw(12) << matrix[0][0] << " "
                  << setw(12) << matrix[0][1] << " "
                  << setw(12) << matrix[0][2] << " "
                  << setw(12) << matrix[1][0] << " "
                  << setw(12) << matrix[1][1] << " "
                  << setw(12) << matrix[1][2] << " "
                  << setw(12) << matrix[2][0] << " "
                  << setw(12) << matrix[2][1] << " "
                  << setw(12) << matrix[2][2];
  }
  /* define hash<MillerIndex> for easier use of a MillerIndex as index
   * for std stl container classes like unordered_map and unordered_set
   */
  template<> class hash<SYMMETRY::MillerIndex> {
    public:
      size_t operator()(const SYMMETRY::MillerIndex &hkl) const 
      {
        const int8_t h = hkl[0];
        const int8_t k = hkl[1];
        const int8_t l = hkl[2];
        return ((reinterpret_cast<size_t>(h))<<16)
              ^((reinterpret_cast<size_t>(k))<<8)
              ^((reinterpret_cast<size_t>(l)));
      }
  };
}
#endif // ASU_H
