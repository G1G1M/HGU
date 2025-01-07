#include <stdio.h>

int main()
{
  int a, b, max = 0, c = 0;
  scanf("%d", &a);
  for (int i = 0; i < a; i++)
  {
    scanf("%d", &b);
    max < b ? max = b : 1;
    c += b;
  }
  c -= max;
  printf("%d\n", c);
}