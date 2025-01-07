#include <stdio.h>

int main()
{
  int n; // 정수 개수
  int arr[100000];

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int max = arr[0];

  for (int i = 1; i < n; i++)
  {
    if (arr[i - 1] > 0) // 양수만 나올 경우
    {
      arr[i] += arr[i - 1];
    }
    if (arr[i] > max) // 양수와 음수가 같이 나올 경우
    {
      max = arr[i];
    }
  }
  printf("%d\n", max);

  return 0;
}