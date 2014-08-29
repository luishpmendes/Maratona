#include <cstdio>
#include <vector>

using namespace std;

typedef vector < vector <int> > matrix;

pair <int, int> escolheCaixa (matrix caixa, matrix custo) {
    int iMax = 0, jMax = 0;
    for (int i = 0; i < (int) caixa.size(); i++) {
        for (int j = 0; j < (int) caixa[i].size(); j++) {
            if (caixa[iMax][jMax] < caixa[i][j]) {
                iMax = i;
                jMax = j;
            } else if (caixa[iMax][jMax] == caixa[i][j] && custo[iMax][jMax] > custo[i][j]) {
                iMax = i;
                jMax = j;
            }
        }
    }
    return make_pair(iMax, jMax);
}

void esvaziaCaixa (matrix * caixa, matrix * custo, int i, int j) {
    if (i > 0) {
        for (int k = 0; k < (int) (*caixa)[0].size(); k++) {
            (*custo)[i - 1][k] -= (*caixa)[i][j];
        }
    }
    if (i < (int) (*caixa).size() - 1) {
        for (int k = 0; k < (int) (*caixa)[0].size(); k++) {
            (*custo)[i + 1][k] -= (*caixa)[i][j];
        }
    }
    if (j > 0) {
        (*custo)[i][j - 1] -= (*caixa)[i][j];
    }
    if (j < (int) (*caixa)[0].size() - 1) {
        (*custo)[i][j + 1] -= (*caixa)[i][j];
    }
    (*caixa)[i][j] = 0;
}

int main () {
    int n, m;
    while (scanf(" %d", &n) == 1 && scanf(" %d", &m) == 1 && (n > 0 || m > 0)) {
        matrix caixa (n, vector <int> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %d", &caixa[i][j]);
            }
        }
        matrix custo (n, vector <int> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) {
                    for (int k = 0; k < m; k++) {
                        custo[i][j] += caixa[i - 1][k];
                    }
                }
                if (i < n - 1) {
                    for (int k = 0; k < m; k++) {
                        custo[i][j] += caixa[i + 1][k];
                    }
                }
                if (j > 0) {
                    custo[i][j] += caixa[i][j - 1];
                }
                if (j < m - 1) {
                    custo[i][j] += caixa[i][j + 1];
                }
            }
        }
        int result = 0;
        bool flag;
        do {
            flag = false;
            pair <int, int> pos = escolheCaixa (caixa, custo);
            int iMax = pos.first, jMax = pos.second;
            result += caixa[iMax][jMax];
            if (caixa[iMax][jMax] > 0) {
                flag = true;
            }
            if (iMax > 0) {
                for (int j = 0; j < m; j++) {
                    esvaziaCaixa (&caixa, &custo, iMax - 1, j);
                    //caixa[iMax - 1][j] = 0;
                }
            }
            if (iMax < n - 1) {
                for (int j = 0; j < m; j++) {
                    esvaziaCaixa (&caixa, &custo, iMax + 1, j);
                    //caixa[iMax + 1][j] = 0;
                }
            }
            if (jMax > 0) {
                esvaziaCaixa (&caixa, &custo, iMax, jMax - 1);
                //caixa[iMax][jMax - 1] = 0;
            }
            if (jMax < m - 1) {
                esvaziaCaixa (&caixa, &custo, iMax, jMax + 1);
                //caixa[iMax][jMax + 1] = 0;
            }
            esvaziaCaixa (&caixa, &custo, iMax, jMax);
            //caixa[iMax][jMax] = 0;
        } while (flag);
        printf("%d\n", result);
    }
    return 0;
}
