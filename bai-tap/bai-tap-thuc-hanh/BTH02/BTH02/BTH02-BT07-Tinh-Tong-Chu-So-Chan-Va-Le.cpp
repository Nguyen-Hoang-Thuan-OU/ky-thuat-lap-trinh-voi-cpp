/*
	Bài 07. Viết hàm đệ qui tính tổng các chữ số chẵn/lẻ của một số nguyên không âm.
			Sau đó xây dựng chương trình để mô phỏng và kiểm tra hàm vừa xây dựng.
*/

#include <iostream>
using namespace std;

int tongChuSoChan(int n);
int tongChuSoLe(int n);

int main()
{
	int n;
	int soDaoNguoc = 0;

	cout << "Tinh tong cac chu so chan / le\n";
	cout << endl;

	do {
		cout << "Nhap vao mot so nguyen (n > 0): ";
		cin >> n;
		cout << endl;

		if (n <= 0)
			cout << "Nhap sai, vui long nhap lai mot so nguyen (n > 0)!\n" << endl;
	} while (n <= 0);

	cout << "Tong chu so chan cua " << n << " la: " << tongChuSoChan(n) << endl;
	cout << "Tong chu so le cua " << n << " la: " << tongChuSoLe(n) << endl;
	cout << endl;

	return 0;
}

// 01. Hàm đệ qui tính tổng các chữ số chẵn
int tongChuSoChan(int n)
{
	if (n == 0)
		return 0;
	if (n % 10 % 2 == 0)
		return n % 10 + tongChuSoChan(n / 10);
	return tongChuSoChan(n / 10);
}

// 02. Hàm đệ qui tính tổng các chữ số lẻ
int tongChuSoLe(int n)
{
	if (n == 0)
		return 0;
	if (n % 10 % 2 != 0)
		return n % 10 + tongChuSoLe(n / 10); 
	return tongChuSoLe(n / 10);
}