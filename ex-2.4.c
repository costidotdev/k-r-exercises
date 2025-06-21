/* Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes
each character in s1 that matches any character in the string s2*/

#include <stdio.h>
#define MAX_LINE 101

void squeeze(char[], const char[]);
void readline(char[]);
void deletechar(char[], int);

int main() {
  int c, i = 0;
  char s1[MAX_LINE], s2[MAX_LINE];
  readline(s1);
  readline(s2);
  squeeze(s1, s2);
  printf("%s", s1);
  return 0;
}

void readline(char s[]) {
  int c, i = 0;
  while ((c = getchar()) != EOF && i < MAX_LINE - 1) {
    if (c == '\n') {
      s[i] = '\0';
      break;
    } else
      s[i++] = c;
  }
}

void deletechar(char s[], int pos) {
  while (s[pos] != '\0') {
    s[pos] = s[pos + 1];
    pos++;
  }
}

void squeeze(char s1[], const char s2[]) {
  for (int i = 0; s1[i]; i++)
    for (int j = 0; s2[j]; j++)
      if (s1[i] == s2[j]) {
        deletechar(s1, i);
        i--;
        break;
      }
}
