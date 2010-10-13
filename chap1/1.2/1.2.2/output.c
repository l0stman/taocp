#include <stdio.h>

#include "output.h"

int prec = PREC;

/* return an integer composed of the first n bits of d (d >= 0) */
int
fit(double d, int n)
{
  int res, l, m;
  char bit;

  res = (int)d;
  /* Compute an integer l such that: 2^l <= res < 2^(l+1) if res > 0. */
  for (l = -1, m = res; m; m >>= 1, l++)
	;
  if (l+1 < n) {
	/* the number of bits in res is less than n */
	n -= l+1;
	d -= res;
	while (n--) {
	  bit = (2 * d < 1 ? 0: 1);
	  d = 2 * d - bit;
	  res = (res << 1) | bit;
	}
  } else
	res &= ~(~0 << n);
  
  return res;
}

void
print(int x)
{
  int mask;

  mask = MASK;
  while (mask) {
	putchar(x & mask ? '1': '0');
	mask >>= 1;
  }
  putchar('\n');
}
