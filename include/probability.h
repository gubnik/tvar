#ifndef TVAR_PROBABILITY_H
#define TVAR_PROBABILITY_H

#include "macros.h"
#include "types.h"

CXX_BEGIN

TVAR prob_t conditional_probability (prob_t, prob_t);
TVAR prob_t bayes_theorem (prob_t, prob_t, prob_t);

CXX_END

#endif // !TVAR_PROBABILITY_H
