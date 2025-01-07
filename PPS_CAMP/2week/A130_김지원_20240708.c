#include <stdio.h>
#define SIZE 1000001

int main()
{
  int k, n, sum = 0; // 줄 개수, 배열 크기 인덱스 값, 저장된 배열 값들의 합
  int N1[SIZE];      // 정수를 저장할 배열
  int N2[SIZE];      // 새로운 정수를 저장할 배열

  scanf("%d", &k);

  for (int i = 0; i < k; i++)
  {
    scanf("%d", &N1[i]);
  }

  for (int i = 0; i < k; i++)
  {
    if (N1[i] != 0)
    {
      N2[n] = N1[i];
      n++;
    }
    else
    {
      N2[n - 1] = 0;
      n--;
    }
  }

  for (int i = 0; i <= n; i++)
  {
    sum += N2[i];
  }

  printf("%d\n", sum);

  return 0;
}