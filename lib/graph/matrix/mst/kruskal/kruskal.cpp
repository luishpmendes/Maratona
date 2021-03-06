#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

#ifndef NIL
#define NIL - (15 << 25)
#endif

using namespace std;

typedef vector < vector <double> > matrix;

typedef struct {
    int u; /* edge source */
    int v; /* edge destination */
    double w; /* edge weight */
} Edge;

struct Sets {
    vector <int> p;
    vector <int> rank;
};

void SETSinit (Sets * S, int n) {
    S->p = vector <int> (n, NIL);
    S->rank = vector <int> (n, NIL);

    for (int i = 0; i < n; i++) {
        S->p[i] = NIL;
        S->rank[i] = NIL;
    }
}

void SETSdestroy (Sets * S) {
    for (int i = 0; i < (int) S->rank.size(); i++) {
        S->rank[i] = NIL;
    }
    for (int i = 0; i < (int) S->p.size(); i++) {
        S->p[i] = NIL;
    }
}

void SETSmake (Sets * S, int x) {
    S->p[x] = x;
    S->rank[x] = 0;
}

int SETSfind (Sets * S, int x) {
    if (x != S->p[x]) {
        S->p[x] = SETSfind (S, S->p[x]);
    }
    return S->p[x];
}

void SETSlink (Sets * S, int x, int y) {
    if (x != y) {
        if (S->rank[x] > S->rank[y]) {
            S->p[y] = x;
        } else {
            S->p[x] = y;
            if (S->rank[x] == S->rank[y]) {
                S->rank[y]++;
            }
        }
    }
}

void SETSunion (Sets * S, int x, int y) {
    SETSlink (S, SETSfind (S, x), SETSfind (S, y));
}

vector<Edge> minEdges (matrix W) {
    vector <Edge> result;
    map <pair <int, int>, double> M;

    for (int u = 0; u < (int) W.size(); u++) {
        for (int v = 0; v < (int) W[u].size(); v++) {
            if (W[u][v] < INFINITE) {
                int w = W[u][v];
                if (u < v) {
                    if (M.find(make_pair(u, v)) != M.end() || M[make_pair(u, v)] > w) {
                        M[make_pair(u, v)] = w;
                    }
                } else {
                    if (M.find(make_pair(v, u)) != M.end() || M[make_pair(v, u)] > w) {
                        M[make_pair(v, u)] = w;
                    }
                }
            }
        }
    }

    for (map <pair <int, int>, double>::iterator it = M.begin(); it != M.end(); ++it) {
        Edge e;
        e.u = ((*it).first).first;
        e.v = ((*it).first).second;
        e.w = (*it).second;
        result.push_back(e);
    }

    return result;
}

bool comparator (Edge a, Edge b) {
    return (a.w < b.w);
}

vector <Edge> kruskal (matrix W) {
    vector <Edge> A; /* A ← ∅ */
    Sets S;

    SETSinit (&S, W.size());

    /* for each vertex v ∈ V[G] */
    for (int v = 0; v < (int) W.size(); v++) {
        SETSmake (&S, v);
    }

    /* sort the edges of E into nondecreasing order by weight w */
    vector <Edge> E = minEdges (W);

    sort(E.begin(), E.end(), comparator);

    /* for each edge (u, v) ∈ E, taken in nondecreasing order by weight */
    for (int i = 0; i < (int) E.size(); i++) {
        Edge e = E[i];
        if (SETSfind (&S, e.u) != SETSfind (&S, e.v)) {
            A.push_back(e);
            SETSunion (&S, e.u, e.v);
        }
    }

    SETSdestroy (&S);

    return A;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        matrix W (n, vector <double> (n, INFINITE));
        for (int i = 0; i < m; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            W[u][v] = w;
            W[v][u] = w;
        }
        vector <Edge> A = kruskal (W);
        for (int i = 0; i < (int) A.size(); i++) {
            Edge e = A[i];
            cout << e.u << " " << e.v << " " << e.w << endl;
        }
    }
    return 0;
}
