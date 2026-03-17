//Bisection Method

#include <iostream>
#include <conio.h>
#include <math.h>
#include <iomanip>

float f(float x){
    return x*(2*x - log10f(x) - 7);
}
using namespace std;

int main(){
    cout << fixed << setprecision(4);
    float x1,x2,x0,err=0.0001;
    float fx1,fx2,fx0;
    cout << "\nEnter the initisl guesses x1 and x2:";
    cin >> x1 >> x2 ;
    fx1=f(x1);
    fx2=f(x2);
    x0 = (x1 + x2) / 2; // initialize midpoint before use
    fx0=f(x0);
    int count = 1;
    if((fx1*fx2)<0){
        cout << "\n The calculation of root is as follows:\n\n";
        cout << setw(12) << "x1" << setw(12) << "x2" << setw(12) << "x0" << setw(12) << "fx1" << setw(12) << "fx2" << setw(12) << "fx0" << '\n';
        cout << setw(12) << x1  << setw(12) << x2  << setw(12) << x0  << setw(12) << fx1  << setw(12) << fx2  << setw(12) << fx0  << '\n';
        do{
            x0=(x1+x2)/2;
            fx0=f(x0);
            if((fx1*fx0)<0){
                x2=x0;
                fx2=f(x2);
            }
            else{
                x1=x0;
                fx1=f(x1);
            }
            cout << setw(12) << x1  << setw(12) << x2  << setw(12) << x0  << setw(12) << fx1  << setw(12) << fx2  << setw(12) << fx0  << '\n';
            count++;
        }while(fabs(fx0)>err);
        cout << "\n\n The root is: " << x0;
        cout << "\n Number of iterations: " << count;
    }
    else{
        cout << "\n Incorrect initial guesses.";
    }
    getch();
    return 0;
}