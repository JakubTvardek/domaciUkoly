#include <stdio.h>

int main() {
    int obrazec = 0;
    int a = 0;
    int b = 0;


    scanf("%d%d%d", &obrazec, &a, &b);

    switch (obrazec) {
        case 0:
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < a; j++) {
                    printf("x");
                }
                printf("\n");
            }
            break;
        case 1:
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < a; j++) {
                    if ((i == b - 1 || i == 0) || (j == a - 1 || j == 0)) {
                        printf("x");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;
        case 2:
            int cislo = 0;
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < a; j++) {
                    if ((i == b - 1 || i == 0) || (j == a - 1 || j == 0)) {
                        printf("x");
                    } else {
                        printf("%d", cislo);
                        if (cislo < 9) {
                            cislo++;
                        } else {
                            cislo = 0;
                        }
                    }
                }
                printf("\n");
            }
            break;
        case 3:
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < i; j++) {
                    printf(" ");
                }
                printf("x\n");
            }
            break;
        case 4:
            for (int i = a; i > 0; i--) {
                for (int j = 0; j < i - 1; j++) {
                    printf(" ");
                }
                printf("x");

                for (int j = 0; j < a - i; j++) {
                    printf(" ");
                }

                printf("\n");
            }
            break;
        case 5:
            if (a % 2 == 0) {
                printf("Cislo A musi byt liche");
                break;
            }
            for (int i = 0, k = -1; i < a; i++, k += 2) {
                if (i == 0) {
                    for (int j = 0; j < a - 1; j++) {
                        printf(" ");
                    }
                    printf("x");
                    for (int j = 0; j < a - i - 1; j++) {
                        printf(" ");
                    }
                    printf("\n");
                } else if (i == a - 1) {
                    for (int j = 0; j < a * 2 - 1; j++) {
                        printf("x");
                    }
                } else {
                    for (int j = a - (i + 1); j > 0; j--) {
                        printf(" ");
                    }
                    printf("x");

                    for (int j = 0; j < k; j++) {
                        printf(" ");
                    }
                    printf("x");
                    for (int j = 0; j < a - i - 1; j++) {
                        printf(" ");
                    }
                    printf("\n");
                }
            }
            printf("\n");
            break;

        case 6:
            if (a % 2 == 0) {
                printf("Cislo A musi byt liche");
                break;
            }
            for (int i = 0; i < a; i++) {
                printf("x");
            }
            printf("\n");
            for (int i = 0; i < b - 1; i++) {
                for (int j = 0; j < a / 2; j++) {
                    printf(" ");
                }
                printf("x\n");
            }
            break;
        case 7:
            if (b % 2 == 0) {
                printf("Cislo B musi byt liche");
                break;
            }
            for (int i = 0; i < b; i++) {
                if (i == 0 || i == (b - 1) / 2) {
                    for (int j = 0; j < a; j++) {
                        printf("x");
                    }
                } else if (i > 0 && i < (b - 1) / 2) {
                    printf("x");
                    for (int j = 0; j < a - 2; j++) {
                        printf(" ");
                    }
                    printf("x");
                } else {
                    printf("x");
                    for (int j = 0; j < a - 1; j++) {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;
        case 9:
            for (int i = 0; i < b; i++) {
                int cisloo = i - 1;
                for (int j = 0; j < a; j++) {
                    if ((i == 0 || i == b - 1) || (j == 0 || j == a - 1)) {
                        printf("x");
                    } else {
                        printf("%d", cisloo % 10);

                        if (cisloo + b - 2 < 10) {
                            cisloo += b - 2;
                        }
                        else {
                            cisloo += b - 12;
                        }
                    }
                }
                printf("\n");
            }
            break;
        default:
            printf("Neznamy obrazec\n");
            break;
    }

    return 0;
}
