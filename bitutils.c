#include "bitutils.h"
#include <stdio.h>

int set_bit(int num, int pos) {
  int mask = 1 << pos;
  return num | mask;
}

int get_bit(int num, int pos) {
  int mask = 1 << pos;
  return num & mask;
}

int clear_bit(int num, int pos) {
  int mask = ~(1 << pos);
  return num & mask;
}

int toggle_bit(int num, int pos) {
  int mask = 1 << pos;
  return num ^ mask;
}

int count_set_bits(int num) {
  int count = 0;
  while (num) {
    count += num & 1;
    num >>= 1;
  }
  return count;
}

void print_in_binary(int num) {
  int bits = sizeof(num) * 8;
  for (int i = bits - 1; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
    if (i % 4 == 0)
      printf(" ");
  }
  printf("\n");
}
