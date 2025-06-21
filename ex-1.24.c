/* Exercise 1-24. Write a program to check a C program for rudimentary syntax
errors like unmatched parentheses, brackets and braces. Don't forget about
quotes, both single and double, escape sequences, and comments. (This program is
hard if you do it in full generality.)*/

#include <stdio.h>
#define MAXSIZE 1000

void skip_double_quote() {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\\') {
      c = getchar();
      if (c == EOF) {
        printf("Error: EOF in escape sequence within double quote\n");
        return;
      }
    } else if (c == '"')
      return;
  }
  printf("Error: No matching double quote\n");
}

void skip_single_quote() {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\\') {
      c = getchar();
      if (c == EOF) {
        printf("Error: EOF in escape sequence within single quote\n");
        return;
      }
    } else if (c == '\'')
      return;
  }
  printf("Error: No matching single quote\n");
}

void skip_inline_comment() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void skip_multiline_comment() {
  int c1 = getchar(), c2;
  while (c1 != EOF) {
    if (c1 == '*') {
      c2 = getchar();
      if (c2 == '/')
        return;
      c1 = c2;
    } else
      c1 = getchar();
  }
  printf("Error: No matching */ for multiline comment\n");
}

int main() {
  int c;
  int stack[MAXSIZE], i = 0, pos = 0;
  while ((c = getchar()) != EOF) {
    if (c == '"')
      skip_double_quote();
    else if (c == '\'')
      skip_single_quote();
    else if (c == '/') {
      c = getchar();
      if (c == '/')
        skip_inline_comment();
      else if (c == '*')
        skip_multiline_comment();
    } else if (c == '(' || c == '{' || c == '[') {
      stack[i++] = c;
    } else if (c == ')') {
      if (i == 0 || stack[i - 1] != '(') {
        printf("Error unmatched parantheses\n");
        return 1;
      }
      i--;
    } else if (c == '}') {
      if (i == 0 || stack[i - 1] != '{') {
        printf("Error unmatched braces\n");
        return 1;
      }
      i--;
    } else if (c == ']') {
      if (i == 0 || stack[i - 1] != '[') {
        printf("Error unmatched square brackets\n");
        return 1;
      }
      i--;
    }
  }
  if (i > 0) {
    printf("Error: Unmatched opening bracket(s) remain\n");
    return 1;
  }
  printf("Syntax check completed successfully\n");
  return 0;
}
