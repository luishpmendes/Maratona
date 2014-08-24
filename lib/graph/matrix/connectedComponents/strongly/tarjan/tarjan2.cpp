#include <iostream>
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

void tarjanAux (matrix W, stack <int> * S, vector <bool> * inS, int * i, vector <int> * index, vector <int> * lowLink, int u, vector <int> * scc, int * ncc) {
    (*index)[u] = *i;
    (*lowLink)[u] = *i;
    (*i)++;
    (*S).push(u);
    (*inS)[u] = true;
    for (int v = 0; v < (int) W.size(); v++) {
        if (u != v && W[u][v] < INFINITE) {
            if ((*index)[v] < 0) {
                tarjanAux (W, S, inS, i, index, lowLink, v, scc, ncc);
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
        do {
            v = (*S).top();
            (*S).pop();
            (*inS)[v] = false;
            (*scc)[v] = *ncc;
        } while (u != v);
        (*ncc)++;
    }
}

int tarjan (matrix W, vector <int> * scc) {
    *scc = vector <int> (W.size(), NIL);
    int ncc = 0;
    stack <int> S;
    vector <bool> inS (W.size(), false);
    int i = 0;
    vector <int> index (W.size(), NIL);
    vector <int> lowLink (W.size(), NIL);
    for (int u = 0; u < (int) W.size(); u++) {
        if (index[u] < 0) {
            tarjanAux (W, &S, &inS, &i, &index, &lowLink, u, scc, &ncc);
        }
    }
    return ncc;
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
        vector <int> scc;
        int ncc = tarjan (W, &scc);
        cout << ncc << endl;
        for (int u = 0; u < n; u++) {
            cout << scc[u] << " ";
        }
        cout << endl;
    }
    return 0;
}
