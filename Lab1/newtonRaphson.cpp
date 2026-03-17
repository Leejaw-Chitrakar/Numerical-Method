#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>

#define f(x) (x*x + 2*x - 2)
#define df(x) (2*x + 2)

using namespace std;

int main()
{
    cout << fixed << setprecision(5);

    float x0, x1;
    float fx, dfx;
    float err = 0.00001;
    int count = 0, max_iter = 100;

    cout << "\nNewton-Raphson Method\n";
    cout << "Function: f(x) = x^2 + 2x - 2\n";
    cout << "Derivative: f'(x) = 2x + 2\n";
    cout << "Error tolerance: " << err << endl;

    cout << "\nEnter initial guess: ";
    cin >> x0;

    cout << "\n--------------------------------------------------------------------------\n";
    cout << setw(3) << "Iter" << setw(11) << "x0" << setw(15) << "x1" << setw(15) << "f(x0)" << setw(15) << "|x1-x0|\n";
    cout << "--------------------------------------------------------------------------\n";

    do
    {
        fx = f(x0);
        dfx = df(x0);

        if (fabs(dfx) < 1e-6)
        {
            cout << "\nDerivative too small. Method fails.\n";
            return 0;
        }

        x1 = x0 - fx / dfx;
        count++;

        cout << setw(3)  << count
             << setw(15) << x0
             << setw(15) << x1
             << setw(15) << fx
             << setw(15) << fabs(x1 - x0) << endl;

        x0 = x1;

    } while (fabs(fx) > err && count < max_iter);

    cout << "--------------------------------------------------------------------------\n";
    cout << "\nApproximate root = " << x1 << endl;
    cout << "Total iterations = " << count << endl;

    getch();
    return 0;
}
