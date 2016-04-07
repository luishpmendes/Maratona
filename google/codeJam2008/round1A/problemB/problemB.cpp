#include <iostream>
#include <vector>

using namespace std;

int main () {
    int c;
    cin >> c;
    for (int caseNumber = 1; caseNumber <= c; caseNumber++) {
        int n, m;
        cin >> n >> m;

        vector <int> result (n, 0);

        vector < pair <int, int> > restrictions;
        vector <int> xs;
        vector <int> ys;

        for (int i = 0; i < m; i++) {
            int t;
            cin >> t;
            for (int j = 0; j < t; j++) {
                int x, y;
                cin >> x >> y;
                restrictions.push_back(make_pair(x, y));
                result[x] = y;
                cout << "result[" << x << "] = " << y << endl;
            }
        }

        bool possible = true;

        for (int i = 0; i < (int) restrictions.size(); i++) {
            if (result[restrictions[i].first] != restrictions[i].second) {
                cout << "result[" << restrictions[i].first << "] != " << restrictions[i].second << endl;
                possible = false;
                break;
            }
        }

        cout << "Case #" << caseNumber << ":";

        if (possible) {
            for (int i = 0; i < n; i++) {
                cout << " " << result[i];
            }
        } else {
            cout << " IMPOSSIBLE";
        }
        cout << endl;
    }
    return 0;
}
