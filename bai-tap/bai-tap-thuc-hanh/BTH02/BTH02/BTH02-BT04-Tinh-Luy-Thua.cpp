/*
	Bài 04. Viết hàm đệ qui tính giá trị của x^n ; với x, n là số nguyên.
			Sau đó xây dựng chương trình để mô phỏng và kiểm tra hàm vừa xây dựng.
*/

#include <iostream>
using namespace std;

double tinhLuyThua(int x, int n);

int main()
{
	int x, n;

	cout << "Ham tinh luy thua x^n\n";
	cout << endl;

	cout << "Nhap vao co so x: ";
	cin >> x;
	cout << endl;

	cout << "Nhap vao so mu n: ";
	cin >> n;
	cout << endl;

	//do {
	//	cout << "Nhap vao so mu n (n >= 0): ";
	//	cin >> n;
	//	cout << endl;

	//	if (n < 0)
	//		cout << "Nhap sai, vui long nhap lai mot so nguyen (n >= 0)!\n" << endl;
	//} while (n < 0);

	cout << x << "^" << n << " la: " << tinhLuyThua(x, n) << endl;
	cout << endl;

	return 0;
}

// Hàm đệ qui tính giá trị của x^n ; với x, n là số nguyên.
double tinhLuyThua(int x, int n)
{
	if (n == 0)
		return 1;
	
	if (n == -1)
		return 1.0 / x;

	else
		if (n < 0)
			return 1.0 / x * tinhLuyThua(x, n + 1);
		else
			return x * tinhLuyThua(x, n - 1);
}