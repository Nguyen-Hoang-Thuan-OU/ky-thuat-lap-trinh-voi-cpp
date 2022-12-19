/*
	Bài 03. Viết hàm đệ qui tính giá trị Fibonacci của một số nguyên không âm.
			Sau đó xây dựng chương trình để mô phỏng và kiểm tra hàm vừa xây dựng.
*/

#include <iostream>
using namespace std;

int tinhGiaTriFibonacci(int n);

int main()
{
	int n;

	cout << "Tinh gia tri Fibonacci cua mot so nguyen khong am\n";
	cout << endl;

	do {
		cout << "Nhap vao mot so nguyen (n > 0): ";
		cin >> n;
		cout << endl;

		if (n <= 0)
			cout << "Nhap sai, vui long nhap lai mot so nguyen (n > 0)!\n" << endl;
	} while (n <= 0);

	cout << "So Fibonacci thu " << n << " la: " << tinhGiaTriFibonacci(n) << endl;
	cout << endl;

	return 0;
}

// Hàm đệ qui tính giá trị Fibonacci của một số nguyên không âm
int tinhGiaTriFibonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return tinhGiaTriFibonacci(n - 1) + tinhGiaTriFibonacci(n - 2);
}