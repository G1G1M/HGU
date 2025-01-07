#include <stdio.h>

int main()
{
  int n, s;
  int temp = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &s);
    temp += s;
  }

  printf("%d\n", temp - (n - 1));
  return 0;
}