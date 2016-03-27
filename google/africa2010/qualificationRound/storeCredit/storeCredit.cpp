#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n;
    cin >> n;
    for (int caseNumber = 1; caseNumber <= n; caseNumber++) {
        int c, i;
        cin >> c >> i;
        vector <int> p (i, 0);
        for (int j = 0; j < i; j++) {
            cin >> p[j];
        }
        bool found = false;
        for (int j = 0; j < i && !found; j++) {
            for (int k = j + 1; k < i && !found; k++) {
                if (p[j] + p[k] == c) {
                    cout << "Case #" << caseNumber << ": " << j + 1 << " " << k + 1 << endl;
                    found = true;
                }
            }
        }
    }
    return 0;
}
