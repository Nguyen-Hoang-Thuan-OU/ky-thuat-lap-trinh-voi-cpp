/*
	Bài 09. Viết chương trình dùng cấp phát động của con trỏ để viết:
			- Hàm nhập 1 mảng số nguyên r hàng và c cột.
			- Hàm xuất 1 mảng số nguyên r hàng c cột.
			- Hàm dùng con trỏ để tính tổng các phần tử nào là số nguyên tố
			  trong mảng 2 chiều.
			- Hàm dùng để trả về các số nguyên tố trong mảng 2 chiều.
			- Hàm main để kiểm chứng.
*/

// Bị lỗi khi nhập số dòng > số cột

#include <iostream>
using namespace std;

void nhapMang(int **a, int dong, int cot);
void inMang(int **a, int dong, int cot);
void inCacSoNguyenTo(int **a, int dong, int cot);
int tongCacSoNguyenTo(int **a, int dong, int cot);

int main()
{
	int dong, cot;

	int **p;

	do {
		cout << "Nhap so dong (1..30): ";
		cin >> dong;

		if (dong < 1 || dong > 30)
			cout << "Vui long nhap so dong (1..30)\n" << endl;
	} while (dong < 1 || dong > 30);
	cout << endl;

	do {
		cout << "Nhap so cot (1..30): ";
		cin >> cot;

		if (cot < 1 || cot > 30)
			cout << "Vui long nhap so cot (1..30)\n" << endl;
	} while (cot < 1 || cot > 30);
	cout << endl;

	p = new int* [dong];
	for (int i = 0; i < cot; i++)
		p[i] = new int[cot];

	cout << "Vui long nhap mang\n";
	nhapMang(p, dong, cot);
	cout << endl;

	cout << "Mang vua nhap la\n";
	inMang(p, dong, cot);
	cout << endl;

	cout << "Danh sach cac so nguyen la: ";
	inCacSoNguyenTo(p, dong, cot);
	cout << endl;

	cout << "Tong cac phan tu la so nguyen: " 
		<< tongCacSoNguyenTo(p, dong, cot);
	cout << endl;
}

void nhapMang(int **a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		cout << "Nhap mot loat " << cot << " phan tu cho dong thu ["
			<< i + 1 << "]: ";

		for (int j = 0; j < cot; j++)
			cin >> a[i][j];
	}
}

void inMang(int **a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			cout << a[i][j] << "  ";
		cout << endl;
	}
}

bool kiemTraSoNguyenTo(int x)
{
	if (x < 2)
		return false;

	for (int i = 2; i <= sqrt(x * 1.0); i++)
		if (x % i == 0)
			return false;
	return true;
}

void inCacSoNguyenTo(int **a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			if (kiemTraSoNguyenTo(a[i][j]) == true)
				cout << a[i][j] << "  ";
}

int tongCacSoNguyenTo(int **a, int dong, int cot)
{
	int tong = 0;

	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (kiemTraSoNguyenTo(a[i][j]) == true)
				tong = tong + a[i][j];
		}
	}

	return tong;
}