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
	
	//testcase 2
	char test2[40];
	decode( 0x82906001, test2 );
	//orcc   %r1, 1, %r1	//format2
	
	//testcase 3
	char test3[40];
	decode( 0xC200E810, test3 );
	//ld     [%r3+2064], %r1	//format3
	
	//testcase 4
	char test4[40];
	decode( 0xC2214007, test4 );
	//st     %r1, [%r5+%r7]	//format3
	
	//testcase 5
	char test5[40];
	decode( 0x03304F15, test5 );
	//sethi  0x304F15, %r1	//format0
	
	//testcase 6
	char test6[40];
	decode( 0x7FFFFFCE, test6 );
	//call   PC+0xFFFFFF38	//format1
	
	
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

