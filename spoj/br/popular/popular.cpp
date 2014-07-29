#include <cstdio>
#include <vector>

using namespace std;

int main (void) {
    int n;
    while (scanf("%d", &n) == 1 && n > 0) {
        vector <int> soma (n, 0);
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int aux = 0;
                scanf("%d", &aux);
                soma[j] += aux;
                if (max < soma[j]) {
                    max = soma[j];
                }
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
