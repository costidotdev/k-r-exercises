#include <math.h>
#include <stdio.h>

double atof(char s[]) {
  double nr = 0;
  int i = 0;
  int power = 1;
  int exp = 0;
  int expsign = 1;
  int hasE = 0;
  int sign = 0;

  if (s[i] == '-') {
    sign = -1;
    i++;
  } else if (s[i] == '+') {
    i++;
  }

  while (s[i] != '.' && s[i] != 'e' && s[i] != 'E' && s[i] != '\0')
    nr = nr * 10 + (s[i++] - '0');

  if (s[i] == '.') {
    i++; // skip .
    while (s[i] != 'e' && s[i] != 'E' && s[i] != '\0') {
      nr = nr * 10 + (s[i++] - '0');
      power *= 10;
    }
  }

  if (s[i] == 'e' || s[i] == 'E') {
    hasE = 1;
    i++;
    if (s[i] == '-') {
      expsign = -1;
      i++;
    } else if (s[i] == '+')
      i++;
    while (s[i] != '\0')
      exp = exp * 10 + (s[i++] - '0');
  }

  return sign * (nr / power) * pow(10, exp * expsign);
}

int main() {
  char s[] = "123.45e2";
  double x = atof(s);
  printf("%f", x);
  return 0;
}
