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

void dfsVisit (vector < list < pair <int, double> > > adj, int u, vector <int> * color, list <int> * l) {
    (*color)[u] = GRAY;

    for (list < pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
        int v = (*it).first;
        if ((*color)[v] == WHITE) {
            dfsVisit(adj, v, color, l);
        }
    }

    (*color)[u] = BLACK;
    (*l).push_front(u);
}

list <int> dfs (vector < list < pair <int, double> > > adj) {
    list <int> result;
    vector <int> color (adj.size(), WHITE);

    for (int u = 0; u < (int) adj.size(); u++) {
        if (color[u] == WHITE) {
            dfsVisit (adj, u, &color, &result);
        }
    }

    return result;
}

vector <int> topologicalSort (vector < list < pair <int, double> > > adj) {
    list <int> l = dfs (adj);
    return vector <int> (l.begin(), l.end());
}

void dagShortestPaths (vector < list < pair <int, double> > > adj, int s, vector <int> * d, vector <int> * pi) {
    (*d) = vector <int> (adj.size(), INFINITE);
    (*pi) = vector <int> (adj.size(), NIL);

    for (int v = 0; v < (int) adj.size(); v++) {
        (*d)[v] = INFINITE;
        (*pi)[v] = NIL;
    }
    (*d)[s] = 0;

    vector <int> ts = topologicalSort (adj);

    for (int i = 0; i < (int) ts.size(); i++) {
        int u = ts[i];
        for (list < pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = (*it).first;
            double w = (*it).second;
            if ((*d)[v] > (*d)[u] + w) {
                (*d)[v] = (*d)[u] + w;
                (*pi)[v] = u;
            }
        }
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
            double w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
        }
        cin >> s;
        dagShortestPaths (adj, s, &d, &pi);
        for (int i = 0; i < n; i++) {
            cout << d[i] << " " << pi[i] << endl;
        }
    }
    return 0;
}
