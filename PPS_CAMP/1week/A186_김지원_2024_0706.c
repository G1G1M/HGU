#include <stdio.h>

int main()
{
  int g;
  scanf("%d", &g);

  if (g > 89 && g <= 100)
  {
    printf("A\n");
  }
  else if (g > 79 && g <= 89)
  {
    printf("B\n");
  }
  else if (g > 69 && g <= 79)
  {
    printf("C\n");
  }
  else if (g > 59 && g <= 69)
  {
    printf("D\n");
  }
  else
  {
    printf("F\n");
  }

  return 0;
}