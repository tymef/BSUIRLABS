#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	double a,b;
	cout << "Введите кол-во унций: ";
	cin >> a;
	b = a*28.35 ;
	cout << "Кол-во граммов равно: " << b << endl;
}