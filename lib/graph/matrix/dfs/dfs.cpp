#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <list>
#include <queue>

#ifndef INFINITE
#define INFINITE INT_MAX
#endif

#ifndef NIL
#define NIL INT_MIN
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

typedef vector< vector<int> > matrix;

void dfsVisit(matrix W, int n, int u, int * time, int color[], int pi[], int d[], int f[]) {
    if (time != NULL) {
        (*time)++;
        if (d != NULL) {
            d[u] = (*time);
        }
    }

    color[u] = GRAY;

    for (int v = 0; v < n; v++) {
        if (u != v && W[u][v] < INFINITE) {
            if (color[v] == WHITE) {
                if(pi != NULL) {
                    pi[v] = u;
                }
                dfsVisit(W, n, v, time, color, pi, d, f);
            }
        }
    }

    color[u] = BLACK;
    if (time != NULL) {
        (*time)++;
        if (f != NULL) {
            f[u] = (*time);
        }
    }
}

void dfs(matrix W, vector<int> pi, int d[], int f[]) {
    vector<int> color;
    int time;

    for(int u = 0; u < n; u++) {
        color[u] = WHITE;
        if(pi != NULL) {
            pi[u] = NIL;
        }
    }

    time = 0;

    for (int u = 0; u < n; u++) {
        if(color[u] == WHITE) {
            dfsVisit(W, n, u, &time, color, pi, d, f);
        }
    }
}
