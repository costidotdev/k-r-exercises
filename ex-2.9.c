int countbits(unsigned x) {
  int len = 0;
  for (; x; x &= x - 1)
    len++;
  return len;
}

int main() { int x = countbits(4); }
