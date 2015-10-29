//cse320 section 1

#include <stdio.h>
#include "/user/cse320/lib/bitlib.h"
#include "/user/cse320/Projects/project05.support.h"
//http://stackoverflow.com/questions/10493411/what-is-masking
//http://www.cse.msu.edu/~cse320/Projects/project06.NOTES
//http://www.cse.msu.edu/~cse320/Projects/project06
int main (int argc, const char * argv[]) {
  
  float a0 = +5.625;	//This example from project06.notes part 11
  float b0 = +17.75;
  float f0 = +23.375;
  float T0 = add( a0, b0 );
  if(T0 == 1){
	printf( "Values: %f + %f\n", a0, b0 );
	printf( "Equal = Float: %f  Decimal: %d  Hexadecimal: %08x\n\n", T0, T0, T0);
	printf( "Correct answer= %f \n", f0 );
  }
  
  float a1 = +1234500000.875;	//This example from project06.viewsp overflow situation
  float b1 = +0;
  float f1 = +0;
  float T1 = add( a1, b1 );
  if(T1 == 1){
	printf( "Values: %f + %f\n", a1, b0 );
	printf( "Equal = Float: %f  Decimal: %d  Hexadecimal: %08x\n\n", T1, T1, T1);
	printf( "Correct answer= %f \n", f1 );
  }
  
  /* If either argument is the floating point value "not-a-number", function
  "add" will return that value.  Otherwise, if either argument is the floating
  point value "infinity", function "add" will return that value. */
  
  /* Be sure to think carefully about the special cases that can arise, such as
the exponent which represents Infinity (and NaN) and the exponent which
represents zero (and denormal values).

As noted on the handout, any arguments which are denormal will be processed as
the value zero for this assignment.

Also, any operation where one of the operands is Not-a-Number produces
Not-a-Number as the result; otherwise, any floating point operation where one
of the operands is Infinity produces Infinity as the result. */
  
  return 0;
  
}
