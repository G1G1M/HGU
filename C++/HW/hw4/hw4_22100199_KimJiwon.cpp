#include <iostream>
#include <string>
using namespace std;

#define EOS '$'

class Node {
public:
    char data;
    Node* next;
};

class op_stack {
  Node* top;

  public:
  op_stack();
  void push(char x);
  char pop();
  bool empty();
  char top_element();
};

bool is_operand(char ch);
int get_precedence(char op);

int main(){
  string input, output;
  op_stack stack1;

  cout << "Input an infix expression to convert: ";
  cin >> input;

  // input += EOS;
  stack1.push(EOS);

  for (int i = 0; i < input.size(); i++) {
    if (is_operand(input[i])) {
      output += input[i];
    } else if (input[i] == '(') {
      stack1.push(input[i]);
    } else if (input[i] == ')') {
      while (stack1.top_element() != '(') {
        output += stack1.pop();
      }
      stack1.pop();  
    } else {  
      while (get_precedence(stack1.top_element()) >= get_precedence(input[i])) {
        output += stack1.pop();
      }
      stack1.push(input[i]);
    }
  }

  while (stack1.top_element() != EOS) {
    output += stack1.pop();
  }

  cout << "Postfix expression: " << output << "\n";

  return 0;
}

op_stack::op_stack() {
  top = nullptr;
}

void op_stack::push(char x) {
  Node* newNode = new Node();
  newNode->data = x;
  newNode->next = top;
  top = newNode;
}

char op_stack::pop() {
  if (empty()) {
    cout << "Stack Underflow\n";
    return EOS;
  }
  Node* temp = top;
  char popped = top->data;
  top = top->next;
  delete temp;
  return popped;
}

bool op_stack::empty() {
  return top == nullptr;
}

char op_stack::top_element() {
  if (empty()) {
    cout << "Stack is empty\n";
    return EOS;
  }
  return top->data;
}

bool is_operand(char ch) {
  return !((ch == '(') || (ch == ')') || (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%') || (ch == '$'));
}

int get_precedence(char op) {
  if (op == '$' || op == '(') return 0;
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/' || op == '%') return 2;
  return -1;
}
