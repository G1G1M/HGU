#include <stdio.h>
#include <string.h>

int main()
{
  char inArr[100] = {0};
  int i;
  scanf("%s", inArr);

  for (i = 0; i < strlen(inArr); i++)
  {
    printf("%c", inArr[i]);
    if (i % 10 == 9) // 10개씩 끊기
      printf("\n");
  }
  printf("\n");
}
