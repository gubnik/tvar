#include "../include/combinations.h"
#include "../include/pmath.h"
#include "../include/vec.h"

TVAR comb_t factorial (comb_t N)
{
  if (N == 0 || N == 1) return 1;
  comb_t res = 1;
  for (comb_t i = 2; i < N + 1; i++)
  {
    res *= i;
  }
  return res;
}

TVAR comb_t combinations (comb_t n, comb_t k)
{
  if (k > n) return 0;
  if (k == 0 || k == n) return 1;
  if (k > n - k) k = n - k;
  comb_t res = 1;
  for (comb_t i = 0; i < k; ++i)
  {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}

TVAR prob_t binominal_distribution(comb_t n, comb_t k, prob_t p)
{
  return combinations(n, k) * prob_pow(p, k) * prob_pow(1 - p, n - k);
}

TVAR prob_t average (datavector * V)
{
  prob_t sum = sum_vec(V);
  return sum / V->len;
}

TVAR prob_t dispersion (datavector * V)
{
  prob_t res = 0;
  prob_t avrg = average(V);
  for (comb_t i = 0; i < V->len; i++)
  {
    res += prob_pow(V->rawmem[i] - avrg, 2);
  }
  return res / V->len;
}

TVAR prob_t standard_deviation (datavector * V)
{
  return psqrt(dispersion(V));
}

TVAR prob_t correlation(comb_t pairs, datavector *X, datavector *Y)
{
  if (pairs != X->len || pairs != Y->len) return 0;
  prob_t xsum = sum_vec(X);
  prob_t ysum = sum_vec(Y);
  prob_t xsumq = prob_pow(xsum, 2);
  prob_t ysumq = prob_pow(ysum, 2);
  datavector * qX = square_vec(X);
  datavector * qY = square_vec(Y);
  prob_t qxsum = sum_vec(qX);
  prob_t qysum = sum_vec(qY);
  destroy_vec(qX);
  destroy_vec(qY);
  datavector * MV = mult_vec(X, Y);
  prob_t m = sum_vec(MV);
  destroy_vec(MV);
  return (pairs * m - (xsum * ysum)) / (psqrt(pairs * (qxsum - xsumq) * (qysum - ysumq)));
}
