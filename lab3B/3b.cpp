#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void main() {
    setlocale(LC_ALL, "ru");
    double a = 0.1, b = 1.0;
    int N = 120;               // количество членов ряда
    double h = (b - a) / 10.0; // шаг изменения x

    cout << fixed << setprecision(10);
    cout << "   x\t\t   y(x)\t\t\t   s(x)\n";
    cout << "-------------------------------------------------------------\n";

    for (double x = a; x <= b + 1e-9; x += h) {
        // Точное значение функции
        double y = exp(-2 * exp(x));

        // Разложение в ряд
        double s = 0.0;
        for (int n = 0; n <= N; n++) {
            s += pow(2, n) * pow(-exp(x), n) / tgamma(n + 1); // tgamma(n+1) = n!
        }

        cout << setw(8) << x << "\t" << setw(16) << y
            << "\t" << setw(16) << s << endl;
    }

  
}
