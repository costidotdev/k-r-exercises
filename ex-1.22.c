#include <stdio.h>

#define MAXCOL 10
#define TABSTOP 4

char line[MAXCOL + 1];

void printLine(int pos) {
  for (int i = 0; i < pos; i++)
    putchar(line[i]);
  if (pos != 0)
    putchar('\n');
}

int findLastBlank(int pos) {
  while (pos >= 0 && line[pos] != ' ')
    pos--;
  // No blanks found
  if (pos < 0)
    return MAXCOL;
  return pos + 1;
}

int rearrange(int pos) {
  if (pos == MAXCOL)
    return 0;
  else {
    int i = 0; // index into beginning of line
    for (int j = pos; j < MAXCOL; j++)
      line[i++] = line[j];
    return i;
  }
}

int main() {
  int c, pos = 0;
  while ((c = getchar()) != EOF) {
    line[pos++] = c;

    if (c == '\t') {
      pos--;
      while (pos < MAXCOL && pos % TABSTOP != 0)
        line[pos++] = ' ';
      if (pos >= MAXCOL) {
        printLine(pos);
        pos = 0;
      }
    } else if (c == '\n') {
      pos--;
      printLine(pos);
      pos = 0;
    } else if (pos >= MAXCOL) {
      pos = findLastBlank(pos);
      printLine(pos);
      pos = rearrange(pos);
    }
  }
  return 0;
}
