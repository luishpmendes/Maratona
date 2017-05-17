#include <iostream>
#include <cmath>

using namespace std;

int main () {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        cout << abs(((315 * n + 36962) / 10) % 10) << endl;
    }
    return 0;
}
