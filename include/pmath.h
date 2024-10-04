#ifndef TVAR_PMATH_H
#define TVAR_PMATH_H

#include "types.h"

CXX_BEGIN

TVAR_HEADER prob_t prob_pow(prob_t A, comb_t B)
{
  prob_t res = 1;
  for (comb_t i = 1; i < B + 1; i++)
  {
    res *= A;
  }
  return res;
}

TVAR_HEADER comb_t comb_pow(comb_t A, comb_t B)
{
  comb_t res = 1;
  for (comb_t i = 1; i < B + 1; i++)
  {
    res *= A;
  }
  return res;
}

TVAR_HEADER prob_t psqrt (prob_t N)
{
  prob_t lo = 0, hi = N, mid;
  for (comb_t i = 0; i < 1000; i++)
  {
    mid = (lo + hi) / 2;
    if (mid * mid == N) return mid;
    if (mid * mid > N) hi = mid;
    else lo = mid; 
  }
  return mid;
}

CXX_END

#endif // !TVAR_PMATH_H>
