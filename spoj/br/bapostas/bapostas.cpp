#include <cstdio>

using namespace std;

int main () {
    int n;
    while (scanf(" %d", &n) == 1 && n > 0) {
        int maiorStreak = 0, streakAtual = 0;
        for (int i = 0; i < n; i++) {
            int aposta;
            scanf(" %d", &aposta);
            streakAtual += aposta;
            if (streakAtual < 0) {
                streakAtual = 0;
            }
            if (streakAtual > maiorStreak) {
                maiorStreak = streakAtual;
            }
        }
        if (maiorStreak > 0) {
            printf("The maximum winning streak is %d.\n", maiorStreak);
        } else {
            printf("Losing streak.\n");
        }
    } 
    return 0;
}
