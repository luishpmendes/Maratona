#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    int n, m, f = 0, flag = 0;
    while (cin >> n >> m && n > 0 && m > 0) {
        vector <string> field;
        for (int i = 0; i < n; i++) {
            string line;
            cin >> line;
            field.push_back(line);
        }
        vector <string> result (field);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] != '*') {
                    result[i][j] = '0';
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == '*') {
                    if (i > 0) {
                        if (result[i - 1][j] != '*') {
                            result[i - 1][j]++;
                        }
                    }
                    if (i < n - 1) {
                        if (result[i + 1][j] != '*') {
                            result[i + 1][j]++;
                        }
                    }
                    if (j > 0) {
                        if (result[i][j - 1] != '*') {
                            result[i][j - 1]++;
                        }
                    }
                    if (j < m - 1) {
                        if (result[i][j + 1] != '*') {
                            result[i][j + 1]++;
                        }
                    }
                    if (i > 0 && j > 0) {
                        if (result[i - 1][j - 1] != '*') {
                            result[i - 1][j - 1]++;
                        }
                    }
                    if (i > 0 && j < m - 1) {
                        if (result[i - 1][j + 1] != '*') {
                            result[i - 1][j + 1]++;
                        }
                    }
                    if (i < n - 1 && j > 0) {
                        if (result[i + 1][j - 1] != '*') {
                            result[i + 1][j - 1]++;
                        }
                    }
                    if (i < n - 1 && j < m - 1) {
                        if (result[i + 1][j + 1] != '*') {
                            result[i + 1][j + 1]++;
                        }
                    }
                }
            }
        }
        if (flag == 1) {
            cout << endl;
        }
        flag = 1;
        cout << "Field #" << ++f << ":" << endl;
        for (int i = 0; i < n; i++) {
            cout << result[i] << endl;
        }
    }
    return 0;
}
