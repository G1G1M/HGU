#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct peoples
{
  int age;
  char name[201];
} people;

people p[100001];

int main()
{
  int num;
  scanf("%d", &num);
  for (int i = 0; i < num; i++)
  {
    scanf("%d %s", &p[i].age, p[i].name);
  }

  for (int i = 1; i <= 200; i++)
  {
    for (int j = 0; j < num; j++)
    {
      if (i == p[j].age)
      {
        printf("%d %s\n", p[j].age, p[j].name);
      }
    }
  }

  return 0;
}