#include "/user/cse320/Projects/project05.support.h"


int convert( const char num[], int base, int* converted)
{
  int A = 0;

  converted = converted*base + (num[A]  '0');

  while(num[A] != NULL)
  {
    if((num[A] >= 'a' && num[A] <= 'z') || (num[A] >= 'A' && num[A] <= 'Z'))
    {
      


