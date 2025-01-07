#include <stdio.h>

int main()
{
  int A[50] = {0};
  int B[50] = {0};
  int N, temp, mul = 0;

  scanf("%d", &N);

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
  }

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &B[i]);
  }

  for (int i = 0; i < N - 1; i++)
  {
    for (int j = 0; j < N - (1 + i); j++)
    {
      if (A[j] > A[j + 1])
      {
        temp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < N - 1; i++)
  {
    for (int j = 0; j < N - (1 + i); j++)
    {
      if (B[j] < B[j + 1])
      {
        temp = B[j];
        B[j] = B[j + 1];
        B[j + 1] = temp;
      }
    }
  }

  for (int k = 0; k < N; k++)
  {
    mul += (A[k] * B[k]);
  }

  printf("%d\n", mul);

  return 0;
}