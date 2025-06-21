#include <stdio.h>

int main() {
  int c, nrWhitespaces = 0, nrOtherChar = 0;
  int digitsArray[10];
  for (int i = 0; i <= 9; i++)
    digitsArray[i] = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      nrWhitespaces++;
    else if (c >= '0' && c <= '9')
      digitsArray[c - '0']++;
    else
      nrOtherChar++;
  }

  printf("Digits: ");
  for (int i = 0; i <= 9; i++)
    printf("%d ", digitsArray[i]);
  printf("\n");
  printf("Whitespaces: %d\n", nrWhitespaces);
  printf("Other Characters: %d\n", nrOtherChar);
  return 0;
}
