#include <stdio.h>
#include <conio.h>
#include <math.h>

/* 
   Picard's Method for solving dy/dx = f(x, y) 
   Example: dy/dx = x + y, with y(0) = 1
   y1 = y0 + integral(x0 to x) (x + y0) dx
   y2 = y0 + integral(x0 to x) (x + y1) dx
   ...
*/

double f1(double x) { return 1 + x + (x * x) / 2.0; } // First iteration for y' = x + y, y(0)=1
double f2(double x) { return 1 + x + x * x + (x * x * x) / 6.0; } // Second iteration
double f3(double x) { return 1 + x + x * x + (x * x * x) / 3.0 + (x * x * x * x) / 24.0; } // Third iteration

int main() {
    double x;

    printf("Picard's Method for dy/dx = x + y, y(0) = 1\n");
    printf("Enter the value of x at which y is to be calculated: ");
    scanf("%lf", &x);

    printf("\nAt x = %0.3f:\n", x);
    printf("y(1) = %0.4f\n", f1(x));
    printf("y(2) = %0.4f\n", f2(x));
    printf("y(3) = %0.4f\n", f3(x));

    getch();
    return 0;
}
