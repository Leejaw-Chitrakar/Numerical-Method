#include <stdio.h>
#include <conio.h>

int main() {
    int n, i, j;
    float x[20], y[20], xp, yp = 0, p;
    printf("Enter number of data points: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Enter x[%d] and y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }
    printf("Enter interpolation point (xp): ");
    scanf("%f", &xp);

    for(i=0; i<n; i++) {
        p = 1;
        for(j=0; j<n; j++) {
            if(i != j) p *= (xp - x[j])/(x[i] - x[j]);
        }
        yp += p * y[i];
    }
    printf("\nInterpolated value at %.3f is: %.4f\n", xp, yp);
    getch();
    return 0;
}
