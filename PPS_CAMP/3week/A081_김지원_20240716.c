#include <stdio.h>

int main()
{

  int a[10] = {0};
  int t, tmp;
  scanf("%d", &t);

  for (int i = 0; i < t; i++)
  {

    for (int j = 0; j < 10; j++)
    {
      scanf("%d", &a[j]);
    }

    for (int j = 0; j < 10; j++) // 내림차순
    {
      for (int k = 0; k < 9; k++)
      {
        if (a[k] < a[k + 1])
        {
          tmp = a[k];
          a[k] = a[k + 1];
          a[k + 1] = tmp;
        }
      }
    }

    printf("%d\n", a[2]); // 3번째로 큰 수
  }
}