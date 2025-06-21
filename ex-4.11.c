#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define SIZE 101
#define NUMBER '0'
#define MATH '1'

int buf[SIZE];
int bp = 0;

int getch();
void ungetch(int c);
void ungets(char s[]);
int getop(char s[]);

int main() {}

int getch() {
  if (bp > 0)
    return buf[--bp];
  else
    return getchar();
}

void ungetch(int c) {
  if (bp < SIZE)
    buf[bp++] = c;
  else
    printf("ungetch: too many characters\n");
}

void ungets(char s[]) {
  int len = strlen(s);
  for (int i = len - 1; i >= 0; i--)
    ungetch(s[i]);
}

int getop(char s[]) {
  int i, c;
  static int lastc = 0;
  if (lastc == 0)
    c = getchar();
  else {
    c = lastc;
    lastc = 0;
  }
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  i = 0;
  if (isalpha(c)) {
    while (isalpha(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    if (c != EOF)
      lastc = c;
    if (strlen(s) > 1)
      return MATH;
    else
      return s[0];
  }
  if (!isdigit(c) && c != '.' && c != '-')
    return c;
  if (c == '-') {
    if (isdigit(c = getch()))
      s[++i] = c;
    else {
      if (c != EOF)
        lastc = c;
      return '-';
    }
  }
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    lastc = c;
  return NUMBER;
}
