#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPair(char open, char close) {
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

char getExpectedClosing(char open) {
    if (open == '(') return ')';
    if (open == '{') return '}';
    if (open == '[') return ']';
    return '\0';
}

string checkParentheses(const string & expression) {
    stack < pair < char, int > > s; 

    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        
        if (c == '(' || c == '{' || c == '[') {
            s.push(std::make_pair(c, i)); 
        }
        
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                return "Error: An extra parenthesis '" + string(1, c) + "' is found. ";
            }
            char open = s.top().first;
            int openPos = s.top().second;
            s.pop();
            
            if (!isPair(open, c)) {
                char expectedClose = getExpectedClosing(open);
                return "Error: mis-matched parenthesis '" + string(1, expectedClose) + "' is expected ";
            }
        }
    }

    return "It’s a normal expression";
}

int main() {
    string test1 = "[ a + { b * (c - d) } ]";
    string test2 = "[ a + { b * (c - d} } ]";
    string test3 = "[ a + { b * (c - d) } ] )";

    cout << "Test 1: " << checkParentheses(test1) << endl;
    cout << "Test 2: " << checkParentheses(test2) << endl;
    cout << "Test 3: " << checkParentheses(test3) << endl;

    return 0;
}
