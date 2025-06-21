#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]) {
  int i, j = 0, last = -1;
  int slen = strlen(s), tlen = strlen(t);
  for (i = 0; i <= slen - tlen; i++) {
    for (j = 0; j < tlen && s[i + j] == t[j]; j++)
      ;
    if (j == tlen)
      last = i;
  }
  return last;
}

int main() {
  char s[] = "hello";
  char t[] = "ell";
  printf("%d", strindex(s, t));
  return 0;
}
