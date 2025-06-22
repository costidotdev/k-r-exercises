#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);
/* getfloat: get next float from input into *pn */
int getfloat(float *pn) {
  int c, sign;
  float power = 1.0;
  while (isspace(c = getch()))
    /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetch(c); /* it is not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
    if (!isdigit(c) && c != '.') {
      ungetch(c);
      ungetch((sign == -1) ? '-' : '+');
      return 0;
    }
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  if (c == '.') {
    c = getch();
    for (; isdigit(c); c = getch())
      *pn = 10 * *pn + (c - '0'), power *= 10;
  }
  *pn = *pn * sign / power;
  if (c != EOF)
    ungetch(c);
  return 1;
}

int main() {
  float x;
  getfloat(&x);
  printf("%f", x);
  return 0;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
/* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
