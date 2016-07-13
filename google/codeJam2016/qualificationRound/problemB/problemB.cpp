#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool allUp (vector <int> v) {
    for (int i = 0; i < (int) v.size(); i++) {
        if (v[i] == 0) {
            return false;
        }
    }
    return true;
}

vector <int> flip (vector <int> v, int n) {
    vector <int> aux (v);
    for (int i = 0; i < n; i++) {
        aux[i] = 1 - v[i];
    }
    vector <int> result (v);
    for (int i = 0; i < n; i++) {
        result[i] = aux[n - i - 1];
    }
    return result;
}

int main () {
    int t;
    cin >> t;
    for (int caseNumber = 1; caseNumber <= t; caseNumber++) {
        string s;
        cin >> s;
        vector <int> v (s.size(), 0);
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == '+') {
                v[i] = 1;
            }
        }
        int result = 0;
        while (!allUp(v)) {
            result++;
            int n = ((int) v.size()) - 1;
            while (v[n] == 1) {
                n--;
            }
            n++;
            
            while (n > 0) {
                vector <int> w;
                w = flip(v, n);
                if (v == w) {
                    n--;
                } else {
                    v = w;
                    break;
                }
            }
        }
        cout << "Case #" << caseNumber << ": " << result << endl;
    }
    return 0;
}
