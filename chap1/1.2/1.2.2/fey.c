#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "output.h"

/*
 * Compute b to the power of x using Feynman's algorithm.
 */
static double
mypow(double b, double x)
{
  int y, k;
  double z;
  extern int prec;

  y = MASK;
  k = 0;
  while (x > 0 && k < prec) {
	z = log(1 + 1.0 / (1 << k)) / log(b);
	if (x >= z) {
	  x -= z;
	  y = y + (y >> k);
	} else
	  k++;
  }

  return y * 1.0 / MASK;
}

int
main(int argc, char *argv[])
{
  printf("%e\n", mypow(atof(argv[1]), atof(argv[2])));
  return 0;
}
