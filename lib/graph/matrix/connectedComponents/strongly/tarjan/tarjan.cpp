#include <iostream>
#include <set>
#include <stack>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

#ifndef NIL
#define NIL - (15 << 25)
#endif

using namespace std;

typedef vector < vector <double> > matrix;

void tarjanAux (matrix W, stack <int> * S, vector <bool> * inS, int * i, vector <int> * index, vector <int> * lowLink, int u, set < set <int> > * scc) {
    (*index)[u] = *i;
    (*lowLink)[u] = *i;
    (*i)++;
    (*S).push(u);
    (*inS)[u] = true;
    for (int v = 0; v < (int) W.size(); v++) {
        if (u != v && W[u][v] < INFINITE) {
            if ((*index)[v] < 0) {
                tarjanAux (W, S, inS, i, index, lowLink, v, scc);
                if ((*lowLink)[u] > (*lowLink)[v]) {
                    (*lowLink)[u] = (*lowLink)[v];
                }
            } else if ((*inS)[v]) {
                if ((*lowLink)[u] > (*lowLink)[v]) {
                    (*lowLink)[u] = (*lowLink)[v];
                }
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

set < set <int> > tarjan (matrix W) {
    set < set <int> > result;
    stack <int> S;
    vector <bool> inS (W.size(), false);
    int i = 0;
    vector <int> index (W.size(), NIL);
    vector <int> lowLink (W.size(), NIL);
    for (int u = 0; u < (int) W.size(); u++) {
        if (index[u] < 0) {
            tarjanAux (W, &S, &inS, &i, &index, &lowLink, u, &result);
        }
    }
    return result;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        matrix W (n, vector <double> (n, INFINITE));
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            W[u][v] = 1;
        }
        set < set <int> > scc = tarjan (W);
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
