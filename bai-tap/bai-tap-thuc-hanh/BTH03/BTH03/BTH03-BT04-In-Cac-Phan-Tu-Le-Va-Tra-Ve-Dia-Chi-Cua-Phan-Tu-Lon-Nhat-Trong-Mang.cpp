/*
	Bài 04. Viết chương trình dùng cấp phát động, cho phép:

			- Nhập vào 1 mảng 1 chiều lưu trữ số nguyên tối đa 30 phần tử.

			- Dùng con trỏ và ký pháp độ dời
			  để xuất ra các phần tử nào là số lẻ trong mảng.

			- Trả về địa chỉ của giá trị phần tử lớn nhất trong mảng
			  (giả sử các giá trị trong mảng không trùng nhau).
*/

// Chưa hoàn thành

#include <iostream>
using namespace std;

void nhapMang(int a[], int n);
void inMang(int a[], int n);
double* timGiaTriLonNhat(int a[], int n, int &diaChi);

int main()
{
	int n;

	int *p;

	int diaChi;

	do {
		cout << "Nhap so luong phan tu (1..30): ";
		cin >> n;

		if (n < 1 || n > 30)
			cout << "Vui long nhap so luong phan tu (1..30)\n" << endl;
	} while (n < 1 || n > 30);
	cout << endl;

	p = new int[n];

	cout << "Nhap mot loat " << n << " phan tu cho mang: ";
	nhapMang(p, n);
	cout << endl;

	cout << "Mang hien tai la: ";
	inMang(p, n);
	cout << endl;

	cout << "Dia chi cua gia tri lon nhat trong mang: ";
	timGiaTriLonNhat(p, n, diaChi);
	cout << endl;
}

void nhapMang(int a[], int n) 
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void inMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
}

double* timGiaTriLonNhat(int a[], int n, int &diaChi)
{
	int max = a[0];

	for (int i = 0; i < n; i++)
		if (a[i] > max)
		{
			max = a[i];
			diaChi = i;
		}
			
	return &a[diaChi];
}

