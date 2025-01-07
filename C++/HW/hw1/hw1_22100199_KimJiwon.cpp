#include <iostream>
using namespace std;

class weight // weight class 선언
{ 
  int kg;
  int gram;
  public:
      void set_weight(int n1, int n2); // kg, gram
      int get_weight(); // gram으로 환산한 값
};

weight add_weight(weight w1, weight w2); // add_weight 함수 선언
bool less_then(weight w1, weight w2); // less_then 함수 선언

int main()
{
  weight w1, w2, w3;
  w1.set_weight(3, 400);
  w2.set_weight(2, 700);
  w3 = add_weight(w1, w2);
  cout << w3.get_weight() << "grams\n";
  if(less_then(w1, w2))
  {
    cout << "yes.\n";
  }
  else
  {
    cout << "no.\n";
  }
  return 0;
}

void weight::set_weight(int n1, int n2) // member function 구현(1)
{
  kg = n1;
  gram = n2;
}

int weight::get_weight() // member function 구현(2)
{
  return(kg * 1000 + gram);
}

weight add_weight(weight w1, weight w2) // 일반 함수 구현(1)
{
  weight tmp;
  int n;
  n = w1.get_weight() + w2.get_weight();
  tmp.set_weight(n / 1000, n % 1000);
  return tmp;
}

bool less_then(weight w1, weight w2) // 일반 함수 구현(2)
{
  if(w1.get_weight() < w2.get_weight())
  {
    return true;
  }
  else
  {
    return false;
  }
}