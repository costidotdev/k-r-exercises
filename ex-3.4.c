// -2^7 -> 1011 0001
// 2^7 ->  0100 0000

#include <stdio.h>
#include <string.h>

void rev(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    c = s[i], s[i] = s[j], s[j] = c;
}

void itoa(int n, char s[]) {
  int i = 0;
  unsigned int num;

  int sign = n;

  num = (n < 0) ? -((unsigned int)n) : n;

  i = 0;
  do {
    s[i++] = num % 10 + '0';
    num /= 10;
  } while (num > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  rev(s);
}

int main() {
  int x = -2147483648;
  char s[101];
  itoa(x, s);
  printf("%s", s);
  return 0;
}
