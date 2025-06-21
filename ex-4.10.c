#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER '0'
#define SIZE 101
#define MATH '1'

double stack[SIZE];
int sp = 0;
double variables[26] = {0};

double pop(void);
double top(void);
int getop(char s[], char line[], int *pos);
void push(double x);
void duplicate(void);
void swap_top_two(void);
void clear(void);

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  char s[SIZE];
  double op1, op2;
  int type;
  int pos;
  double mostRecent = 0;

  printf("Enter expressions (Ctrl+D to exit):\n");

  while ((read = getline(&line, &len, stdin)) != -1) {
    pos = 0;

    while (pos < strlen(line)) {
      type = getop(s, line, &pos);

      if (type == EOF || type == '\n')
        break;

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
          printf("Unknown math function: %s\n", s);
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
      default:
        if (type >= 'A' && type <= 'Z')
          push(variables[type - 'A']);
        else
          printf("error: unknown command %s\n", s);
        break;
      }
    }

    // Print result at end of line if stack is not empty
    if (sp > 0) {
      mostRecent = pop();
      printf("\t%.8g\n", mostRecent);
    }
  }

  free(line);
  return 0;
}

double pop(void) {
  if (sp > 0)
    return stack[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void push(double f) {
  if (sp < SIZE)
    stack[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double top(void) {
  if (sp > 0)
    return stack[sp - 1];
  return 0.0;
}

void duplicate(void) {
  if (sp > 0 && sp < SIZE) {
    stack[sp] = stack[sp - 1];
    sp++;
  } else {
    printf("error: cannot duplicate\n");
  }
}

void swap_top_two(void) {
  if (sp >= 2) {
    double temp = stack[sp - 1];
    stack[sp - 1] = stack[sp - 2];
    stack[sp - 2] = temp;
  } else {
    printf("error: not enough elements to swap\n");
  }
}

void clear(void) { sp = 0; }

/* getop: get next operator or numeric operand from line */
int getop(char s[], char line[], int *pos) {
  int i, c;

  // Skip whitespace
  while (*pos < strlen(line) && (line[*pos] == ' ' || line[*pos] == '\t'))
    (*pos)++;

  // Check for end of line
  if (*pos >= strlen(line) || line[*pos] == '\n')
    return '\n';

  s[0] = c = line[(*pos)++];
  s[1] = '\0';

  // Handle alphabetic characters (math functions or variables)
  if (isalpha(c)) {
    i = 0;
    s[i++] = c;
    while (*pos < strlen(line) && isalpha(line[*pos]))
      s[i++] = line[(*pos)++];
    s[i] = '\0';
    if (strlen(s) > 1)
      return MATH;
    else
      return s[0]; // Single letter variable
  }

  // Handle numbers (including negative numbers)
  if (isdigit(c) || c == '.' || c == '-') {
    i = 0;
    s[i++] = c;

    // If it's a minus sign, check if it's followed by a digit
    if (c == '-') {
      if (*pos < strlen(line) && (isdigit(line[*pos]) || line[*pos] == '.')) {
        // It's a negative number
        while (*pos < strlen(line) &&
               (isdigit(line[*pos]) || line[*pos] == '.'))
          s[i++] = line[(*pos)++];
      } else {
        // It's a minus operator
        s[1] = '\0';
        return c;
      }
    } else {
      // Collect the rest of the number
      while (*pos < strlen(line) && (isdigit(line[*pos]) || line[*pos] == '.'))
        s[i++] = line[(*pos)++];
    }
    s[i] = '\0';
    return NUMBER;
  }

  // Return the character as is (operator)
  return c;
}
