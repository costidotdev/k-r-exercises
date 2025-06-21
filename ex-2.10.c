#include <stdio.h>

char lower(char c) { return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c; }

int main() {
  char c = '9';
  printf("%c", lower(c));
}
