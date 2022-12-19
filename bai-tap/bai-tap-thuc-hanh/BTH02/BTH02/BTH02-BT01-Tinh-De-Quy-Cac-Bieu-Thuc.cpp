/*
	Bài 01. Xây dựng các hàm đệ qui tính các biểu thức như sau:
			a. S1 = 1 + 2 + 3 + ⋯ + n (n là số nguyên dương)
			b. S2 = 1^2 + 2^2 + 3^2 + ⋯ + n^2 (n là số nguyên dương)
			c. S3 = 1 + 1/3 + 1/5 + ⋯ + 1/n (n là số nguyên dương và là số lẻ)
			d. S4 = 1! + 2! + 3! + ⋯ + n! (n là số nguyên dương)
*/

#include <iostream>
using namespace std;

int tinhTongSoNguyenDuongS1(int n);
int tinhTongBinhPhuongS2(int n);
double tinhTongSoNguyenDuongVaLaSoLeS3(int n);
int tinhGiaiThua(int n);
int tinhTongGiaiThuaS4(int n);

int main()
{
	int n, m;

	cout << "S1 = 1 + 2 + 3 + ... + n\n";
	cout << "S2 = 1^2 + 2^2 + 3^2 + ... + n^2\n";
	cout << "S3 = 1 + 1/3 + 1/5 + ... + 1/n\n";
	cout << "S4 = 1! + 2! + 3! + ... + n!\n";
	cout << endl;

	do {
		cout << "S1, S2, S4 - Nhap vao mot so nguyen (n > 0): ";
		cin >> n;
		cout << endl;

		if (n <= 0)
			cout << "Nhap sai, vui long nhap lai mot so nguyen (n > 0)!\n" << endl;
	} while (n <= 0);

	do {
		cout << "S3 - Nhap vao mot so nguyen le (n > 0): ";
		cin >> m;
		cout << endl;

		if (m <= 0 || m % 2 == 0)
			cout << "Nhap sai, vui long nhap lai mot so nguyen le (n > 0)!\n" << endl;
	} while (m <= 0 || m % 2 == 0);

	// a. S1 = 1 + 2 + 3 + ⋯ + n (n là số nguyên dương)
	cout << "Tong so nguyen duong S1: " << tinhTongSoNguyenDuongS1(n) << endl;
	cout << endl;

	// b. S2 = 1^2 + 2^2 + 3^2 + ⋯ + n^2 (n là số nguyên dương)
	cout << "Tong luy thua S2: " << tinhTongBinhPhuongS2(n) << endl;
	cout << endl;

	// c. S3 = 1 + 1/3 + 1/5 + ⋯ + 1/n (n là số nguyên dương và là số lẻ)
	cout << "Tong so nguyen duong va la so le S3: " << tinhTongSoNguyenDuongVaLaSoLeS3(m) << endl;
	cout << endl;

	// d. S4 = 1! + 2! + 3! + ⋯ + n! (n là số nguyên dương)
	cout << "Tong giai thua S4: " << tinhTongGiaiThuaS4(n) << endl;
	cout << endl;

	return 0;
}

// a. S1 = 1 + 2 + 3 + ⋯ + n (n là số nguyên dương)
int tinhTongSoNguyenDuongS1(int n)
{
	// Trường hợp cơ bản - có thể trả về kết quả trực tiếp
	if (n = 1)
		return 1; // return n;
	
	// Trường hợp tổng quát - có câu lệnh để gọi lại chính hàm đệ quy
	return n + tinhTongSoNguyenDuongS1(n - 1);
}

// b. S2 = 1^2 + 2^2 + 3^2 + ⋯ + n^2 (n là số nguyên dương)
int tinhTongBinhPhuongS2(int n)
{
	if (n == 1)
		return 1;
	return n * n + tinhTongBinhPhuongS2(n - 1);
}

// c. S3 = 1 + 1/3 + 1/5 + ⋯ + 1/n (n là số nguyên dương và là số lẻ)
double tinhTongSoNguyenDuongVaLaSoLeS3(int n)
{
	if (n == 1)
		return 1;
	return 1.0 / n + tinhTongSoNguyenDuongVaLaSoLeS3(n - 2);
}

// d. S4 = 1! + 2! + 3! + ⋯ + n! (n là số nguyên dương)
int tinhTongGiaiThuaS4(int n)
{
	if (n == 1)
		return 1;
	return tinhGiaiThua(n) + tinhTongGiaiThuaS4(n - 1);
}

int tinhGiaiThua(int n)
{
	//int tich = 1;

	//if (n == 0 || n == 1)
	//	return 1;

	//for (int i = 2; i <= n; i++)
	//	tich = tich * i;

	//return tich;

	if (n == 1)
		return 1;
	return n * tinhGiaiThua(n - 1);
}