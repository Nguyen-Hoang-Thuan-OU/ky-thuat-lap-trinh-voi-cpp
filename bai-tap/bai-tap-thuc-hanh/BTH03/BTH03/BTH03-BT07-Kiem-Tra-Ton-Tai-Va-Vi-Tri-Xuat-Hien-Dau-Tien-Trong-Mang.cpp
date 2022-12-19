/*
	Bài 07. Dùng con trỏ viết hàm tìm kiếm 1 số nguyên
			có tồn tại trong mảng 1 chiều lưu trữ số nguyên hay không?
			Nếu có thì trả về vị trí đầu tiên xuất hiện số nguyên đó.
			Nếu không thì trả con trỏ về NULL.
			Sau đó viết chương trình kiểm chứng lại hàm vừa xây dựng.
*/

// Bị lỗi tìm kiếm

#include <iostream>
using namespace std;

void nhapMang(int* a, int n);
void xuatMang(int* a, int n);
int* timViTriXuatHien(int a[], int n, int x);
void timKiem(int* a, int n, int &x);

int main()
{
	int* a, n, x = 0;

	do {
		cout << "Nhap so luong phan tu (n > 0): ";
		cin >> n;
		cout << endl;

		if (n < 0)
			cout << "Vui long nhap so luong phan tu (n > 0)!\n" << endl;
	} while (n < 0);

	a = new int[n];

	nhapMang(a, n);
	cout << endl;

	cout << "Cac phan tu chua trong mang la: ";
	xuatMang(a, n);
	cout << endl;

	cout << "Nhap vao so can tim trong mang: ";
	cin >> x;
	cout << endl;

	timKiem(a, n, x);
	cout << endl;

	delete[]a;
	a = nullptr;

	return 0;
}

// 01. Hàm nhập mảng
void nhapMang(int* a, int n)
{
	cout << "Nhap mot loat " << n << " phan tu cho mang: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

// 02. Hàm xuất mảng
void xuatMang(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(a + i) << " ";
	cout << endl;
}

// 03. Hàm trả về vị trí đầu tiên xuất hiện
int* timViTriXuatHien(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return &a[i];	// Hoặc *(a + i)
	return NULL;
}

// 04. Hàm tìm kiếm một số nguyên
void timKiem(int* a, int n, int &x)
{
	int* diaChi = timViTriXuatHien(a, n, x);

	while (*a == *diaChi)
	{
		cout << "So " << x << " can tim xuat hien tai dia chi: " << diaChi << endl;

		int viTri = (int(*diaChi) - int(a[0])) / 4;
		cout << "Nam tai vi tri [" << viTri << "] trong mang!";

		a++;
	}
}