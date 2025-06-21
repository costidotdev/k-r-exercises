#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 101
#define NUMBER '0'
#define MATH '1'

double stack[SIZE];
int sp = 0;

int buf[SIZE];
int bp = 0;
double variables[26] = {0};

double pop();
double top();
int getop(char s[]);
void push(double x);
void duplicate();
void swap_top_two();
void clear();

int main() {
  char s[SIZE];
  double op1, op2;
  int type;
  double mostRecent = -1;

  while ((type = getop(s)) != EOF)
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case MATH:
      if (strcmp(s, "sin") == 0)
        push(sin(pop()));
      else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
      else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
      else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
      } else
        printf("Unknown math function\n");
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      op1 = pop();
      if (op2 != 0.0)
        push(op1 - op2 * (int)(op1 / op2));
      else
        printf("zero division error\n");
      break;
    case 'p':
      printf("Top: %.8g\n", top());
      break;
    case 'd':
      duplicate();
      break;
    case 's':
      swap_top_two();
      break;
    case 'c':
      clear();
      break;
    case '=': {
      double value = pop();
      int var_index = (int)pop();
      if (var_index >= 'A' && var_index <= 'Z') {
        variables[var_index - 'A'] = value;
        push(value);
      } else
        printf("Invalid variable\n");
      break;
    }
    case 'A' ... 'Z':
      push(variables[type - 'A']);
      break;
    case '\n':
      mostRecent = pop();
      printf("\t%.8g\n", mostRecent);
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  return 0;
}

int getch();
void ungetch(int c);

double pop() {
  if (sp > 0)
    return stack[--sp];
  printf("error: stack empty\n");
  return 0.0;
}

void push(double x) {
  if (sp < SIZE)
    stack[sp++] = x;
  else
    printf("error: stack full, can't push %g\n", x);
}

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

double top() {
  if (sp > 0)
    return stack[sp - 1];
  return 0.0;
}

void duplicate() {
  if (sp > 0 && sp < SIZE) {
    stack[sp] = stack[sp - 1];
    sp++;
  }
}

void swap(double *a, double *b) {
  double aux = *a;
  *a = *b;
  *b = aux;
}

void swap_top_two() {
  if (sp >= 2)
    swap(&stack[sp - 2], &stack[sp - 1]);
}

void clear() { sp = 0; }

int getop(char s[]) {
  int i, c;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  i = 0;
  if (isalpha(c)) {
    while (isalpha(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    if (c != EOF)
      ungetch(c);
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
      if (c != EOF) {
        ungetch(c);
      }
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
    ungetch(c);
  return NUMBER;
}
