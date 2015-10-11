//cse320 section 1

#include <stdio.h>
#include "/user/cse320/Projects/project05.support.h"
#include <string.h>

/* http://www.dreamincode.net/forums/topic/339092-2s-complement-converter-challenge/
http://www3.ntu.edu.sg/home/ehchua/programming/java/datarepresentation.html
http://www.cse.msu.edu/~cse320/Projects/project05
http://stackoverflow.com/questions/5036321/undefined-symbol-function-first-referenced-in-file-file-link-error */

int convert( const char ch[], int base, int* num)
{
  //Testing if base is in value range of (2,36) inclusive
  /* if(base == 2 || base == 3 || base == 4 || base == 5 || base == 6 || base == 7 || base == 8 || base == 9 || base == 10 || base == 11 || base == 12 || base == 13 || base == 14 || base == 15 || base == 16 || base == 17 || base == 18 || base == 19 || base == 20 || base == 21 || base == 22 || base == 23 || base == 24 || base == 25 || base == 26 || base == 27 || base == 28 || base == 29 || base == 30 || base == 31 || base == 32 || base == 33 || base == 34 || base == 35 || base == 36 ){
	  return 0;
  } */
  if(base >36 || base<2){return 1;}
  int negative_value =0;
  int value = 0;
  
  //int value = ch - '0';
  //int value = (ch - 'A') + 10;
  int i =0;
  while(ch[i] != 0){
  //printf("spot: %d\n", i);
	  if(ch[i] == ' ' || ch[i] == '\n' || ch[i] == '\t'){			//WHITESPACE
		if(value == 1){	//If a value charter was found, an empty space would be in value so return 0
			return 1;	//Just stop and return the numbers we have before the space
		}
	  }
	  else if(ch[i] == '-'){	//Negative-sign
		if(value == 1){
			return 1;	//Just stop and return the numbers we have before the negative-sign
		}
		else{
			negative_value = 1;
		}
	  }
	  else if(ch[i] == '+'){	//Positive-sign
		if(value == 1){
			return 1;	//Just stop and return the numbers we have before the positive-sign
		}
	  }
	  else if((ch[i] >= '0') && (ch[i] <= '9')){
		int curr = (ch[i] - '0');
		if( curr >= base){
			if(value == 0){return 0;}
			break;
		}
		value = 1;
		*num = (base * (*num)) + curr;
	  }
	  else if((ch[i] >= 'a') && (ch[i] <= 'z')){
		int curr = ((ch[i]-'a')+10);
		if( curr >= base){
			if(value == 0){return 0;}
			break;
		}
		value = 1;
		*num = (base * (*num)) + curr;
	  }
	  else if((ch[i] >= 'A') && (ch[i] <= 'Z')){
		int curr = ((ch[i]-'A')+10);
		if( curr >= base){
			if(value == 0){
				return 0;
			}
			break;
		}
		value = 1;
		*num = (base * (*num)) + curr;
	  }
	  else{
		if(value == 0){return 0;}	//empty I think
		return 1;	//If we find another character return the 'numbers' before the character
		
	  }
	  i++;
  }
  if(negative_value == 1){
		*num = 0-(*num);
		//printf( "%d\n",*num);
	  }
  return 1;

}     
