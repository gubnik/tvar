#include <stdio.h>
#include <tvar/combinations.h>
#include <tvar/vec.h>

int main(int argc, char *argv[])
{
  printf("COMB_POW : %llu\n", comb_pow(3, 3));
  printf("(29 5) : %llu\n", combinations(29, 5));
  printf("Bindistr {29, 5, 0.3} : %Lf\n", binominal_distribution(29, 5, 0.3));
  datavector * V = make_vec(10);
  for (int i = 1; i < 11; i++) V->rawmem[i - 1] = (comb_t)i;
  datavector * V1 = make_vec(10);
  for (int i = 1; i < 11; i++) V1->rawmem[i - 1] = (comb_t)i * 3;
  printf("Sum : %Lf\n", sum_vec(V));
  printf("Correlation : %Lf\n", correlation(10, V, V1));
  return 0;
}
