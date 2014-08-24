#include <iostream>
#include <list>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

#ifndef WHITE
#define WHITE 0
#endif

#ifndef GRAY
#define GRAY  1
#endif

#ifndef BLACK
#define BLACK 2
#endif

using namespace std;

typedef vector < vector <double> > matrix;

void dfsVisit (matrix W, int u, vector <int> * color, list <int> * l) {
    (*color)[u] = GRAY;
    for (int v = 0; v < (int) W.size(); v++) {
        if (u != v && W[u][v] < INFINITE) {
            if ((*color)[v] == WHITE) {
                dfsVisit(W, v, color, l);
            }
        }
    }
    (*color)[u] = BLACK;
    (*l).push_front(u);
}

list <int> dfs (matrix W) {
    list <int> result;
    vector <int> color (W.size(), WHITE);
    for (int u = 0; u < (int) W.size(); u++) {
        if (color[u] == WHITE) {
            dfsVisit(W, u, &color, &result);
        }
    }
    return result;
}

vector <int> topologicalSort (matrix W) {
    list <int> l = dfs (W);
    return vector <int> (l.begin(), l.end());
}

matrix transpose (matrix W) {
    matrix result (W.size(), vector <double> (W.size(), INFINITE));
    for (int u = 0; u < (int) W.size(); u++) {
        for (int v = 0; v < (int) W.size(); v++) {
            result[v][u] = W[u][v];
        }
    }
    return result;
}

void dfsTVisit (matrix W, int u, vector <int> * color, vector <int> * scc, int ncc) {
    (*color)[u] = GRAY;
    for (int v = 0; v < (int) W.size(); v++) {
        if (u != v && W[u][v] < INFINITE) {
            if ((*color)[v] == WHITE) {
                dfsTVisit(W, v, color, scc, ncc);
            }
        }
    }
    (*color)[u] = BLACK;
    (*scc)[u] = ncc;
}

int dfsT (matrix W, vector <int> ts, vector <int> * scc) {
    int result = 0;
    *scc = vector <int> (W.size(), -1);
    vector <int> color (W.size(), WHITE);
    for (int i = 0; i < (int) ts.size(); i++) {
        int u = ts[i];
        if (color[u] == WHITE) {
            dfsTVisit (W, u, &color, scc, result++);
        }
    }
    return result;
}

int kosaraju (matrix W, vector <int> * scc) {
    vector <int> ts = topologicalSort (W);
    matrix T = transpose (W);
    return dfsT (T, ts, scc);
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        matrix W (n, vector <double> (n, INFINITE));
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            W[u][v] = 1;
        }
        vector <int> scc;
        int ncc = kosaraju (W, &scc);
        cout << ncc << endl;
        for (int u = 0; u < n; u++) {
            cout << scc[u] << " ";
        }
        cout << endl;
    }
    return 0;
}
