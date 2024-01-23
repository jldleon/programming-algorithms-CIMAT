/* Tarea 2. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 2. Cal­cu­la­do­ra de Ex­pre­sio­nes:
- Di­se­ña una cal­cu­la­do­ra que pue­da eva­luar ex­pre­sio­nes arit­mé­ti­cas sim­ples
in­gre­sa­das por el usua­rio, como "5 + 3 (8 - 3)".
************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <stack>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '(')
        return 0;
    return -1;
}

int applyOp(int a, int b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0) {
            throw invalid_argument("División por cero indefinida");
        }
        return a / b;
    }
    return 0;
}

int evaluateExpression(const string &tokens) {
    stack<int> values;
    stack<char> ops;

    for (size_t i = 0; i < tokens.length(); i++) {
        if (tokens[i] == ' ')
            continue;
        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        } else if (isdigit(tokens[i])) {
            int val = 0;
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = val * 10 + (tokens[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        } else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if (!ops.empty())
                ops.pop();
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }
    while (!ops.empty()) {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op));
    }
    return values.top();
}

string insertMultiplication(string expression) {
    string result;
    for (size_t i = 0; i < expression.length(); i++) {
        if (i > 0 && (isdigit(expression[i]) || expression[i] == '(') &&
            (expression[i - 1] == ')' || isdigit(expression[i - 1]))) {
            result += '*';
        }
        result += expression[i];
    }
    return result;
}

int main() {
    string expression;
    cout << "Ingrese una expresión aritmética: ";
    getline(cin, expression);

    string expressionWithMultiplication = insertMultiplication(expression);

    try {
        int result = evaluateExpression(expressionWithMultiplication);
        cout << "El resultado es: " << result << endl;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

