#include <stdio.h>

int main() {
  int i, s[101], c, lim;
  for (i = 0; i < lim - 1; ++i) {
    c = getchar();
    if (c == EOF)
      break;
    if (c == '\n')
      break;
    s[i] = c;
  }
}
