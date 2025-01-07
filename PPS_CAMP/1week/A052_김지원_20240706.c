#include <stdio.h>
#include <string.h>

int main()
{

  int test, point, sum;
  char ox[80];

  scanf("%d", &test);

  for (int i = 0; i < test; i++)
  {
    sum = 0;
    point = 1;
    scanf("%s", ox);
    for (int j = 0; j < strlen(ox); j++)
    { // 문자열 길이 만큼 반복
      if (ox[j] == 'O')
      {
        sum += point;
        point++; // 다음 점수 1점 증가
      }
      if (ox[j] == 'X')
      {
        point = 1; // 더해도 0이기 때문에 점수만 1로 초기화
      }
    }
    printf("%d\n", sum);
  }
}
