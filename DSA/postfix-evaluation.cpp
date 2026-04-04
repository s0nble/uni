#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to apply operator
int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

// Function to evaluate postfix
int evaluatePostfix(string exp) {
    stack<int> s;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // If operand
        if (isdigit(c)) {
            s.push(c - '0'); // convert char to int
        }

        // If operator
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            int result = applyOp(val1, val2, c);
            s.push(result);
        }
    }

    return s.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix) << endl;

    return 0;
}