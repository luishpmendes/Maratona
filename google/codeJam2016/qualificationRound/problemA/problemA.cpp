#include <iostream>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

string itos(int i) {
    stringstream s;
    s << i;
    return s.str();
}

int main () {
    int t;
    cin >> t;
    for (int caseNumber = 1; caseNumber <= t; caseNumber++) {
        long long int n;
        cin >> n;
        long long int result = n;
        set <int> seen;
        bool first = true;
        while ((int) seen.size() < 10) {
            if (!first && (result == n || result < 0)) {
                break;
            }
            string s = itos(result);
            for (int i = 0; i < (int) s.size(); i++) {
                int d = s[i] - '0';
                seen.insert(d);
            }
            result += n;
            first = false;
        }
        result -= n;
        if (seen.size() == 10) {
            cout << "Case #" << caseNumber << ": " << result << endl;
        } else {
            cout << "Case #" << caseNumber << ": INSOMNIA" << endl;
        }
    }
    return 0;
}
