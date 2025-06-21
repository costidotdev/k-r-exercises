// Exercise 3-2. Write a function escape(s,t) that converts characters like
// newline and tab into visible escape sequences like \n and \t as it copies the
// string t to s. Use a switch. Write a function for the other direction as
// well, converting escape sequences into the real characters.

#include <stdio.h>
#define SIZE 100

void escape(char s[], char t[]) {
  int i = 0, j = 0;
  while (t[i] != '\0') {
    switch (t[i]) {
    case '\t':
      s[j] = '\\';
      j++;
      s[j] = 't';
      break;
    case '\n':
      s[j] = '\\';
      j++;
      s[j] = 'n';
      break;
    default:
      s[j] = t[i];
      break;
    }
    i++;
    j++;
  }
  s[j] = '\0';
}

void descape(char s[], char t[]) {
  int i = 0, j = 0;
  while (t[i] != '\0') {
    if (t[i] == '\\') {
      i++;
      switch (t[i]) {
      case 't':
        s[j] = '\t';
        break;
      case 'n':
        s[j] = '\n';
        break;
      default:
        s[j] = t[i];
        break;
      }
    }
    i++;
    j++;
  }
  s[j] = '\0';
}

int main() {
  int c, i = 0;
  char s[SIZE], t[SIZE], d[SIZE];
  while ((c = getchar()) != EOF && i < SIZE - 1)
    t[i++] = c;
  t[i] = '\0';
  escape(s, t);
  descape(d, s);
  printf("%s\n", s);
  printf("%s\n", d);
}
