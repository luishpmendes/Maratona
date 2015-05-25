#include <cstdio>
#include <cmath>

using namespace std;

double v[1010];

int main () {
    int n;
    while (scanf(" %d", &n) == 1 && n > 0) {
        double mean = 0.0;
        for (int i = 0; i < n; i++) {
            scanf(" %lf", &v[i]);
            mean += v[i];
        }
        mean /= ((float) n);
        double negative = 0.0, positive = 0.0;
        for (int i = 0; i < n; i++) {
            double dif = (double) (long) ((v[i]-mean) * 100.0) / 100.0;
            if (dif <= 0) {
                negative -= dif;
            } else {
                positive += dif;
            }
        }
        double result;
        if (negative > positive) {
            result = negative;
        } else {
            result = positive;
        }
        if (result < 0) {
            result = -result;
        }
        printf("$%.2lf\n", result);
    }
    return 0;
}
