#ifndef ENCODE_H
#define ENCODE_H

#include <iostream>
#include <limits>
#include <tgmath.h>
#include <iomanip>

#ifndef WMATH_H
#include "wmath.hpp"
#endif //WMATH_H

#ifndef ASU_H
#include <asu>
#endif // ASU_H

namespace SYMMETRY{
using std::abs;
using std::swap;
using wmath::universal_encode_uint64;
using wmath::universal_decode_uint64;
using wmath::zigzag_encode;
using wmath::zigzag_decode;

uint64_t constexpr get_point_group(const size_t s){
  switch (s){
    case   1:
      return 1;
    case   2:
      return 2;
    case   3:
    case   4:
    case   5:
      return 3; 
    case   6:
    case   7:
    case   8:
    case   9:
      return 4;
    case  10:
    case  11:
    case  12:
    case  13:
    case  14:
    case  15:
      return 5;
    case  16:
    case  17:
    case  18:
    case  19:
    case  20:
    case  21:
    case  22:
    case  23:
    case  24:
      return 6;
    case  25:
    case  26:
    case  27:
    case  28:
    case  29:
    case  30:
    case  31:
    case  32:
    case  33:
    case  34:
    case  35:
    case  36:
    case  37:
    case  38:
    case  39:
    case  40:
    case  41:
    case  42:
    case  43:
    case  44:
    case  45:
    case  46:
      return 7;
    case  47:
    case  48:
    case  49:
    case  50:
    case  51:
    case  52:
    case  53:
    case  54:
    case  55:
    case  56:
    case  57:
    case  58:
    case  59:
    case  60:
    case  61:
    case  62:
    case  63:
    case  64:
    case  65:
    case  66:
    case  67:
    case  68:
    case  69:
    case  70:
    case  71:
    case  72:
    case  73:
    case  74:
      return 8;
    case  75:
    case  76:
    case  77:
    case  78:
    case  79:
    case  80:
      return 9;
    case  81:
    case  82:
      return 10;
    case  83:
    case  84:
    case  85:
    case  86:
    case  87:
    case  88:
      return 11;
    case  89:
    case  90:
    case  91:
    case  92:
    case  93:
    case  94:
    case  95:
    case  96:
    case  97:
    case  98:
      return 12;
    case  99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
      return 13;
    case 111:
    case 112:
    case 113:
    case 114:
      return 14;
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
      return 15;
    case 121:
    case 122:
      return 14;
    case 123:
    case 124:
    case 125:
    case 126:
    case 127:
    case 128:
    case 129:
    case 130:
    case 131:
    case 132:
    case 133:
    case 134:
    case 135:
    case 136:
    case 137:
    case 138:
    case 139:
    case 140:
    case 141:
    case 142:
      return 16;
    case 143:
    case 144:
    case 145:
    case 146:
      return 17;
    case 147:
    case 148:
      return 18;
    case 149:
      return 19;
    case 150:
      return 20;
    case 151:
      return 19;
    case 152:
      return 20;
    case 153:
      return 19;
    case 154:
      return 20;
    case 155:
      return 20;
    case 156:
      return 21;
    case 157:
      return 22;
    case 158:
      return 21;
    case 159:
      return 22;
    case 160:
      return 21;
    case 161:
      return 21;
    case 162:
    case 163:
      return 23;
    case 164:
    case 165:
    case 166:
    case 167:
      return 24;
    case 168:
    case 169:
    case 170:
    case 171:
    case 172:
    case 173:
      return 25;
    case 174:
      return 26;
    case 175:
    case 176:
      return 27;
    case 177:
    case 178:
    case 179:
    case 180:
    case 181:
    case 182:
      return 28;
    case 183:
    case 184:
    case 185:
    case 186:
      return 29;
    case 187:
    case 188:
      return 30;
    case 189:
    case 190:
      return 31;
    case 191:
    case 192:
    case 193:
    case 194:
      return 32;
    case 195:
    case 196:
    case 197:
    case 198:
    case 199:
      return 33;
    case 200:
    case 201:
    case 202:
    case 203:
    case 204:
    case 205:
    case 206:
      return 34;
    case 207:
    case 208:
    case 209:
    case 210:
    case 211:
    case 212:
    case 213:
    case 214:
      return 35;
    case 215:
    case 216:
    case 217:
    case 218:
    case 219:
    case 220:
      return 36;
    case 221:
    case 222:
    case 223:
    case 224:
    case 225:
    case 226:
    case 227:
    case 228:
    case 229:
    case 230:
      return 37;
    default:
      return 1;
  }
}

size_t constexpr pointgroup_to_laue(const size_t s){
  switch (s){
    case  1:
    case  2:
      return 2;
    case  3:
    case  4:
    case  5:
      return 5;
    case  6:
    case  7:
    case  8:
      return 8;
    case  9:
    case 10:
    case 11:
      return 11;
    case 12:
    case 13:
    case 14:
    case 15:
      return 15;
    case 16:
    case 17:
      return 17;
    case 18:
    case 19:
    case 20:
      return 20;
    case 21:
    case 22:
    case 23:
      return 23;
    case 24:
    case 25:
    case 26:
    case 27:
      return 27;
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
      return 32;
  }
}

size_t constexpr get_laue_group(const size_t s){
  return pointgroup_to_laue(get_point_group(s));
}

// 111
uint64_t constexpr encode(const uint32_t _h,
                          const uint32_t _k,
                          const uint32_t _l){ 
  uint64_t h = _h+1;
  uint64_t k = _k+1;
  uint64_t l = _l+1;
  uint64_t reorder = 0;
  if (k<h){
    swap(h,k);
    reorder = 1ull;
  }
  if (l<k){
    swap(k,l);
    reorder^= 2ull;
  }
  if (k<h){
    swap(h,k);
    reorder^= 4ull;
  }
  // encode
  const uint64_t log2h = log2(h);
  const uint64_t log2k = log2(k);
  const uint64_t log2l = log2(l);
  uint64_t r = 0;
  uint64_t a=0;
  const uint64_t elog2h = universal_encode_uint64(log2h+1,a);
  r^=(elog2h>>(64-a));
  r<<=log2h;
  r^=(h^(1ull<<log2h));
  //r^=h;
  a=0;
  const uint64_t elog2k = universal_encode_uint64(log2k-log2h+1,a);
  r<<=a;
  r^=(elog2k>>(64-a));
  r<<=log2k;
  r^=(k^(1ull<<log2k));
  a=0;
  const uint64_t elog2l = universal_encode_uint64(log2l-log2k+1,a);
  r<<=a;
  r^=(elog2l>>(64-a));
  r<<=log2l;
  r^=(l^(1ull<<log2l));
  r<<=3;
  r^=reorder;
  // pack
  return r;//reorder log2(h) h log2(k)-log2(h) k log2(l)-log2(k) l
}

constexpr void decode(const uint64_t x,
                      uint32_t& h,
                      uint32_t& k,
                      uint32_t& l){
  const uint64_t lz = __builtin_clzll(x);
  uint64_t a=0;
  uint64_t r = x;
  r <<= lz;
  const uint64_t log2h = universal_decode_uint64(r,a)-1;
  r <<= a;
  h = ((r>>(64-log2h))|(1ull<<log2h))-1;
  r <<= log2h;
  a = 0;
  const uint64_t log2k = log2h+universal_decode_uint64(r,a)-1;
  r <<= a;
  k = ((r>>(64-log2k))|(1ull<<log2k))-1;
  r <<= log2k;
  a = 0;
  const uint64_t log2l = log2k+universal_decode_uint64(r,a)-1;
  r <<= a;
  l = ((r>>(64-log2l))|(1ull<<log2l))-1;
  r <<=log2l;
  if (r&(1ull<<63)){
    swap(h,k);
  }
  if (r&(1ull<<62)){
    swap(k,l);
  }
  if (r&(1ull<<61)){
    swap(h,k);
  }
}

// 000
uint64_t constexpr encode(const int32_t h,const int32_t k,const int32_t l){
  return encode(zigzag_encode(-h),zigzag_encode(-k),zigzag_encode(-l));
}
// 001
uint64_t constexpr encode(const int32_t h,const int32_t k,const uint32_t l){
  return encode(zigzag_encode(-h),zigzag_encode(-k),l);
}
// 010
uint64_t constexpr encode(const int32_t h,const uint32_t k,const int32_t l){
  return encode(zigzag_encode(-h),k,zigzag_encode(-l));
}
// 011
uint64_t constexpr encode(const int32_t h,const uint32_t k,const uint32_t l){
  return encode(zigzag_encode(-h),k,l);
}
// 100
uint64_t constexpr encode(const uint32_t h,const int32_t k,const int32_t l){
  return encode(h,zigzag_encode(-k),zigzag_encode(-l));
}
// 101
uint64_t constexpr encode(const uint32_t h,const int32_t k,const uint32_t l){
  return encode(h,zigzag_encode(-k),zigzag_encode(-l));
}
// 110
uint64_t constexpr encode(const uint32_t h,const uint32_t k,const int32_t l){
  return encode(h,k,zigzag_encode(-l));
}


MillerIndex constexpr decode_sss(const uint64_t x){
  uint32_t h=0,k=0,l=0;
  decode(x,h,k,l);
  return {{-zigzag_decode(h),-zigzag_decode(k),-zigzag_decode(l)}};
}

MillerIndex constexpr decode_uss(const uint64_t x){
  uint32_t h=0,k=0,l=0;
  decode(x,h,k,l);
  return {{static_cast<int32_t>(h),-zigzag_decode(k),-zigzag_decode(l)}};
}

MillerIndex constexpr decode_sus(const uint64_t x){
  uint32_t h=0,k=0,l=0;
  decode(x,h,k,l);
  return {{-zigzag_decode(h),static_cast<int32_t>(k),-zigzag_decode(l)}};
}

MillerIndex constexpr decode_uus(const uint64_t x){
  uint32_t h=0,k=0,l=0;
  decode(x,h,k,l);
  return {{
    static_cast<int32_t>(h),
    static_cast<int32_t>(k),
    -zigzag_decode(l)
  }};
}

MillerIndex constexpr decode_uds(const uint64_t x){
  uint32_t h=0,k=0,l=0;
  decode(x,h,k,l);
  return {{
    static_cast<int32_t>(h),
    static_cast<int32_t>(k+h),
    -zigzag_decode(l)
  }};
}

MillerIndex constexpr decode_uas(const uint64_t x){
  uint32_t h=0,k=0,l=0;
  decode(x,h,k,l);
  return {{
    static_cast<int32_t>(h),
    static_cast<int32_t>(k)-static_cast<int32_t>(h),
    -zigzag_decode(l)
  }};
}

MillerIndex constexpr decode_udu(const uint64_t x){
  uint32_t h=0,k=0,l=0;
  decode(x,h,k,l);
  return {{
    static_cast<int32_t>(h),
    static_cast<int32_t>(k+h),
    static_cast<int32_t>(l)
  }};
}

MillerIndex constexpr decode_uud(const uint64_t x){
  uint32_t h=0,k=0,l=0;
  decode(x,h,k,l);
  return {{
    static_cast<int32_t>(h),
    static_cast<int32_t>(k),
    static_cast<int32_t>(l+h),
  }};
}

MillerIndex constexpr decode_udd(const uint64_t x){
  uint32_t h=0,k=0,l=0;
  decode(x,h,k,l);
  return {{
    static_cast<int32_t>(h),
    static_cast<int32_t>(k+h),
    static_cast<int32_t>(l+k+h),
  }};
}

MillerIndex constexpr decode_uuu(const uint64_t x){
  uint32_t h=0,k=0,l=0;
  decode(x,h,k,l);
  return {{
    static_cast<int32_t>(h),
    static_cast<int32_t>(k),
    static_cast<int32_t>(l),
  }};
}

//general reduction convention:
//1. h positvie
//2. k positive
//3. l positive
//4. h small
//5. k small
//6. l small

template<size_t s>
constexpr void reduce(int32_t& h,int32_t& k,int32_t& l){
  return; // default to do nothing ;)
}
//this is the old way and it persists as the most general form for s=1
template<size_t s>
uint64_t constexpr reduce_encode(const MillerIndex& hkl){
  return encode(hkl[0],hkl[1],hkl[2]);
}
template<size_t s>
MillerIndex constexpr decode(const uint64_t x){
  return decode_sss(x);
}

template<>
constexpr void reduce<1>(int32_t& h,int32_t& k,int32_t& l){
  return;
}
template<>
uint64_t constexpr reduce_encode<1>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<1>(h,k,l);
  return encode(h,k,l);
}
template<>
MillerIndex constexpr decode<1>(const uint64_t x){return decode_sss(x);}

template<>
constexpr void reduce<2>(int32_t& h,int32_t& k,int32_t& l){
  if(h<0){
    h=-h;
    k=-k;
    l=-l;
    return;
  }
  if(h>0) return;
  if(k<0){
    k=-k;
    l=-l;
  }
  if(k>0) return;
  l=abs(l);
}
template<>
uint64_t constexpr reduce_encode<2>(const MillerIndex& hkl){
  int32_t h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<2>(h,k,l);
  return encode(static_cast<uint32_t>(h),k,l);
}
template<>
MillerIndex constexpr decode<2>(const uint64_t x){return decode_uss(x);}

template<>
constexpr void reduce<3>(int32_t& h,int32_t& k,int32_t& l){
  if (h<0){
    h=-h;
    l=-l;
    return;
  }
  if (h>0) return;
  l=abs(l);
}
template<>
uint64_t constexpr reduce_encode<3>(const MillerIndex& hkl){
  int32_t h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<3>(h,k,l);
  return encode(static_cast<uint32_t>(h),k,l);
}
template<>
MillerIndex constexpr decode<3>(const uint64_t x){return decode_uss(x);}

template<>
constexpr void reduce<4>(int32_t& h,int32_t& k,int32_t& l){
  k=abs(k);
}
template<>
uint64_t constexpr reduce_encode<4>(const MillerIndex& hkl){
  int32_t h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<4>(h,k,l);
  return encode(h,static_cast<uint32_t>(k),l);
}
template<>
MillerIndex constexpr decode<4>(const uint64_t x){return decode_sus(x);}

template<>
constexpr void reduce<5>(int32_t& h,int32_t& k,int32_t& l){
  k=abs(k);
  if (h<0){
    h=-h;
    l=-l;
  }
  if(h==0){
    l=abs(l);
  }
}
template<>
uint64_t constexpr reduce_encode<5>(const MillerIndex& hkl){
  int32_t h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<5>(h,k,l);
  return encode(static_cast<uint32_t>(h),static_cast<uint32_t>(k),l);
};
template<>
MillerIndex constexpr decode<5>(const uint64_t x){return decode_uus(x);}

template<>
constexpr void reduce<6>(int32_t& h,int32_t& k,int32_t& l){
  // 110 011 101
  l=((h<0)!=(k<0))?-l:l;
  h=abs(h);
  k=abs(k);
  if (h==0||k==0) l=abs(l);
}
template<>
uint64_t constexpr reduce_encode<6>(const MillerIndex& hkl){
  int32_t h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<6>(h,k,l);
  return encode(static_cast<uint32_t>(h),static_cast<uint32_t>(k),l);
};
template<>
MillerIndex constexpr decode<6>(const uint64_t x){return decode_uus(x);}

template<>
constexpr void reduce<7>(int32_t& h,int32_t& k,int32_t& l){
  // 110 100 010
  h = abs(h);
  k = abs(k);
}
template<>
uint64_t constexpr reduce_encode<7>(const MillerIndex& hkl){
  int32_t h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<7>(h,k,l);
  return encode(static_cast<uint32_t>(h),static_cast<uint32_t>(k),l);
};
template<>
MillerIndex constexpr decode<7>(const uint64_t x){return decode_uus(x);}

template<>
constexpr void reduce<8>(int32_t& h,int32_t& k,int32_t& l){
//  + o o   + o o   + o o   - o o   - o o   - o o   - o o
//  o + o   o - o   o - o   o + o   o + o   o - o   o - o
//  o o -   o o +   o o -   o o +   o o -   o o +   o o -
// 001 010 011 100 101 110 111
  h = abs(h);
  k = abs(k);
  l = abs(l);
}
template<>
uint64_t constexpr reduce_encode<8>(const MillerIndex& hkl){
  int32_t h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<8>(h,k,l);
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k),
                static_cast<uint32_t>(l));
};
template<>
MillerIndex constexpr decode<8>(const uint64_t x){return decode_uuu(x);}

template<>
constexpr void reduce<9>(int32_t& h,int32_t& k,int32_t& l){
//  o - o   - o o   o + o
//  + o o   o - o   - o o
//  o o +   o o +   o o +
// definition: h>=0, k>=0
  if ((h<0)!=(k<0)){
    swap(h,k);
  }
  h=abs(h);
  k=abs(k);
  if (k==0) swap(h,k);
}
template<>
uint64_t constexpr reduce_encode<9>(const MillerIndex& hkl){
  int32_t h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<9>(h,k,l); // h always positive, abs(h)>abs(k) -> h+k>=0
  return encode(static_cast<uint32_t>(h),static_cast<uint32_t>(k),l);
}
template<>
MillerIndex constexpr decode<9>(const uint64_t x){return decode_uus(x);}

template<>
constexpr void reduce<10>(int32_t& h,int32_t& k,int32_t& l){
//  o + o   - o o   o - o
//  - o o   o - o   + o o
//  o o -   o o +   o o -
//  definition: h>=0,k>=0
  if ((h<0)!=(k<0)){
    swap(h,k);
    l=-l;
  }
  h=abs(h);
  k=abs(k);
  if (h==0||k==0){
    if (l<0){
      l=abs(l);
      swap(h,k);
    }
  }
  if ((k==0)&&(l==0)){
    swap(h,k);
  }
}
template<>
uint64_t constexpr reduce_encode<10>(const MillerIndex& hkl){
  int32_t h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<10>(h,k,l); // h always positive, abs(h)>abs(k) -> h+k>=0
  return encode(static_cast<uint32_t>(h),static_cast<uint32_t>(k),l);
};
template<>
MillerIndex constexpr decode<10>(const uint64_t x){return decode_uus(x);}

template<>
constexpr void reduce<11>(int32_t& h,int32_t& k,int32_t& l){
//  o - o   - o o   o + o   - o o   o + o   + o o   o - o
//  + o o   o - o   - o o   o - o   - o o   o + o   + o o
//  o o +   o o +   o o +   o o -   o o -   o o -   o o -
//  definition h>=0,k>=0,l>=0
  l = abs(l);
  if ((h<0)!=(k<0)){
    swap(h,k);
  }
  h=abs(h);
  k=abs(k);
  if (k==0) swap(h,k);
}
template<>
uint64_t constexpr reduce_encode<11>(const MillerIndex& hkl){
  int32_t h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<11>(h,k,l);
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k),
                static_cast<uint32_t>(l));
};
template<>
MillerIndex constexpr decode<11>(const uint64_t x){return decode_uuu(x);}

template<>
constexpr void reduce<12>(int32_t& h,int32_t& k,int32_t& l){
//  - o o   + o o   - o o   o + o   o + o   o - o   o - o
//  o - o   o - o   o + o   - o o   + o o   + o o   - o o
//  o o +   o o -   o o -   o o +   o o -   o o +   o o - 
  if ((h<0)!=(k<0)){
    l=-l;
  }
  if (l<0){
    swap(h,k);
    l=-l;
  }
  h=abs(h);
  k=abs(k);
  if (k==0){
    swap(h,k);
  }
  if (l==0){
    if (k<h){
      swap(h,k);
    }
  }
}
template<>
uint64_t constexpr reduce_encode<12>(const MillerIndex& hkl){
//  - o o   + o o   - o o   o + o   o + o   o - o   o - o
//  o - o   o - o   o + o   - o o   + o o   + o o   - o o
//  o o +   o o -   o o -   o o +   o o -   o o +   o o -
//  
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<12>(h,k,l);
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k),
                static_cast<uint32_t>(l));
};
template<>
MillerIndex constexpr decode<12>(const uint64_t x){return decode_uuu(x);}

template<>
constexpr void reduce<13>(int32_t& h,int32_t& k,int32_t& l){
//   o - o   - o o   o + o   - o o   o - o   + o o   o + o
//   + o o   o - o   - o o   o + o   - o o   o - o   + o o
//   o o +   o o +   o o +   o o +   o o +   o o +   o o +
// definition: h>=0,k>=0,h<=k
  h=abs(h);
  k=abs(k);
  if (h>k){
    swap(h,k);
  }
}
template<>
uint64_t constexpr reduce_encode<13>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<13>(h,k,l);
  return encode(static_cast<uint32_t>(h),static_cast<uint32_t>(k-h),l);
};
template<>
MillerIndex constexpr decode<13>(const uint64_t x){return decode_uds(x);}

template<>
constexpr void reduce<14>(int32_t& h,int32_t& k,int32_t& l){
//   o + o    - o o    o - o    + o o    o - o    - o o    o + o
//   - o o    o - o    + o o    o - o    - o o    o + o    + o o
//   o o -    o o +    o o -    o o -    o o +    o o -    o o +
// definition: h>=0,k>=0,h<=k
  if ((h<0)!=(k<0)){
    l=-l;
  }
  h=abs(h);
  k=abs(k);
  if (h>k) swap(h,k);
  if (h==0) l=abs(l);
}
template<>
uint64_t constexpr reduce_encode<14>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<14>(h,k,l);//k>=h
  return encode(static_cast<uint32_t>(h),static_cast<uint32_t>(k-h),l);
}
template<>
MillerIndex constexpr decode<14>(const uint64_t x){return decode_uds(x);}

template<>
constexpr void reduce<15>(int32_t& h,int32_t& k,int32_t& l){
// ̅4m2 is an alternative representation of ̅42m (14)
// + o o   o + o   - o o   o - o   - o o   o + o   + o o   o - o
// o + o   - o o   o - o   + o o   o + o   + o o   o - o   - o o
// o o +   o o -   o o +   o o -   o o +   o o -   o o +   o o -
// definition: h>=0, k>=0, l>=0
  h=abs(h);
  k=abs(k);
  if (l<0){
    swap(h,k);
    l=-l;
  }
  if (l==0&&k<h){
    swap(h,k);
  }
}
template<>
uint64_t constexpr reduce_encode<15>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<15>(h,k,l);//k>=h
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k),
                static_cast<uint32_t>(l));
}
template<>
MillerIndex constexpr decode<15>(const uint64_t x){return decode_uuu(x);}

//  121 -> 14
//   + o o   o + o   - o o   o - o   + o o   o - o   - o o   o + o
//   o + o   - o o   o - o   + o o   o - o   - o o   o + o   + o o
//   o o +   o o -   o o +   o o -   o o -   o o +   o o -   o o +

template<>
constexpr void reduce<16>(int32_t& h,int32_t& k,int32_t& l){
//  + o o   o - o   - o o   o + o   + o o   o + o   - o o   o - o 
//  o + o   + o o   o - o   - o o   o - o   + o o   o + o   - o o 
//  o o +   o o +   o o +   o o +   o o -   o o -   o o -   o o -
//
//  - o o   o + o   + o o   o - o   - o o   o - o   + o o   o + o 
//  o - o   - o o   o + o   + o o   o + o   - o o   o - o   + o o 
//  o o -   o o -   o o -   o o -   o o +   o o +   o o +   o o +
  h=abs(h);
  k=abs(k);
  l=abs(l);
  if (h>k) swap(h,k);
}
template<>
uint64_t constexpr reduce_encode<16>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<16>(h,k,l);
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k-h),//k>=h
                static_cast<uint32_t>(l));
}
template<>
MillerIndex constexpr decode<16>(const uint64_t x){return decode_udu(x);}

template<>
constexpr void reduce<17>(int32_t& h,int32_t& k,int32_t& l){
//   o - o   - + o
//   + - o   - o o
//   o o +   o o +
//
// definition: h>=0
//
//h,k|-h-k,h|k,-h-k
  if (h<0){
    if (k>=0){
      const int32_t _h=h;
      h=k;
      k=-_h-k;
    }else{
      const int32_t _h=h;
      h=-k-h;
      k=_h;
    }
  }else{
    if (k<0){
      if (-h-k>=0){
        const int32_t _h=h;
        h=-k-h;
        k=_h;
      }
    }
  }
  if (k<0&&h==0){
    swap(h,k);
    h=-h;
  }
}
template<>
uint64_t constexpr reduce_encode<17>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<17>(h,k,l);
  return encode(static_cast<uint32_t>(h),k,l);
};
template<>
MillerIndex constexpr decode<17>(const uint64_t x){return decode_uss(x);}

template<>
constexpr void reduce<18>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   o - o   - + o   - o o   o + o   + - o
//   o + o   + - o   - o o   o - o   - + o   + o o
//   o o +   o o +   o o +   o o -   o o -   o o -
//
// definiton: h>=0, k>=0
// 0  h,k =  h    k     l
// 1  h,k = -h   -k    -l
// 2  h,k = -h-k  h     l
// 3  h,k =    k -h-k   l
// 4  h,k =  h+k -h    -l
// 5  h,k =   -k  h+k  -l
// h>0&&k>0 -> 0
// h>0&&k<0 -> 2|5
// h<0&&k<0 -> 1
// h<0&&k>0 -> 3|4
  if (h>=0){
    if (k>=0){
      // do nothing
    }else if (k<0){
      // choose between 2 and 5
      if (-h-k>=0){//2
        const int32_t _h=h;
        h=-h-k;
        k=_h;
      }else{//5
        const int32_t _h=h;
        h=-k;
        k=_h+k;
        l=-l;
      }
    }
  } else if (h<0){
    if (k<=0){
      // choose 1
      h=-h;
      k=-k;
      l=-l;
    }else if (k>0){
      // choose between 3 and 4
      if (-h-k>=0){//3
        const int32_t _h=h;
        h=k;
        k=-_h-k;
      }else{//4
        const int32_t _h=h;
        h=h+k;
        k=-_h;
        l=-l;
      }
    }
  }
  if (l<0){
    if (h==0||k==0){
      swap(h,k);
      l=-l;
    }
  }else if (l==0){
    if (k==0){
      swap(h,k);
    }
  }
}
template<>
uint64_t constexpr reduce_encode<18>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<18>(h,k,l);
  return encode(static_cast<uint32_t>(h),static_cast<uint32_t>(k),l);
};
template<>
MillerIndex constexpr decode<18>(const uint64_t x){return decode_uus(x);}

template<>
constexpr void reduce<19>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   o - o   - + o   o - o   + o o   - + o
//   o + o   + - o   - o o   - o o   + - o   o + o
//   o o +   o o +   o o +   o o -   o o -   o o -
// definition: h>=0 k>=0
//  h      k  l
//    k -h-k  l
// -h-k  h    l
//   -k -h   -l
//  h+k -k   -l
//   -h  h+k -l
//
  if (l<0){
    k = -k;
    h = -h;
    swap(h,k);
    l = -l;
  }
  if (h>=0&&k>=0){
    // do nothing
  }else if (k>=0&&-h-k>=0){
    const int32_t _h=h;
    h = k;
    k = -_h-k;
  }else if (-h-k>=0&&h>=0){
    const int32_t _h=h;
    h = -h-k;
    k = _h;
  }else if (k<=0&&h<=0){
    k = -k;
    h = -h;
    swap(h,k);
    l = -l;
  }else if (h+k>=0&&-k>=0){
    k = -k;
    h = h-k;
    l = -l;
  }else if (-h>=0&&h+k>=0){
    h=-h;
    k=k-h;
    l=-l;
  }
  if ((h==0||k==0)){
    l=abs(l);
  }
}
template<>
uint64_t constexpr reduce_encode<19>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<19>(h,k,l);
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k),l);
};
template<>
MillerIndex constexpr decode<19>(const uint64_t x){return decode_uus(x);}

template<>
constexpr void reduce<20>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   o - o   - + o   o + o   - o o   + - o
//   o + o   + - o   - o o   + o o   - + o   o - o
//   o o +   o o +   o o +   o o -   o o -   o o - 
  if (l<0){
    swap(h,k);
    l=-l;
  }
  if (h>=0&&k>=0){
    // do nothing
  }else if ((k>=0)&&(-h-k>=0)){
    const int32_t _h=h;
    h = k;
    k = -_h-k;
  }else if (-h-k>=0&&h>=0){
    const int32_t _h=h;
    h = -h-k;
    k = _h;
  }else if (-h-k>=0&&k>=0){
    h = -h-k;
    l = -l;
  }else if (h>=0&&-h-k>=0){
    k=-k-h;
    l=-l;
  }else if (k>=0){
    const int32_t _h=h;
    h = k;
    k = -_h-k;
  }else if (-h-k>=0){
    const int32_t _h=h;
    h = -h-k;
    k = _h;
  }
  if (l==0){
    if (k<0){
      if (abs(-h-k)<abs(k)){
        k = -h-k;
      }
    }else{
      if (k<h){
        swap(h,k);
      }
    }
  }
}
template<>
uint64_t constexpr reduce_encode<20>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<20>(h,k,l);
  return encode(static_cast<uint32_t>(h),k,l);
};
template<>
MillerIndex constexpr decode<20>(const uint64_t x){return decode_uss(x);}

template<>
constexpr void reduce<21>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   o - o   - + o   o - o   + o o   - + o
//   o + o   + - o   - o o   - o o   + - o   o + o
//   o o +   o o +   o o +   o o +   o o +   o o + 
  if (h<=0&&k<=0){
    h=-h;
    k=-k;
    swap(h,k);
  }
  if ((k>=0)&&(-h-k>=0)){
    if (k<h||h<0){
      const int32_t _h=h;
      h = k;
      k = -_h-k;
    }
  }
  if (-h-k>=0&&h>=0){
    if (-h-k<h||k<0){
      const int32_t _h=h;
      h = -h-k;
      k = _h;
    }
  }
  if (h+k>=0&&k<=0){
    h = h+k;
    k = -k;
  }
  if (h+k>=0&&h<=0){
    k = h+k;
    h = -h;
  }
}
template<>
uint64_t constexpr reduce_encode<21>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<21>(h,k,l);
  return encode(static_cast<uint32_t>(h),static_cast<uint32_t>(k),l);
};
template<>
MillerIndex constexpr decode<21>(const uint64_t x){return decode_uus(x);}

template<>
constexpr void reduce<22>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   o - o   - + o   o + o   - o o   + - o
//   o + o   + - o   - o o   + o o   - + o   o - o
//   o o +   o o +   o o +   o o +   o o +   o o +
//
  const int32_t h0=h;
  const int32_t k0=k;
  const int32_t c =-h-k;
  if (isred(k0,c,h,k)){
    h=k0;
    k=c;
  }
  if (isred(c,h0,h,k)){
    h=c;
    k=h0;
  }
  if (isred(k0,h0,h,k)){
    h=k0;
    k=h0;
  }
  if (isred(c,k0,h,k)){
    h=c;
    k=k0;
  }
  if (isred(h0,c,h,k)){
    h=h0;
    k=c;
  }
}
template<>
uint64_t constexpr reduce_encode<22>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<22>(h,k,l);
  return encode(static_cast<uint32_t>(h),k,l);
};
template<>
MillerIndex constexpr decode<22>(const uint64_t x){return decode_uss(x);}
// 158
//   + o o   o - o   - + o   o - o   + o o   - + o
//   o + o   + - o   - o o   - o o   + - o   o + o
//   o o +   o o +   o o +   o o +   o o +   o o +


template<>
constexpr void reduce<23>(int32_t& h,int32_t& k,int32_t& l){ 
//   + o o   o - o   - + o   o - o   + o o   - + o
//   o + o   + - o   - o o   - o o   + - o   o + o
//   o o +   o o +   o o +   o o -   o o -   o o -
//
//   - o o   o + o   + - o   o + o   - o o   + - o
//   o - o   - + o   + o o   + o o   - + o   o - o
//   o o -   o o -   o o -   o o +   o o +   o o +
  reduce<19>(h,k,l);
  if (h>k) swap(h,k);
}
template<>
uint64_t constexpr reduce_encode<23>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<23>(h,k,l);
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k-h),
                l);
};
template<>
MillerIndex constexpr decode<23>(const uint64_t x){return decode_uds(x);}

template<>
constexpr void reduce<24>(int32_t& h,int32_t& k,int32_t& l){

//   + o o   o - o   - + o   - + o   + o o   o - o
//   o + o   + - o   - o o   o + o   + - o   - o o
//   o o +   o o +   o o +   o o +   o o +   o o +

//   - o o   o + o   + - o   + - o   - o o   o + o
//   o - o   - + o   + o o   o - o   - + o   + o o
//   o o -   o o -   o o -   o o -   o o -   o o -
  if (l<0){
    h=-h;
    k=-k;
    l=-l;
  }
  reduce<21>(h,k,l);
  if (l==0){
    if (h<0){
      swap(h,k);
    }else if(k>=0&&k<h){
      swap(h,k);
    }
  }
}
template<>
uint64_t constexpr reduce_encode<24>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<24>(h,k,l);
  return encode(static_cast<uint32_t>(h),
      static_cast<uint32_t>(k),
      static_cast<uint32_t>(l));
};
template<>
MillerIndex constexpr decode<24>(const uint64_t x){return decode_uuu(x);}

template<>
constexpr void reduce<25>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   + - o   o - o   - o o   - + o   o + o
//   o + o   + o o   + - o   o - o   - o o   - + o
//   o o +   o o +   o o +   o o +   o o +   o o +
//
//   + o   - o   + -   - +    o -   o +
//   o +   o -   + o   - o    + -   - +
//
  
  const int32_t h0=h;
  const int32_t k0=k;
  const int32_t c=h+k;
  if (isred(-h0,-k0,h,k)){
    h=-h0;
    k=-k0;
  }
  if (isred(c,-h0,h,k)){
    h=c;
    k=-h0;
  }
  if (isred(-c,h0,h,k)){
    h=-c;
    k=h0;
  }
  if (isred(k0,-c,h,k)){
    h=k0;
    k=-c;
  }
  if (isred(-k0,c,h,k)){
    h=-k0;
    k=c;
  }
}
template<>
uint64_t constexpr reduce_encode<25>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<25>(h,k,l);
  return encode(static_cast<uint32_t>(h),static_cast<uint32_t>(k),l);
};
template<>
MillerIndex constexpr decode<25>(const uint64_t x){return decode_uus(x);}

template<>
constexpr void reduce<26>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   - + o   o - o   + o o   - + o   o - o
//   o + o   - o o   + - o   o + o   - o o   + - o
//   o o +   o o -   o o +   o o -   o o +   o o -
//
  const int32_t h0=h;
  const int32_t k0=k;
  const int32_t c=-h-k;
  l=abs(l);
  if (isred(c,h0,h,k)){
    h=c;
    k=h0;
  }
  if (isred(k0,c,h,k)){
    h=k0;
    k=c;
  }
  if (h==0&&k==0){
    l=abs(l);
  }
}
template<>
uint64_t constexpr reduce_encode<26>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<26>(h,k,l);
  return encode(static_cast<uint32_t>(h),k,l);
};
template<>
MillerIndex constexpr decode<26>(const uint64_t x){return decode_uss(x);}


template<>
constexpr void reduce<27>(int32_t& h,int32_t& k,int32_t& l){
//    + o o    + - o    o - o    - o o    - + o    o + o
//    o + o    + o o    + - o    o - o    - o o    - + o
//    o o +    o o +    o o +    o o +    o o +    o o +
//
//    - o o    - + o    o + o    + o o    + - o    o - o
//    o - o    - o o    - + o    o + o    + o o    + - o
//    o o -    o o -    o o -    o o -    o o -    o o -
//    
  if (l<0){
    h=-h;
    k=-k;
    l=-l;
  }
  reduce<25>(h,k,l);
}
template<>
uint64_t constexpr reduce_encode<27>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<27>(h,k,l);
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k),
                static_cast<uint32_t>(l));
};
template<>
MillerIndex constexpr decode<27>(const uint64_t x){return decode_uuu(x);}

template<>
constexpr void reduce<28>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   + - o   o - o   - o o   - + o   o + o
//   o + o   + o o   + - o   o - o   - o o   - + o
//   o o +   o o +   o o +   o o +   o o +   o o +
//
//   o - o   + - o   + o o   o + o   - + o   - o o
//   - o o   o - o   + - o   + o o   o + o   - + o
//   o o -   o o -   o o -   o o -   o o -   o o -
//
  if (l<0){
    l=-l;
    h=-h;
    k=-k;
    swap(h,k);
  }
  reduce<25>(h,k,l);
  if(l==0){
    if (k<h) swap(h,k);
  }
}
template<>
uint64_t constexpr reduce_encode<28>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<28>(h,k,l);
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k),
                static_cast<uint32_t>(l));
};
template<>
MillerIndex constexpr decode<28>(const uint64_t x){return decode_uuu(x);}

template<>
constexpr void reduce<29>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   + - o   o - o   - o o   - + o   o + o
//   o + o   + o o   + - o   o - o   - o o   - + o
//   o o +   o o +   o o +   o o +   o o +   o o +
//
//   o + o   - + o   - o o   o - o   + - o   + o o
//   + o o   o + o   - + o   - o o   o - o   + - o
//   o o +   o o +   o o +   o o +   o o +   o o +
//
//generator:
//   + - o  
//   + o o
//   o o +
// definition: h>=0, k>=0, h<k
  if (h<0){
    h=-h;
    k=-k;
  }
  const int32_t c = h+k;
  // 6 -7
  if (k<0){
    if (c>=0){ // c = -1
      h=-k;
      k=c;
    }else{
      k=h;
      h=-c;
    }
  }
  if (k<h){
    swap(h,k);
  }
}
template<>
uint64_t constexpr reduce_encode<29>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<29>(h,k,l);
  return encode(static_cast<uint32_t>(h),static_cast<uint32_t>(k-h),l);
};
template<>
MillerIndex constexpr decode<29>(const uint64_t x){return decode_uds(x);}

template<>
constexpr void reduce<30>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   o - o   - + o   - + o   o - o   + o o
//   o + o   + - o   - o o   o + o   - o o   + - o
//   o o +   o o +   o o +   o o +   o o +   o o +
//   
//   + o o   o - o   - + o   - + o   o - o   + o o
//   o + o   + - o   - o o   o + o   - o o   + - o
//   o o -   o o -   o o -   o o -   o o -   o o -
//
  l=abs(l);
// now the only thing that is left is:
//   o -   - +   - +    o -    + o
//   + -   - o   o +    - o    + -
  reduce<21>(h,k,l);
}
template<>
uint64_t constexpr reduce_encode<30>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<30>(h,k,l);
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k),
                static_cast<uint32_t>(l));
};
template<>
MillerIndex constexpr decode<30>(const uint64_t x){return decode_uuu(x);}

template<>
constexpr void reduce<31>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   o - o   - + o   o + o   + - o   - o o
//   o + o   + - o   - o o   + o o   o - o   - + o
//   o o +   o o +   o o +   o o +   o o +   o o +
//
//   + o o   - + o   o - o   o + o   + - o   - o o
//   o + o   - o o   + - o   + o o   o - o   - + o
//   o o -   o o -   o o -   o o -   o o -   o o -
  l=abs(l);
// now the only thing that is left is:
//   o -   - +    o +    + -    - o
//   + -   - o    + o    o -    - +
  reduce<22>(h,k,l);
}
template<>
uint64_t constexpr reduce_encode<31>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<31>(h,k,l);
  return encode(static_cast<uint32_t>(h),k,l);
};
template<>
MillerIndex constexpr decode<31>(const uint64_t x){return decode_uss(x);}

template<>
constexpr void reduce<32>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   + - o   o - o   o + o   - + o   + o o
//   o + o   + o o   + - o   + o o   o + o   + - o
//   o o +   o o +   o o +   o o +   o o +   o o +
//
//   - o o   - + o   o + o   o - o   + - o   - o o
//   o - o   - o o   - + o   - o o   o - o   - + o
//   o o +   o o +   o o +   o o +   o o +   o o +
//
//   + o o   + - o   o - o   o + o   - + o   + o o
//   o + o   + o o   + - o   + o o   o + o   + - o
//   o o -   o o -   o o -   o o -   o o -   o o -
//
//   - o o   - + o   o + o   o - o   + - o   - o o
//   o - o   - o o   - + o   - o o   o - o   - + o
//   o o -   o o -   o o -   o o -   o o -   o o -
  l=abs(l);
  reduce<29>(h,k,l);
}
template<>
uint64_t constexpr reduce_encode<32>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<32>(h,k,l);
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k-h),
                static_cast<uint32_t>(l));
};
template<>
MillerIndex constexpr decode<32>(const uint64_t x){return decode_udu(x);}

template<>
constexpr void reduce<33>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   - o o   + o o   - o o
//   o + o   o - o   o - o   o + o
//   o o +   o o +   o o -   o o -
//
//   o o +   o o -   o o +   o o -
//   + o o   - o o   - o o   + o o
//   o + o   o + o   o - o   o - o
//
//   o + o   o + o   o - o   o - o
//   o o +   o o -   o o +   o o -
//   + o o   - o o   - o o   + o o
//
// symop 
//   o o +
//   + o o
//   o + o
// allows us to rotate hkl to lhk and klh
// swap(h,l);swap(k,l);
// h=min(abs(h),abs(k),abs(l));
// definition: h>=0,k>=0,h<=k

  if ((abs(k)<=abs(h))&&(abs(k)<=abs(l))){
    swap(h,k);swap(k,l); // hkl -> khl -> klh
  }else if ((abs(l)<=abs(h))&&(abs(l)<=abs(k))){
    swap(h,l);swap(k,l); // hkl -> lkh -> lhk
  }
  if (abs(h)==abs(l)){
    swap(h,l);swap(k,l);
  }
  if ((h<0)!=(k<0)){
    l=-l;
  }
  h=abs(h);
  k=abs(k);
  if (h==0||k==0) l=abs(l);
}
template<>
uint64_t constexpr reduce_encode<33>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<33>(h,k,l);
  return encode(static_cast<uint32_t>(h),static_cast<uint32_t>(k-h),l);
};
template<>
MillerIndex constexpr decode<33>(const uint64_t x){return decode_uds(x);}

template<>
constexpr void reduce<34>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   + o o   + o o   + o o   - o o   - o o   - o o   - o o
//   o + o   o + o   o - o   o - o   o + o   o + o   o - o   o - o
//   o o +   o o -   o o +   o o -   o o +   o o -   o o +   o o -
//
//   o o +   o o +   o o +   o o +   o o -   o o -   o o -   o o -
//   + o o   + o o   - o o   - o o   + o o   + o o   - o o   - o o
//   o + o   o - o   o + o   o - o   o + o   o - o   o + o   o - o
//
//   o + o   o + o   o + o   o + o   o - o   o - o   o - o   o - o
//   o o +   o o +   o o -   o o -   o o +   o o +   o o -   o o -
//   + o o   - o o   + o o   - o o   + o o   - o o   + o o   - o o

  h=abs(h);
  k=abs(k);
  l=abs(l);
  if ((k<=h)&&(k<=l)){
    swap(h,k);swap(k,l);
  }else if ((l<=h)&&(l<=k)){
    swap(h,l);swap(k,l);
  } 
  if (h==l){
    swap(h,l);swap(k,l);
  }
}
template<>
uint64_t constexpr reduce_encode<34>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<34>(h,k,l);
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k-h),
                static_cast<uint32_t>(l));
};
template<>
MillerIndex constexpr decode<34>(const uint64_t x){return decode_udu(x);}

template<>
constexpr void reduce<35>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   + o o   - o o   - o o
//   o + o   o - o   o + o   o - o
//   o o +   o o -   o o -   o o +

//   o o +   o o +   o o -   o o -
//   + o o   - o o   + o o   - o o
//   o + o   o - o   o - o   o + o

//   o + o   o + o   o - o   o - o
//   o o +   o o -   o o +   o o -
//   + o o   - o o   - o o   + o o

//   o o -   o o -   o o +   o o +
//   o - o   o + o   o - o   o + o
//   - o o   + o o   + o o   - o o

//   o - o   o + o   o + o   o - o
//   - o o   + o o   - o o   + o o
//   o o -   o o -   o o +   o o +

//   - o o   - o o   + o o   + o o
//   o o -   o o +   o o -   o o +
//   o - o   o + o   o + o   o - o
//
// first make them all positive, then order as good as possible
  if ((h<0)!=(k<0)){
    l=-l;
  }
  h=abs(h);
  k=abs(k);
// now h,k are positive
  if (l<0){
    const int32_t _h=h;
    h=k;
    k=_h;
    l=-l;
  }
// all positive now
// now determine best order hkl,lhk or klh
  if (k<=h&&k<=l){
    swap(h,k);swap(k,l); // -> klh bc k is min
  }
  if (l<=h&&l<=k){ 
    swap(h,l);swap(k,l); // -> lhk bc l is min
  }
  if (h==l){
    swap(h,l);swap(k,l);
  }
  if (h==0){
    if (l<k){
      swap(k,l);
    }
  }
// now the order that is left must be the best
}
template<>
uint64_t constexpr reduce_encode<35>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<35>(h,k,l);
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k),
                static_cast<uint32_t>(l-h));
};
template<>
MillerIndex constexpr decode<35>(const uint64_t x){return decode_uud(x);}

template<>
constexpr void reduce<36>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   + o o   - o o   - o o
//   o + o   o - o   o + o   o - o
//   o o +   o o -   o o -   o o +
//
//   o o +   o o -   o o +   o o -
//   + o o   - o o   - o o   + o o
//   o + o   o + o   o - o   o - o
//
//   o + o   o + o   o - o   o - o
//   o o +   o o -   o o +   o o -
//   + o o   - o o   - o o   + o o
//  
//   o o +   o o +   o o -   o o -
//   o + o   o - o   o + o   o - o
//   + o o   - o o   - o o   + o o
//
//   o + o   o + o   o - o   o - o
//   + o o   - o o   + o o   - o o
//   o o +   o o -   o o -   o o +
//
//   + o o   + o o   - o o   - o o
//   o o +   o o -   o o +   o o -
//   o + o   o - o   o - o   o + o
//
// hkl order arbitrary -> sort them
  if (abs(k)<abs(h)) swap(h,k);
  if (abs(l)<abs(k)) swap(k,l);
  if (abs(k)<abs(h)) swap(h,k);
  if ((h<0)!=(k<0)){
    l=-l;
  }
  h=abs(h);
  k=abs(k);
  if (h==0) l=abs(l);
}
template<>
uint64_t constexpr reduce_encode<36>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<36>(h,k,l);
  return encode(static_cast<uint32_t>(h),static_cast<uint32_t>(k-h),l);
};
template<>
MillerIndex constexpr decode<36>(const uint64_t x){return decode_uds(x);}

template<>
constexpr void reduce<37>(int32_t& h,int32_t& k,int32_t& l){
//   + o o   o - o   - o o   o + o   + o o   o + o   - o o   o - o
//   o + o   + o o   o - o   - o o   o - o   + o o   o + o   - o o
//   o o +   o o +   o o +   o o +   o o -   o o -   o o -   o o -
//
//   o o +   - o o   o o -   + o o   o o +   + o o   o o -   - o o
//   + o o   o o +   - o o   o o -   - o o   o o +   + o o   o o -
//   o + o   o + o   o + o   o + o   o - o   o - o   o - o   o - o
//
//   o + o   o + o   o o +   o - o   o o -   o - o   o o +   o o -
//   o o +   o o -   o + o   o o +   o - o   o o -   o - o   o + o
//   + o o   - o o   - o o   - o o   - o o   + o o   + o o   + o o
//
//   - o o   o + o   + o o   o - o   - o o   o - o   + o o   o + o
//   o - o   - o o   o + o   + o o   o + o   - o o   o - o   + o o
//   o o -   o o -   o o -   o o -   o o +   o o +   o o +   o o +
//
//   o o -   + o o   o o +   - o o   o o -   - o o   o o +   + o o
//   - o o   o o -   + o o   o o +   + o o   o o -   - o o   o o +
//   o - o   o - o   o - o   o - o   o + o   o + o   o + o   o + o
//
//   o - o   o - o   o o -   o + o   o o +   o + o   o o -   o o +
//   o o -   o o +   o - o   o o -   o + o   o o +   o + o   o - o
//   - o o   + o o   + o o   + o o   + o o   - o o   - o o   - o o
  h=abs(h);
  k=abs(k);
  l=abs(l);
  if (k<h) swap(h,k);
  if (l<k) swap(k,l);
  if (k<h) swap(h,k);
}
template<>
uint64_t constexpr reduce_encode<37>(const MillerIndex& hkl){
  int h=hkl[0],k=hkl[1],l=hkl[2];
  reduce<37>(h,k,l);
  return encode(static_cast<uint32_t>(h),
                static_cast<uint32_t>(k-h),
                static_cast<uint32_t>(l-k));
};
template<>
MillerIndex constexpr decode<37>(const uint64_t x){return decode_udd(x);}

size_t constexpr reduce_encode(const MillerIndex& hkl,const size_t s){
  switch (s){
    case 1:
      return reduce_encode< 1>(hkl);
    case 2:
      return reduce_encode< 2>(hkl);
    case 3:
      return reduce_encode< 3>(hkl);
    case 4:
      return reduce_encode< 4>(hkl);
    case 5:
      return reduce_encode< 5>(hkl);
    case 6:
      return reduce_encode< 6>(hkl);
    case 7:
      return reduce_encode< 7>(hkl);
    case 8:
      return reduce_encode< 8>(hkl);
    case 9:
      return reduce_encode< 9>(hkl);
    case 10:
      return reduce_encode<10>(hkl);
    case 11:
      return reduce_encode<11>(hkl);
    case 12:
      return reduce_encode<12>(hkl);
    case 13:
      return reduce_encode<13>(hkl);
    case 14:
      return reduce_encode<14>(hkl);
    case 15:
      return reduce_encode<15>(hkl);
    case 16:
      return reduce_encode<16>(hkl);
    case 17:
      return reduce_encode<17>(hkl);
    case 18:
      return reduce_encode<18>(hkl);
    case 19:
      return reduce_encode<19>(hkl);
    case 20:
      return reduce_encode<20>(hkl);
    case 21:
      return reduce_encode<21>(hkl);
    case 22:
      return reduce_encode<22>(hkl);
    case 23:
      return reduce_encode<23>(hkl);
    case 24:
      return reduce_encode<24>(hkl);
    case 25:
      return reduce_encode<25>(hkl);
    case 26:
      return reduce_encode<26>(hkl);
    case 27:
      return reduce_encode<27>(hkl);
    case 28:
      return reduce_encode<28>(hkl);
    case 29:
      return reduce_encode<29>(hkl);
    case 30:
      return reduce_encode<30>(hkl);
    case 31:
      return reduce_encode<31>(hkl);
    case 32:
      return reduce_encode<32>(hkl);
    case 33:
      return reduce_encode<33>(hkl);
    case 34:
      return reduce_encode<34>(hkl);
    case 35:
      return reduce_encode<35>(hkl);
    case 36:
      return reduce_encode<36>(hkl);
    case 37:
      return reduce_encode<37>(hkl);
    default:
      return reduce_encode<1>(hkl);
  }
}
constexpr void reduce(int32_t& h,int32_t& k,int32_t& l,const size_t s){
  switch (s){
    case 1:
      return reduce< 1>(h,k,l);
    case 2:
      return reduce< 2>(h,k,l);
    case 3:
      return reduce< 3>(h,k,l);
    case 4:
      return reduce< 4>(h,k,l);
    case 5:
      return reduce< 5>(h,k,l);
    case 6:
      return reduce< 6>(h,k,l);
    case 7:
      return reduce< 7>(h,k,l);
    case 8:
      return reduce< 8>(h,k,l);
    case 9:
      return reduce< 9>(h,k,l);
    case 10:
      return reduce<10>(h,k,l);
    case 11:
      return reduce<11>(h,k,l);
    case 12:
      return reduce<12>(h,k,l);
    case 13:
      return reduce<13>(h,k,l);
    case 14:
      return reduce<14>(h,k,l);
    case 15:
      return reduce<15>(h,k,l);
    case 16:
      return reduce<16>(h,k,l);
    case 17:
      return reduce<17>(h,k,l);
    case 18:
      return reduce<18>(h,k,l);
    case 19:
      return reduce<19>(h,k,l);
    case 20:
      return reduce<20>(h,k,l);
    case 21:
      return reduce<21>(h,k,l);
    case 22:
      return reduce<22>(h,k,l);
    case 23:
      return reduce<23>(h,k,l);
    case 24:
      return reduce<24>(h,k,l);
    case 25:
      return reduce<25>(h,k,l);
    case 26:
      return reduce<26>(h,k,l);
    case 27:
      return reduce<27>(h,k,l);
    case 28:
      return reduce<28>(h,k,l);
    case 29:
      return reduce<29>(h,k,l);
    case 30:
      return reduce<30>(h,k,l);
    case 31:
      return reduce<31>(h,k,l);
    case 32:
      return reduce<32>(h,k,l);
    case 33:
      return reduce<33>(h,k,l);
    case 34:
      return reduce<34>(h,k,l);
    case 35:
      return reduce<35>(h,k,l);
    case 36:
      return reduce<36>(h,k,l);
    case 37:
      return reduce<37>(h,k,l);
    default:
      return reduce<1>(h,k,l);
  }
}
constexpr void reduce(MillerIndex& hkl,const size_t s){
  switch (s){
    case 1:
      return reduce< 1>(hkl[0],hkl[1],hkl[2]);
    case 2:
      return reduce< 2>(hkl[0],hkl[1],hkl[2]);
    case 3:
      return reduce< 3>(hkl[0],hkl[1],hkl[2]);
    case 4:
      return reduce< 4>(hkl[0],hkl[1],hkl[2]);
    case 5:
      return reduce< 5>(hkl[0],hkl[1],hkl[2]);
    case 6:
      return reduce< 6>(hkl[0],hkl[1],hkl[2]);
    case 7:
      return reduce< 7>(hkl[0],hkl[1],hkl[2]);
    case 8:
      return reduce< 8>(hkl[0],hkl[1],hkl[2]);
    case 9:
      return reduce< 9>(hkl[0],hkl[1],hkl[2]);
    case 10:
      return reduce<10>(hkl[0],hkl[1],hkl[2]);
    case 11:
      return reduce<11>(hkl[0],hkl[1],hkl[2]);
    case 12:
      return reduce<12>(hkl[0],hkl[1],hkl[2]);
    case 13:
      return reduce<13>(hkl[0],hkl[1],hkl[2]);
    case 14:
      return reduce<14>(hkl[0],hkl[1],hkl[2]);
    case 15:
      return reduce<15>(hkl[0],hkl[1],hkl[2]);
    case 16:
      return reduce<16>(hkl[0],hkl[1],hkl[2]);
    case 17:
      return reduce<17>(hkl[0],hkl[1],hkl[2]);
    case 18:
      return reduce<18>(hkl[0],hkl[1],hkl[2]);
    case 19:
      return reduce<19>(hkl[0],hkl[1],hkl[2]);
    case 20:
      return reduce<20>(hkl[0],hkl[1],hkl[2]);
    case 21:
      return reduce<21>(hkl[0],hkl[1],hkl[2]);
    case 22:
      return reduce<22>(hkl[0],hkl[1],hkl[2]);
    case 23:
      return reduce<23>(hkl[0],hkl[1],hkl[2]);
    case 24:
      return reduce<24>(hkl[0],hkl[1],hkl[2]);
    case 25:
      return reduce<25>(hkl[0],hkl[1],hkl[2]);
    case 26:
      return reduce<26>(hkl[0],hkl[1],hkl[2]);
    case 27:
      return reduce<27>(hkl[0],hkl[1],hkl[2]);
    case 28:
      return reduce<28>(hkl[0],hkl[1],hkl[2]);
    case 29:
      return reduce<29>(hkl[0],hkl[1],hkl[2]);
    case 30:
      return reduce<30>(hkl[0],hkl[1],hkl[2]);
    case 31:
      return reduce<31>(hkl[0],hkl[1],hkl[2]);
    case 32:
      return reduce<32>(hkl[0],hkl[1],hkl[2]);
    case 33:
      return reduce<33>(hkl[0],hkl[1],hkl[2]);
    case 34:
      return reduce<34>(hkl[0],hkl[1],hkl[2]);
    case 35:
      return reduce<35>(hkl[0],hkl[1],hkl[2]);
    case 36:
      return reduce<36>(hkl[0],hkl[1],hkl[2]);
    case 37:
      return reduce<37>(hkl[0],hkl[1],hkl[2]);
    default:
      return reduce<1>(hkl[0],hkl[1],hkl[2]);
  }
}
MillerIndex constexpr decode(const uint64_t x,const size_t s){
  switch (s){
    case 1:
      return decode< 1>(x);
    case 2:
      return decode< 2>(x);
    case 3:
      return decode< 3>(x);
    case 4:
      return decode< 4>(x);
    case 5:
      return decode< 5>(x);
    case 6:
      return decode< 6>(x);
    case 7:
      return decode< 7>(x);
    case 8:
      return decode< 8>(x);
    case 9:
      return decode< 9>(x);
    case 10:
      return decode<10>(x);
    case 11:
      return decode<11>(x);
    case 12:
      return decode<12>(x);
    case 13:
      return decode<13>(x);
    case 14:
      return decode<14>(x);
    case 15:
      return decode<15>(x);
    case 16:
      return decode<16>(x);
    case 17:
      return decode<17>(x);
    case 18:
      return decode<18>(x);
    case 19:
      return decode<19>(x);
    case 20:
      return decode<20>(x);
    case 21:
      return decode<21>(x);
    case 22:
      return decode<22>(x);
    case 23:
      return decode<23>(x);
    case 24:
      return decode<24>(x);
    case 25:
      return decode<25>(x);
    case 26:
      return decode<26>(x);
    case 27:
      return decode<27>(x);
    case 28:
      return decode<28>(x);
    case 29:
      return decode<29>(x);
    case 30:
      return decode<30>(x);
    case 31:
      return decode<31>(x);
    case 32:
      return decode<32>(x);
    case 33:
      return decode<33>(x);
    case 34:
      return decode<34>(x);
    case 35:
      return decode<35>(x);
    case 36:
      return decode<36>(x);
    case 37:
      return decode<37>(x);
    default:
      return decode< 1>(x);
  }
}
}
#endif // ENCODE_H
