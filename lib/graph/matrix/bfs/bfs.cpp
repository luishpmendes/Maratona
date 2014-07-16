#include <iostream>
#include <queue>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 24
#endif

#ifndef NIL
#define NIL - 15 << 24
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

void bfs(matrix W, int s, vector<int> * pi, vector<int> * d) {
    vector<int> color;
    queue<int> Q;

    for (unsigned int u = 0; u < W.size(); u++) {
        color.push_back(WHITE);
        (*d).push_back(INFINITE);
        (*pi).push_back(NIL);
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
    while (cin >> n >> m) {
        matrix W (n, vector<int>(n, INFINITE));
        int s;
        vector<int> pi;
        vector<int> d;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            W[u][v] = 1;
        }
        cin >> s;
        bfs(W, s, &pi, &d);
        for (int i = 0; i < n; i++) {
            cout << pi[i] << " " << d[i] << endl;
        }
    }
    return 0;
}
