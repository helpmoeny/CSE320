//cse320 section 1 project6

#include <stdio.h>
#include "/user/cse320/Projects/project05.support.h"
//http://stackoverflow.com/questions/10493411/what-is-masking
//http://www.cse.msu.edu/~cse320/Projects/project06.NOTES
//http://www.cse.msu.edu/~cse320/Projects/project06
//http://kias.dyndns.org/comath/14.html
//http://docs.oracle.com/cd/E19957-01/806-3568/ncg_math.html	bit patterns for INF, NaN and -

/* I completed some good test cases for each situation that you could run into */
int main (int argc, const char * argv[]) {
  
  float a0 = +5.625;	//This example from project06.notes part 11
  float b0 = +17.75;
  float f0 = +23.375;
  float T0 = add( a0, b0 );
	printf( "Values: %f + %f\n", a0, b0 );
	printf( "Equal = Float: %f  Decimal: %d  Hexadecimal: %08x\n", T0, T0, T0 );
	printf( "Correct answer= %f \n\n", f0 );
  
  float a1 = +1234500000.875;	//This example from project06.viewsp overflow situation
  float b1 = +0;
  float f1 = +0;
  float T1 = add( a1, b1 );
	printf( "Values: %f + %f\n", a1, b1 );
	printf( "Equal = Float: %f  Decimal: %d  Hexadecimal: %08x\n", T1, T1, T1 );
	printf( "Correct answer= %f \n\n", f1 );
  
  float a2 = 9.25;	//This example from project06.viewsp overflow situation
  float b2 = 11.625;
  float f2 = 20.875;
  float T2 = add( a2, b2 );
	printf( "Values: %f + %f\n", a2, b2 );
	printf( "Equal = Float: %f  Decimal: %d  Hexadecimal: %08x\n", T2, T2, T2 );
	printf( "Correct answer= %f \n\n", f2 );
	
  float a3 = 1.0;	//This example from project06.notes part 11
  float b3 = 10.0;
  float f3 = 2.0;
  float T3 = add( a3, b3 );
	printf( "Values: %f + %f\n", a3, b3 );
	printf( "Equal = Float: %f  Decimal: %d  Hexadecimal: %08x\n", T3, T3, T3 );
	printf( "Correct answer= %f \n\n", f3 );
  
  float a4 = 32.640;	//Infinity and -infinity cases are covered here because the exponent will be all 11111111 (0x7f80, 0xff80)
  float b4 = -32.640;
  float f4 = 0.0;
  float T4 = add( a4, b4 );
	printf( "Values: %f + %f\n", a4, b4 );
	printf( "Equal = Float: %f  Decimal: %d  Hexadecimal: %08x\n", T4, T4, T4 );
	printf( "Correct answer= %f \n\n", f4 );
  
  return 0;
  
}
