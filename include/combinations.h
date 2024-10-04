#ifndef TVAR_COMBINATIONS_H
#define TVAR_COMBINATIONS_H

#include "macros.h"
#include "types.h"


CXX_BEGIN

TVAR comb_t factorial (comb_t N);
TVAR comb_t combinations (comb_t n, comb_t k);
TVAR prob_t binominal_distribution (comb_t n, comb_t k, prob_t p);
TVAR prob_t average (datavector * V);
TVAR prob_t dispersion (datavector * V);
TVAR prob_t standard_deviation (datavector * V);
TVAR prob_t varcoeff (datavector * V);
TVAR prob_t correlation (comb_t pairs, datavector * X, datavector * Y);

CXX_END

#endif // !TVAR_COMBINATIONS_H
