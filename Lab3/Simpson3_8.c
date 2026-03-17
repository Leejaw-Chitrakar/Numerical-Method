#include <stdio.h>
#include <conio.h>

double f(double x) {
    return x * x;
}

int main() {
    double a, b, h, sum = 0;
    int n, i;
    printf("Enter limits and segments (multiple of 3): ");
    scanf("%lf %lf %d", &a, &b, &n);
    h = (b - a) / n;
    sum = f(a) + f(b);
    for(i = 1; i < n; i++) {
        if(i % 3 == 0) sum += 2 * f(a + i * h);
        else sum += 3 * f(a + i * h);
    }
    printf("Result: %lf", (3 * h / 8) * sum);
    getch();
    return 0;
}
