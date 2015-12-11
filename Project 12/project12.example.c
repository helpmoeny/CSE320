
#include <stdio.h>

/******************************************************************************
  A "union" allows you to access the same area of memory as two different
  types of objects.  In the example below, a 64-bit area of memory (8 bytes)
  is treated as a 64-bit unsigned integer (type "unsigned long long") in
  some places, and as a 64-bit double precision floating point in others.

  Note the use of the "%llx" and "%lf" formatting specs in the calls to
  "printf", as well as the "ULL" suffix on the 64-bit literal constant.
******************************************************************************/
 
union dp_item
{
  double drep;
  unsigned long long int irep;
};

int main()
{
  double A = 1.25;

  union dp_item B;

  B.drep = A;

  printf( "B as a 64-bit dp float: %16.8lf\n", B.drep );

  printf( "B as a 64-bit integer:  %016llx\n", B.irep );

  B.irep = B.irep ^ 0xffffffffffffffffULL;

  printf( "B as a 64-bit integer:  %016llx\n", B.irep );

  return 0;
}

