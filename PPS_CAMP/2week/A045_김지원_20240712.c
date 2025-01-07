#include <stdio.h>
#include <string.h>

int main()
{
  int i, j, max, result = 0, len;
  char arr[1000000];
  int cnt[26] = {0};
  int select = 0;

  scanf("%s", arr);
  len = strlen(arr);

  for (i = 'a'; i <= 'z'; i++)
  {
    for (j = 0; j < len; j++)
    {
      if (i == arr[j])
        cnt[i - 'a']++;
    }
  }

  for (i = 'A'; i <= 'Z'; i++)
  {
    for (j = 0; j < len; j++)
    {
      if (i == arr[j])
        cnt[i - 'A']++;
    }
  }

  max = cnt[0];
  for (i = 1; i < 26; i++) // 가장 많이 나온 단어 출력
  {
    if (max < cnt[i])
    {
      max = cnt[i];
      select = i;
    }
  }

  for (i = 0; i < 26; i++) // 많이 나온 단어가 여러개일 경우
  {
    if (max == cnt[i])
      result++;
  }

  if (result > 1)
    printf("?\n");
  else
    printf("%c\n", select + 'A');

  return 0;
}