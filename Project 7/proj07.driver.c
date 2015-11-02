//cse320 project 7 section 1

#include <stdio.h>
#include "/user/cse320/Projects/project05.support.h"
#include <string.h>

int main()
{
	/* //example from proj07 handout
	char destination[40];
	decode( 0x98816003, destination );
	//sprintf( destination, "Opcode: %#2x (%s)", 16, "addcc" );
	
	//example from proj07 notes file
	char buffer[80];
	strcpy( buffer, "addcc" );
	printf( "'%s' contains %d characters\n", buffer, strlen( buffer ) ); */
	
	/* 0x86884002    andcc  %r1, %r2, %r3
    0x82906001    orcc   %r1, 1, %r1
    0xC200E810    ld     [%r3+2064], %r1
    0xC2214007    st     %r1, [%r5+%r7]
    0x03304F15    sethi  0x304F15, %r1
    0x7FFFFFCE    call   PC+0xFFFFFF38 */
	
	//testcase 1
	char test1[80];
	decode( 0x86884002, test1 );
	//andcc  %r1, %r2, %r3	//format2
	printf( "%s",test1 );
	
	//testcase 2
	char test2[80];
	decode( 0x82906001, test2 );
	//orcc   %r1, 1, %r1	//format2
	printf( "%s",test2 );
	
	//testcase 3
	char test3[80];
	decode( 0xC200E810, test3 );
	//ld     [%r3+2064], %r1	//format3
	printf( "%s",test3 );
	
	//testcase 4
	char test4[80];
	decode( 0xC2214007, test4 );
	//st     %r1, [%r5+%r7]	//format3
	printf( "%s",test4 );
	
	//testcase 5
	char test5[80];
	decode( 0x03304F15, test5 );
	//sethi  0x304F15, %r1	//format0
	printf( "%s",test5 );
	
	//testcase 6
	char test6[80];
	decode( 0x7FFFFFCE, test6 );
	//call   PC+0xFFFFFF38	//format1
	printf( "%s",test6 );
	
	//testcase 7	from 1021.pdf slides, slide 27
	char test7[80];
	decode( 0xA484BFFF, test7 );
	//addcc   %r18, -1, %r18	//format2
	printf( "%s",test7 );
	
	//testcase 8	from github test cases ta
	char test8[80];
	decode( 0x85306003, test8 );
	//srl  %r2, 3, %r1	//format3
	printf( "%s",test8 );
	
	//testcase 9	from github test cases ta
	char test9[80];
	decode( 0x82B04000, test9 );
	//orncc  %r1, %r0, %r1	//format3
	printf( "%s",test9 );
	
	
	/* //from sample.c
	char opname[10];
	char buffer[80];

	unsigned A = 0xA6;

	printf( "A: %#08x\n", A );

	printf( "Percent sign: %%\n" );

	strcpy( opname, "addcc" );

	sprintf( buffer, "The string '%s' contains %d characters\n",
	opname, strlen( opname ) );

	printf( "%s", buffer ); */

	return 0;
}

