#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int memory[1010];
int reg[13];
int m;
int result;

void split (int command, int * i, int * a, int * b) {
    *b = command % 10;
    command /= 10;
    *a = command % 10;
    command /= 10;
    *i = command % 10;
}

void compute () {
    int index = 0;
    while (true) {
        result++;
        int i, a, b;
        split(memory[index++], &i, &a, &b);
        switch (i) {
            case 1 :
                return;
                break;
            case 2 :
                reg[a] = b;
                break;
            case 3 :
                reg[a] += b;
                reg[a] %= 1000;
                break;
            case 4 :
                reg[a] *= b;
                reg[a] %= 1000;
                break;
            case 5 :
                reg[a] = reg[b];
                break;
            case 6 :
                reg[a] += reg[b];
                reg[a] %= 1000;
                break;
            case 7 :
                reg[a] *= reg[b];
                reg[a] %= 1000;
                break;
            case 8 :
                reg[a] = memory[reg[b]];
                break;
            case 9 :
                memory[reg[b]] = reg[a];
                break;
            case 0 :
                if (reg[b]) {
                    index = reg[a];
                    continue;
                }
                break;
        }
    }
}

int main () {
    int c;
    string line;
    cin >> c;
    cin.ignore();
    cin.ignore();
    while (c--) {
        m = 0;
        result = 0;
        memset(memory, 0, sizeof(memory));
        memset(reg, 0, sizeof(reg));
        while (getline(cin, line) && line.length()) {
            memory[m++] = atoi(line.c_str());
        }
        compute();
        cout << result << endl;
        if (c) {
            cout << endl;
        }
    }
    return 0;
}
