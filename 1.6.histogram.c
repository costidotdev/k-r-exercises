#include <stdio.h>

int main() {
  int c, wordsLength[100], nrWords = 0, currentWordLength = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      wordsLength[nrWords++] = currentWordLength;
      currentWordLength = 0;
    } else
      currentWordLength++;
  }
  if (currentWordLength > 0) {
    wordsLength[nrWords++] = currentWordLength;
  }
  for (int i = 0; i < nrWords; i++) {
    printf("%d:", i + 1);
    for (int j = 0; j < wordsLength[i]; j++)
      printf("#");
    printf("\n");
  }
  return 0;
}
