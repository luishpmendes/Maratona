#include <iostream>
#include <string>

using namespace std;

int main () {
    int t, result;
    cin >> t;
    result = 0;
    while (t-- > 0) {
        string s;
        cin >> s;
        if (s == "donate") {
            int k;
            cin >> k;
            result += k;
        } else  {
            cout << result << endl;
        }
    }
    return 0;
}
