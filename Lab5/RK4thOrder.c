#include <stdio.h>
#include <conio.h>

/* Define function f(x, y) = dy/dx */
float f(float x, float y) {
    return x + y; // Example: dy/dx = x + y
}

int main() {
    float x0, y0, xn, h, yn, k1, k2, k3, k4;
    int i, n;

    printf("Enter Initial Condition (x0, y0): ");
    scanf("%f %f", &x0, &y0);
    printf("Enter calculation point xn: ");
    scanf("%f", &xn);
    printf("Enter number of steps: ");
    scanf("%d", &n);

    /* Calculating step size (h) */
    h = (xn - x0) / n;

    printf("\nx\ty\tyn\n");
    printf("------------------------------\n");
    for (i = 0; i < n; i++) {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        k4 = h * f(x0 + h, y0 + k3);
        yn = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        printf("%0.4f\t%0.4f\t%0.4f\n", x0, y0, yn);
        x0 = x0 + h;
        y0 = yn;
    }

    printf("\nValue of y at x = %0.4f is %0.4f\n", xn, y0);

    getch();
    return 0;
}
