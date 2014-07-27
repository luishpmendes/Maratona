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

void dijkstra (matrix W, int s, vector <int> * d, vector <int> * pi) {
    (*d) = vector <int> (W.size(), INFINITE);
    (*pi) = vector <int> (W.size(), NIL);
    vector <bool> Q (W.size(), true);

    for (int v = 0; v < (int) W.size(); v++) {
        (*d)[v] = INFINITE;
        (*pi)[v] = NIL;
        Q[v] = true;
    }
    (*d)[s] = 0;

    for (int i = 0; i < (int) W.size(); i++) {
        int u = -1;
        for (int j = 0; j < (int) W.size(); j++) {
            if (Q[j] && (u < 0 || (*d)[u] > (*d)[j])) {
                u = j;
            }
        }
        Q[u] = false;
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
        dijkstra (W, s, &d, &pi);
        for (int i = 0; i < n; i++) {
            cout << d[i] << " " << pi[i] << endl;
        }
    }
    return 0;
}
