#include <stdio.h>

int main()
{
  int n, i, cost[20];
  int Y, M = 0;
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    scanf("%d", &cost[i]);
    Y += cost[i] / 30 + 1;
    M += cost[i] / 60 + 1;
  }

  Y *= 10;
  M *= 15;

  if (Y == M)
    printf("Y M %d\n", Y);
  else if (Y > M)
    printf("M %d\n", M);
  else
    printf("Y %d\n", Y);

  return 0;
}
