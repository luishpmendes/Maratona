#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char str[100000];

int main() {
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        bool valid = true;
        stack <char> pilha;
        scanf(" %s", str);
        int len = (int) strlen(str);
        int s = 0;
        for (int j = 0; j < len; j++) {
            if (s > len - j) {
                valid = false;
                break;
            }
            if (str[j] == '{' || str[j] == '[' || str[j] == '(') {
                pilha.push(str[j]);
                s++;
            } else {
                if (s == 0 || (str[j] == ')' && pilha.top() != '(') || (str[j] == ']' && pilha.top() != '[') || (str[j] == '}' && pilha.top() != '{')) {
                    valid = false;
                    break;
                } else {
                    pilha.pop();
                    s--;
                }
            }
        }
        if (valid && s == 0) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}
