/*
	Bài 01. Viết chương trình dùng cấp phát động
		cho nhập vào mảng 1 chiều gồm các số nguyên (tối đa 20 phần tử).
		Sau đó tiến hành đảo ngược mảng vừa nhập.
		Xuất lại mảng cho người dùng kiểm tra.
*/

#include<iostream>
using namespace std;

int main()
{
	int *a;
	int *p;
	int *q;
	int n, temp;

	cout << "Nhap so phan tu: ";
	cin >> n;
	a = new int [n];

	// Nhập mảng
	cout << "Nhap mot loat [" << n << "] phan tu cho mang: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	// Xuất mảng
	cout << "Mang truoc khi hoan doi la:\t";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// Đảo ngược mảng
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

	// Xuất lại mảng
	cout << "Mang sau khi hoan doi la:\t";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	delete[]a;
	a = NULL;

	return 0;
}