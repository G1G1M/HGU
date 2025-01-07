#include <iostream>
#include <string>
#define SIZE 100
#define EOS '$'
using namespace std;

class op_stack
{
  char s[SIZE];
  int top;

public:
  op_stack();
  void push(char x);
  char pop();
  bool empty();
  char top_element();
};

bool is_operand(char ch);
int get_precedence(char op);

int main()
{
  string input, output;
  op_stack stack1;

  cout << "Input an infix expression to convert : ";
  cin >> input;
  // input += EOS;
  stack1.push(EOS); // a*(b+c)-d/e = abc+*de/-

  for (int i = 0; i < input.size(); i++)
  {
    if (is_operand(input[i])) // operand는 output에 추가
    {
      output += input[i];
    }
    else if (input[i] == '(') // '('는 stack에 추가
    {
      stack1.push(input[i]);
    }
    else if (input[i] == ')') // ')'는 '('가 나올 때까지 pop -> '('가 나오면 삭제
    {
      while (stack1.top_element() != '(')
      {
        output += stack1.pop();
      }
      stack1.pop(); // '(' 삭제
    }
    else
    {
      while (get_precedence(stack1.top_element()) >= get_precedence(input[i])) // operator 우선순위 비교
      {
        output += stack1.pop();
      }
      stack1.push(input[i]);
    }
  }

  while (stack1.top_element() != EOS) // stack에 있는 문자들을 EOS전까지 pop
  {
    output += stack1.pop();
  }

  cout << output << "\n";

  return 0;
}

op_stack::op_stack()
{
  top = 0;
}

void op_stack::push(char x)
{
  s[top] = x;
  top++;
}

char op_stack::pop()
{
  top--;
  return (s[top]);
}

bool op_stack::empty()
{
  return (top == 0);
}

char op_stack::top_element()
{
  return (s[top - 1]);
}

bool is_operand(char ch)
{
  if ((ch == '(') || (ch == ')') || (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%') || (ch == '$'))
    return false;
  else
    return true;
}

int get_precedence(char op)
{
  if ((op == '$') || (op == '('))
    return (0);
  if ((op == '+') || (op == '-'))
    return (1);
  if ((op == '*') || (op == '/') || (op == '%'))
    return (2);
  return (-1);
}