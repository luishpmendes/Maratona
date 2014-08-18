#include <iostream>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

#ifndef NIL
#define NIL - (15 << 25)
#endif

using namespace std;

typedef vector < vector <int> > matrix;

matrix transitiveClosure (matrix W) {
    matrix result (W.size(), vector <int> (W.size(), 0));
    for (int i = 0; i < (int) W.size(); i++) {
        for (int j = 0; j < (int) W.size(); j++) {
            if (i == j || W[i][j] < INFINITE) {
                result[i][j] = 1;
            }
        }
    }
    for (int k = 0; k < (int) W.size(); k++) {
        for (int i = 0; i < (int) W.size(); i++) {
            for (int j = 0; j < (int) W.size(); j++) {
                result[i][j] = result[i][j] | (result[i][k] & result[k][j]);
            }
        }
    }
    return result;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        matrix W (n, vector <int> (n, INFINITE)), T;
        for (int i = 0; i < n; i++) {
            W[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            W[u][v] = 1;
        }
        T = transitiveClosure (W);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << T[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
