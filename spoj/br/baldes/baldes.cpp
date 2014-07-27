#include <cstdio>

using namespace std;

int main () {
    int n;
    while (scanf(" %d", &n) == 1 && n > 0) {
        bool vencedor = false;
        int v[100000];
        for (int i = 0; i < n; i++) {
            int aux;
            scanf(" %d", &aux);
            v[i] = aux;
        }
        for (int i = 0; i < n; i++) {
            while (v[i] != i+1) {
                int aux = v[v[i]-1];
                v[v[i]-1] = v[i];
                v[i] = aux;
                vencedor = !vencedor;
            }
        }
        if (vencedor) {
            printf("Marcelo\n");
        } else {
            printf("Carlos\n");
        }
    }
    return 0;
}
