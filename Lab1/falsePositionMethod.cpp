#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>

#define f(x) sin(x)-x+2

using namespace std;

int main() {
    cout << fixed << setprecision(5);

    float a, b, c_prev = 0.0;
    float fa, fb, fc;
    float c = 0.0;
    float err = 0.00001;
    int max_iterations = 100;
    int count = 0;


    cout << "\nFalse Position Method (Regula Falsi)" << endl;
    cout << "Function: f(x) = sin(x) - x + 2" << endl;
    cout << "Error Tolerance (err): " << err << endl;

    cout << "\nEnter the initial guesses 'a' and 'b': ";
    if (!(cin >> a >> b)) {
        cerr << "Invalid input." << endl;
        return 1;
    }

    fa = f(a);
    fb = f(b);

    if ((fa * fb) >= 0) {
        cout << "\n❌ Incorrect initial guesses: f(a) and f(b) must have opposite signs." << endl;
        return 1;
    }

    cout << "\nIteration Details:" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    cout << "Iteration\t a\t \tb\t \tc (Root)\t f(c)\t\t|c - c_prev|" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;

    do {
        c_prev = c;

        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);

        count++;

        cout << count << "\t\t" << a << "\t\t" << b << "\t\t" << c << "\t\t" << fc << "\t\t" << fabs(c - c_prev) << endl;

        if ((fa * fc) < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }

    } while (fabs(c - c_prev) > err && count < max_iterations);

    cout << "-------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\n The approximate root is: " << c << endl;
    cout << " The value of f(root) is: " << fc << endl;
    cout << " Total number of iterations: " << count << endl;

    getch();
    return 0;
}