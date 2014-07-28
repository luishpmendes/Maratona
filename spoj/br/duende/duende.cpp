#include <cstdio>
#include <queue>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

#ifndef NIL
#define NIL - (15 << 25)
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

typedef vector < vector <int> > matrix;

void bfs (matrix W, int s, vector <int> * pi, vector <int> * d) {
    vector <int> color (W.size(), WHITE);
    queue <int> Q;

    (*pi) = vector <int> (W.size(), NIL);
    (*d) = vector <int> (W.size(), INFINITE);

    for (int u = 0; u < (int) W.size(); u++) {
        color[u] = WHITE;
        (*d)[u] = INFINITE;
        (*pi)[u] = NIL;
    }

    color[s] = GRAY;
    (*d)[s] = 0;
    (*pi)[s] = NIL;

    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v = 0; v < (int) W.size(); v++) {
            if (u != v && W[u][v] < INFINITE) {
                if (color[v] == WHITE) {
                    color[v] = GRAY;
                    (*d)[v] = (*d)[u]+1;
                    (*pi)[v] = u;
                    Q.push(v);
                }
            }
        }
        color[u] = BLACK;
    }
}

int main () {
    int n, m;
    scanf(" %d", &n);
    scanf(" %d", &m);
    matrix c (n, vector <int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &c[i][j]);
        }
    }
    matrix W (n*m, vector <int> (n*m, INFINITE));
    int s;
    vector <int> e;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == 0) {
                e.push_back(i*m+j);
            } else if (c[i][j] == 3) {
                s = i*m+j;
            }
            if (c[i][j] != 2) {
                if (i > 0 && c[i-1][j] != 2) {
                    W[i*m+j][(i-1)*m+j] = 1;
                    W[(i-1)*m+j][i*m+j] = 1;
                }
                if (j > 0 && c[i][j-1] != 2) {
                    W[i*m+j][i*m+(j-1)] = 1;
                    W[i*m+(j-1)][i*m+j] = 1;
                }
                if (i < n-1 && c[i+1][j] != 2) {
                    W[i*m+j][(i+1)*m+j] = 1;
                    W[(i+1)*m+j][i*m+j] = 1;
                }
                if (j < m-1 && c[i][j+1] != 2) {
                    W[i*m+j][i*m+(j+1)] = 1;
                    W[i*m+(j+1)][i*m+j] = 1;
                }
            }
        }
    }
    vector <int> pi;
    vector <int> d;
    bfs (W, s, &pi, &d);
    int min = INFINITE;
    for (int i = 0; i < (int) e.size(); i++) {
        if (min > d[e[i]]) {
            min = d[e[i]];
        }
    }
    printf("%d\n", min);
    return 0;
}
