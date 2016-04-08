#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main () {
    int t;
    cin >> t;
    vector <int> a (33, 0);
    a[0] = 1;
    a[1] = 5;

    for (int i = 2; i < 31; i++) {
        int aux  = (6 * a[i - 1]) % 1000;
        int aux2 = (996 * a[i - 2]) % 1000;
        int aux3 = (aux + aux2) % 1000;
        a[i] = (aux3 + 1) % 1000;
    }

    for (int caseNumber = 1; caseNumber <= t; caseNumber++) {
        int n;
        cin >> n;
        cout << "Case #" << caseNumber << ": ";
        if (a[n] < 100) {
            cout << "0";
        }
        if (a[n] < 10) {
            cout << "0";
        }
        cout << a[n] << endl;
    }
    return 0;
}
