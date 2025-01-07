#include <stdio.h>

int main()
{
  int C, N;        // test case, student num
  scanf("%d", &C); // test case 횟수 입력

  for (int i = 0; i < C; i++)
  {
    scanf("%d", &N);

    int S[1000], sum = 0; // 학생들 점수 모아둘 배열, 합
    double avg = 0.0;     // 평균

    for (int j = 0; j < N; j++)
    {
      scanf("%d", &S[j]);
      sum += S[j]; // 총합
    }

    avg = (double)sum / N; // 총평균
    int count = 0;         // 평균 넘는 인원 수
    for (int k = 0; k < N; k++)
    {
      if (avg < S[k])
      {
        count++;
      }
    }
    printf("%.3lf%%\n", (double)count * 100 / N); // %: %%로 출력
  }

  return 0;
}