
/* Write a pointer version of the function
 * strcat that we showed inChapter2: strcat(s,t) copies the string 't' to the end of 's'.
*/

#include <stdlib.h>
#include <stdio.h>

size_t my_strlen(const char *s) {
  const char *ptr = s;
  while (*ptr != '\0') {
    ptr++;
  }
  return ptr - s;
}

void print_arr(const char *s) {
  while (*s) {
    printf("%c", *s);
    s++;
  }
  printf("%c", '\n');
}

char *my_strcat(char *dest, const char *src) {
  size_t new_size = (my_strlen(dest) + my_strlen(src) + 1) * sizeof(char);

  char *new_dest = malloc(new_size);
  char *newptr = new_dest;

  while (*dest) { *newptr++ = *dest++; }
  while (*src) { *newptr++ = *src++; }
  *newptr = '\0';

  return new_dest;
}

int main() {
  char *dest = "hello, ";
  const char *src = "world!";
  const char *another = "\tGoodbye";
  char *new_str = my_strcat(dest, src);
  print_arr(new_str);
  new_str = my_strcat(new_str, another);
  print_arr(new_str);

  return 0;
}