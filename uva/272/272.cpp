#include <cstdio>

using namespace std;

int main () {
    char c = 0;
    bool flag = false;
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            if (!flag) {
                flag = !flag;
                putchar('`');
                putchar('`');
            } else {
                flag = !flag;
                putchar('\'');
                putchar('\'');
            }
        } else {
            putchar(c);
        }
    }
    return 0;
}
