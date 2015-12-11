
#include <math.h>

#define INFINITY  (__builtin_inf())
#define NAN       (__builtin_nan(""))

double absolute( double X );
double modulo( double X, double Y );
double factorial( unsigned N );
double power( double X, unsigned N );
double sine( double X );

union dp_item
{
  double drep;
  unsigned long long int irep;
};

