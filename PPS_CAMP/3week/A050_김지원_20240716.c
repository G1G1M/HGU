#include <stdio.h>
#include <string.h>

int main()
{
  char c[1001] = {}; // 카이사르 단어: A -> D, B -> E, C -> F 3개씩 건너뛰어 적음
  char a[1001] = {}; // 알파벳 단어

  scanf("%s", c);
  int len = strlen(c);

  for (int i = 0; i < len; i++)
  {
    if (c[i] == 'A')
    {
      a[i] = 'X';
    }

    else if (c[i] == 'B')
    {
      a[i] = 'Y';
    }

    else if (c[i] == 'C')
    {
      a[i] = 'Z';
    }

    else
    {
      a[i] = c[i] - 3; // 카이사르 단어에서 원래 알파벳으로 출력
    }
  }
  printf("%s\n", a);

  return 0;
}