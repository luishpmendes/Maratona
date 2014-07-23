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
                dfsVisit (W, v, color, l);
            }
        }
    }

    (*color)[u] = BLACK;
    (*l).push_front(u);
}

list<int> dfs (matrix W) {
    list <int> result;
    vector <int> color (W.size(), WHITE);

    for (int u = 0; u < (int) W.size(); u++) {
        if (color[u] == WHITE) {
            dfsVisit (W, u, &color, &result);
        }
    }
    return result;
}

vector <int> topologicalSort (matrix W) {
    list <int> l = dfs (W);
    return vector <int> (l.begin(), l.end());
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        matrix W (n, vector <double> (n, INFINITE));
        vector <int> pi;
        vector <int> d;
        vector <int> f;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            W[u][v] = 1;
        }
        vector <int> ts = topologicalSort (W);
        for (int i = 0; i < n; i++) {
            cout << ts[i] << endl;
        }
    }
    return 0;
}
