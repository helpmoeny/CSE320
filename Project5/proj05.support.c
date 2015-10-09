#include "/user/cse320/Projects/project05.support.h"


int convert( const char num[], int base, int* converted)
{
  //Make sure base is corrcet
  if(base > 36 || base < 2)
    return 0;

  int A = 0;
  int *Conv = converted;
  int neg = 0;

  //skip any whitespace up until the first valid character
  if(num[A] == ' ')
  {
    while(num[A] == ' ')
      A++;
  }
  //Check for a negative
  if(num[A] == '-')
  {
    neg = 1;
    A++;
  }
  //Check for a positive
  if(num[A] == '+')
    A++;

  while(num[A])
  {
   //int  z = num-'0';
    
    if((num[A] >= 'a' && num[A] <= 'z') || (num[A] >= 'A' && num[A] <= 'Z'))
    {
      int val = num[A] - 'A';
      if(val >= base)
        return 0;
      else
        *Conv = *Conv*base + val;
      A++;
      continue;
      if(base <= 10)
        return 0;
      else if(base > 10 && (num[A] == 'a' || num[A] == 'A'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 11 && (num[A] == 'b' || num[A] == 'B'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 12 && (num[A] == 'c' || num[A] == 'C'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 13 && (num[A] == 'd' || num[A] == 'D'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 14 && (num[A] == 'e' || num[A] == 'E'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 15 && (num[A] == 'f' || num[A] == 'F'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 16 && (num[A] == 'g' || num[A] == 'G'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 17 && (num[A] == 'h' || num[A] == 'H'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 18 && (num[A] == 'i' || num[A] == 'I'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 20 && (num[A] == 'j' || num[A] == 'J'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 21 && (num[A] == 'k' || num[A] == 'K'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 22 && (num[A] == 'l' || num[A] == 'L'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 23 && (num[A] == 'm' || num[A] == 'M'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 24 && (num[A] == 'n' || num[A] == 'N'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 25 && (num[A] == 'o' || num[A] == 'O'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 26 && (num[A] == 'p' || num[A] == 'P'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 27 && (num[A] == 'q' || num[A] == 'Q'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 28 && (num[A] == 'r' || num[A] == 'R'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 29 && (num[A] == 's' || num[A] == 'S'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 30 && (num[A] == 't' || num[A] == 'T'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 31 && (num[A] == 'u' || num[A] == 'U'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 32 && (num[A] == 'v' || num[A] == 'V'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 33 && (num[A] == 'w' || num[A] == 'W'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 34 && (num[A] == 'x' || num[A] == 'X'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 35 && (num[A] == 'y' || num[A] == 'Y'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;
      else if(base > 36 && (num[A] == 'z' || num[A] == 'Z'))
        *Conv = *Conv*base + (num[A] - 'A') + 10;


    }
   
    else if(num[A] >= '0' && num[A] <= '9') 
    {
      *Conv = *Conv*base + (num[A]-'0');
    }
    else
      return 0;
          
    A++;
    //*Conv *= base;
  }
  if(neg == 1)
    *Conv = 0 - *Conv;
  return 1;
}
