#include <stdio.h>
#define MAX_LINE 101

void readline(char[]);
int any(char[], const char[]);

int main() {
  int c, i = 0;
  char s1[MAX_LINE], s2[MAX_LINE];
  readline(s1);
  readline(s2);
  int x = any(s1, s2);
  printf("%d", x);
  return 0;
}

void readline(char s[]) {
  int c, i = 0;
  while ((c = getchar()) != EOF && i < MAX_LINE) {
    if (c == '\n') {
      s[i] = '\0';
      break;
    } else
      s[i++] = c;
  }
}

int any(char s1[], const char s2[]) {
  for (int i = 0; s1[i]; i++)
    for (int j = 0; s2[j]; j++)
      if (s1[i] == s2[j])
        return i;
  return -1;
}
