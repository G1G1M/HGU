#include <stdio.h>

int main()
{
  int n; // 4의 배수
  scanf("%d", &n);

  for (int i = 0; i < n / 4; i++)
  {
    printf("long ");
  }
  printf("int\n");

  return 0;
}