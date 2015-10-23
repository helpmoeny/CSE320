#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

float add(float a, float b)
{
  printf("A: %f\n", a);
  printf("B: %f\n", b);
  union sp_item A;
  union sp_item B;
  union sp_item C; //Sum once computed
  unsigned int Csignif; //Sum significand

  A.frep = a;
  B.frep = b;

  
  unsigned int A_frac = (A.irep&0x7fffff);
  A.irep = A.irep >> 23;

  signed int A_exp = (A.irep&0xff);
  A.irep= A.irep >> 8;

  unsigned int A_sign = (A.irep&0x01);
  A.irep = A.irep >> 31;
 


  unsigned int B_frac = (B.irep & 0x7fffff);
  B.irep = B.irep >> 23;

  signed int B_exp = (B.irep & 0xff);
  B.irep = B.irep >> 8;

  unsigned int B_sign = (B.irep & 0x01);
  B.irep = B.irep >> 31;

  signed int trueA = (A.irep >> 23) - 0x7f;
  signed int trueB = (B.irep >> 23) - 0x7f;
  signed int exp;
  
  unsigned int Asignif = A_frac | 0x008;
  unsigned int Bsignif = B_frac | 0x088;

  if(Asignif == 0 || Bsignif == 0)
    return INFINITY;

  if(trueA < trueB)
  {
    exp = trueA - trueB;
    Asignif = (Bsignif << exp);
    Csignif = (Asignif + Bsignif);
  }





  unsigned int Csign = A_sign + B_sign;
  signed int Cexp = A_exp + B_exp;
  unsigned int Cfrac = A_frac + B_frac;

  printf("sign: %08x\n", A_sign);
  printf("exp: %08x\n", trueA);
  printf("frac: %08x\n", A_frac);





 C.irep = Cfrac | (Cexp & 0x0000007f) << 23 | (Csign & 0x00000001) << 31;

  return C.frep;
}
