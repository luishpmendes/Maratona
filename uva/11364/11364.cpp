#include <iostream>

using namespace std;

int main () {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, min, max;
        cin >> n;
        min = max = -1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (min > x || min < 0) {
                min = x;
            }
            if (max < x || max < 0) {
                max = x;
            }
        }
        cout << 2*(max - min) << endl;
    }
    return 0;
}
