#include <stdio.h>
#include <time.h>
#define SIZE 1000000

int binsearch(int x, int v[], int low, int high);
int iterative_bin_search(int x, int v[], int n);
int iterative_bin_search_1(int x, int v[], int n);

int main() {
  int v[SIZE];
  for (int i = 0; i < SIZE; ++i)
    v[i] = i * 2;

  int x = 345678;
  int result;

  clock_t start, end;
  double cpu_time_used;

  start = clock();

  for (int i = 0; i < 1000; i++)
    result = binsearch(x, v, 0, SIZE - 1);

  end = clock();

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Recursive binsearch: %.6f seconds, result: %d\n", cpu_time_used,
         result);

  start = clock();

  for (int i = 0; i < 1000; i++)
    result = iterative_bin_search(x, v, SIZE);

  end = clock();

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Iterative binsearch: %.6f seconds, result: %d\n", cpu_time_used,
         result);

  start = clock();

  for (int i = 0; i < 1000; i++)
    result = iterative_bin_search_1(x, v, SIZE);

  end = clock();

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Iteartive binsearch 1: %.6f seconds, result: %d\n", cpu_time_used,
         result);

  return 0;
}

int binsearch(int x, int v[], int low, int high) {
  if (high < low)
    return -1;
  int mid = (low + high) / 2;
  if (v[mid] == x)
    return mid;
  if (v[mid] > x)
    return binsearch(x, v, low, mid - 1);
  return binsearch(x, v, mid + 1, high);
}

int iterative_bin_search(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

int iterative_bin_search_1(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  mid = (low + high) / 2;
  while (low <= high && v[mid] != x) {
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
    mid = (low + high) / 2;
  }
  if (v[mid] == x)
    return mid;
  return -1;
}
