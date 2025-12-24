#include <iostream>
#include <cmath> // для sin, sinh, exp, pow, fabs, cbrt
using namespace std;

void main() {
    setlocale(LC_ALL, "ru");
    double x, y;
    int choice;
    double f, s;

    cout << "Введите x и y: ";
    cin >> x >> y;

    cout << "Выберите вид функции f(x):\n";
    cout << "1 - sh(x)\n";
    cout << "2 - x^2\n";
    cout << "3 - e^x\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    // Определяем f(x) в зависимости от выбора пользователя
    switch (choice) {
    case 1: f = sinh(x); break;
    case 2: f = pow(x, 2); break;
    case 3: f = exp(x); break;
    default:
        cout << "Неверный выбор функции!" << endl;
        
    }

    // Основные условия
    if (x + fabs(y) == 0) {
        s = pow(sin(x), 2) - f;
        cout << "Выполнено условие x + |y| = 0" << endl;
    }
    else if (x + fabs(y) < 0) {
        s = cbrt(fabs(x * y));
        cout << "Выполнено условие x + |y| < 0" << endl;
    }
    else {
        s = 3 * pow(f, 2);
        cout << "Выполнено условие иначе (x + |y| > 0)" << endl;
    }

    cout << "Результат: s = " << s << endl;

  
}
