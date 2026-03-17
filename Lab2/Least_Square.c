#include <stdio.h>
#include <conio.h>

int main() {
    int n, i;
    float x[20], y[20], sx=0, sy=0, sxy=0, sx2=0, a, b;
    printf("Enter number of data points: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Enter x[%d] and y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
        sx += x[i]; sy += y[i];
        sxy += x[i]*y[i]; sx2 += x[i]*x[i];
    }
    b = (n*sxy - sx*sy)/(n*sx2 - sx*sx);
    a = (sy - b*sx)/n;
    printf("\nFitted line equation: y = %.4f + %.4fx\n", a, b);
    getch();
    return 0;
}
