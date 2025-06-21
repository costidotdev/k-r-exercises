#include <stdio.h>

void print_binary(unsigned int x) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (x >> i) & 1);
    if (i % 4 == 0)
      printf(" ");
  }
  printf("\n");
}

// get n bits from position p
unsigned int getbits(unsigned int x, int p, int n) {
  return (x >> (p + 1 - n));
}

int main() {
  unsigned int x = 0b00001001, p = 3, n = 3;
  print_binary(x);
  unsigned int z = getbits(x, p, n);
  print_binary(z);
}
