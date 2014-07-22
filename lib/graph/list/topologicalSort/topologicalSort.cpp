#include <list>
#include <iostream>
#include <vector>

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

void dfsVisit (vector< list < pair <int, double> > > adj, int u, vector<int> * color, list<int> * l) {
    (*color)[u] = GRAY;

    for (list< pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
        int v = (*it).first;
        if ((*color)[v] == WHITE) {
            dfsVisit(adj, v, color, l);
        }
    }

    (*color)[u] = BLACK;
    (*l).push_front(u);
}

list<int> dfs (vector< list < pair <int, double> > > adj) {
    list<int> result;
    vector<int> color (adj.size(), WHITE);

    for (int u = 0; u < (int) adj.size(); u++) {
        if (color[u] == WHITE) {
            dfsVisit(adj, u, &color, &result);
        }
    }

    return result;
}

vector<int> topologicalSort (vector< list < pair <int, double> > > adj) {
    list<int> l = dfs (adj);
    return vector<int> (l.begin(), l.end());
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        vector< list < pair <int, double> > > adj (n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(make_pair(v, 1));
        }
        vector<int> ts = topologicalSort(adj);
        for (int i = 0; i < n; i++) {
            cout << ts[i] << endl;
        }
    }
    return 0;
}
