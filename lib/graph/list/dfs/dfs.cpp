#include <list>
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

void dfsVisit(vector< list < pair <int, double> > > adj, int u, int * time, vector<int> * color, vector<int> * pi, vector<int> * d, vector<int> * f) {
    (*time)++;
    (*d)[u] = (*time);

    (*color)[u] = GRAY;

    for (list< pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
        int v = (*it).first;
        if ((*color)[v] == WHITE) {
            (*pi)[v] = u;
            dfsVisit(adj, v, time, color, pi, d, f);
        }
    }

    (*color)[u] = BLACK;
    (*time)++;
    (*f)[u] = (*time);
}

void dfs(vector< list < pair <int, double> > > adj, vector<int> * pi, vector<int> * d, vector<int> * f) {
    vector<int> color (adj.size(), WHITE);
    int time;

    (*pi) = vector<int> (adj.size(), NIL);
    (*d) = vector<int> (adj.size(), INFINITE);
    (*f) = vector<int> (adj.size(), INFINITE);

    for (int u = 0; u < (int) adj.size(); u++) {
        color[u] = WHITE;
        (*pi)[u] = NIL;
        (*d)[u] = INFINITE;
        (*f)[u] = INFINITE;
    }

    time = 0;

    for (int u = 0; u < (int) adj.size(); u++) {
        if (color[u] == WHITE) {
            dfsVisit(adj, u, &time, &color, pi, d, f);
        }
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        vector< list < pair <int, double> > > adj (n);
        vector<int> pi;
        vector<int> d;
        vector<int> f;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(make_pair(v, 1));
        }
        dfs(adj, &pi, &d, &f);
        for (int i = 0; i < n; i++) {
            cout << pi[i] << " " << d[i] << " " << f[i] << endl;
        }
    }
    return 0;
}
