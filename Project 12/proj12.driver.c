#include<stdio.h>
#include "/user/cse320/Projects/project12.support.h"
#include<math.h>

int main(){
	//need to use double notation here otherwise we get extremely weird printouts !NaN
	double num1= 1.5;
	double numneg1= -1.5;
	double num2= 1;
	double numneg2= -1;
	double num3= 69;
	double num4= 100;
	double numneg4= -100;
	double num5= 3.45;
	double num0= 0;
	
	printf("Absolute:\n");
    printf("abs(1.5) = %16.8lf\n", absolute(num1));
    printf("abs(-1.5) = %16.8lf\n", absolute(numneg1));
    printf("abs(69) = %16.8lf\n", absolute(num3));
    printf("abs(-100) = %16.8lf\n\n", absolute(numneg4));

	printf("Modulo(remainder of x/y where(x,y)):\n");
	printf( "modulo(0, 1) = %16.8lf\n", modulo(num0, num2));	//returns 0
	printf( "modulo(1, 0) = %16.8lf\n", modulo(num2, num0));	//returns NaN
    printf( "modulo(1, 1) = %16.8lf\n", modulo(num2, num2));
    printf( "modulo(-1.5, 1) = %16.8lf\n", modulo(numneg1, num2));	//should be positive?!
	printf( "modulo(-1, -1.5) = %16.8lf\n", modulo(numneg2, numneg1));
	printf( "modulo(100, 69) = %16.8lf\n", modulo(num4, num3));
	printf( "modulo(3.45, 1.5) = %16.8lf\n\n", modulo(num5, num1));

	//not allowed to pass in negative values, so return 0
    printf("Factorial:\n");
	printf( "1! = %16.8lf\n", factorial(1));
	printf( "-1! = %16.8lf\n", factorial(-1));
	printf( "3! = %16.8lf\n", factorial(3));
	printf( "-3! = %16.8lf\n", factorial(-3));
	printf( "5! = %16.8lf\n", factorial(5));
	printf( "10! = %16.8lf\n\n", factorial(10));
	//printf( "1.5! = %16.8lf\n", factorial(1.5));	//no testing for float exponents because unsigned int is passed in
	
    printf("Power:\n");		//no testing for float exponents because unsigned int is passed in
	printf("%d ^ %d = %16.8lf\n", 0, 2, power(0,2));
    printf("%d ^ %d = %16.8lf\n", 1, 1, power(1,1));
    printf("%d ^ %d = %16.8lf\n", 3, 3, power(3.0,3.0));
    printf("%d ^ %d = %16.8lf\n", -1, 1, power(-1,1));
    printf("%d ^ %d = %16.8lf\n", -4, 2, power(-4,2));
	printf("%d ^ %d = %16.8lf\n\n", -1, -1, power(-1,-1));
	//negative exponents and negative bases have not been fully worked out yet, really need to do additional testing(test cases)
	
	//test cases even though didn't finish sine
    printf( "sine(0): %16.8lf\n", sine(0));
    printf( "sine(pi/2): %16.8lf\n", sine(M_PI/2));
    printf( "sine(pi/3): %16.8lf\n", sine(M_PI/3));
    printf( "sine(pi/4): %16.8lf\n", sine(M_PI/4));
    printf( "sine(pi/6): %16.8lf\n", sine(M_PI/6));
    printf( "sine(pi): %16.8lf\n", sine(M_PI));
	printf( "sine(-pi): %16.8lf\n", sine(-M_PI));
	printf( "sine(-1.5): %16.8lf\n\n", sine(-1.5));

    return 0;
}
