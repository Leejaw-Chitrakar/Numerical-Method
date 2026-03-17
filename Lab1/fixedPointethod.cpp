
#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>

using namespace std;


#define f(x) (x*x + x - 2)
#define g(x) (2/(x+1))

int main() {
	cout << fixed << setprecision(5);
    
	float x0, x1;
	float tol = 1e-2;
	int max_iter = 100;

	cout << "Fixed Point Iteration (solve x^2 + x - 2 = 0)" << endl;
	cout << "Enter initial guess: ";
	if (!(cin >> x0)) {
		cerr << "Invalid input." << endl;
		return 1;
	}

	cout << "\nIter" << setw(14) << "x0" << setw(14) << "x1" << setw(14) << "f(x1)" << setw(14) << "|x1-x0|" << endl;
	cout << "----------------------------------------------------------" << endl;

	int iter = 0;
	float diff = 0.0;

	do {
		x1 = g(x0);
		diff = fabs(x1 - x0);

		cout << setw(4) << (iter+1) << setw(14) << x0 << setw(14) << x1 << setw(14) << f(x1) << setw(14) << diff << endl;

		x0 = x1;
		iter++;

		if (diff < tol) break;
	} while (iter < max_iter);

	cout << "----------------------------------------------------------" << endl;
	cout << "Approximate root: " << x1 << endl;
	cout << "f(root) = " << f(x1) << endl;
	cout << "Iterations: " << iter << endl;

    getch();
	return 0;
}

