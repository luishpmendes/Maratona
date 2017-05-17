#include <iostream>

using namespace std;

int main () {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, m;
        cin >> n >> m;
        cout << (n/3) * (m/3) << endl;
    }
    return 0;
}
