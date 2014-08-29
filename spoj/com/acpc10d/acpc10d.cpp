#include <algorithm>
#include <cstdio>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

using namespace std;

typedef vector < vector <int> > matrix;

int main () {
    int n, k = 0;
    while (scanf(" %d", &n) == 1 && n > 0) {
        k++;
        matrix c (n, vector <int> (3));
        for (int i = 0; i < n; i++) {
            for (long long int j = 0; j < 3; j++) {
                scanf(" %d", &c[i][j]);
            }
        }
        matrix d (n, vector <int> (3));
        d[0][0] = INFINITE;
        d[0][1] = c[0][1];
        d[0][2] = c[0][1] + c[0][2]; 
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                int v0 = INFINITE;
                int v1 = INFINITE;
                int v2 = INFINITE;
                int v3 = INFINITE;
                if (j > 0) {
                    v0 = d[i][j-1] + c[i][j];
                    v1 = d[i-1][j-1] + c[i][j];
                }
                v2 = d[i-1][j] + c[i][j];
                if (j < 2) {
                    v3 = d[i-1][j+1] + c[i][j];
                }
                d[i][j] = min(min(v0, v1), min(v2, v3));
            }
        }
        printf("%d. %d\n", k, d[n-1][1]);
    }
    return 0;
}
