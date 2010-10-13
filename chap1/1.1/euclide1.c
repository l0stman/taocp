/*
 * A version of Euclide's algorithm wihout swapping.
 */

#include <err.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define	toint(s)	(int)strtol(s, (char **)NULL, 10)

static inline int
gcd(int m, int n)
{
  int r;

  for (;;) {
	r = m - (m/n) * n;
	if (r == 0)
	  return n;

	m = n - (n/r) * r;
	if (m == 0)
	  return r;

	n = r - (r/m) * m;
	if (n == 0)
	  return m;
  }

  return -1;
}

int
main(int argc, char **argv)
{
  int m, n;

  if (argc < 3)
	errx(1, "Too few arguments");
  else if (argc > 3)
	errx(1, "Too many arguments");

  m = toint(argv[1]);
  n = toint(argv[2]);
  
  printf("gcd(%d, %d) = %d\n", m, n, gcd(m, n));
  return 0;
}
