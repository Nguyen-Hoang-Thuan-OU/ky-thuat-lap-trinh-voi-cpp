/*
	Bài 08. Viết hàm đệ qui chuyển một số nguyên dương từ hệ thập phân sang nhị phân.
			Sau đó xây dựng chương trình để mô phỏng và kiểm tra hàm vừa xây dựng.
*/

// Lỗi đổi số > 95

#include <iostream>
using namespace std;

int chuyenThapPhanSangNhiPhan(int n);

int main()
{
	int n;

	cout << "Chuyen so thap phan sang nhi phan\n";
	cout << endl;

	do {
		cout << "Nhap vao mot so thap phan (n > 0): ";
		cin >> n;
		cout << endl;

		if (n <= 0)
			cout << "Nhap sai, vui long nhap lai mot so thap phan (n > 0)!\n" << endl;
	} while (n <= 0);

	cout << "So nhi phan cua " << n << " la: " << chuyenThapPhanSangNhiPhan(n) << endl;
	cout << endl;

	return 0;
}

// Hàm đệ qui chuyển một số nguyên dương từ hệ thập phân sang nhị phân
int chuyenThapPhanSangNhiPhan(int n)
{
	if (n == 2)
		return 0;
	else
		return n % 2 + chuyenThapPhanSangNhiPhan(n / 2) * 10;
}