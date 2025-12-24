#include <iostream>
#include <string>
using namespace std;


int main() {
    setlocale(LC_ALL, "ru");
   string s;
   while (true) {
       cout << "Введите строку из 0 и 1: ";
       cin >> s;
       bool error = false;
       for (int i = 0; i < s.size(); ++i) {
           if (s[i] != '0' && s[i] != '1')
           {
               cout << "Заново ";
               error = true;
               break;
           }
       }
       if (!error) {
           break;
       }
   }
        
    int count = 0;

    for ( int i = 0; i + 4 < s.size(); ++i) {
        if (s[i] == '1' &&
            s[i + 1] == '1' &&
            s[i + 2] == '1' &&
            s[i + 3] == '1' &&
            s[i + 4] == '1')
        {
            count++;
            i = i + 4;
        }
    }

    cout << "Количество групп из пяти единиц: " << count << endl;
}
