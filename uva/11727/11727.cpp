#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        vector <int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());
        cout << "Case " << t << ": " << v[1] << endl;
    }
    return 0;
}
