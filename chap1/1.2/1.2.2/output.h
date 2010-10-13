#ifndef _OUTPUT_H
#define _OUTPUT_H

#include <limits.h>

#define INT_BIT	(sizeof(int) * CHAR_BIT)
#define PREC	(INT_BIT - 1)	/* precision of computation. */
#define MASK	(1 << (prec-1))

extern int prec;
int fit(double, int);
void print(int);

#endif	/* !_OUTPUT_H */
