#include <stdio.h>
#include <conio.h>

int main() {
    int n, i, j;
    float x[20], y[20][20], xp, yp, p;
    printf("Enter number of data points: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Enter x[%d] and y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[0][i]);
    }
    printf("Enter interpolation point (xp): ");
    scanf("%f", &xp);

    for(j=1; j<n; j++)
        for(i=0; i<n-j; i++)
            y[j][i] = (y[j-1][i+1]-y[j-1][i])/(x[i+j]-x[i]);

    yp = y[0][0]; p = 1;
    for(i=1; i<n; i++) {
        p *= (xp - x[i-1]);
        yp += p * y[i][0];
    }
    printf("\nInterpolated value at %.3f is: %.4f\n", xp, yp);
    getch();
    return 0;
}
