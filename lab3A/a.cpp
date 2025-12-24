#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void main() {
    setlocale(LC_ALL, "ru");
    double a, b, h, x, y;
    int n;

    cout << "¬ведите a: ";
    cin >> a;
    cout << "¬ведите b: ";
    cin >> b;
    cout << "¬ведите n: ";
    cin >> n;


    h = (b - a) / 10.0;

    cout << fixed << setprecision(6);
    cout << "\n   x\t\t   y(x)\n";
    cout << "--------------------------\n";

    for (x = a; x <= b + 1e-9; x += h) {
        y = 0;
        for (int i = 1; i <= n; i++) {
            y += 2 * cos(i * x) * cosh(x);
        }
        cout << setw(8) << x << "\t" << setw(12) << y << endl;
    }

  
}
