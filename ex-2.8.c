// Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
// integer x rotated to the right by n positions.

// 11100011 -> 11110001 (241) (n=1)
// 11100011 -> 11111000 (248) (n=2)
#include <stdio.h>

unsigned int rightrot(unsigned int x, int n) {
  while (n != 0) {
    unsigned int lastBit = x & 1;
    x = x >> 1;
    // put the last bit into the first bit
    lastBit = lastBit << (sizeof(x) * 8 - 1);
    x = x | lastBit;
    n--;
  }
  return x;
}

int main() {
  unsigned int x = 0b11100011;
  int n = 2;
  printf("%d", rightrot(x, n));
}
