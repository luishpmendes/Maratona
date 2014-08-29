#include <iostream>
#include <string>
#include <stack>

using namespace std;

int precedenceInput (char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '^') {
        return 3;
    }
    return 9;
}
 
int precedenceStack (char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '^') {
        return 3;
    }
    return -1;
}

int main () {
    int t;
    for (cin >> t; t > 0; t--) {
        string expr;
        stack <char> pilha;
        cin >> expr;
        for (int i = 0; i < (int) expr.length(); i++) {
            if (expr[i] >= 'a' && expr[i] <= 'z') { /* operando */
                cout << expr[i];
            } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^' || expr[i] == '(') { /* operador */
                while (!pilha.empty()) {
                    if (precedenceStack (pilha.top()) >= precedenceInput (expr[i])) {
                        cout << pilha.top();
                        pilha.pop();
                    } else {
                        break;
                    }
                }
                pilha.push(expr[i]);
            } else { /* ')' */
                while (!pilha.empty()) {
                    if (pilha.top() == '(') {
                        pilha.pop();
                        break;
                    } else {
                        cout << pilha.top();
                        pilha.pop();
                    }
                }
            }
        }
        while (!pilha.empty()) {
            if (pilha.top() != '(') {
                cout << pilha.top();
            }
            pilha.pop();
        }
        cout << endl;
    }
    return 0;
}
