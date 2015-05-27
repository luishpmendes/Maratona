#include <cstdio>
#include <cstring>

using namespace std;

char n[12];

int main () {
    int s;
    while (scanf(" %d", &s) == 1 && scanf(" %s", n) == 1 && s > 0) {
        int len = strlen(n);
        // first line
        for (int i = 0; i < len; i++) {
            if (i > 0) {
                printf(" ");
            }
            switch (n[i]) {
                case '0' :
                case '2' :
                case '3' :
                case '5' :
                case '6' :
                case '7' :
                case '8' :
                case '9' :
                    printf(" ");
                    for (int j = 0; j < s; j++) {
                        printf("-");
                    }
                    printf(" ");
                    break;
                case '1' :
                case '4' :
                    printf(" ");
                    for (int j = 0; j < s; j++) {
                        printf(" ");
                    }
                    printf(" ");
                    break;
            }
        }
        printf("\n");
        // top segment
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < len; j++) {
                if (j > 0) {
                    printf(" ");
                }
                switch (n[j]) {
                    case '0' :
                    case '4' :
                    case '8' :
                    case '9' :
                        printf("|");
                        for (int k = 0; k < s; k++) {
                            printf(" ");
                        }
                        printf("|");
                        break;
                    case '1' :
                    case '2' :
                    case '3' :
                    case '7' :
                        printf(" ");
                        for (int k = 0; k < s; k++) {
                            printf(" ");
                        }
                        printf("|");
                        break;
                    case '5' :
                    case '6' :
                        printf("|");
                        for (int k = 0; k < s; k++) {
                            printf(" ");
                        }
                        printf(" ");
                        break;
                }
            }
            printf("\n");
        }
        // middle line
        for (int i = 0; i < len; i++) {
            if (i > 0) {
                printf(" ");
            }
            switch (n[i]) {
                case '0' :
                case '1' :
                case '7' :
                    printf(" ");
                    for (int j = 0; j < s; j++) {
                        printf(" ");
                    }
                    printf(" ");
                    break;
                case '2' :
                case '3' :
                case '4' :
                case '5' :
                case '6' :
                case '8' :
                case '9' :
                    printf(" ");
                    for (int j = 0; j < s; j++) {
                        printf("-");
                    }
                    printf(" ");
                    break;
            }
        }
        printf("\n");
        // bottom segment
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < len; j++) {
                if (j > 0) {
                    printf(" ");
                }
                switch (n[j]) {
                    case '0' :
                    case '6' :
                    case '8' :
                        printf("|");
                        for (int k = 0; k < s; k++) {
                            printf(" ");
                        }
                        printf("|");
                        break;
                    case '1' :
                    case '3' :
                    case '4' :
                    case '5' :
                    case '7' :
                    case '9' :
                        printf(" ");
                        for (int k = 0; k < s; k++) {
                            printf(" ");
                        }
                        printf("|");
                        break;
                    case '2' :
                        printf("|");
                        for (int k = 0; k < s; k++) {
                            printf(" ");
                        }
                        printf(" ");
                        break;
                }
            }
            printf("\n");
        }
        // final line
        for (int i = 0; i < len; i++) {
            if (i > 0) {
                printf(" ");
            }
            switch (n[i]) {
                case '0' :
                case '2' :
                case '3' :
                case '5' :
                case '6' :
                case '8' :
                case '9' :
                    printf(" ");
                    for (int j = 0; j < s; j++) {
                        printf("-");
                    }
                    printf(" ");
                    break;
                case '1' :
                case '4' :
                case '7' :
                    printf(" ");
                    for (int j = 0; j < s; j++) {
                        printf(" ");
                    }
                    printf(" ");
                    break;
            }
        }
        printf("\n\n");
    }
    return 0;
}
