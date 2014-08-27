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

bool isAcyclicRec (vector < list < pair <int, double> > > adj, int u, vector <int> * color) {
    (*color)[u] = GRAY;
    for (list < pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
        int v = (*it).first;
        if ((*color)[v] == GRAY) {
            return false;
        } else if ((*color)[v] == WHITE) {
            if (isAcyclicRec (adj, v, color) == false) {
                return false;
            }
        }
    }
    (*color)[u] = BLACK;
    return true;
}

bool isAcyclic (vector < list < pair <int, double> > > adj) {
    vector <int> color (adj.size(), WHITE);
    for (int u = 0; u < (int) adj.size(); u++) {
        color[u] = WHITE;
    }
    for (int u = 0; u < (int) adj.size(); u++) {
        if (color[u] == WHITE) {
            if (isAcyclicRec (adj, u, &color) == false) {
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
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(make_pair(v, 1));
        }
        cout << isAcyclic (adj) << endl;;
    }
    return 0;
}
