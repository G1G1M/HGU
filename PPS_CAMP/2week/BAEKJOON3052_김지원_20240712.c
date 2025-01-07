#include <stdio.h>
#define SIZE 1001

int main()
{
  int n[SIZE] = {0}; // 정수가 저장된 배열
  int m[SIZE] = {0}; // 정수를 42로 나눈 나머지가 저장된 배열
  int k, cnt = 0;

  for (int i = 0; i < 10; i++)
  {
    scanf("%d", &n[i]);
    k = n[i] % 42;
    m[k]++;
  }

  for (int i = 0; i < SIZE; i++)
  {
    if (m[i] != 0)
    {
      cnt++;
    }
  }

  printf("%d\n", cnt);

  return 0;
}