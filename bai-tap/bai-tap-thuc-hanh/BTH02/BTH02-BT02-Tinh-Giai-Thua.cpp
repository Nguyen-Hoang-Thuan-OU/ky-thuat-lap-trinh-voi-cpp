/*
	Bài 02. Viết hàm đệ qui tính giai thừa của một số nguyên không âm.
		Sau đó xây dựng chương trình để mô phỏng và kiểm tra hàm vừa xây dựng.
*/

#include <iostream>
using namespace std;

int tinhGiaiThua(int n);

int main()
{
	int n;

	cout << "Tinh giai thua cua mot so nguyen khong am\n";
	cout << endl;

	do {
		cout << "Nhap vao mot so nguyen (n > 0): ";
		cin >> n;
		cout << endl;

		if (n <= 0)
			cout << "Nhap sai, vui long nhap lai mot so nguyen (n > 0)!\n" << endl;
	} while (n <= 0);

	cout << n << "!: " << tinhGiaiThua(n) << endl;
	cout << endl;

	return 0;
}

// Hàm đệ quy tính giai thừa của một số nguyên không âm
int tinhGiaiThua(int n)
{
	if (n == 1)
		return 1;
	return n * tinhGiaiThua(n - 1);
}