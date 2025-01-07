#include <stdio.h>

int main()
{
  int N, min = 0;  // 방 번호, 최소 세트 개수
  int a[10] = {0}; // 1~9
  scanf("%d", &N);

  for (int i = N; i > 0; i /= 10)
  {
    a[i % 10]++;
  }

  for (int i = 0; i < 10; i++)
  {
    if (min < a[i])
    {
      if (i == 6 || i == 9)
      {
        min = (a[6] + a[9] + 1) / 2;
      }
      else
      {
        min = a[i];
      }
    }
  }

  printf("%d\n", min);

  return 0;
}