#ifndef TVAR_PMATH_H
#define TVAR_PMATH_H

#include "types.h"

CXX_BEGIN

TVAR_HEADER prob_t prob_pow(prob_t A, comb_t B)
{
  if (B == 0) return 1;
  prob_t res = 1;
  while (B > 1)
  {
    if (B % 2 == 0)
    {
      A *= A;
      B /= 2;
    }
    else 
    {
      res *= A;
      B--;
    }
  }
  return res * A;
}

TVAR_HEADER comb_t comb_pow(comb_t A, comb_t B)
{
  if (B == 0) return 1;
  comb_t res = 1;
  while (B > 1)
  {
    if (B % 2 == 0)
    {
      A *= A;
      B /= 2;
    }
    else 
    {
      res *= A;
      B--;
    }
  }
  return res * A;
}

TVAR_HEADER prob_t psqrt (prob_t N)
{
  if (N < 0) return -1;
  if (N == 0 || N == 1) return N;

  prob_t x = N;
  prob_t y = (N + 1) / 2;

  while (x - y > 1e-6)
  {
    x = y;
    y = (x + x / N) / 2;
  }
  return y;
}

CXX_END

#endif // !TVAR_PMATH_H>
