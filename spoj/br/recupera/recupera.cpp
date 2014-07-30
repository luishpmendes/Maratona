#include <cstdio>
 
int main (void) {
    int n, contaInstancia = 0;
    while (scanf(" %d", &n) == 1) {
        bool achou = false;
        int soma = 0, k;
        contaInstancia++;
        for (int i = 0; i < n; i++) {
            int a;
            scanf(" %d", &a);
            if (!achou && a == soma) {
                k = a;
                achou = true;
            }
            soma += a;
        }
        if (!achou) {
            printf("Instancia %d\nnao achei\n\n", contaInstancia);
        } else {
            printf("Instancia %d\n%d\n\n", contaInstancia, k);
        }
    }
    return 0;
}
