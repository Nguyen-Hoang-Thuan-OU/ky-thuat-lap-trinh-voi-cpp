/*
	Bài 04: Viết hàm đệ qui để chuyển 1 số nguyên dương
		từ hệ thập phân sang nhị phân.
		Sau đó viết chương trình để kiểm tra hàm vừa viết.
*/

// Lỗi đổi số > 1023

#include <iostream>
using namespace std;

int chuyenThapPhanSangNhiPhan(int n);

int main()
{
	int n;

	cout << "Vui long nhap (n > 0): ";
	cin >> n;
	do
	{
		if (n < 1)
		{
			cout << "Nhap sai, vui long nhap (n > 0): ";
			cin >> n;
			cout << endl;
		}
	} while(n < 1);

	cout << "So nhi phan cua " << n << " la: " << chuyenThapPhanSangNhiPhan(n) << endl;

	return 0;
}

int chuyenThapPhanSangNhiPhan(int n)
{
	if (n == 0)
		return 0;
	else
		return n % 2 + chuyenThapPhanSangNhiPhan(n / 2) * 10;
}