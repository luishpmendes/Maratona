#include <iostream>
#include <list>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

#ifndef NIL
#define NIL - (15 << 25)
#endif

using namespace std;

typedef struct {
    int u; /* edge source */
    int v; /* edge destination */
    double w; /* edge weight */
} Edge;

vector <Edge> prim (vector < list < pair <int, double> > > adj, int r) {
    vector <Edge> result;
    vector <bool> Q (adj.size(), true);
    vector <int> key (adj.size(), INFINITE);
    vector <int> pi (adj.size(), NIL);

    for (int u = 0; u < (int) adj.size(); u++) {
        Q[u] = true;
        key[u] = INFINITE;
        pi[u] = NIL;
    }

    key[r] = 0; 

    for (int i = 0; i < (int) adj.size(); i++) {
        int u = -1;
        for (int j = 0; j < (int) adj.size(); j++) {
            if (Q[j] && (u < 0 || key[u] > key[j])) {
                u = j;
            }
        }
        Q[u] = false;

        for (list < pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = (*it).first;
            double w = (*it).second;
            if (Q[v] && w < key[v]) {
                pi[v] = u;
                key[v] = w;
            }
        }
    }

    for (int u = 0; u < (int) adj.size(); u++) {
        if (pi[u] >= 0 && pi[u] < (int) adj.size()) {
            Edge e;
            e.u = pi[u];
            e.v = u;
            e.w = key[u];
            result.push_back(e);
        }
    }

    return result;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        vector < list < pair <int, double> > > adj (n);
        for (int i = 0; i < m; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        int r;
        cin >> r;
        vector <Edge> A = prim(adj, r);
        for (vector <Edge>::iterator it = A.begin() ; it != A.end(); ++it) {
            Edge e = *it;
            cout << e.u << " " << e.v << " " << e.w << endl;
        }
    }
    return 0;
}
