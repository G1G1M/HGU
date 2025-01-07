#include <stdio.h>
int main()
{
  int N;
  char name[40];
  int arr[27] = {0};
  int i;
  int flag = 0;
  scanf("%d", &N);

  for (i = 0; i < N; i++)
  {
    scanf("%s", name);
    arr[name[0] - 'a']++;
  }

  for (i = 0; i < 26; i++)
  {
    if (arr[i] >= 5)
    {
      printf("%c", i + 'a');
      flag = 1;
    }
  }

  if (flag == 0)
  {
    printf("PREDAJA\n");
  }

  return 0;
}