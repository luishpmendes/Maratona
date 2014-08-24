#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <vector>

#ifndef NIL
#define NIL - (15 << 25)
#endif

using namespace std;

void tarjanAux (vector < list < pair <int, double> > > adj, stack <int> * S, vector <bool> * inS, int * i, vector <int> * index, vector <int> * lowLink, int u, set < set <int> > * scc) {
    (*index)[u] = *i;
    (*lowLink)[u] = *i;
    (*i)++;
    (*S).push(u);
    (*inS)[u] = true;
    for (list < pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
        int v = (*it).first;
        if ((*index)[v] < 0) {
            tarjanAux (adj, S, inS, i, index, lowLink, v, scc);
            if ((*lowLink)[u] > (*lowLink)[v]) {
                (*lowLink)[u] = (*lowLink)[v];
            }
        } else if ((*inS)[v]) {
            if ((*lowLink)[u] > (*lowLink)[v]) {
                (*lowLink)[u] = (*lowLink)[v];
            }
        }
    }
    if ((*lowLink)[u] == (*index)[u]) {
        int v = NIL;
        set <int> component;
        do {
            v = (*S).top();
            (*S).pop();
            (*inS)[v] = false;
            component.insert(v);
        } while (u != v);
        (*scc).insert(component);
    }
}

set < set <int> > tarjan (vector < list < pair <int, double> > > adj) {
    set < set <int> > result;
    stack <int> S;
    vector <bool> inS (adj.size(), false);
    int i = 0;
    vector <int> index (adj.size(), NIL);
    vector <int> lowLink (adj.size(), NIL);
    for (int u = 0; u < (int) adj.size(); u++) {
        if (index[u] < 0) {
            tarjanAux (adj, &S, &inS, &i, &index, &lowLink, u, &result);
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
        set < set <int> > scc = tarjan (adj);
        for (set < set <int> >::iterator it = scc.begin(); it != scc.end(); ++it) {
            for (set <int>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
                cout << *it2 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
