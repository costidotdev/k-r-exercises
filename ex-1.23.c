/* Exercise 1-23. Write a program to remove all comments from a C program. Don't
forget to hand*le quoted strings and character constants properly. C comments
\\n don't nest. */

// There are single line comments //(that go from the slashes to the end of the
// line), and multi line comments /* */(dont nest). we need to check that the
// comments are not in quoted strings can i write here

// He said \"Hello\""
#include <stdio.h>

int main() {
  int c, c2;
  int inQuotedString = 0;
  int inChar = 0;
  while ((c = getchar()) != EOF) {
    if (c == '"' && !inChar) {
      inQuotedString = !inQuotedString;
      putchar(c);
    } else if (c == '\'' && !inQuotedString) {
      inChar = !inChar;
      putchar(c);
    } else if (c == '\\' && (inQuotedString || inChar)) {
      // if there is a escape character in a string or char we print it
      putchar(c);
      if ((c2 = getchar()) != EOF)
        putchar(c2);
    } else if (c == '/' && !inQuotedString && !inChar) {
      c2 = getchar();
      if (c2 == '/') {
        while ((c2 = getchar()) != '\n' && c2 != EOF)
          ;
        if (c2 == '\n')
          putchar('\n');
      } else if (c2 == '*') {
        int prev = c;
        while ((c = getchar()) != EOF) {
          if (c == '/' && prev == '*')
            break;
          prev = c;
        }
      } else {
        putchar('/');
        if (c2 != EOF)
          putchar(c2);
      }
    } else
      putchar(c);
  }
  return 0;
}
