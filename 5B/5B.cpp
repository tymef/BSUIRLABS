#include <iostream>
#include <cstdlib>   // для rand(), srand()
#include <ctime>     // для time()
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int N, M;
    cout << "Введите количество строк N: ";
    cin >> N;
    cout << "Введите количество столбцов M: ";
    cin >> M;

    // динамическое создание матрицы
    int** a = new int* [N];
    for (int i = 0; i < N; i++) {
        a[i] = new int[M];
    }

    // выбор способа заполнения
     int mode;
    cout << "\nВыберите способ заполнения матрицы:\n";
    cout << "1 — Ввести вручную\n";
    cout << "2 — Заполнить случайными числами\n";
    cout << "Ваш выбор: ";
    cin >> mode;

    if (mode == 1) {
        // ручной ввод
         int N, M;
    cout << "Введите количество строк N: ";
    cin >> N;
    cout << "Введите количество столбцов M: ";
    cin >> M;

    // динамическое создание матрицы
    int** a = new int* [N];
    for (int i = 0; i < N; i++) {
        a[i] = new int[M];
    }
        cout << "\nВведите элементы матрицы (" << N << " x " << M << "):\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
                cin >> a[i][j];
            }
        }
    }
    else if (mode == 2) {
        // случайное заполнение
        srand(time(0)); // инициализация генератора случайных чисел
        int minVal, maxVal;
        cout << "\nВведите диапазон случайных чисел (например, 0 100): ";
        cin >> minVal >> maxVal;

        cout << "\nМатрица заполнена случайными числами:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                a[i][j] = minVal + rand() % (maxVal - minVal + 1);
            }
        }
    }
    else {
        cout << "Неверный выбор. Завершение программы.\n";
        return 0;
    }

    // вывод исходной матрицы
    cout << "\nИсходная матрица:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    // массив сумм строк
    int* sum = new int[N];
    for (int i = 0; i < N; i++) {
        sum[i] = 0;
        for (int j = 0; j < M; j++) {
            sum[i] += a[i][j];
        }
    }

    // сортировка строк по возрастанию суммы элементов
    for (int i = 0; i < N - 1; i++) {
        for (int k = i + 1; k < N; k++) {
            if (sum[i] > sum[k]) {
                // меняем строки местами
                for (int j = 0; j < M; j++) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
                // меняем суммы
                int t = sum[i];
                sum[i] = sum[k];
                sum[k] = t;
            }
        }
    }

    cout << "\nМатрица после сортировки строк по возрастанию суммы элементов:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    // освобождение памяти
    for (int i = 0; i < N; i++) {
        delete[] a[i];
    }
    delete[] a;
    delete[] sum;

    return 0;
}
