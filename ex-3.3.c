// Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations
// like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
// Allow for letters of either case and digits, and be prepared to handle cases
// like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
// literally.

#include <stdio.h>
#define SIZE 101

void expnd(char s1[], const char s2[]) {
  char first = s2[0];
  char second = s2[2];
  int i, j;
  for (i = first, j = 0; i <= second; i++, j++)
    s1[j] = i;
  s1[j] = '\0';
}

void expand(char s1[], char s2[]) {
  int i = 0;
  int j = 0;
  char c;

  while ((c = s1[i]) != '\0') {
    if (s1[i + 1] == '-' && s1[i + 2] >= c) {
      i = i + 2;
      while (c <= s1[i])
        s2[j++] = c, c++;
    } else
      s2[j++] = c;
    i++;
  }

  s2[j] = '\0';
}

int main() {
  char s1[] = "-a-zA-Z0-9HELLOa-0", s2[SIZE];
  expand(s1, s2);
  printf("%s", s2);
  return 0;
}
