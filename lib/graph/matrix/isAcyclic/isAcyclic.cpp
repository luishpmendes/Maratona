#include <iostream>
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

bool isAcyclicRec (matrix W, int u, vector <int> * color) {
    (*color)[u] = GRAY;
    for (int v = 0; v < (int) W.size(); v++) {
        if (u != v && W[u][v] < INFINITE) {
            if ((*color)[v] == GRAY) {
                return false;
            } else if ((*color)[v] == WHITE) {
                if (isAcyclicRec (W, v, color) == false) {
                    return false;
                }
            }
        }
    }
    (*color)[u] = BLACK;
    return true;
}

bool isAcyclic (matrix W) {
    vector <int> color (W.size(), WHITE);
    for (int u = 0; u < (int) W.size(); u++) {
        color[u] = WHITE;
    }
    for (int u = 0; u < (int) W.size(); u++) {
        if (color[u] == WHITE) {
            if (isAcyclicRec (W, u, &color) == false) {
                return false;
            }
        }
    }
    return true;
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
        cout << isAcyclic (W) << endl;
    }
    return 0;
}
