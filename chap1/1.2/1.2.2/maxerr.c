#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "output.h"

#define MAX		((1 << prec) - 1)

static int
compute(int m, char pflag)
{
  int k, z, n;

  n = 0;
  k = 1;
  z = m >> 1;
  while (m != MASK) {
	if (m - z < MASK) {
	  z >>= 1;
	  k++;
	} else {
	  n++;
	  if (pflag) {
		print(m);
		print(z);
		putchar('\n');
	  }
	  m -= z;
	  z = m >> k;
	}
  }

  return n;
}

/*
 * Ouput the maximum number of times an addition is executed in log.c.
 * Note that we should give an argument because the default value in `prec'
 * is too high.
 */
int
main(int argc, char *argv[])
{
  int nmax, max, m, n;

  if (argc > 1)
	prec = atoi(argv[1]);
  
  nmax = -1;
  for (m = MAX; m > MASK; m--)
	if ((n = compute(m, 0)) > nmax) {
	  nmax = n;
	  max = m;
	}

  printf("%d\n", nmax);
  compute(max, 1);

  return 0;
}
