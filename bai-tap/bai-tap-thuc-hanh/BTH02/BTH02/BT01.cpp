/*
	Bài 01. Xây dựng các hàm đệ qui tính các biểu thức như sau:
			a. S1 = 1 + 2 + 3 + ⋯ + n (n là số nguyên dương)
			b. S2 = 1^2 + 2^2 + 3^2 + ⋯ + n^2 (n là số nguyên dương)
			c. S3 = 1 + 1/3 + 1/5 + ⋯ + 1/n (n là số nguyên dương và là số lẻ)
			d. S4 = 1! + 2! + 3! + ⋯ + n! (n là số nguyên dương)
*/

#include <iostream>
using namespace std;

int tinhGiaiThua(int n);
int tinhTongGiaiThua(int n);

int main()
{
	cout << tinhTongGiaiThua(4) << endl;
	return 0;
}

int tinhTongGiaiThua(int n)
{
	if (n == 1)
		return 1;
	return tinhGiaiThua(n) + tinhTongGiaiThua(n - 1);
}

int tinhGiaiThua(int n)
{
	int tich = 1;

	if (n == 0 || n == 1)
		return 1;

	for (int i = 2; i <= n; i++)
		tich = tich * i;

	return tich;
}