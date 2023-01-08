#include<iostream>
using namespace std;

int main()
{
	// Khai báo 2 biến x, y

	int x, y;

	// Khai báo con trỏ p

	int *p;

	// Cho con trỏ p trỏ đến x

	p = &x;

	// Con trỏ p nhận giá trị lưu trữ là 80

	*p = 80;

	// Xuất giá trị, địa chỉ của biến x

	cout << "Gia tri cua bien x: " << x << endl;
	cout << "Dia chi cua bien x: " << &x << endl;

	// Xuất giá trị của biến mà p trỏ đến, địa chỉ của biến p và địa chỉ của x lưu trong con trỏ p 

	cout << "Gia tri cua bien p: " << *p << endl;
	cout << "Dia chi cua bien p: " << &p << endl;
	cout << "Mien gia tri cua p (dia chi cua bien x): " << p << endl;

	return 0;
}