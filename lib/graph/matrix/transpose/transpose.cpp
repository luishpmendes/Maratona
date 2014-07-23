#include <iostream>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

using namespace std;

typedef vector < vector <double> > matrix;

matrix transpose (matrix W) {
    matrix result (W.size(), vector <double> (W.size(), INFINITE));

    for (int u = 0; u < (int) W.size(); u++) {
        for (int v = 0; v < (int) W.size(); v++) {
            result[v][u] = W[u][v];
        }
    }

    return result;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        matrix W (n, vector<double>(n, INFINITE));
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            W[u][v] = 1;
        }
        matrix T = transpose(W);
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (T[u][v] < INFINITE) {
                    cout << u << " " << v << endl;
                }
            }
        }
    }
    return 0;
}
