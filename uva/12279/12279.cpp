#include <iostream>

using namespace std;

int main () {
    int n, x;
    x = 1;
    while (cin >> n && n > 0) {
        int y = 0;
        for (int i = 0; i < n; i++) {
            int z;
            cin >> z;
            if (z == 0) {
                y--;
            } else {
                y++;
            }
        }
        cout << "Case " << x++ << ": " << y << endl;
    }
    return 0;
}
