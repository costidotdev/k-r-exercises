#include <stdio.h>

int main() {
  int c, words = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      words++;
      printf("\n");
    } else
      putchar(c);
  }
  printf("%d", words);
}
