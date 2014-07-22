#include <algorithm>
#include <iostream>
#include <vector>

#ifndef NIL
#define NIL - (15 << 25)
#endif

using namespace std;

typedef struct {
    int u; /* edge source */
    int v; /* edge destination */
    double w; /* edge weight */
} Edge;

struct Sets {
    vector<int> p;
    vector<int> rank;
};

void SETSinit (Sets * S, int n) {
    S->p = vector<int> (n, NIL);
    S->rank = vector<int> (n, NIL);

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
        S->p[x] = SETSfind(S, S->p[x]);
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
    SETSlink(S, SETSfind(S, x), SETSfind(S, y));
}

bool comparator (Edge a, Edge b) {
    return (a.w < b.w);
}

vector<Edge> kruskal (vector<Edge> E, int n) {
    vector<Edge> A; /* A ← ∅ */
    Sets S;

    SETSinit(&S, n);

    /* for each vertex v ∈ V[G] */
    for (int v = 0; v < n; v++) {
        SETSmake(&S, v);
    }

    /* sort the edges of E into nondecreasing order by weight w */
    sort(E.begin(), E.end(), comparator);

    /* for each edge (u, v) ∈ E, taken in nondecreasing order by weight */
    for (vector<Edge>::iterator it = E.begin(); it != E.end(); ++it) {
        Edge e = *it;
        if (SETSfind(&S, e.u) != SETSfind(&S, e.v)) {
            A.push_back(e);
            SETSunion(&S, e.u, e.v);
        }
    }

    SETSdestroy(&S);

    return A;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        vector<Edge> E (m);
        for (int i = 0; i < m; i++) {
            Edge e;
            cin >> e.u >> e.v >> e.w;
            E[i] = e;
        }
        vector<Edge> A = kruskal(E, n);
        for (vector<Edge>::iterator it = A.begin() ; it != A.end(); ++it) {
            Edge e = *it;
            cout << e.u << " " << e.v << " " << e.w << endl;
        }
    }
    return 0;
}
