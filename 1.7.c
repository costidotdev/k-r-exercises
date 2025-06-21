#include <stdio.h>

long long power(int m, int n);

int main() {
  for (int i = 0; i <= 32; i++)
    printf("%lld\n", power(2, i));
  return 0;
}

long long power(int m, int n) {
  if (n == 0)
    return 1;
  if (n < 0)
    return 1 / power(m, -n);
  return m * power(m, n - 1);
}
