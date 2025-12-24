#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <stdio.h>
#include <cstring>
using namespace std;

struct Book {
    char title[100];
    char author[50];
    int year;
    int pages;
};

Book b;
Book* books = nullptr;
FILE* fl;
int n = 0;
char fname[50] = "";

// Прототипы функций
char* nnf();
void fadd();
void frd();
void rezc();
void rezf();
int menu();

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    while (true) {
        switch (menu()) {
        case 1: fadd(); break;
        case 2: frd(); break;
        case 3: rezc(); break;
        case 4: rezf(); break;
        case 5: return 0;
        default: cout << "Введите правильный выбор." << endl; break;
        }
        cout << "Нажмите Enter для продолжения...";
        while (cin.get() != '\n');
        cin.get();
        system("cls");

    }

}

// Меню
int menu() {
    cout << "Выберите: " << endl;
    cout << "1.Записать данные о книгах в файл." << endl;
    cout << "2.Прочитать данные из файла." << endl;
    cout << "3.Вывести книги с названием на 'А' на экран." << endl;
    cout << "4.Вывести книги с названием на 'А' в текстовый файл." << endl;
    cout << "5.Выход." << endl;
    int i;
    cin >> i;
    return i;
}

// Получение имени файла
char* nnf() {
    if (strlen(fname)) return fname;
    cout << "Введите имя файла: ";
    cin >> fname;
    return fname;
}

// Добавление данных в файл
void fadd() {
    if (fopen_s(&fl, nnf(), "ab") != 0)
        if (fopen_s(&fl, nnf(), "wb") != 0) {
            cout << "Ошибка при создании файла." << endl;
            return;
        }
    char ch;
    do {
        cin.ignore();
        cout << "Введите название книги: "; cin.getline(b.title, 100);
        cout << "Введите фамилию автора: "; cin.getline(b.author, 50);
        cout << "Введите год издания: "; cin >> b.year;
        cout << "Введите количество страниц: "; cin >> b.pages;
        fwrite(&b, sizeof(Book), 1, fl);
        cout << "Будете вводить ещё книги? (д/н): "; cin >> ch;
        ch = tolower((unsigned char)ch);
    } while (ch == 'д');
    fclose(fl);
}

// Чтение всех данных из файла
void frd() {
    if (fopen_s(&fl, nnf(), "rb") != 0) {
        cout << "Ошибка при открытии файла." << endl; return;
    }

    // Вычисляем количество записей через fseek/ftell
    fseek(fl, 0, SEEK_END);
    long size = ftell(fl);
    rewind(fl);
    n = size / sizeof(Book);

    books = new Book[n];
    fread(books, sizeof(Book), n, fl);

    cout << "\nСписок всех книг:\n";
    cout << setw(30) << "Название" << setw(20) << "Автор"
        << setw(10) << "Год" << setw(10) << "Страниц" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(30) << books[i].title << setw(20) << books[i].author
            << setw(10) << books[i].year << setw(10) << books[i].pages << endl;
    }

    delete[] books;
    fclose(fl);
}

// Вывод книг, название которых начинается на 'А', на экран
void rezc() {
    if (fopen_s(&fl, nnf(), "rb") != 0) {
        cout << "Ошибка при открытии файла." << endl; return;
    }

    // Количество записей
    fseek(fl, 0, SEEK_END);
    long size = ftell(fl);
    rewind(fl);
    n = size / sizeof(Book);

    bool found = false;
    cout << "\nКниги, название которых начинается на 'А':\n";
    for (int i = 0; i < n; i++) {
        fread(&b, sizeof(Book), 1, fl);
        if (b.title[0] == 'А' || b.title[0] == 'A') {
            cout << setw(30) << b.title << setw(20) << b.author
                << setw(10) << b.year << setw(10) << b.pages << endl;
            found = true;
        }
    }
    if (!found) cout << "Книг с названием на 'А' нет.\n";
    fclose(fl);
}

// Вывод книг, название которых начинается на 'А', в текстовый файл
void rezf() {
    char fnamet[50];
    FILE* ft;
    cout << "Введите имя текстового файла: "; cin >> fnamet;
    if (fopen_s(&ft, fnamet, "w") != 0) {
        cout << "Ошибка при создании текстового файла." << endl;
        return;
    }
    if (fopen_s(&fl, nnf(), "rb") != 0) {
        cout << "Ошибка при открытии бинарного файла." << endl;
        fclose(ft);
        return;
    }

    fseek(fl, 0, SEEK_END);
    long size = ftell(fl);
    rewind(fl);
    n = size / sizeof(Book);

    bool found = false;
    fprintf(ft, "%30s%20s%10s%10s\n", "Название", "Автор", "Год", "Страниц");
    for (int i = 0; i < n; i++) {
        fread(&b, sizeof(Book), 1, fl);
        if (b.title[0] == 'А' || b.title[0] == 'A') {
            fprintf(ft, "%30s%20s%10d%10d\n", b.title, b.author, b.year, b.pages);
            found = true;
        }
    }
    if (!found) fprintf(ft, "Книг с названием на 'А' нет.\n");

    fclose(ft);
    fclose(fl);
    cout << "Результат записан в файл: " << fnamet << endl;
}
