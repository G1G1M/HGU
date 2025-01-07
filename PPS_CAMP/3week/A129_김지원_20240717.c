#include <stdio.h>

int t, n, result[11];

int main()
{
  scanf("%d", &t);

  result[1] = 1;
  result[2] = 2;
  result[3] = 4;

  for (int i = 4; i < 11; i++)
  {
    result[i] = result[i - 1] + result[i - 2] + result[i - 3];
  }

  for (int i = 0; i < t; i++)
  {
    scanf("%d", &n);
    printf("%d\n", result[n]);
  }
  return (0);
}