#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  printf("Ranges:\n");

  printf("Char min: %d\n", CHAR_MIN);
  printf("Char max: %d\n", CHAR_MAX);
  printf("Unsigned Char max: %d\n", UCHAR_MAX);

  printf("Short min: %d\n", SHRT_MIN);
  printf("Short max: %d\n", SHRT_MAX);
  printf("Unsigned Short max: %d\n", USHRT_MAX);

  printf("Int min: %d\n", INT_MIN);
  printf("Int max: %d\n", INT_MAX);
  printf("Unsigned Int max: %u\n", UINT_MAX);

  printf("Long min: %ld\n", LONG_MIN);
  printf("Long max: %ld\n", LONG_MAX);
  printf("Unsigned Long max: %lu\n", ULONG_MAX);

  printf("Long Long max: %lld\n", LLONG_MIN);
  printf("Long Long min: %lld\n", LLONG_MAX);
  printf("Unsigned Long Long max: %llu\n", ULLONG_MAX);

  printf("FLoat min: %e\n", FLT_MIN);
  printf("Float max: %e\n", FLT_MAX);

  printf("Double min: %e\n", DBL_MIN);
  printf("Double max: %e\n", DBL_MAX);
}
