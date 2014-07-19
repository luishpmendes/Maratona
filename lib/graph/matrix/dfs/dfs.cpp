#include <iostream>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

#ifndef NIL
#define NIL - (15 << 25)
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

typedef vector< vector<double> > matrix;

void dfsVisit(matrix W, int u, int * time, vector<int> * color, vector<int> * pi, vector<int> * d, vector<int> * f) {
    (*time)++;
    (*d)[u] = (*time);

    (*color)[u] = GRAY;

    for (int v = 0; v < (int) W.size(); v++) {
        if (u != v && W[u][v] < INFINITE) {
            if ((*color)[v] == WHITE) {
                (*pi)[v] = u;
                dfsVisit(W, v, time, color, pi, d, f);
            }
        }
    }

    (*color)[u] = BLACK;
    (*time)++;
    (*f)[u] = (*time);
}

void dfs(matrix W, vector<int> * pi, vector<int> * d, vector<int> * f) {
    vector<int> color (W.size(), WHITE);
    int time;

    (*pi) = vector<int> (W.size(), NIL);
    (*d) = vector<int> (W.size(), INFINITE);
    (*f) = vector<int> (W.size(), INFINITE);

    for (int u = 0; u < (int) W.size(); u++) {
        color[u] = WHITE;
        (*pi)[u] = NIL;
        (*d)[u] = INFINITE;
        (*f)[u] = INFINITE;
    }

    time = 0;

    for (int u = 0; u < (int) W.size(); u++) {
        if (color[u] == WHITE) {
            dfsVisit(W, u, &time, &color, pi, d, f);
        }
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        matrix W (n, vector<double>(n, INFINITE));
        vector<int> pi;
        vector<int> d;
        vector<int> f;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            W[u][v] = 1;
        }
        dfs(W, &pi, &d, &f);
        for (int i = 0; i < n; i++) {
            cout << pi[i] << " " << d[i] << " " << f[i] << endl;
        }
    }
    return 0;
}
