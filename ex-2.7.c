// Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
// that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
// leaving the others unchanged.

#include <stdio.h>

unsigned int invert(int x, int p, int n) {
  unsigned int mask = (~(~0 << n)); //  11111000 -> 00000111
  mask = mask << (p + 1 - n);       // -> 01110000
  return x ^ mask;
}

int main() {
  unsigned int x = 240; // 11110000 , 10000000, 1111 1111,
  int p = 6;
  int n = 3;
  printf("%d", invert(x, p, n)); // 11110000 -> 10000000 (128)
}
