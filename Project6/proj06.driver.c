#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

int main()
{
  printf("Begin test cases\n");

  float a = 0.1;
  float b = 0.1;
  float ans = a + b;
  float x;

  x = add(a, b);

  printf("Testing 0.1 + 0.1\n");
  printf("\n");
  printf("Computed, float: %f \n",x);
  printf("Computed, Hex: %08x\n", x);
  printf("Correct: %f\n", ans);

  a = 0.01;
  b = 1.0;
  ans = a + b;

  x = add(a, b);

  printf("Testing 0.01 + 1.0\n");
  printf("\n");
  printf("Computed, float: %f\n", x);
  printf("Computed, Hex: %08x\n", x);
  printf("Correct: %f\n", ans); 




  return 0;
}

      
