#ifndef TVAR_TYPES_H
#define TVAR_TYPES_H

#include "macros.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef unsigned long long comb_t;
typedef signed long long mathint_t;
typedef long double prob_t;

typedef struct datavector
{
  comb_t len;
  prob_t * rawmem;
} datavector;

#define TRIPPLE(Type) \
typedef struct tripple_##Type \
{ \
  Type first; \
  Type second; \
  Type third; \
} tripple_##Type;

CXX_BEGIN


TRIPPLE(comb_t)
TRIPPLE(prob_t)

#define TRIPPLE_SUM(Type) \
TVAR_HEADER Type sum_tripple_##Type (tripple_##Type T) \
{ \
  return T.first + T.second + T.third; \
}

TRIPPLE_SUM(comb_t)
TRIPPLE_SUM(prob_t)

CXX_END

#endif // !TVAR_TYPES_H
