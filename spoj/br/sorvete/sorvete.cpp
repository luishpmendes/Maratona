#include <cstdio>
#include <vector>

using namespace std;

int main () {
    int p, s, n = 0;
    while (scanf(" %d", &p) == 1 && scanf(" %d", &s) == 1 && (p > 0 || s > 0)) {
        vector <bool> praia (p, false);
        for (int i = 0; i < s; i++) {
            int u, v;
            scanf(" %d", &u);
            scanf(" %d", &v);
            for (int j = u; j < v; j++) {
                praia[j] = true;
            }
        }
        printf("Teste %d\n", ++n);
        for (int i = 0; i < p; i++) {
            if (praia[i]) {
                int j = i+1;
                while (praia[j] && j < p) {
                    j++;
                }
                printf("%d %d\n", i, j);
                i = j;
            }
        }
        printf("\n");
    }
    return 0;
}
