#include <cstdio>

using namespace std;
 
int main () {
    int n, p;
    while (scanf(" %d", &n) == 1 && scanf(" %d", &p) == 1 && (n > 0 || p > 0)) {
        int vetor[1000];
        int pilha, altura;
        for (int i = 0; i < p; i++) {
            scanf(" %d", &vetor[i]);
            for (int j = 0; j < vetor[i]; j++) {
                int caixa;
                scanf (" %d", &caixa);
                if (caixa == 1) {
                    pilha = i;
                    altura = j+1;
                }
            }
        }
        int esquerda = vetor[pilha] - altura;
        for (int i = pilha-1; i >= 0 && vetor[i] >= altura; i--) {
            esquerda += (vetor[i]-altura+1);
        }
        int direita = vetor[pilha] - altura;
        for (int i = pilha+1; i < p && vetor[i] >= altura; i++) {
            direita += (vetor[i]-altura+1);
        }
        printf ("%d\n", esquerda < direita ? esquerda : direita);
    }
    return 0;
}
