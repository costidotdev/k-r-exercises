#include <stdio.h>
#define TABSTOP 8

int main(void) {
  int c, pos = 0, nrSpaces = 0, nrTabs = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (pos % TABSTOP != 0)
        nrSpaces++;
      else {
        nrSpaces = 0;
        nrTabs++;
      }
    } else {
      // Put tabs
      for (int i = 0; i < nrTabs; i++)
        putchar('\t');
      nrTabs = 0;
      // If the char is a tab go to next tab stop and make nrSpaces 0
      if (c == '\t') {
        nrSpaces = 0;
        pos = pos + TABSTOP - (pos % TABSTOP);
      }
      // Put spaces
      for (int i = 0; i < nrSpaces; i++)
        putchar(' ');
      nrSpaces = 0;
      putchar(c);
      if (c == '\n')
        pos = 0;
    }
    pos++;
  }
  return 0;
}
