#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define LIMIT 80

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);

int main() {
  int len;
  int max = 0;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    if (len > LIMIT) {
      printf("Long line (> %d chars):\n%s", LIMIT, line);
    }

    char reversed[MAXLINE];
    copy(reversed, line);
    reverse(reversed);
    printf("Reversed line:\n%s", reversed);

    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("\nLongest line (%d chars):\n%s", max, longest);
  }

  return 0;
}

int getLine(char s[], int lim) {
  int c, i = 0;

  while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }

  while (i > 0 && (s[i - 1] == ' ' || s[i - 1] == '\t')) {
    --i;
  }

  if (c == '\n') {
    s[i++] = '\n';
  }

  s[i] = '\0';

  return i > 1 ? i : 0;
}

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    i++;
  }
}

void reverse(char s[]) {
  int i, j;
  char temp;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    if (s[j] == '\n')
      j--;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}
