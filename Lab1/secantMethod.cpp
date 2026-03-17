#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cmath>

#define f(x) (x*x - 4*x - 10)

using namespace std;

int main() {
    cout << fixed << setprecision(5);

    float x0, x1;
    float tol = 1e-5;
    int max_iter = 100;

    cout << "Secant Method for f(x) = x^2 - 4x - 10" << endl;
    cout << "Enter two initial guesses x0 and x1: ";
    if (!(cin >> x0 >> x1)) {
        cerr << "Invalid input." << endl;
        return 1;
    }

    float f0 = f(x0);
    float f1 = f(x1);
    float x2;
    int iter = 0;

    cout << "Iter\t x0\t\t x1\t\t f(x1)\t\t |x1 - x0|" << endl;
    cout << "---------------------------------------------------------------" << endl;

    while (iter < max_iter) {
        if (fabs(f1 - f0) < 1e-12) {
            cerr << "Denominator too small. Method fails or stagnates." << endl;
            return 1;
        }

        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

        cout << (iter+1) << "\t " << x0 << "\t " << x1 << "\t " << f1 << "\t " << fabs(x1 - x0) << endl;

        if (fabs(x2 - x1) < tol) {
            x1 = x2;
            break;
        }

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f(x1);
        iter++;
    }

    cout << "---------------------------------------------------------------" << endl;
    cout << "Approximate root: " << x1 << endl;
    cout << "Iterations: " << (iter+1) << endl;

    getch();
    return 0;
}
