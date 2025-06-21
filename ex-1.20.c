#include <stdio.h>
#define TABSIZE 4

int main() {
  int c, pos = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      int spaces = TABSIZE - (pos % TABSIZE);
      for (int i = 0; i < spaces; i++)
        putchar(' ');
      pos += spaces;
    } else {
      putchar(c);
      if (c == '\n')
        pos = 0;
      else
        pos++;
    }
  }
}
