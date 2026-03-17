#include <stdio.h>
#include <conio.h>

// Using float for function evaluation
float f(float x) {
    return x * x; // Example: f(x) = x^2
}

int main() {
    float x, h, derivative;

    printf("Enter the point (x) at which to find the derivative: ");
    scanf("%f", &x);
    printf("Enter the small step size (h): ");
    scanf("%f", &h);

    // Calculating derivative using float precision
    derivative = (f(x + h) - f(x - h)) / (2 * h);

    printf("\nThe approximate derivative at x = %f is: %f\n", x, derivative);

    getch();
    return 0;
}
