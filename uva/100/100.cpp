#include <cstdio>

using namespace std;

int main () {
    int i, j;
    while (scanf(" %d", &i) == 1 && scanf(" %d", &j) == 1) {
        int tempi = i;
        int tempj = j;
        if (i > j) {
            int temp = i;
            i = j;
            j = temp;
        }
        int result = 0;
        for (int k = i; k <= j; k++) {
            int n = k;
            int aux = 1;
            while (n != 1) {
                if (n & 1) {
                    n = 3 * n + 1;
                } else {
                    n >>= 1;
                }
                aux++;
            }
            if (result < aux) {
                result = aux;
            }
        }
        printf("%d %d %d\n", tempi, tempj, result);
    }
    return 0;
}
