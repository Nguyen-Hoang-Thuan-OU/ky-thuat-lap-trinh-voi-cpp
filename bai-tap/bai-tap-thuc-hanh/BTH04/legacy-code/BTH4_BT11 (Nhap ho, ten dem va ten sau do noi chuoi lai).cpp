#include<iostream>
#include<string>
using namespace std;

int main()
{
	string ho;
	string tenDem;
	string ten;

	cout << "Nhap ho: ";
	getline(cin, ho);
	cout << "Nhap ten dem: ";
	getline(cin, tenDem);
	cout << "Nhap ten: ";
	getline(cin, ten);

	cout << "Ten day du cua ban la: " << ho + " " + tenDem + " " + ten << endl;
}