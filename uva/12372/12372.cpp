#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int l, w, h;
        cin >> l >> w >> h;
        if (l <= 20 && w <= 20 && h <= 20) {
            cout << "Case " << t << ": good" << endl;
        } else {
            cout << "Case " << t << ": bad" << endl;
        }
    }
    return 0;
}
