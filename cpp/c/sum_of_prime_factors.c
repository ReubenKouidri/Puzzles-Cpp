#include <stdlib.h>
#include "prime_finder.h"


 void reduce(int n, int *fptr) {
  if (!isPrime(n)) {
    for (int i = 2; i < (int)n/2; i++) {
      if (n % i == 0) {
        *fptr++ = i;
        *fptr++ = n / i;
        reduce(i, fptr);
        reduce(n / i, fptr);
        break;
      }
    }
  }
}

int sum_prime_factors(int n) {
  if (isPrime(n)) return n;
  int *factors = malloc(sizeof(int) * n);
  int *fptr = factors;

  reduce(n, fptr);
  int *it = &factors[0];
  int sum = 0;
  while (*it != 0) {
    if (isPrime(*it)) {
      sum += *it;
    }
    it++;
  }
  free(factors);
  return sum;
}


int main() {
  int n = 75;
  int sum = sum_prime_factors(n);
  printf("%d", sum);
  return 0;
}
