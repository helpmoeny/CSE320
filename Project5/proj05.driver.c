#include <stdio.h>
#include "/user/cse320/Projects/project05.support.h"
#include "/user/cse320/lib/bitlib.h"

int main()
{
  int res;
  int A = 12;
  int C = 0;
  char B[] = "12";
  
  res = convert(&B[0], 10, &C);

  //test a regular decimal number

  printf( "A: %o (base 8)\n", A);
  printf( "A: %32s", bit32(A));
  printf( "B: %32s", bit32(C));
  printf("\n");
 

  //testing random characters
  printf("Testing the string #S&*3...\n");
  char fakenum[] = "#$&*3";
  res = convert(&fakenum[0], 10, &C);

  if(res == 0)
    printf("bad string\n");
  else
    printf("good string\n");
  printf("\n");



  C = 0;
  char num[] = "A";

  res = convert(&num[0], 16, &C);
  if(res == 0)
    printf("bad\n");
  else
  {
   //printf("num: %32s", bit32(G));
    printf("num: %32s\n", bit32(C));
  }

  C = 0;
  char negnum[] = "-30";

  res = convert(&negnum[0], 10, &C);
  if(res == 0)
    printf("bad conversion\n");
  else
    printf("num: %32s", bit32(C));



  C = 0;
  char random[] = "   A3";
  res = convert(&random[0], 11, &C);
  if(res == 0)
    printf("bad conversion");
  else
  {
    int N = 113;
    printf("Decimal: %d\n", C);
    printf("Hex: %x\n", C);
    printf("Oct: %o\n", C);
    printf("num: %32s\n", bit32(C));
  }

  C=0;


  char hexa[] = "  -AAA";
  res = convert(&hexa[0], 16, &C);
  if(res == 0)
   printf("bad conversion");
  else
  {
    int N = 2730;
    printf("Decimal: %d\n", C);
    printf("Hex: %x\n", C);
    printf("Oct: %o\n", C);
    printf("num: %32s\n", bit32(C));
  }





  return 0;
}

