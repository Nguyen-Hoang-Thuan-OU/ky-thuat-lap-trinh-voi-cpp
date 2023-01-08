/*
	Bài 01: Viết hàm đệ qui để tính tổng S = 1^2 + 2^2 + ... + n^2
		với n là số nguyên dương.
		Sau đó viết chương trình để kiểm tra hàm vừa viết.
*/

#include <iostream>
using namespace std;

int tinhTongCacSoBinhPhuong(int n);

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

	cout << "Tong la: " << tinhTongCacSoBinhPhuong(n) << endl;

	return 0;
}

int tinhTongCacSoBinhPhuong(int n)
{
	if (n == 1)
		return 1;
	else
		return tinhTongCacSoBinhPhuong(n - 1) + n * n;
}