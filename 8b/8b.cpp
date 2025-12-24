#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Структура для хранения информации о товаре
struct books {
    string book;
    string name;
    int quantity;
    int year;
};
int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите количество книг: ";
    cin >> n;

    // динамическое выделение памяти под массив книг
    books* bookss = new books[n];

    // ввод данных
    for (int i = 0; i < n; i++) {
        cout << "\nКнига " << i + 1 << ":\n";
        cout << "Наименование: ";
        cin >> bookss[i].book;
        cout << "Автор: ";
        cin >> bookss[i].name;
        cout << "Количесво страниц: ";
        cin >> bookss[i].quantity;
        cout << "Год: ";
        cin >> bookss[i].year;
    }

    sort (bookss, bookss + n, [](const books& a, const books& b) {
        return a.book < b.book;
        });
    cout << "\nКниги:\n";
    for (int i = 0; i < n; i++) {
        if (bookss[i].year < 1900) {
            cout << " Наименование: " << bookss[i].book
                << ", Автор " << bookss[i].name
                << ", Количество страниц: " << bookss[i].quantity
                << ", Год: " << bookss[i].year << endl;
        }
    }

    // освобождение памяти
    delete[] bookss;

    return 0;
}
