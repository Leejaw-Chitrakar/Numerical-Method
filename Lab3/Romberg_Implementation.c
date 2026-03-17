#include <conio.h>
#include <math.h>
#include <stdio.h>


float f(float x) { return x * x; }

int main() {
  float R[10][10], a, b, h, sum;
  int n, i, j, k;

  printf("--- Romberg Integration ---\n");
  printf("Integrating f(x) = x^2 from 0 to 1\n");

  a = 0; // Lower limit
  b = 1; // Upper limit
  n = 4; // Number of iterations
  h = b - a;

  // Step 1: Initial Trapezoidal estimate
  R[0][0] = (h / 2.0) * (f(a) + f(b));

  // Step 2: Fill the first column with refined Trapezoidal results
  for (i = 1; i < n; i++) {
    h = h / 2.0;
    sum = 0;
    // Calculate the sum of function values at new points
    for (k = 1; k <= pow(2, i) - 1; k += 2) {
      sum += f(a + k * h);
    }
    R[i][0] = 0.5 * R[i - 1][0] + sum * h;
  }

  // Step 3: Richardson Extrapolation to fill the rest of the table
  for (j = 1; j < n; j++) {
    for (i = j; i < n; i++) {
      R[i][j] = R[i][j - 1] + (R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j) - 1);
    }
  }

  // Output the Romberg Table
  printf("\nRomberg Table:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++) {
      printf("%f\t", R[i][j]);
    }
    printf("\n");
  }

  printf("\nThe final approximate value is: %f\n", R[n - 1][n - 1]);

  getch();
  return 0;
}