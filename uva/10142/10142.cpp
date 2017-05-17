#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main () {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        vector <string> v (n);
        for (int i = 0; i < n; i++) {
            getline(cin, v[i]);
        }
        vector < vector <int> > m;
        string line;
        while (getline(cin, line)) {
            if (line.empty()) {
                break;
            } else {
                istringstream iss (line);
                vector <int> aux (n);
                for (int i = 0; i < n; i++) {
                    cin >> aux[i];
                }
                m.push_back(aux);
            }
        }
        
    }
    return 0;
}
