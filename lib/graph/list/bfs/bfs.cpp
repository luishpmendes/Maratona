#include <list>
#include <iostream>
#include <queue>
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

void bfs (vector < list < pair <int, double> > > adj, int s, vector<int> * pi, vector<int> * d) {
    vector <int> color (adj.size(), WHITE);
    queue <int> Q;

    (*pi) = vector<int> (adj.size(), NIL);
    (*d) = vector<int> (adj.size(), INFINITE);

    for (int u = 0; u < (int) adj.size(); u++) {
        color[u] = WHITE;
        (*d)[u] = INFINITE;
        (*pi)[u] = NIL;
    }

    color[s] = GRAY;
    (*d)[s] = 0;
    (*pi)[s] = NIL;

    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (list < pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = (*it).first;
            if (color[v] == WHITE) {
                color[v] = GRAY;
                (*d)[v] = (*d)[u]+1;
                (*pi)[v] = u;
                Q.push(v);
            }
        }
        color[u] = BLACK;
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        vector < list < pair <int, double> > > adj (n);
        int s;
        vector <int> pi;
        vector <int> d;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(make_pair(v, 1));
            adj[v].push_back(make_pair(u, 1));
        }
        cin >> s;
        bfs (adj, s, &pi, &d);
        for (int i = 0; i < n; i++) {
            cout << pi[i] << " " << d[i] << endl;
        }
    }
    return 0;
}
