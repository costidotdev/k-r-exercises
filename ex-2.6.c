#include <stdio.h>

// Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
// bits that begin at position p set to the rightmost n bits of y, leaving the
// other bits unchanged.

int setbits(int x, int p, int n, int y) {
  // Get the last n bits from y
  int lastBits = y & ~(~0 << n);
  // Move bits over to position
  int setBits = lastBits << (p - n);
  // Clear bits in x starting at position p
  int cleared = ~(~(~0 << n) << (p - n));
  x = x & cleared;
  return x | setBits;
}

int main() {
  unsigned int x = 240;
  int p = 6;
  int n = 3;
  int y = 15;
  printf("%d", setbits(x, p, n, y));
}
