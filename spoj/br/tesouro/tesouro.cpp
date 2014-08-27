#include <cstdio>

using namespace std;

#define MAXN 10100
 
int v[MAXN];
bool pd[MAXN];

int main() {
    int x, y, n;
    int t = 0;
    while (scanf(" %d", &x) == 1 && scanf(" %d", &y) == 1 && scanf(" %d", &n) == 1 && !(x == 0 && y == 0 && n == 0)) {
        int s = 0;              
        for (int i = 0 ; i < n ; i++) {
            scanf(" %d", &v[i]);
            s += v[i];
        }
        bool possivel = false;
        int d = (s + y - x);
        if ((d & 1) == 0) {
            d /= 2;
            for (int i = 0 ; i <= d ; i++) {
                pd[i] = false;
            }
            pd[0] = 1;
            for (int i = 0; !possivel && i < n ; i++) {
                for (int j = d - v[i]; j >= 0 ; j--) {
                    if (pd[j]) {
                        pd[j + v[i]] = true;
                    }
                }
                possivel = pd[d];                       
            }
        }
        printf("Teste %d\n", ++t);
        if (possivel) {
            printf("S\n");
        } else {
            printf("N\n");
        }
        printf("\n");
    }
    return 0;
}
