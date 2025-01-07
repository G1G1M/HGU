#include <stdio.h>

int main()
{
  int price, result, count = 0;
  scanf("%d", &price);
  result = 1000 - price; // 거스름돈
  while (1)
  {
    if (result == 0)
    {
      break;
    }

    if (result >= 500)
    {
      result -= 500;
      count++;
      continue;
    }

    if (result >= 100)
    {
      result -= 100;
      count++;
      continue;
    }

    if (result >= 50)
    {
      result -= 50;
      count++;
      continue;
    }

    if (result >= 10)
    {
      result -= 10;
      count++;
      continue;
    }

    if (result >= 5)
    {
      result -= 5;
      count++;
      continue;
    }

    if (result >= 1)
    {
      result -= 1;
      count++;
      continue;
    }
  }
  printf("%d\n", count);
}