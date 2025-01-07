#include <stdio.h>

int main()
{
  int a, b, c, d, rank, max = 0;
  for (int i = 0; i < 5; i++)
  {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int n = a + b + c + d;
    if (n > max)
    {
      max = n;
      rank = i;
    }
  }
  printf("%d %d\n", rank + 1, max);

  return 0;
}