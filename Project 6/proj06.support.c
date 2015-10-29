//cse320 section 1	project6

#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

/* Can't finish working because the numbers I pass in arn't even correct So I can't test my other work to see if I'm doing it correctly 
I understand the project in many aspects, but didn't move on to many special test cases because me and T.A King could not figure out why
the values being passed in are not making it to proj06.support.c*/
float add( float a, float b )
{
	printf( "value a: %f\n",a);	//These prints don't even print the values getting passed in! can't continue
	printf( "value b: %f\n",b);	//These prints don't even print the values getting passed in!
	
	/* For computing C = A + B: Extract sign, exponent, and fraction fields of both A and B.
    Place leading bit in both significands.
    Determine exponent of C based on exponents of A and B; shift
      significand of A or B (based on the difference between exponents).
    Compute significand of C = significand of A + significand of B.
    Normalize significand of C.
    Insert sign, exponent, and fraction fields of C. */
	union sp_item numa;
	signed true_expa;
	numa.frep = a;
	true_expa = ((numa.irep >> 23) & 0xff) - 0x7f;
	printf( "truea: %08x\n",((numa.irep >> 23) & 0xff));
	
	union sp_item numb;
	signed true_expb;
	numb.frep = b;
	true_expb = ((numb.irep >> 23) & 0xff) - 0x7f;

	/* signBitMask = 0x80000;
	expMask = 0x7C000;
	mantissaMask = 0x03FF; */
	
	printf( "numa: %08x\n",numa.irep);
	unsigned int a_sign = (numa.irep >> 31);
	//unsigned int a_exp = ((numa.irep << 1) >> 24);	//biased exponent for a
	unsigned int a_fracfield = ((numa.irep << 9) >> 9);
	printf( "SignA= %08x ExpA= %d FracfieldA= %08x \n", a_sign, true_expa, a_fracfield );
	//printf( "SignA= %d ExpA= %d FracfieldA= %d \n", a_sign, true_expa, a_fracfield );
	
	printf( "numb: %08x\n",numb.irep);
	unsigned int b_sign = (numb.irep >> 31);
	//unsigned int b_exp = ((numb.irep << 1) >> 24);	//biased exponent for b
	unsigned int b_fracfield = ((numb.irep << 9) >> 9);
	printf( "SignB= %08x ExpB= %d FracfieldB= %08x \n", b_sign, true_expb, b_fracfield );
	//printf( "SignB= %d ExpB= %d FracfieldB= %d \n", a_sign, true_expb, a_fracfield );
	
	unsigned int siga = (a_fracfield | 0x008);
	unsigned int sigb = (b_fracfield | 0x008); //83..
	printf( "Siga= %d Sigb= %d \n", siga, sigb );
	
	/* if the significand is 0, the number represents infinity, and 
	if the significand is not zero, that number represents a "NaN" ("Not a Number"): the result of a division by zero. Need to do this through looking at bit patterns */
	if( siga==0 || sigb==0 ){return INFINITY;} //1/0 &infin;
	
	//Take the difference in the exponents, shift the smallest significand that many places right <<
	unsigned int temp_exp;
	if( true_expa > true_expb){
		temp_exp = true_expa - true_expb;
		sigb = (sigb >> temp_exp); //<<?
		
		unsigned int sigc = ( siga + sigb );
		unsigned int fraction = sigc & 0xff7fffff;
		unsigned int Sum = (fraction) | (temp_exp & 0x0000008f)<<23  | (a_sign& 0x00000001)<<31;	//bringing everything back together
	}
	else if( true_expa < true_expb ){
		temp_exp = true_expb - true_expa;
		siga = (siga >> temp_exp);	//<<?
		
		unsigned int sigc = ( siga + sigb );
		unsigned int fraction = sigc & 0xff7fffff;
		unsigned int Sum = (fraction) | (temp_exp & 0x0000008f)<<23  | (a_sign& 0x00000001)<<31;
	}
	else{
		temp_exp = 0;	//No shifting needed exponents are the same
		
		unsigned int sigc = ( siga + sigb );
		unsigned int fraction = sigc & 0xff7fffff;
		unsigned int Sum = (fraction) | (temp_exp & 0x0000008f)<<23  | (a_sign& 0x00000001)<<31;
	}
	
	//Overflow occurs when the biased exponent becomes too large to fit into the biased exponent field -- the result is the value Infinity.-
	//Any arguments which are denormal will be processed as the value zero for this assignment.
	
	return sum;
}     
