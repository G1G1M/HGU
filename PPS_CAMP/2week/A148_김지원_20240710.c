#include <stdio.h>
#include <string.h>
#define SIZE 1000000

int main()
{
  int i, len, cnt = 0;
  char str[SIZE];

  scanf("%[^\n]s", str);
  len = strlen(str);

  if (len == 1)
  {
    if (str[i] == ' ')
    {
      printf("0\n");
      return 0;
    }
  }

  for (i = 1; i < len - 1; i++)
  {
    if (str[i] == ' ')
    {
      cnt++;
    }
  }
  printf("%d\n", cnt + 1);

  return 0;
}