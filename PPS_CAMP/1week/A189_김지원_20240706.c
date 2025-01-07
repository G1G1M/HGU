#include <stdio.h>

int main()
{
  int h, m, eh, em; // 일어나는 시간, 45분전 시간
  scanf("%d %d", &h, &m);
  eh = h;
  em = m - 45;

  if (em < 0)
  {
    em += 60;
    eh--;
  }

  if (eh < 0)
  {
    eh = 23;
  }

  printf("%d %d\n", eh, em);

  return 0;
}