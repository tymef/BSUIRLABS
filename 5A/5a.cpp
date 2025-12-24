#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    const int n = 6;
    int a[n][n], k = 1;

     cout << "Введите элементы массива 5x5:\n";
    for (int i = 1; i < n ; i++) {
        for (int j = 1; j < n; j++) {
            while (true) {
                cout << "a[" << i << "][" << j << "] = ";
                cin >> a[i][j];
                if (cin.fail()) {
                    cout << "Ошибка ввода! Введите число заново.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    break;
                }
            }
        }

    }

    cout << "\nИсходный массив:\n";
    for (int i = 1; i < n ; i++) {
        for (int j = 1; j < n ; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nМинимальные элементы в каждой строке:\n";
    for (int  i = 1; i < n; i++) {
        int min = a[i][1];  
        for (int j = 1; j < n; j++) {
            if (a[i][j] < min)
                min = a[i][j];
        }
        cout << "Строка " << i << ": " << min << endl;
    }
    return 0;
}
