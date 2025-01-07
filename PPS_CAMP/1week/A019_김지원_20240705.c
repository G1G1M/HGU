#include <stdio.h>

int main()
{
  int A, B, C, mul;
  int arr[100] = {0};

  scanf("%d", &A);
  scanf("%d", &B);
  scanf("%d", &C);

  mul = A * B * C;

  for (int i = mul; i > 0; i /= 10)
  {
    arr[i % 10]++;
  }

  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", arr[i]);
  }

  return 0;
}