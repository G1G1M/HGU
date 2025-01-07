// 백준 2738번으로 대체
#include <stdio.h>

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  int a[n][m];
  int b[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%d", &b[i][j]);
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int sum = a[i][j] + b[i][j];
      printf("%d ", sum);
    }
    printf("\n");
  }

  return 0;
}