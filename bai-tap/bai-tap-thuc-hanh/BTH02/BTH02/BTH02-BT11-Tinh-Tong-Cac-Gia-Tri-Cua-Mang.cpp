/*
	Bài 11. Viết hàm đệ qui tính tổng các giá trị của một mảng 1 chiều lưu trữ số nguyên.
			Sau đó xây dựng chương trình để mô phỏng và kiểm tra hàm vừa xây dựng.
*/

#include <iostream>
using namespace std;

const int MAX = 20;

void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int tinhTongCacGiaTri(int a[], int n);

int main()
{
	int a[MAX];
	int n;

	cout << "Tinh tong cac gia tri cua mot mang\n";
	cout << endl;

	do {
		cout << "Nhap so luong phan tu cua mang (n > 0): ";
		cin >> n;
		cout << endl;

		if (n <= 0)
			cout << "Nhap sai, vui long nhap lai so luong phan tu cua mang (n > 0)!\n" << endl;
	} while (n <= 0);

	cout << "Nhap mot loat " << n << " phan tu cua mang: ";
	nhapMang(a, n);
	cout << endl;

	cout << "Cac phan tu co trong mang la: ";
	xuatMang(a, n);
	cout << endl;

	cout << "Tong cua cac phan tu co trong mang la: " << tinhTongCacGiaTri(a, n) << endl;
	cout << endl;

	return 0;
}

// 01. Hàm nhập mảng
void nhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

// 02. Hàm xuất mảng
void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}

// 03. Hàm tính tổng các giá trị của một mảng 1 chiều
int tinhTongCacGiaTri(int a[], int n)
{
	if (n == 1)
		return a[0];
	else
		return a[n - 1] + tinhTongCacGiaTri(a, n - 1);
}