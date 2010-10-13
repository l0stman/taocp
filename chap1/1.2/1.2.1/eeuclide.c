#include <err.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define	toint(s)	(int)strtol(s, (char **)NULL, 10)

/*
 * Extended Euclide's algorithm.
 * Given two positive integers m and n, we compute their greatest common
 * divisor d and two integers a and b such that a m + b n = d.
 */

static void
gcd(int m, int n, int *d, int *a, int *b)
{
  int a0, b0, q, r, t;

  *b = a0 = 1;
  *a = b0 = 0;

  do {
	q = m/n;
	r = m - q*n;
	if (r == 0)
	  break;

	m = n;
	n = r;
	
	t = a0;
	a0 = *a;
	*a = t - q * (*a);
	
	t = b0;
	b0 = *b;
	*b = t - q * (*b);
  } while (r);

  *d = n;
}

int
main(int argc, char **argv)
{
  int m, n, a, b, d;
  
  if (argc < 3)
	errx(1, "Too few arguments");
  if (argc > 3)
	errx(1, "Too many arguments");

  m = toint(argv[1]);
  n = toint(argv[2]);

  gcd(m, n, &d, &a, &b);
  printf("gcd(%d, %d) = %d -- %d*%d + %d*%d = %d\n", m, n, d, a, m, b, n, d);

  return 0;
}
