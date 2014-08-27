#include <iostream>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

using namespace std;

typedef vector < vector <double> > matrix;

void degree (matrix W, vector <int> * in, vector <int> * out) {
    (*in) = vector <int> (W.size(), 0);
    (*out) = vector <int> (W.size(), 0);
    for (int u = 0; u < (int) W.size(); u++) {
        (*in)[u] = 0;
        (*out)[u] = 0;
    }
    for (int u = 0; u < (int) W.size(); u++) {
        for (int v = 0; v < (int) W.size(); v++) {
            if (u != v && W[u][v] < INFINITE) {
                (*in)[v]++;
                (*out)[u]++;
            }
        }
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        matrix W (n, vector <double> (n, INFINITE));
        vector <int> in;
        vector <int> out;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            W[u][v] = 1;
        }
        degree (W, &in, &out);
        for (int i = 0; i < n; i++) {
            cout << in[i] << " " << out[i] << endl;
        }
    }
    return 0;
}
