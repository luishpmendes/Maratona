#include <iostream>
#include <string>

using namespace std;

int main () {
    string s;
    int i = 1;
    while (cin >> s && s != "*") {
        if (s == "Hajj") {
            cout << "Case " << i++ << ": Hajj-e-Akbar" << endl;
        }
        if (s == "Umrah") {
            cout << "Case " << i++ << ": Hajj-e-Asghar" << endl;
        }
    }
    return 0;
}
