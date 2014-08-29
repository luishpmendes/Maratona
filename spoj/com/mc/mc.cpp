#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector < vector <int> > matrix;

int main () {
    string s, t;
    while (cin >> s && cin >> t && s[0] != '#' && t[0] != '#') {
        int n = (int) s.size(), m = (int) t.size();
        matrix c (n+1, vector <int> (m+1));
        for (int i = 0; i < n; i++) {
            c[i][0] = 0;
        }
        for (int j = 1; j < m; j++) {
            c[0][j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1]) {
                    c[i][j] = c[i-1][j-1]+1;
                } else if (c[i-1][j] > c[i][j-1]) {
                    c[i][j] = c[i-1][j];
                } else {
                    c[i][j] = c[i][j-1];
                }
            }
        }
        cout << (n - c[n][m]) * 15 + (m - c[n][m]) * 30 << endl;
    }
    return 0;
}
