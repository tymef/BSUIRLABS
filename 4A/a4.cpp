#include <iostream>   
#include <cmath>      
#include <limits>    
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    const int n = 10;     
    double a[n];    

    cout << "Введите 10 действительных чисел:\n";

   
    for (int i = 1; i < n+1; i++) {
        while (true) {  
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
    }

    
    int minIndex = a[1], maxIndex = a[1];
    for (int i = 2; i < n+1; i++) {
        if (a[i] < minIndex) minIndex = a[i];
        if (a[i] > maxIndex) maxIndex = a[i];
    }
    int min, max;
    for (int i = 1; i < n+1; i++) {
        if (a[i] == minIndex)  min = i;
        if (a[i] == maxIndex)  max = i;
    }

    int  k = 0, h = 0;
    for (int i = 1; i < n+1; i++) {
        if (a[i] == minIndex) k = k + 1;
        if (a[i] == maxIndex) h = h + 1;
    }

   
    
    
    int between=abs(max - min) - 1;
    if (max == min) 
        cout << "\nМинимальный элемент = Максимальный элемент: " << minIndex << "\n";
    else {
            cout << "\nМинимальный элемент: " << minIndex << "\n";
        cout << "Максимальный элемент: " << maxIndex << "\n";
        cout << "Количество элементов между ними: " << between << "\n";
        if (k > 1) cout << "Количество минимальных элементов: " << k << "\n";
        if (h > 1) cout << "Количество максимальных элементов: " << h << endl;
    }
    return 0;
}
