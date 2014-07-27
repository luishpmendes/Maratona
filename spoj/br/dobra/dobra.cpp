#include <cmath>
#include <cstdio>

using namespace std;

int main () {
    int n, t = 1;
    while (scanf(" %d", &n) == 1 && n >= 0) {
        long int result = pow(2, n)+1;
        printf("Teste %d\n%ld\n\n", t++, result*result);
    }
    return 0;
}
