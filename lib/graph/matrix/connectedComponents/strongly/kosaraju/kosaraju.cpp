#include <iostream>
#include <list>
#include <set>
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

set <int> dfsTVisit (matrix W, int u, vector <int> * color) {
    set <int> result;
    (*color)[u] = GRAY;
    for (int v = 0; v < (int) W.size(); v++) {
        if (u != v && W[u][v] < INFINITE) {
            if ((*color)[v] == WHITE) {
                set <int> aux = dfsTVisit(W, v, color);
                result.insert(aux.begin(), aux.end());
            }
        }
    }
    (*color)[u] = BLACK;
    result.insert(u);
    return result;
}

set < set <int> > dfsT (matrix W, vector <int> ts) {
    set < set <int> > result;
    vector <int> color (W.size(), WHITE);
    for (int i = 0; i < (int) ts.size(); i++) {
        int u = ts[i];
        if (color[u] == WHITE) {
            result.insert(dfsTVisit (W, u, &color));
        }
    }
    return result;
}

set < set <int> > kosaraju (matrix W) {
    vector <int> ts = topologicalSort (W);
    matrix T = transpose (W);
    return dfsT (T, ts);
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
        set < set <int> > scc = kosaraju (W);
        for (set < set <int> >::iterator it = scc.begin(); it != scc.end(); ++it) {
            for (set <int>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
                cout << *it2 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
