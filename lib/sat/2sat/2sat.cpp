#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <vector>

#ifndef NIL
#define NIL - (15 << 25)
#endif

using namespace std;

void tarjanAux (vector < list < pair <int, double> > > adj, stack <int> * S, vector <bool> * inS, int * i, vector <int> * index, vector <int> * lowLink, int u, vector <int> * scc, int * ncc) {
    (*index)[u] = *i;
    (*lowLink)[u] = *i;
    (*i)++;
    (*S).push(u);
    (*inS)[u] = true;
    for (list < pair <int, double> >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
        int v = (*it).first;
        if ((*index)[v] < 0) {
            tarjanAux (adj, S, inS, i, index, lowLink, v, scc, ncc);
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
        do {
            v = (*S).top();
            (*S).pop();
            (*inS)[v] = false;
            (*scc)[v] = *ncc;
        } while (u != v);
        (*ncc)++;
    }
}

int tarjan (vector < list < pair <int, double> > > adj, vector <int> * scc) {
    *scc = vector <int> (adj.size(), NIL);
    int ncc = 0;
    stack <int> S;
    vector <bool> inS (adj.size(), false);
    int i = 0;
    vector <int> index (adj.size(), NIL);
    vector <int> lowLink (adj.size(), NIL);
    for (int u = 0; u < (int) adj.size(); u++) {
        if (index[u] < 0) {
            tarjanAux (adj, &S, &inS, &i, &index, &lowLink, u, scc, &ncc);
        }
    }
    return ncc;
}

bool sat (vector < pair < pair <int, bool>, pair <int, bool> > > V, int m) {
    vector < list < pair <int, double> > > adj (2*m);
    for (int i = 0; i < (int) V.size(); i++) {
        int id1 = V[i].first.first;
        int b1 = V[i].first.second ? 1 : 0;
        int id2 = V[i].second.first;
        int b2 = V[i].second.second ? 1 : 0;
        adj[(1 - b1) * m + id1].push_back(make_pair(b2 * m + id2, 1));
        adj[(1 - b2) * m + id2].push_back(make_pair(b1 * m + id1, 1));
    }
    vector <int> scc;
    tarjan (adj, &scc);
    for (int i = 0; i < m; i++) {
        if (scc[i] == scc[m + i]) {
            return false;
        }
    }
    return true;
}

int main () {
    int n;
    while (cin >> n) {
        int m = 0;
        map <string, int> M;
        vector < pair < pair <int, bool>, pair <int, bool> > > V;
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            bool b1 = true, b2 = true;
            if (s1[0] == '!' || s1[0] == '-') {
                b1 = false;
                s1.erase(0, 1);
            }
            if (s2[0] == '!' || s2[0] == '-') {
                b2 = false;
                s2.erase(0, 1);
            }
            if (M.find(s1) == M.end()) {
                M[s1] = m++;
            }
            if (M.find(s2) == M.end()) {
                M[s2] = m++;
            }
            V.push_back(make_pair(make_pair(M[s1], b1), make_pair(M[s2], b2)));
        }
        cout << sat (V, m) << endl;
    }
    return 0;
}
