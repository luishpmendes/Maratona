#include <iostream>
#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

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

typedef vector < vector <double> > matrix;

void dfsVisit (matrix W, int u, vector <int> * color, list <int> * l) {
    (*color)[u] = GRAY;
    for (int v = 0; v < (int) W.size(); v++) {
        if (u != v && W[u][v] < INFINITE) {
            if ((*color)[v] == WHITE) {
                dfsVisit(W, v, color, l);
            }
        }
    }
    (*color)[u] = BLACK;
    (*l).push_front(u);
}

list <int> dfs (matrix W) {
    list <int> result;
    vector <int> color (W.size(), WHITE);
    for (int u = 0; u < (int) W.size(); u++) {
        if (color[u] == WHITE) {
            dfsVisit(W, u, &color, &result);
        }
    }
    return result;
}

vector <int> topologicalSort (matrix W) {
    list <int> l = dfs (W);
    return vector <int> (l.begin(), l.end());
}

matrix transpose (matrix W) {
    matrix result (W.size(), vector <double> (W.size(), INFINITE));
    for (int u = 0; u < (int) W.size(); u++) {
        for (int v = 0; v < (int) W.size(); v++) {
            result[v][u] = W[u][v];
        }
    }
    return result;
}

void dfsTVisit (matrix W, int u, vector <int> * color, vector <int> * scc, int ncc) {
    (*color)[u] = GRAY;
    for (int v = 0; v < (int) W.size(); v++) {
        if (u != v && W[u][v] < INFINITE) {
            if ((*color)[v] == WHITE) {
                dfsTVisit(W, v, color, scc, ncc);
            }
        }
    }
    (*color)[u] = BLACK;
    (*scc)[u] = ncc;
}

int dfsT (matrix W, vector <int> ts, vector <int> * scc) {
    int result = 0;
    *scc = vector <int> (W.size(), -1);
    vector <int> color (W.size(), WHITE);
    for (int i = 0; i < (int) ts.size(); i++) {
        int u = ts[i];
        if (color[u] == WHITE) {
            dfsTVisit (W, u, &color, scc, result++);
        }
    }
    return result;
}

int stronglyConnectedComponents (matrix W, vector <int> * scc) {
    vector <int> ts = topologicalSort (W);
    matrix T = transpose (W);
    return dfsT (T, ts, scc);
}

bool sat (vector < pair < pair <int, bool>, pair <int, bool> > > V, int m) {
    matrix W (2*m, vector <double> (2*m, INFINITE));
    for (int i = 0; i < (int) V.size(); i++) {
        int id1 = V[i].first.first;
        int b1 = V[i].first.second ? 1 : 0;
        int id2 = V[i].second.first;
        int b2 = V[i].second.second ? 1 : 0;
        W[(1 - b1) * m + id1][b2 * m + id2] = 1;
        W[(1 - b2) * m + id2][b1 * m + id1] = 1;
    }
    vector <int> scc;
    stronglyConnectedComponents (W, &scc);
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
