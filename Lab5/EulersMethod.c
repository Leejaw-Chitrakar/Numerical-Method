#include <stdio.h>
#include <conio.h>

/* Define function f(x, y) = dy/dx */
float f(float x, float y) {
    return x + y; // Example: dy/dx = x + y
}

int main() {
    float x0, y0, xn, h, yn, slope;
    int i, n;

    printf("Enter Initial Condition (x0, y0): ");
    scanf("%f %f", &x0, &y0);
    printf("Enter calculation point xn: ");
    scanf("%f", &xn);
    printf("Enter number of steps: ");
    scanf("%d", &n);

    /* Calculating step size (h) */
    h = (xn - x0) / n;

    printf("\nx\ty\tslope\tyn\n");
    printf("------------------------------\n");
    for (i = 0; i < n; i++) {
        slope = f(x0, y0);
        yn = y0 + h * slope;
        printf("%0.4f\t%0.4f\t%0.4f\t%0.4f\n", x0, y0, slope, yn);
        y0 = yn;
        x0 = x0 + h;
    }

    printf("\nValue of y at x = %0.4f is %0.4f\n", xn, y0);

    getch();
    return 0;
}
