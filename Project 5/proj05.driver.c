//Author james Mithell
//cse320 section 1

#include <stdio.h>
#include "/user/cse320/lib/bitlib.h"
#include "/user/cse320/Projects/project05.support.h"

int main (int argc, const char * argv[]) {
  
  char array0[]= "  +aaA";		//Testing leading whitespace and positive-sign
  int base0 = 16;
  int num0 = 0;
  int T0 = convert(&array0[0], base0, &num0);
  if(T0 == 1){
	printf( "Value: %s base %d\n", array0, base0 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num0, num0);
  }
  
  char array[]= "  -aaA";			//Testing capitatlization and negative values
  int base = 16;
  int num = 0;
  int T = convert(&array[0], base, &num);
  if(T == 1){
	printf( "Value: %s base %d\n", array, base );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num, num);
  }
  
  char array1[]= "100!";		//Testing 100! which should be 4 in base 2 (binary)
  int base1 = 2;
  int num1 = 0;
  int T1 = convert(&array1[0], base1, &num1);
  if(T1 == 1){
	printf( "Value: %s base %d\n", array1, base1 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num1, num1);
  } 
  
  char array2[]= "zZ";			//Testing capitalization and correct base (up to z-36)
  int base2 = 36;
  int num2 = 0;
  int T2 = convert(&array2[0], base2, &num2);
  if(T2 == 1){
	printf( "Value: %s base %d\n", array2, base2 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num2, num2);
  }
  
  char array3[]= "abcd";		//Irregular base with ascii char's in array
  int base3 = 16;
  int num3 = 0;
  int T3 = convert(&array3[0], base3, &num3);
  if(T3 == 1){
	printf( "Value: %s base %d\n", array3, base3 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num3, num3);
  }
  
  char array4[]= "\n \t abcd";	//Testing newline, tab and comparing to previous test case
  int base4 = 16;
  int num4 = 0;
  int T4 = convert(&array4[0], base4, &num4);
  if(T4 == 1){
	printf( "Value: %s base %d\n", array4, base4 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num4, num4);
  }
  
  char array5[]= "   ab89  -+54";		//Testing leading whitespace and interuption in string
  int base5 = 16;
  int num5 = 0;
  int T5 = convert(&array5[0], base5, &num5);
  if(T5 == 1){
	printf( "Value: %s base %d\n", array5, base5 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num5, num5);
  }
  
  char array6[]= "ab89-&54  ";		//Testing interuption and trailing whitespaces
  int base6 = 36;
  int num6 = 0;
  int T6 = convert(&array6[0], base6, &num6);
  if(T6 == 1){
	printf( "Value: %s base %d\n", array6, base6 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num6, num6);
  }
  
  char array7[]= "James Mitchell";		//Testing what should only convert (firstname)
  int base7 = 36;
  int num7 = 0;
  int T7 = convert(&array7[0], base7, &num7);
  if(T7 == 1){
	printf( "Value: %s base %d\n", array7, base7 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num7, num7);
  }
  
  char test1[]= "1023";		
  int base_test1 = 10;
  int num_test1 = 0;
  int Test1 = convert(&test1[0], base_test1, &num_test1);
  if(Test1 == 1){
	printf( "Value: %s base %d\n", test1, base_test1 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test1, num_test1);
  }
  
  char test2[]= "2378DE";		
  int base_test2 = 16;
  int num_test2 = 0;
  int Test2 = convert(&test2[0], base_test2, &num_test2);
  if(Test2 == 1){
	printf( "Value: %s base %d\n", test2, base_test2 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test2, num_test2);
  }
  
  char test3[]= "1YZ";		
  int base_test3 = 36;
  int num_test3 = 0;
  int Test3 = convert(&test1[0], base_test1, &num_test3);
  if(Test3 == 1){
	printf( "Value: %s base %d\n", test3, base_test3 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test3, num_test3);
  }
  
  char test4[]= "+110101011010011";		
  int base_test4 = 2;
  int num_test4 = 0;
  int Test4 = convert(&test4[0], base_test4, &num_test4);
  if(Test4 == 1){
	printf( "Value: %s base %d\n", test4, base_test4 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test4, num_test4);
  }
  
  char test5[]= "-513";		
  int base_test5 = 10;
  int num_test5 = 0;
  int Test5 = convert(&test5[0], base_test5, &num_test5);
  if(Test5 == 1){
	printf( "Value: %s base %d\n", test5, base_test5 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test5, num_test5);
  }
  
  char test6[]= "-FE51C";		
  int base_test6 = 16;
  int num_test6 = 0;
  int Test6 = convert(&test6[0], base_test6, &num_test6);
  if(Test6 == 1){
	printf( "Value: %s base %d\n", test6, base_test6 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test6, num_test6);
  }
  
  char test7[]= "-Z2";		
  int base_test7 = 36;
  int num_test7 = 0;
  int Test7 = convert(&test7[0], base_test7, &num_test7);
  if(Test7 == 1){
	printf( "Value: %s base %d\n", test7, base_test7 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test7, num_test7);
  }
  
  char test8[]= "-101011011010111";		
  int base_test8 = 2;
  int num_test8 = 0;
  int Test8 = convert(&test8[0], base_test8, &num_test8);
  if(Test8 == 1){
	printf( "Value: %s base %d\n", test8, base_test8 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test8, num_test8);
  }
  
  char test9[]= "+7cd";		
  int base_test9 = 14;
  int num_test9 = 0;
  int Test9 = convert(&test9[0], base_test9, &num_test9);
  if(Test9 == 1){
	printf( "Value: %s base %d\n", test9, base_test9 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test9, num_test9);
  }
  
  char test10[]= "-7cD";		
  int base_test10 = 14;
  int num_test10 = 0;
  int Test10 = convert(&test10[0], base_test10, &num_test10);
  if(Test10 == 1){
	printf( "Value: %s base %d\n", test10, base_test10 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test10, num_test10);
  }
  
  char test11[]= "+0";		
  int base_test11 = 20;
  int num_test11 = 0;
  int Test11 = convert(&test11[0], base_test11, &num_test11);
  if(Test11 == 1){
	printf( "Value: %s base %d\n", test11, base_test11 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test11, num_test11);
  }
  
  char test12[]= "-0";		
  int base_test12 = 27;
  int num_test12 = 0;
  int Test12 = convert(&test12[0], base_test12, &num_test12);
  if(Test12 == 1){
	printf( "Value: %s base %d\n", test12, base_test12 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test12, num_test12);
  }
  
  char test13[]= "  5544";		
  int base_test13 = 6;
  int num_test13 = 0;
  int Test13 = convert(&test13[0], base_test13, &num_test13);
  if(Test13 == 1){
	printf( "Value: %s base %d\n", test13, base_test13 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test13, num_test13);
  }
  
  char test14[]= "              1231231";		
  int base_test14 = 4;
  int num_test14 = 0;
  int Test14 = convert(&test14[0], base_test14, &num_test14);
  if(Test14 == 1){
	printf( "Value: %s base %d\n", test14, base_test14 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test14, num_test14);
  }
  
  char test15[]= "37  ";		
  int base_test15 = 8;
  int num_test15 = 0;
  int Test15 = convert(&test15[0], base_test15, &num_test15);
  if(Test15 == 1){
	printf( "Value: %s base %d\n", test15, base_test15 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test15, num_test15);
  }
  
  char test16[]= "44A??A";		
  int base_test16 = 9;
  int num_test16 = 0;
  int Test16 = convert(&test16[0], base_test16, &num_test16);
  if(Test16 == 1){
	printf( "Value: %s base %d\n", test16, base_test16 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test16, num_test16);
  }
  
  char test17[]= "   ";		
  int base_test17 = 10;
  int num_test17 = 0;
  int Test17 = convert(&test17[0], base_test17, &num_test17);
  if(Test17 == 1){
	printf( "Value: %s base %d\n", test17, base_test17 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test17, num_test17);
  }
  
  char test18[]= "WXYZ";		
  int base_test18 = 10;
  int num_test18 = 0;
  int Test18 = convert(&test18[0], base_test18, &num_test18);
  if(Test18 == 1){
	printf( "Value: %s base %d\n", test18, base_test18 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test18, num_test18);
  }
  
  char test19[]= "1111";		
  int base_test19 = 37;
  int num_test19 = 0;
  int Test19 = convert(&test19[0], base_test19, &num_test19);
  if(Test19 == 1){
	printf( "Value: %s base %d\n", test19, base_test19 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test19, num_test19);
  }
  
  char test20[]= "1111";		
  int base_test20 = 1;
  int num_test20 = 0;
  int Test20 = convert(&test20[0], base_test20, &num_test20);
  if(Test20 == 1){
	printf( "Value: %s base %d\n", test20, base_test20 );
	printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test20, num_test20);
  }
  
  return 0;
  
}
