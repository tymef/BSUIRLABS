#include <iostream>
#include <cmath>
using namespace std;

void main() {
    double x = 0.1722;
    double y = 6.33;
    double z = 0.000325;

    double numerator = x + 3 * fabs(x - y) + pow(x, 2);
    double denominator = fabs(x - y) * z + pow(x, 2);

    double s = 5 * atan(x) - (1.0 / 4.0) * acos(x) * (numerator / denominator);

    cout << "s = " << s << endl;

}
