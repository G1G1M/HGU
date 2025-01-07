#include <stdio.h>

int main()
{
  int n, swap, sum = 0; // 사람 수, 오름차순 swap
  int p[1001] = {0};    // 인출하는데 걸리는 시간 p를 모아둔 배열

  scanf("%d", &n);

  for (int i = 0; i < n; i++) // n만큼의 p인덱스들을 배열에 저장
  {
    scanf("%d", &p[i]);
  }

  for (int i = 0; i < n; i++) // 입력한 시간을 오름차순으로 나열
  {
    for (int j = 0; j < n - (i + 1); j++)
      if (p[j] > p[j + 1])
      {
        swap = p[j];
        p[j] = p[j + 1];
        p[j + 1] = swap;
      }
  }

  for (int i = 0; i < n; i++) // 나열한 시간을 주어진 조건에 따라 더하기
  {
    for (int j = 0; j < i + 1; j++)
    {
      sum += p[j];
    }
  }

  printf("%d\n", sum);

  return 0;
}