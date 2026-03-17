#include <stdio.h>
#include <conio.h>
#include <math.h>

int main() {
    float a[10][10], x[10], x_new[10];
    float lambda_old, lambda_new, error, e;
    int i, j, n, step = 1;

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter initial guess vector:\n");
    for (i = 1; i <= n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
    }

    printf("Enter tolerable error: ");
    scanf("%f", &e);

    lambda_old = 1;

    /* Power Method Algorithm */
    printf("\nSTEP\tLAMBDA\tVECTOR\n");
    do {
        /* Multiplication */
        for (i = 1; i <= n; i++) {
            x_new[i] = 0;
            for (j = 1; j <= n; j++) {
                x_new[i] = x_new[i] + a[i][j] * x[j];
            }
        }

        /* Replacing lambda_new with largest element of x_new */
        lambda_new = x_new[1];
        for (i = 2; i <= n; i++) {
            if (fabs(x_new[i]) > fabs(lambda_new)) {
                lambda_new = x_new[i];
            }
        }

        /* Normalization */
        for (i = 1; i <= n; i++) {
            x[i] = x_new[i] / lambda_new;
        }

        /* Display */
        printf("%d\t%0.4f\t[", step, lambda_new);
        for (i = 1; i <= n; i++) {
            printf("%0.4f ", x[i]);
        }
        printf("]\n");

        error = fabs(lambda_new - lambda_old);
        lambda_old = lambda_new;
        step++;

    } while (error > e);

    printf("\nDominant Eigen Value = %0.4f\n", lambda_new);
    printf("Eigen Vector:\n");
    for (i = 1; i <= n; i++) {
        printf("%0.4f\n", x[i]);
    }

    getch();
    return 0;
}
