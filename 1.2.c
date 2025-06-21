#include <stdio.h>

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("%3.0f %6.1f\n", fahr, celsius);
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9.0;
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
