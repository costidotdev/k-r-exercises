#include <stdio.h>

int main() {
  int c, count = 0;
  /*while ((c = getchar()) != EOF)*/
  /*  count++;*/
  /*while (getchar() != EOF)*/
  /*  count++;*/

  double nc;
  for (nc = 0; getchar() != EOF; nc++)
    ;
  printf("%0.f\n", nc);
}
