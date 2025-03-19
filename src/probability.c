#include "../include/probability.h"

TVAR prob_t conditional_probability(prob_t A, prob_t AnB)
{
  return AnB / A;
}

TVAR prob_t bayes_theorem(prob_t A, prob_t B, prob_t BnA)
{
  return BnA * A / B;
}
