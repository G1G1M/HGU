#include <stdio.h>
#include <string.h>

int main()
{
  char s[100];
  int a[26], len, idx;

  for (int i = 0; i < 26; i++)
  {
    a[i] = -1;
  }

  scanf("%s", s);

  len = strlen(s);
  for (int i = 0; i < len; i++)
  {
    idx = s[i] - 'a';
    if (a[idx] == -1)
    {
      a[idx] = i;
    }
    else
    {
      continue;
    }
  }

  for (int i = 0; i < 26; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}