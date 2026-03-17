#include <stdio.h>
#include <conio.h>
#include <math.h>

// Define the function to integrate
double f(double x) {
    return x * x; // Example: f(x) = x^2
}

int main() {
    double a, b, h, sum = 0;
    int n, i;

    printf("Enter lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter upper limit (b): ");
    scanf("%lf", &b);
    printf("Enter number of segments (n): ");
    scanf("%d", &n);

    h = (b - a) / n;
    sum = f(a) + f(b);

    for (i = 1; i < n; i++) {
        sum += 2 * f(a + i * h);
    }

    sum = (h / 2) * sum;

    printf("\nResult of integration: %lf", sum);

    getch();
    return 0;
}
