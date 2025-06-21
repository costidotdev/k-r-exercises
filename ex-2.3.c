/* Exercise 2-3. Write a function htoi(s), which converts a string of
hexadecimal digits (including an optional 0x or 0X) into its equivalent integer
value. The allowable digits are 0 through 9, a through f, and A through F.*/

#include <ctype.h>
#include <stdio.h>
#define MAX_HEX_LIM 101

int htoi(char[]);

int main() {
  char hex[MAX_HEX_LIM];
  int c, i = 0;
  while ((c = getchar()) != EOF && i < MAX_HEX_LIM) {
    c = tolower(c);
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || c == 'x') {
      hex[i++] = c;
    } else
      break;
  }
  hex[i] = '\0';
  int hexNr = htoi(hex);
  printf("%d", hexNr);
  return 0;
}

int htoi(char s[]) {
  int i = 0;
  int result = 0;

  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    i = 2;

  while (s[i] != '\0') {
    int c = tolower(s[i]);
    int convertedDigit = 0;
    if (c >= '0' && c <= '9')
      convertedDigit = c - '0';
    else if (c >= 'a' && c <= 'f')
      convertedDigit = c - 'a' + 10;
    else
      return -1;

    result = result * 16 + convertedDigit;
    i++;
  }
  return result;
}

// F4A -> 16^2 * 15 + 16^1 * 4 + 16^0 * 2
