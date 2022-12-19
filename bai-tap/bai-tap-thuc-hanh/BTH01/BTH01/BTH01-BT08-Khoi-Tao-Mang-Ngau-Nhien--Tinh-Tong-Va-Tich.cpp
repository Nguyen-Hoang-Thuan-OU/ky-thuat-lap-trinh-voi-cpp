/*
	Bài 08. Xây dựng các hàm:

			- Khởi tạo ngẫu nhiên giá trị cho 1 mảng số nguyên
			  gồm n hàng và n cột (ma trận vuông cấp n);

			- Xuất giá trị lưu trữ trong 1 mảng số nguyên gồm n hàng và n cột.

			- Viết hàm tính tổng, tích 2 ma trận vuông cấp n.

			- Viết hàm main để kiểm tra các hàm đã xây dựng.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 50;

void khoiTaoNgauNhienGiaTri(int a[][MAX], int &n);
void xuatMang(int a[][MAX], int n);
int tinhTong(int a[][MAX], int n);
long tinhTich(int a[][MAX], int n);

int main()
{
	int a[MAX][MAX], b[MAX][MAX], n;

	cout << "Mang a: \n";
	khoiTaoNgauNhienGiaTri(a, n);
	cout << endl;

	cout << "Mang b: \n";
	khoiTaoNgauNhienGiaTri(b, n);
	cout << endl;

	cout << "Mang a: \n";
	xuatMang(a, n);
	cout << endl;

	cout << "Mang b: \n";
	xuatMang(b, n);
	cout << endl;

	cout << "Tong 2 ma tran a va b: " << tinhTong(a, n) + tinhTong(b, n) << endl;

	cout << "Tich 2 ma tran a va b: " << tinhTich(a, n) * tinhTich(b, n) << endl;

	return 0;
}

void khoiTaoNgauNhienGiaTri(int a[][MAX], int &n)
{
	do {
		cout << "Nhap so cap cua ma tran (1..50): ";
		cin >> n;

		if (n < 1 || n > MAX)
			cout << "Nhap sai, vui long nhap lai trong khoang 1..50\n" << endl;
	} while (n < 1 || n > MAX);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % 5 + 1;
}

void xuatMang(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

int tinhTong(int a[][MAX], int n)
{
	int tongGiaTri = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tongGiaTri = tongGiaTri + a[i][j];

	return tongGiaTri;
}

long tinhTich(int a[][MAX], int n)
{
	long tichGiaTri = 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tichGiaTri = tichGiaTri * a[i][j];

	return tichGiaTri;
}
