#include <stdio.h>

void itoa(int x, char s[]) {
  static int i = 0;
  if (x / 10) {
    itoa(x / 10, s);
  }
  s[i++] = x % 10 + '0';
  s[i] = '\0';
}

int main() {
  char s[101];
  itoa(123, s);
  printf("%s", s);
  return 0;
}
