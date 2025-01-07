#include <stdio.h>

int main()
{
  int max = 0, idx, num[9];

  for (int i = 0; i < 9; i++)
  {
    scanf("%d", &num[i]);
    if (max < num[i])
    {
      max = num[i];
      idx = i + 1;
    }
  }
  printf("%d\n%d\n", max, idx);

  return 0;
}