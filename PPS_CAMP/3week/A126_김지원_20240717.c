#include <stdio.h>
int main()
{
  int n, a = 0;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
  {
    if (i < 100)
      a++;
    else
    {
      if (i / 100 - (i % 100 / 10) == (i % 100 / 10) - i % 10)
        a++;
    }
  }

  printf("%d\n", a);
}