/*
	Bài 10. Viết chương trình dùng cấp phát động để khởi tạo ngẫu nhiên giá trị
			của 2 mảng số nguyên theo dạng thức ma trận.
			Sau đó tính tổng và tích của 2 ma trận đó.
*/

#include <iostream>
using namespace std;

void nhap(int** a, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		cout << "Nhap phan tu tai dong thu " << i + 1 << ": ";
		for (int j = 0; j < c; j++)
			cin >> *(*(a + i) + j);
	}
}

void xuat(int** a, int r, int c)
{
	cout << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << *(*(a + i) + j) << "\t";
		cout << endl;
	}
	cout << endl;
}

void tong(int** a, int** b, int r, int c, int** z)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			*(*(z + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
}

void tich(int** a, int** b, int r2, int c1, int r1, int** z)
{
	for (int i = 0; i < c1; i++)
		for (int j = 0; j < r1; j++)
		{
			*(*(z + i) + j) = 0;
			for (int k = 0; k < r1; k++)
				*(*(z + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);
		}
}

int main()
{
	int r1, r2, c1, c2;
	cout << "Nhap so dong cua ma tran thu nhat: ";
	cin >> r1;
	cout << "Nhap so cot cua ma tran thu nhat: ";
	cin >> c1;
	cout << "Nhap so dong cua ma tran thu hai: ";
	cin >> r2;
	cout << "Nhap so cot cua ma tran thu hai: ";
	cin >> c2;
	int** a;
	int** b;
	a = new int* [r1];
	for (int i = 0; i < r1; i++)
		a[i] = new int[c1];
	b = new int* [r2];
	for (int i = 0; i < r2; i++)
		b[i] = new int[c2];
	cout << "Nhap cac phan tu cua ma tran thu nhat.\n";
	nhap(a, r1, c1);
	cout << "Nhap cac phan tu cua ma tran thu hai.\n";
	nhap(b, r2, c2);
	system("cls");
	cout << "Cac phan tu trong ma tran thu nhat la: ";
	xuat(a, r1, c1);
	cout << "Cac phan tu trong ma tran thu hai la: ";
	xuat(b, r2, c2);
	if (r1 == r2 && c1 == c2)
	{
		int** c;
		c = new int* [r1];
		for (int i = 0; i < r1; i++)
			c[i] = new int[c1];
		cout << "Tong cua 2 ma tran la: ";
		tong(a, b, r1, c1, c);
		xuat(c, r1, c1);
		for (int i = 0; i < r1; i++)
			delete[] c[i];
		delete[]c;
		c = nullptr;
	}
	else
		cout << "Dieu kien khong phu hop de tinh tong.\n";
	if (c1 == r2)
	{
		int** d;
		d = new int* [r1];
		for (int i = 0; i < r1; i++)
			d[i] = new int[c2];
		cout << "Tich 2 ma tran la: ";
		tich(a, b, r2, c1, r1, d);
		xuat(d, r1, c2);
		for (int i = 0; i < r1; i++)
			delete[] d[i];
		delete[]d;
		d = nullptr;
	}
	else
		cout << "Dieu kien khong phu hop de tinh tich.\n";
	for (int i = 0; i < r1; i++)
		delete[] a[i];
	delete[]a;
	for (int i = 0; i < r2; i++)
		delete[] b[i];
	delete[]b;
	a = nullptr;
	b = nullptr;
	return 0;
}