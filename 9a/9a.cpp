#include <stdio.h>
#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    FILE* fl;
    const int D = 10;
    double a[D], b[D];
    int i;
    bool th;

    // Генерация 10 уникальных чисел от 0 до 100
    srand((unsigned)time(NULL));
    for (i = 0; i < D;) {
        th = false;
        double nw = (double)rand() / RAND_MAX * 100;
        // Проверяем, нет ли повторов
        for (int j = 0; j < i; j++) {
            if (a[j] == nw) {
                th = true;
                break;
            }
        }
        if (!th) {
            a[i] = nw;
            i++;
        }
    }

    // Создание бинарного файла
    fopen_s(&fl, "mass2.dat", "wb");
    if (fl == NULL) {
        cout << "Ошибка при создании бинарного файла." << endl;
        return 1;
    }
    fwrite(a, sizeof(double), D, fl);
    fclose(fl);

    // Чтение данных из бинарного файла
    fopen_s(&fl, "mass2.dat", "rb");
    if (fl == NULL) {
        cout << "Ошибка при открытии бинарного файла." << endl;
        return 1;
    }
    fread(b, sizeof(double), D, fl);
    fclose(fl);

    // Вычисление среднего значения
    double sum = 0;
    for (i = 0; i < D; i++) sum += b[i];
    double avg = sum / D;

    // Подсчёт чисел больше среднего
    int count = 0;
    for (i = 0; i < D; i++) {
        if (b[i] > avg) count++;
    }

    // Вывод на экран
    cout << "Массив чисел: ";
    for (i = 0; i < D; i++) cout << b[i] << " ";
    cout << endl;
    cout << "Среднее значение: " << avg << endl;
    cout << "Количество чисел больше среднего: " << count << endl;

    // Запись результата в текстовый файл
    FILE* flt;
    fopen_s(&flt, "res.txt", "w");
    if (flt == NULL) {
        cout << "Ошибка при создании текстового файла." << endl;
        return 1;
    }

    fprintf(flt, "Массив чисел: ");
    for (i = 0; i < D; i++) fprintf(flt, "%lf ", b[i]);
    fprintf(flt, "\nСреднее значение: %lf\n", avg);
    fprintf(flt, "Количество чисел больше среднего: %d\n", count);

    fclose(flt);
   


    return 0;
}
