#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main () {
    int n;
    cin >> n;
    cin.ignore();
    for (int caseNumber = 1; caseNumber <= n; caseNumber++) {
        string line;
        getline(cin, line);
        stringstream ss (line);
        string word;
        vector <string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        cout << "Case #" << caseNumber << ":";
        for (vector <string> :: reverse_iterator rit = words.rbegin(); rit != words.rend(); rit++) {
            cout << " " << *rit; 
        }
        cout << endl;
    }
    return 0;
}
