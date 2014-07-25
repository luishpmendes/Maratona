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

bool bellmanFord (vector < list < pair <int, double> > > adj, int s, vector <int> * d, vector <int> * pi) {
    (*d) = vector <int> (adj.size(), INFINITE);
    (*pi) = vector <int> (adj.size(), NIL);

    for (int v = 0; v < (int) adj.size(); v++) {
        (*d)[v] = INFINITE;
        (*pi)[v] = NIL;
    }
    (*d)[s] = 0;

    for (int i = 1; i < (int) adj.size(); i++) {
        for (int u = 0; u < (int) adj.size(); u++) {
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
    for (int u = 0; u < (int) adj.size(); u++) {
        for (list < pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = (*it).first;
            double w = (*it).second;
            if ((*d)[v] > (*d)[u] + w) {
                return false;
            }
        }
    }
    return true;
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
        if (bellmanFord (adj, s, &d, &pi)) {
            for (int i = 0; i < n; i++) {
                cout << d[i] << " " << pi[i] << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
