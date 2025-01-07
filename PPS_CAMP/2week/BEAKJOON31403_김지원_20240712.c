#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int A, B, C;
  char buf1[100];
  char buf2[100];

  scanf("%d %d %d", &A, &B, &C);

  sprintf(buf1, "%d", A); // int A를 string으로 변환
  sprintf(buf2, "%d", B); // int B를 string으로 변환
  strcat(buf1, buf2);     // string A, B 합치기
  int n = atoi(buf1);     // 합친 string을 int로 변환

  printf("%d\n", A + B - C); // int A, B, C 계산
  printf("%d\n", n - C);     // int(A + B) - int C 계산

  return 0;
}