//cse320 section 1	project7

//http://www.cse.msu.edu/~cse320/Projects/
//make -f proj07.makefile
//gcc -Wall proj07.driver.c proj07.support.c
//http://www.cse.msu.edu/~cse320/Lectures/1021.pdf page 12

#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

// {ld, st, sethi, andcc, orcc, orncc, srl, addcc, call}.
void decode( unsigned bit_pattern, char outary[] )	//(bit_pattern,address of array)
{
	//printf( "bit_pattern: %08x\n",bit_pattern );
	unsigned int op = (bit_pattern >> 30);
	//printf( "Op: %d\n",op );
	
	if( op==0 || op==1 || op==2 || op==3 ){
		
		//if op 00: SETHI/BRANCH	(format0)
		if( op==0 ){
			unsigned int regd = ((bit_pattern << 2) >> 27);
			//printf( "regd: %d\n",regd );
			unsigned int op2 = ((bit_pattern << 7) >> 29);
			//printf( "Op2: %d\n",op2 );
			if( op2==4 ){	//if op2==100 is sethi ,op==010 is branch
				unsigned int imm22 = ((bit_pattern << 10) >> 10);
				//printf( "imm22: %#08x\n", imm22 );
				sprintf(outary,"%s  %#08x, %%r%d\n", "sethi", imm22, regd );
				//printf( "%s",outary );
			}
			else{
				sprintf(outary,"hit branch instruction, invalid instruction \n");
				//printf( "%s",outary );
			}
		}
		//if op 01: CALL	(format1)
		else if( op==1 ){
			unsigned int disp30 = ((bit_pattern << 2) >> 2);
			sprintf(outary,"%s  PC+%#08X\n", "call", 4*disp30);
			//printf( "%s",outary );
		}
		//if op 10: ARITHMETIC	(format2)
		else if( op==2 ){
			//check rsd and rs1 and rs2
			unsigned int rd = ((bit_pattern << 2) >> 27);
			//printf( "rd: %d\n",rd );
			unsigned int op3 = ((bit_pattern << 7) >> 26);
			//printf( "op3: %d\n",op3 );
			unsigned int rs1 = ((bit_pattern << 13) >> 27);
			//printf( "rs1: %d\n",rs1 );
			unsigned int i = ((bit_pattern << 18) >> 31);
			//printf( "i: %d\n",i );
			
			char callsign[40];
			if( op3==16 ){ 
				sprintf(callsign,"addcc" );
			}
			else if( op3==17 ){
				sprintf(callsign,"andcc" );
			}
			else if( op3==18 ){
				sprintf(callsign,"orcc" );
			}
			else if( op3==22 ){
				sprintf(callsign,"orncc" );
			}
			else if( op3==38 ){
				sprintf(callsign,"srl" );
			}
			else{
				sprintf(outary,"hit op3!=16,17,18,22,38 arithmetic format  invalid instruction \n");
				//printf( "%s",outary );
			}
			
			if( i==0 ){
				unsigned int rs2 = ((bit_pattern << 27) >> 27);
				//printf( "rs2: %d\n",rs2 );
				sprintf(outary,"%s  %%r%d, %%r%d, %%r%d\n", callsign, rs1, rs2, rd );
				//printf( "%s",outary );
			}
			else{	//i==1
				unsigned int simm13_sign = ((bit_pattern << 19) >> 31);
				//printf( "simm13_sign: %d\n",simm13_sign );
				if( simm13_sign==1 ){	//if sign negative
					int simm13 = (bit_pattern | 0xFFFFe000 );	//11111111111111111110000000000000
					//printf( "simm13: %d\n",simm13 );
					sprintf(outary,"%s  %%r%d, %d, %%r%d\n", callsign, rd, simm13, rs1 );
					//printf( "%s",outary );
				}
				else{	//if sign positive==0
					unsigned int simm13 = ((bit_pattern << 19) >> 19);	
					//printf( "simm13: %d\n",simm13 );
					sprintf(outary,"%s  %%r%d, %d, %%r%d\n", callsign, rd, simm13, rs1 );
				}
			}
		}
		//if op 11: MEMORY	(format3)
		else{
			//check rsd and rs1 and rs2
			unsigned int rd = ((bit_pattern << 2) >> 27);
			//printf( "rd: %d\n",rd );
			unsigned int op3 = ((bit_pattern << 7) >> 26);
			//printf( "op3: %d\n",op3 );
			unsigned int rs1 = ((bit_pattern << 13) >> 27);
			//printf( "rs1: %d\n",rs1 );
			unsigned int i = ((bit_pattern << 18) >> 31);
			//printf( "i: %d\n",i );
			
			char callsign[40];
			if( op3==0 ){ 
				sprintf(callsign,"ld" );
				if( i==0 ){
				unsigned int rs2 = ((bit_pattern << 27) >> 27);
				//printf( "rs2: %d\n",rs2 );
				sprintf(outary,"%s  [%%r%d+%%r%d], %%r%d\n", callsign, rd, rs1, rs2 );
				//printf( "%s",outary );
				}
				else{	//i==1
				unsigned int simm13 = ((bit_pattern << 19) >> 19);
				//printf( "simm13: %d\n",simm13 );
				sprintf(outary,"%s  [%%r%d+%d], %%r%d\n", callsign, rs1, simm13, rd );
				//printf( "%s",outary );
				}
			}
			else if( op3==4 ){
				sprintf(callsign,"st" );
				if( i==0 ){
				unsigned int rs2 = ((bit_pattern << 27) >> 27);
				//printf( "rs2: %d\n",rs2 );
				sprintf(outary,"%s  %%r%d, [%%r%d+%%r%d]\n", callsign, rd, rs1, rs2 );
				//printf( "%s",outary );
				}
				else{	//i==1
				unsigned int simm13 = ((bit_pattern << 19) >> 19);
				//printf( "simm13: %d\n",simm13 );
				sprintf(outary,"%s  %%r%d, [%%r%d+%d]\n", callsign, rd, rs1, simm13 );
				//printf( "%s",outary );
				}
			}
			else{
				sprintf(outary,"hit op3!=0,4 memory format invalid instruction \n");
				//printf( "%s",outary );
			}
			
			
		}
	}
	else{	//op is not 0,1,2,3 which should not be possible
		sprintf(outary,"should not reach, op not 0,1,2,3 \n");
		printf( "%s",outary );
	}
	printf( "\n" );
}     
