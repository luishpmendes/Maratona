#include <iostream>
#include <list>
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

void dfsVisit (vector < list < pair <int, double> > > adj, int u, vector <int> * color, list <int> * l) {
    (*color)[u] = GRAY;
    for (list < pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
        int v = (*it).first;
        if ((*color)[v] == WHITE) {
            dfsVisit (adj, v, color, l);
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

vector < list < pair <int, double> > > transpose (vector < list < pair <int, double> > > adj) {
    vector < list < pair <int, double> > > result (adj.size());
    for (int u = 0; u < (int) adj.size(); u++) {
        for (list < pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = (*it).first;
            result[v].push_back(make_pair(u, 1));
        }
    }

    return result;
}

void dfsTVisit (vector < list < pair <int, double> > > adj, int u, vector <int> * color, vector <int> * scc, int ncc) {
    (*color)[u] = GRAY;
    for (list < pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
        int v = (*it).first;
        if ((*color)[v] == WHITE) {
            dfsTVisit (adj, v, color, scc, ncc);
        }
    }
    (*color)[u] = BLACK;
    (*scc)[u] = ncc;
}

int dfsT (vector < list < pair <int, double> > > adj, vector <int> ts, vector <int> * scc) {
    int result = 0;
    *scc = vector <int> (adj.size(), -1);
    vector <int> color (adj.size(), WHITE);
    for (int i = 0; i < (int) ts.size(); i++) {
        int u = ts[i];
        if (color[u] == WHITE) {
            dfsTVisit (adj, u, &color, scc, result++);
        }
    }
    return result;
}

int stronglyConnectedComponents (vector < list < pair <int, double> > > adj, vector <int> * scc) {
    vector <int> ts = topologicalSort (adj);
    vector < list < pair <int, double> > > adjT = transpose (adj);
    return dfsT (adjT, ts, scc);
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        vector < list < pair <int, double> > > adj (n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(make_pair(v, 1));
        }
        vector <int> scc;
        int ncc = stronglyConnectedComponents (adj, &scc);
        cout << ncc << endl;
        for (int u = 0; u < n; u++) {
            cout << scc[u] << " ";
        }
        cout << endl;
    }
    return 0;
}
