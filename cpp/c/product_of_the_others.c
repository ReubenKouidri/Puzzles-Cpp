
/*
Create a product_of_the_others() function that takes in an array of integers and
replaces each number in the array with the product of all the numbers
in the array except the number at that index itself.

For example, product_of_the_others([1, 2, 3, 4, 5]) should return [120, 60, 40, 30, 24],
and product_of_the_others([5, 5, 5]) should return [25, 25, 25].
*/

#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

int* product_of_the_others(const int *arr, const size_t size) {
  int* result = calloc(size, sizeof(int));  // initialises to 0 by default

  for (int i = 0; i < size; i++) {
     for (int j = 0; j < size; j++) {
       if (i != j) {
         if (result[i] == 0) { result[i] = arr[j]; }
         result[i] *= arr[j];
       }
     }
  }
  return result;
}

void print_arr(const int* arr, size_t size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  srand(1241839);
  int arr[SIZE];
  for (int i = 0; i < SIZE; i++) { arr[i] = (rand() % 10) + 1; }
  int* result = product_of_the_others(arr, SIZE);
  print_arr(result, SIZE);
  free(result);  // freed anyway after func next line so don't really need this
  return 0;
}