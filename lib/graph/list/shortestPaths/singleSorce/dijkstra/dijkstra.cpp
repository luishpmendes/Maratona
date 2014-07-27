#include <list>
#include <iostream>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

#ifndef NIL
#define NIL - (15 << 25)
#endif

using namespace std;

void dijkstra (vector < list < pair <int, double> > > adj, int s, vector <int> * d, vector <int> * pi) {
    (*d) = vector <int> (adj.size(), INFINITE);
    (*pi) = vector <int> (adj.size(), NIL);
    vector <bool> Q (adj.size(), true);

    for (int v = 0; v < (int) adj.size(); v++) {
        (*d)[v] = INFINITE;
        (*pi)[v] = NIL;
        Q[v] = true;
    }
    (*d)[s] = 0;

    for (int i = 0; i < (int) adj.size(); i++) {
        int u = -1;
        for (int j = 0; j < (int) adj.size(); j++) {
            if (Q[j] && (u < 0 || (*d)[u] > (*d)[j])) {
                u = j;
            }
        }
        Q[u] = false;

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
        dijkstra (adj, s, &d, &pi);
        for (int i = 0; i < n; i++) {
            cout << d[i] << " " << pi[i] << endl;
        }
    }
    return 0;
}
