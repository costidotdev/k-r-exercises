#include <stdio.h>

int main() {
  int c;
  int isEOF = (getchar() == EOF);
  printf("%d\n", isEOF);
  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
  printf("Printing EOF:");
  printf("%d", c);
}
