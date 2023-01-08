/*
	Bài 06. Dùng con trỏ viết hàm đảo ngược 1 mảng 1 chiều lưu trữ số nguyên.
		Sau đó viết chương trình kiểm chứng lại hàm vừa xây dựng.
*/

#include <iostream>
using namespace std;

void nhapMang(int* a, int n);
void xuatMang(int* a, int n);
void daoNguocMang(int* a, int n);

int main()
{
	int* a;
	int n;

	// Nhập số lượng thực tế cần sử dụng
	cout << "Nhap so luong phan tu (1..20): ";
	cin >> n;
	do {
		if (n <= 0 || n > 20)
		{
			cout << "Nhap sai, vui long nhap so luong phan tu (1..20): ";
			cin >> n;
		}
	} while(n <= 0 || n > 20);

	// Cấp phát động vùng nhớ cho mảng
	a = new int[n];

	// Nhập mảng
	cout << "Nhap mot loat [" << n << "] phan tu: ";
	nhapMang(a, n);
	cout << endl;

	// In mảng sau khi vừa nhập
	cout << "Mang truoc khi dao nguoc:\t";
	xuatMang(a, n);
	cout << endl;

	// Đảo ngược mảng
	daoNguocMang(a, n);

	// In mảng sau khi đảo ngược
	cout << "Mang sau khi dao nguoc:\t\t";
	xuatMang(a, n);
	cout << endl;

	// Huỷ vùng nhớ cấp phát động
	delete[] a;
	a = NULL;

	return 0;
}

void nhapMang(int* a, int n)
{
	for(int i = 0; i < n; i++)
		cin >> a[i];
}

void xuatMang(int* a, int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
}

void daoNguocMang(int* a, int n)
{
	int* p;
	int* q;
	int temp;

	p = &a[0];
	q = &a[n - 1];

	while(p < q)
	{
		temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q--;
	}
}