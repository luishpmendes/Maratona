#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main () {
    int t;
    for (cin >> t; t > 0; t--) {
        int n;
        cin >> n;
        vector <string> v (n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        bool flag = false;
        for (int i = 0; i < (int) v.size() - 1; i++) {
            if (v[i+1].find(v[i]) == 0) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
