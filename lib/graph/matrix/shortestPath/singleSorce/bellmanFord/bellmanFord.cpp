#include <iostream>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

#ifndef NIL
#define NIL - (15 << 25)
#endif

using namespace std;

typedef vector < vector <double> > matrix;

bool bellmanFord (matrix W, int s, vector <int> * d, vector <int> * pi) {
    (*d) = vector <int> (W.size(), INFINITE);
    (*pi) = vector <int> (W.size(), NIL);

    for (int v = 0; v < (int) W.size(); v++) {
        (*d)[v] = INFINITE;
        (*pi)[v] = NIL;
    }
    (*d)[s] = 0;

    for (int i = 1; i < (int) W.size(); i++) {
        for (int u = 0; u < (int) W.size(); u++) {
            for (int v = 0; v < (int) W.size(); v++) {
                if (u != v && W[u][v] < INFINITE) {
                    if ((*d)[v] > (*d)[u] + W[u][v]) {
                        (*d)[v] = (*d)[u] + W[u][v];
                        (*pi)[v] = u;
                    }
                }
            }
        }
    }
    for (int u = 0; u < (int) W.size(); u++) {
        for (int v = 0; v < (int) W.size(); v++) {
            if (u != v && W[u][v] < INFINITE) {
                if ((*d)[v] > (*d)[u] + W[u][v]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        matrix W (n, vector <double> (n, INFINITE));
        int s;
        vector <int> d;
        vector <int> pi;
        for (int i = 0; i < m; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            W[u][v] = w;
        }
        cin >> s;
        if (bellmanFord (W, s, &d, &pi)) {
            for (int i = 0; i < n; i++) {
                cout << d[i] << " " << pi[i] << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
