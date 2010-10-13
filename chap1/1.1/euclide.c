/*
 * Euclid's algorithm to find the greatest common divisor between two
 * integers.
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
  
  while ((r = m - (m/n) * n))
	m = n, n = r;
  return n;
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
