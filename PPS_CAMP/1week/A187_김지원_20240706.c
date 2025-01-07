#include <stdio.h>

int main()
{
  int Y;

  scanf("%d", &Y);
  if (Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0)
  {
    printf("1\n");
  }
  else
  {
    printf("0\n");
  }

  return 0;
}
