#include <iostream>
#include <string>
using namespace std;


int main() {
    setlocale(LC_ALL, "ru");
    string s;
    cout << "¬ведите строку: ";
    getline(cin, s);

    char n = '*';

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            s[i] = n;
        }
    }

    cout << "–езультат: " << s << endl;
    return 0;
}
