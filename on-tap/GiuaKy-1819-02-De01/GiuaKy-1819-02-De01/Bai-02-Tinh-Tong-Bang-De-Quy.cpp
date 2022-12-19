/*
	CÂU 02. Xây dựng 1 chương trình gồm các hàm sau:
			- Hàm đệ qui tính S = 1/2! + 1/3! + ... + 1/n!
			  (n là số nguyên dương lớn hơn 1)
			- Hàm main để kiếm chứng toàn bộ chương trình.
*/

#include <iostream>
using namespace std;

int tinhGiaiThua(int n);
double tinhTongS(int n);

int main()
{
	int n;
	cout << "Nhap so nguyen duong (n > 1): ";
	cin >> n;
	cout << endl;

	do {
		if (n <= 1)
		{
			cout << "Nhap so nguyen duong lon hon 1 (n > 1). Nhap lai: ";
			cin >> n;
			cout << endl;
		}
	} while(n <= 1);

	cout << "Tong chuoi la: " << tinhTongS(n) << endl;

	return 0;
}

// 01. Hàm tính giai thừa
int tinhGiaiThua(int n)
{
	if (n == 2)
		return 2;
	return n * tinhGiaiThua(n - 1);
}

// 02. Hàm tính tổng
double tinhTongS(int n)
{
	if (n == 2)
		return 1.0 / tinhGiaiThua(2);
	else
		return tinhTongS(n - 1) + (1.0 / tinhGiaiThua(n));
}