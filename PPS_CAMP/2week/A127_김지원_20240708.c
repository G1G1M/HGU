#include <stdio.h>

int main()
{
  int n1, n2, max, t = 0;
  scanf("%d", &t);

  for (int i = 0; i < t; i++)
  {
    scanf("%d %d", &n1, &n2);

    if (n1 > n2)
    {
      for (int i = 1; i < n1; i++)
      {
        if (n1 % i == 0 && n2 % i == 0)
        {
          max = i;
        }
      }
    }

    if (n1 < n2)
    {
      for (int i = 1; i < n2; i++)
      {
        if (n1 % i == 0 && n2 % i == 0)
        {
          max = i;
        }
      }
    }

    if (n1 == n2)
    {
      max = n1;
    }

    printf("%d\n", (n1 * n2) / max);
  }

  return 0;
}