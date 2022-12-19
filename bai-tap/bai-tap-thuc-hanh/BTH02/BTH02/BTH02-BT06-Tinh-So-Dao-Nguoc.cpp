/*
	Bài 06. Viết hàm đệ qui tính số đảo ngược của một số nguyên không âm.
			Sau đó xây dựng chương trình để mô phỏng và kiểm tra hàm vừa xây dựng.
*/

#include <iostream>
using namespace std;

int tinhSoDaoNguoc(int n, int soDaoNguoc);

int main()
{
	int n;
	int soDaoNguoc = 0;

	cout << "Tinh so dao nguoc\n";
	cout << endl;

	do {
		cout << "Nhap vao mot so nguyen (n > 0): ";
		cin >> n;
		cout << endl;

		if (n <= 0)
			cout << "Nhap sai, vui long nhap lai mot so nguyen (n > 0)!\n" << endl;
	} while (n <= 0);

	cout << "So dao nguoc cua " << n << " la: " << tinhSoDaoNguoc(n, soDaoNguoc) << endl;
	cout << endl;

	return 0;
}

// Hàm đệ qui tính số đảo ngược của một số nguyên không âm
int tinhSoDaoNguoc(int n, int soDaoNguoc)
{
	if (n == 0)
		return soDaoNguoc;
	soDaoNguoc = soDaoNguoc * 10 + n % 10;
	return tinhSoDaoNguoc(n / 10, soDaoNguoc);
}