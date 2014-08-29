#include <cstdio>
#include <vector>
#define MOD 1000000007

using namespace std;

typedef vector< vector<long long> > matrix;

matrix mul (matrix a, matrix b) {
    matrix c (3, vector <long long> (3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

matrix pow (matrix m, int n) {
    if (n == 1) {
        return m;
    }
    if (n % 2) {
        return mul(m, pow(m, n-1));
    }
    matrix x = pow(m, n/2);
    return mul (x, x);
}

int main () {
    int t;
    for (scanf(" %d", &t); t > 0; t--) {
        int n, m;
        long long sn = 0, sm = 0, result = 0;
        matrix a (3, vector <long long> (3));
        vector <int> v(3);
        scanf(" %d", &n);
        scanf(" %d", &m);
        n--;
        if (n > 0) {
            a[0][0] = 0;
            a[0][1] = 1;
            a[0][2] = 0;
            a[1][0] = 1;
            a[1][1] = 1;
            a[1][2] = 0;
            a[2][0] = 0;
            a[2][1] = 1;
            a[2][2] = 1;
            v[0] = 0;
            v[1] = 1;
            v[2] = 0;
            a = pow(a, n);
            sn = (sn + a[2][0]*v[0]) % MOD;
            sn = (sn + a[2][1]*v[1]) % MOD;
            sn = (sn + a[2][2]*v[2]) % MOD;
        }
        if (m > 0) {
            a[0][0] = 0;
            a[0][1] = 1;
            a[0][2] = 0;
            a[1][0] = 1;
            a[1][1] = 1;
            a[1][2] = 0;
            a[2][0] = 0;
            a[2][1] = 1;
            a[2][2] = 1;
            v[0] = 0;
            v[1] = 1;
            v[2] = 0;
            a = pow(a, m);
            sm = (sm + a[2][0]*v[0]) % MOD;
            sm = (sm + a[2][1]*v[1]) % MOD;
            sm = (sm + a[2][2]*v[2]) % MOD;
        }
        result = (sm - sn + MOD) % MOD;
        printf("%lld\n", result);
    }
    return 0;
}
