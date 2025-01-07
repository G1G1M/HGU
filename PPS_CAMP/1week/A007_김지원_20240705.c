#include <stdio.h>

int main()
{
  int mel[8] = {0};
  int cnt = 0; // mixed

  for (int i = 0; i < 8; i++)
  {
    scanf("%d", &mel[i]);
  }

  if (mel[0] == 1)
  {
    for (int i = 1; i < 8; i++)
    {
      if (mel[i] == i + 1)
      {
        cnt = 1; // ascending
      }
      else
      {
        cnt = 0; // mixed
        break;
      }
    }
  }

  else if (mel[0] == 8)
  {
    for (int i = 1; i < 8; i++)
    {
      if (mel[i] == 8 - i)
      {
        cnt = 2; // descending
      }
      else
      {
        cnt = 0; // mixed
        break;
      }
    }
  }

  if (cnt == 0)
  {
    printf("mixed\n");
  }
  else if (cnt == 1)
  {
    printf("ascending\n");
  }
  else if (cnt == 2)
  {
    printf("descending\n");
  }

  return 0;
}