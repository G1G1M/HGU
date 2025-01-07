#include <stdio.h>
#include <math.h>

int main()
{
  int t, k;
  scanf("%d", &t);

  for (int i = 0; i < t; i++)
  {
    scanf("%d", &k);

    double n = pow(2, k) - 1;
    printf("%.0lf\n", n);
  }

  return 0;
}