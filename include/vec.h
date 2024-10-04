#include "pmath.h"
#include "types.h"

TVAR_HEADER datavector * make_vec (comb_t N)
{
  datavector * V = (datavector *) malloc(sizeof(datavector));
  V->len = N;
  V->rawmem = (prob_t *) malloc(N * sizeof(prob_t));
  return V;
}

TVAR_HEADER void destroy_vec (datavector * V)
{
  free(V->rawmem);
  free(V);
}

TVAR_HEADER prob_t sum_vec (datavector * V)
{
  prob_t res = 0;
  for (comb_t i = 0; i < V->len; i++)
  {
    res += V->rawmem[i];
  }
  return res;
}

TVAR_HEADER datavector * square_vec (datavector * V)
{
  datavector * V1 = make_vec(V->len);
  for (comb_t i = 0; i < V->len; i++)
  {
    V1->rawmem[i] = prob_pow(V->rawmem[i], 2);
  }
  return V1;
}

TVAR_HEADER datavector * mult_vec (datavector * V1, datavector * V2)
{
  datavector * V = make_vec(V1->len);
  for (comb_t i = 0; i < V->len; i++)
  {
    V->rawmem[i] = V1->rawmem[i] * V2->rawmem[i];
  }
  return V1;
}
