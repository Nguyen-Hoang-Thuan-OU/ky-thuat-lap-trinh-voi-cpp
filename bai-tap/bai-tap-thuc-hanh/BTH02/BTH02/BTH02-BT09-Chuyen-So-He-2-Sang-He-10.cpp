/*
	Bài 09. Viết hàm đệ qui chuyển một số nguyên ở dạng nhị phân sang hệ thập phân.
*/

// Lỗi nếu n > 0011 1111 1111 = 1023

#include <iostream>
using namespace std;

int tinhSoMu(int y);
int chuyenNhiPhanSangThapPhan(int n, int soMu);

int main()
{
	int n;

	cout << "Chuyen so nhi phan sang thap phan\n";
	cout << endl;

	do {
		cout << "Nhap vao mot so nhi phan (n > 0): ";
		cin >> n;
		cout << endl;

		if (n <= 0)
			cout << "Nhap sai, vui long nhap lai mot so nhi phan (n > 0)!\n" << endl;
	} while (n <= 0);

	cout << "So thap phan cua " << n << " la: " << chuyenNhiPhanSangThapPhan(n, 0) << endl;
	cout << endl;

	return 0;
}

// 01. Hàm đệ qui chuyển một số nguyên ở dạng nhị phân sang hệ thập phân
int chuyenNhiPhanSangThapPhan(int n, int soMu)
{
	if (n == 0)
		return 0;
	else
		return n % 10 * tinhSoMu(soMu) + chuyenNhiPhanSangThapPhan(n / 10, soMu + 1);
}

// 02. Hàm tính sổ mũ
int tinhSoMu(int y)
{
	if (y == 0)
		return 1;
	else
		return 2 * tinhSoMu(y - 1);
}