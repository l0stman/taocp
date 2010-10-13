#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "output.h"

static double
mylog(double x0)
{
  double y;
  int k, x, z, nc;

  y = 0;
  x = fit(x0, prec);
  z = x >> 1;
  k = 1;
  
  nc = 0;
  while (x != MASK) {
	if (x - z < MASK) {
	  z >>= 1;
	  k++;
	} else {
	  nc++;
	  print(x);
	  print(z);
	  x -= z;
	  z = x >> k;
	  y += log((double)(1<<k)/((1<<k) - 1));
	}
  }
  printf("k:%d nc: %d\n", k, nc);

  return y;
}

int
main(int argc, char *argv[])
{
  double d;
  double lg;

  d = atof(argv[1]);
  lg = mylog(d);
  printf("log(%e) =  %e error: %e%%\n", d, lg, fabs(1 - log(d)/lg) * 100);

  return 0;
}
  
