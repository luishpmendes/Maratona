#include <list>
#include <iostream>
#include <vector>

using namespace std;

void degree (vector < list < pair <int, double> > > adj, vector <int> * in, vector <int> * out) {
    (*in) = vector <int> (adj.size(), 0);
    (*out) = vector <int> (adj.size(), 0);
    for (int u = 0; u < (int) adj.size(); u++) {
        (*in)[u] = 0;
        (*out)[u] = 0;
    }
    for (int u = 0; u < (int) adj.size(); u++) {
        for (list < pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = (*it).first;
            (*in)[v]++;
            (*out)[u]++;
        }
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        vector < list < pair <int, double> > > adj (n);
        vector <int> in;
        vector <int> out;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(make_pair(v, 1));
        }
        degree (adj, &in, &out);
        for (int i = 0; i < n; i++) {
            cout << in[i] << " " << out[i] << endl;
        }
    }
    return 0;
}
