
#include <stdio.h>
#include <string.h>

int main()
{
  char opname[10];
  char buffer[80];

  unsigned A = 0xA6;

  printf( "A: %#08x\n", A );

  printf( "Percent sign: %%\n" );

  strcpy( opname, "addcc" );

  sprintf( buffer, "The string '%s' contains %d characters\n",
    opname, strlen( opname ) );

  printf( "%s", buffer );

  return 0;
}

