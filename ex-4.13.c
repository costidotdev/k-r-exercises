#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
  static int i = 0;
  int j = strlen(s) - i - 1;
  if (i < j) {
    int aux = s[i];
    s[i] = s[j];
    s[j] = aux;
    i++;
    reverse(s);
  }
}

int main() {
  char s[] = "hello";
  reverse(s);
  printf("%s", s);
  return 0;
}
