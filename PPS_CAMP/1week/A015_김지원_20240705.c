#include <stdio.h>

int main()
{
  int A, B, C, D, E;
  scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);

  int KOINUM = ((A * A) + (B * B) + (C * C) + (D * D) + (E * E)) % 10;
  printf("%d\n", KOINUM);

  return 0;
}