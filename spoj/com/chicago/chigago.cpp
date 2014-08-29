#include <cstdio>
#include <vector>

using namespace std;

typedef vector < vector <double> > matrix;

void bellmanFord (matrix W, int s, vector <double> * d) {
    (*d) = vector <double> (W.size(), 0);
    (*d)[s] = 1;
    for (int i = 1; i < (int) W.size(); i++) {
        for (int u = 0; u < (int) W.size(); u++) {
            for (int v = 0; v < (int) W.size(); v++) {
                if (u != v && W[u][v] > 0) {
                    if ((*d)[v] < (*d)[u] * W[u][v]) {
                        (*d)[v] = (*d)[u] * W[u][v];
                    }
                }
            }
        }
    }
}

int main () {
    int n, m;
    while (scanf (" %d", &n) == 1 && scanf (" %d", &m) == 1) {
        double result;
        matrix W (n, vector <double> (n, 0));
        vector <double> d;
        for (int i = 0; i < m; i++) {
            int a, b, p;
            double w;
            scanf (" %d", &a);
            scanf (" %d", &b);
            scanf (" %d", &p);
            a--;
            b--;
            w = ((double) p)/100;
            W[a][b] = w;
            W[b][a] = w;
        }
        bellmanFord (W, 0, &d);
        result = d[n-1]*100;
        printf("%.6lf percent\n", result);
    }
    return 0;
}
