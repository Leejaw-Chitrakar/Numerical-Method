#include <stdio.h>
#include <conio.h>
#include <math.h>

/* Equation: a1x + b1y + c1z = d1
            a2x + b2y + c2z = d2
            a3x + b3y + c3z = d3
*/

#define f1(x, y, z, a, b, c, d)  ((d - b * y - c * z) / a)
#define f2(x, y, z, a, b, c, d)  ((d - a * x - c * z) / b)
#define f3(x, y, z, a, b, c, d)  ((d - a * x - b * y) / c)

int main() {
    float a1, b1, c1, d1;
    float a2, b2, c2, d2;
    float a3, b3, c3, d3;
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;
    int count = 1;

    printf("Enter coefficients for Eq 1 (a1 b1 c1 d1): ");
    scanf("%f %f %f %f", &a1, &b1, &c1, &d1);
    printf("Enter coefficients for Eq 2 (a2 b2 c2 d2): ");
    scanf("%f %f %f %f", &a2, &b2, &c2, &d2);
    printf("Enter coefficients for Eq 3 (a3 b3 c3 d3): ");
    scanf("%f %f %f %f", &a3, &b3, &c3, &d3);

    printf("Enter tolerable error: ");
    scanf("%f", &e);

    printf("\nCount\tx\ty\tz\n");
    do {
        /* Calculation */
        x1 = f1(x0, y0, z0, a1, b1, c1, d1);
        y1 = f2(x0, y0, z0, a2, b2, c2, d2);
        z1 = f3(x0, y0, z0, a3, b3, c3, d3);
        printf("%d\t%0.4f\t%0.4f\t%0.4f\n", count, x1, y1, z1);

        /* Error */
        e1 = fabsf(x0 - x1);
        e2 = fabsf(y0 - y1);
        e3 = fabsf(z0 - z1);

        count++;

        /* Set value for next iteration */
        x0 = x1;
        y0 = y1;
        z0 = z1;

    } while (e1 > e && e2 > e && e3 > e);

    printf("\nSolution: x = %0.3f, y = %0.3f, z = %0.3f\n", x1, y1, z1);

    getch();
    return 0;
}
