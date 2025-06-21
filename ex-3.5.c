#include <stdio.h>
#include <string.h>

void rev(char s[]);
void itob(int n, char s[], int b);

int main() {
  int x = -125;
  char s[101];

  itob(x, s, 16);
  printf("%s\n", s);
  itob(x, s, 2);
  printf("%s\n", s);
  return 0;
}

void rev(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    c = s[i], s[i] = s[j], s[j] = c;
}

void itob(int n, char s[], int b) {
  int r, sign, i = 0;
  char c;
  int bits = sizeof(n) * 8;
  if ((sign = n) < 0)
    n = -n;
  if (n == 0)
    s[i++] = '0';
  while (n != 0) {
    r = n % b;
    n = n / b;
    if (r > 9)
      c = r - 10 + 'A';
    else
      c = r + '0';
    s[i++] = c;
  }
  if (b == 2)
    while (i < bits)
      s[i++] = '0';
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  rev(s);
}
