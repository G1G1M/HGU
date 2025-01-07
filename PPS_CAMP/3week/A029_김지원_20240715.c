#include <stdio.h>

long long int door;
int open;

int main()
{
  scanf("%lld %d", &door, &open); // 문 갯수와 여는 방식 입력받은

  if (door > 5)
  { // 6이상이면 탈출 못함
    printf("Love is open door\n");
  }
  else
  { // 5이하 탈출 가능 (0과 1번갈아 가면서 출력)
    for (int i = 1; i < door; i++)
    {
      open = 1 - open; // 1-open하면 0 or 1만 출력됨
      printf("%d\n", open);
    }
  }
  return 0;
}