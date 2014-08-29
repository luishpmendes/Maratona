#include <cstdio>
#include <vector>

using namespace std;

short int minPrice[6];

int main () {
    int n, t;
    while (scanf(" %d", &n) == 1 && scanf(" %d", &t) == 1) {
        vector <int> type (n);
        vector <int> p (n);
        vector <int> q (n);
        for (short int i = 0; i < n; i++) {
            scanf(" %d", &type[i]);
            scanf(" %d", &p[i]);
            scanf(" %d", &q[i]);
        }
        int result = 0;
        for (result = t; result > 0; result--) {
            vector <int> minPrice (6);
            for (int i = 0; i < 6; i++) {
                minPrice[i] = t+1;
            }
            for (int i = 0; i < n; i++) {
                if (type[i] > 0 && type[i] <= 6) {
                    if (q[i] >= result) {
                        if (minPrice[type[i]-1] > p[i]) {
                            minPrice[type[i]-1] = p[i];
                        }
                    }
                }
            }
            int sum = 0;
            for (int i = 0; i < 6; i++) {
                sum += minPrice[i];
            }
            if (sum <= t) {
                break;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
