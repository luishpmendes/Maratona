#include <iostream>
#include <string>
#include <map>

using namespace std;

int main () {
    map <char, string> digit;
    digit['a'] = "2";
    digit['b'] = "22";
    digit['c'] = "222";
    digit['d'] = "3";
    digit['e'] = "33";
    digit['f'] = "333";
    digit['g'] = "4";
    digit['h'] = "44";
    digit['i'] = "444";
    digit['j'] = "5";
    digit['k'] = "55";
    digit['l'] = "555";
    digit['m'] = "6";
    digit['n'] = "66";
    digit['o'] = "666";
    digit['p'] = "7";
    digit['q'] = "77";
    digit['r'] = "777";
    digit['s'] = "7777";
    digit['t'] = "8";
    digit['u'] = "88";
    digit['v'] = "888";
    digit['w'] = "9";
    digit['x'] = "99";
    digit['y'] = "999";
    digit['z'] = "9999";
    digit[' '] = "0";
    int n;
    cin >> n;
    cin.ignore();
    for (int caseNumber = 1; caseNumber <= n; caseNumber++) {
        string line;
        getline(cin, line);
        cout << "Case #" << caseNumber << ": ";
        for (int i = 0; i < (int) line.size() - 1; i++) {
            cout << digit[line[i]];
            if (digit[line[i]][0] == digit[line[i + 1]][0]) {
                cout << ' ';
            }
        }
        cout << digit[line[line.size() - 1]];
        cout << endl;
    }
    return 0;
}
