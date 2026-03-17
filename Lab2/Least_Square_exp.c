#include <stdio.h>
#include <math.h>
#include <conio.h>

int main() {
    int n, i;
    float x[20], y[20], Y[20]; // Y stores ln(y)
    float sx = 0, sY = 0, sxy = 0, sx2 = 0;
    float A, b, a;

    printf("Enter number of data points: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter x[%d] and y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);

        // Transform y to Y = ln(y)
        Y[i] = log(y[i]);

        sx += x[i];
        sY += Y[i];
        sxy += x[i] * Y[i];
        sx2 += x[i] * x[i];
    }

    // Solve for linear form Y = A + bx using Least Squares
    b = (n * sxy - sx * sY) / (n * sx2 - sx * sx);
    A = (sY - b * sx) / n;

    // Transform back: a = exp(A)
    a = exp(A);

    printf("\nExponential fit equation: y = %.4f * e^(%.4fx)\n", a, b);
    getch();
    return 0;
}
