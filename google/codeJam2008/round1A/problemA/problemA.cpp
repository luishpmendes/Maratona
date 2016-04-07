#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main () {
    int t;
    cin >> t;
    for (int caseNumber = 1; caseNumber <= t; caseNumber++) {
        int n;
        cin >> n;
        vector <int> v1 (n);
        vector <int> v2 (n);
        for (int i = 0; i < n; i++) {
            cin >> v1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> v2[i];
        }
        sort(v1.begin(), v1.end(), less <int> ());
        sort(v2.begin(), v2.end(), greater <int> ());
        long long int result = 0;
        for (int i = 0; i < n; i++) {
            result += (long long int) v1[i] * (long long int) v2[i];
        }
        cout << "Case #" << caseNumber << ": " << result << endl;
    }
    return 0;
}
