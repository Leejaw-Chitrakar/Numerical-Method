#include <stdio.h>
#include <conio.h>

double f(double x) {
    return x * x; // Example: f(x) = x^2
}

int main() {
    double a, b, h, sum = 0;
    int n, i;
    printf("Enter lower limit, upper limit and even number of segments: ");
    scanf("%lf %lf %d", &a, &b, &n);
    h = (b - a) / n;
    sum = f(a) + f(b);
    for(i = 1; i < n; i++) {
        if(i % 2 == 0) sum += 2 * f(a + i * h);
        else sum += 4 * f(a + i * h);
    }
    printf("Result: %lf", (h / 3) * sum);
    getch();
    return 0;
}
