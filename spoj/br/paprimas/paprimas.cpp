#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int converteParaNumero (string palavra) {
    int result = 0, len = palavra.size();
    for (int i = 0; i < len; i++) {
        if (palavra[i] >= 'a' && palavra[i] <= 'z') {
            result += palavra[i]-'a'+1;
        } else if (palavra[i] >= 'A' && palavra[i] <= 'Z') {
            result += palavra[i]-'A'+27;
        }
    }
    return result;
}

bool ehPrimo (int n) {
    int raiz = sqrt (n);
    for (int i = 2; i <= raiz; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main (void) {
    string palavra;
    while (cin >> palavra) {
        if (ehPrimo (converteParaNumero (palavra))) {
            cout << "It is a prime word." << endl;
        } else {
            cout << "It is not a prime word." << endl;
        }
    }
    return 0;
}
