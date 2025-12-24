#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int n,b,c;
    cout << "Введите размер массива: ";
    cin >> n;

    double*a = new double[n]; // создаём массив размера n

    cout << "Введите " << n << " элементов массива:\n";
    for (int i = 0; i < n; i++)  while (true) {  
            cout << "a[" << i << "] = ";  
            cin >> a[i];                   

            if (cin.fail()) { 
                cout << "Ошибка ввода! Введите число заново.\n";
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
            else {
                break; 
            }
        }


    cout << "Вы ввели:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << " \n";
    
    int minIndex = a[0], min, max, maxIndex = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < minIndex) minIndex = a[i], min = i ;
        if (a[i] > maxIndex) maxIndex = a[i], max = i;
    }

    b = a[0];
    c = a[n-1];
    a[max] = b;
    a[min] = c;  
    a[0] = maxIndex;
    a[n-1] = minIndex;

    cout << "Новый массив:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    delete[] a;
    
    return 0;
}
