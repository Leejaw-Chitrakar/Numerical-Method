#include <stdio.h>
#include <conio.h>

int main() {
    int n, i, j, k;
    float a[10][11], ratio;

    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    printf("Enter elements of augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    /* Applying Gauss Jordan Elimination */
    for (i = 0; i < n; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error!");
            getch();
            return 0;
        }
        for (j = 0; j < n; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < n + 1; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    /* Row elimination to obtain unit matrix */
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %0.3f\n", i, a[i][n] / a[i][i]);
    }

    getch();
    return 0;
}
