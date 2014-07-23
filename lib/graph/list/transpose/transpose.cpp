#include <list>
#include <iostream>
#include <vector>

using namespace std;

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

int main () {
    int n, m;
    while (cin >> n >> m) {
        vector < list < pair <int, double> > > adj (n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(make_pair(v, 1));
        }
        vector < list < pair <int, double> > > adjT = transpose (adj);
        for (int u = 0; u < (int) adjT.size(); u++) {
            for (list < pair <int, double> >::iterator it = adjT[u].begin(); it != adjT[u].end(); ++it) {
                int v = (*it).first;
                cout << u << " " << v << endl;
            }
        }
    }
    return 0;
}
