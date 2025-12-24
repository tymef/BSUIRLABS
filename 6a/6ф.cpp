#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double y(double x, int n);

int main() {
  setlocale(LC_ALL, "ru");
    double a = 0.34;
    double b = 1.1;
    int n = 8;

    double h = (b - a) / 10.0;

    cout << fixed << setprecision(6);
    cout << "   x\t\t y(x, n)\n";
    cout << "-------------------------------\n";

    for (double x = a; x <= b + 1e-12; x += h) {
        double result = y(x, n);
        cout << x << "\t " << result << endl;
    }

    return 0;
}


double y(double x, int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 2 * log(i * x) - pow(sin(x), 2 * i);
    }
    return sum;
}
