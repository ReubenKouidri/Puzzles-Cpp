#include <stdio.h>
#include <stdbool.h>

#ifndef PRIME_FINDER_H
#define PRIME_FINDER_H

bool isPrime(const int n) {
  for (int i = 2; i <= (int)(n / 2); i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void print_array(int* aptr, int size_of_array) {
  printf("[");
  for (int i = 0; i < size_of_array - 1; i++ && aptr++) {
    if (*aptr != 0) { printf("%d ", *aptr); }
  }
  printf("]");
}

//int main() {
//  const int n = 10;
//  int primes[n - 1] = {};
//  for (int i = 2; i <= n; i++) {
//    if (isPrime(i)) {
//      primes[i - 2] = i;
//    }
//  }
//
//  print_array(&primes[0], n - 1);
//  return 0;
//}

#endif  // PRIME_FINDER_H