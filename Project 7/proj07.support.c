//cse320 section 1	project7

//http://iiusatech.com/murdocca/CAO/SlidesPDF/Ch04CAO.pdf
//https://github.com/xianhechen/CSE320/tree/master/proj07
//http://www.cse.msu.edu/~cse320/Projects/
//make -f proj07.makefile
//gcc -Wall proj07.driver.c proj07.support.c

#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

// {ld, st, sethi, andcc, orcc, orncc, srl, addcc, call}.
void decode( unsigned bit_pattern, char outary[] )	//(bit_pattern,address of array)
{
	printf( "bit_pattern: %08x\n",bit_pattern );
	unsigned int op = (bit_pattern >> 30);
	printf( "Op: %d\n",op );
	
	if( op==0 || op==1 || op==2 || op==3 ){
		
		//if op 00: SETHI/BRANCH	(format0)
		if( op==0 ){
			unsigned int regd = ((bit_pattern << 2) >> 27);
			printf( "regd: %d\n",regd );
			unsigned int op2 = ((bit_pattern << 7) >> 29);
			printf( "Op2: %d\n",op2 );
			if( op2==4 ){	//if op2==100 is sethi ,op==010 is branch
				printf( "made it here op2==4\n" );
			}
			else{
				//sprintf(outary," %#08x ");
				printf( "hit branch instruction \n" );
			}
		}
		//if op 01: CALL	(format1)
		else if( op==1 ){
			
		}
		//if op 10: ARITHMETIC	(format2)
		else if( op==2 ){
			//check rsd and rs1 and rs2
		}
		//if op 11: MEMORY	(format3)
		else{
			//check rsd and rs1 and rs2
		}
	}
	else{	//op is not 0,1,2,3 which should not be possible
		//sprintf(outary," %#08x ");
		printf( "should not reach op not 0,1,2,3 \n" );
	}
	printf( "\n" );
}     
