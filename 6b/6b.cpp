#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Функция s(x)
double s(double, int);
double s(double x, int N) {
    long double sum = 0.0;
    long double sinx = sin(x);

    for (int n = 0; n <= N; n++) {
        long double fact = 1.0;
        for (int k = 1; k <= 2 * n; k++)
            fact *= k;

        long double term = ((n % 2 == 0) ? 1.0 : -1.0) * pow(sinx, 2 * n) / fact;
        sum += term;
    }
    return (double)sum;
}
double y(double);
// Функция y(x) = cos(sin(x))
  double y(double x) {
        long double sinx = sin(x);
        return cos(sinx);
    }

int main() {
    setlocale(LC_ALL, "ru");

    double a = -0.5;
    double b = 0.5;
    int N = 10000;
    double h = (b - a) / 10.0;

    cout << fixed << setprecision(10);
    cout << "       x\t\t y(x)\t\t s(x)\n";
    cout << "------------------------------------------------------\n";

    for (double x = a; x <= b + 1e-12; x += h) {
        double valS = s(x, N);
        double valY = y(x);

        cout << setw(10) << x << "\t "
            << setw(12) << valY << "\t "
            << setw(12) << valS << endl;
    }

  

    return 0;
}

