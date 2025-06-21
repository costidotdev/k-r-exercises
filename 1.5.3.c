#include <stdio.h>

int main() {

  int c, lines = 0, tabs = 0, blanks = 0;
  /*while ((c = getchar()) != EOF) {*/
  /*  if (c == '\n')*/
  /*    lines++;*/
  /*  if (c == '\t')*/
  /*    tabs++;*/
  /*  if (c == ' ')*/
  /*    blanks++;*/
  /*}*/
  /*while ((c = getchar()) != EOF) {*/
  /*  if (c == ' ') {*/
  /*    while ((c = getchar()) == ' ')*/
  /*      ;*/
  /*    putchar(' ');*/
  /*    if (c == EOF)*/
  /*      break;*/
  /*  }*/
  /*  putchar(c);*/
  /*}*/
  /*printf("%d\n%d\n%d", lines, tabs, blanks);*/
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
    } else if (c == '\b') {
      putchar('\\');
      putchar('b');
    } else if (c == '\\') {
      putchar('\\');
      putchar('\\');
    } else
      putchar(c);
  }
}
