#include <cstdio>
 
using namespace std;
 
int mar[100][100];
 
int main() {
    int n, area = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            mar[i][j] = 0;
        }
    }
    scanf(" %d", &n);
    for (int k = 0; k < n; k++) {
        int xi, xf, yi, yf;
        scanf(" %d", &xi);
        scanf(" %d", &xf);
        scanf(" %d", &yi);
        scanf(" %d", &yf);

        for (int i = yi; i < yf; i++) {
            for (int j = xi; j < xf; j++) {
                if (mar[i][j] == 0) {
                    area++;
                }
                mar[i][j] = 1;
            }
        }
    }
    printf("%d\n", area);
    return 0;
}
