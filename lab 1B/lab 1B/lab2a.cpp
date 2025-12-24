#include <iostream>
#include <cmath> 
using namespace std;

void main() {
    setlocale(LC_ALL, "ru");
    double a, b, c;
    cout << "¬ведите три действительных числа: ";
    cin >> a >> b >> c;
    a = pow(a, 3);
    b = pow(b, 3);
    c = pow(c, 3);
    cout << "ќтрицательные числа после возведени€ в куб:" << endl;
    if (a < 0) cout << "a^3 = " << a << endl;
    if (b < 0) cout << "b^3 = " << b << endl;
    if (c < 0) cout << "c^3 = " << c << endl;


}
