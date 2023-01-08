/*
	Bài 02. Viết chương trình dùng cấp phát động để nhập,
		xuất 1 mảng số nguyên gồm m hàng và n cột.
		Đếm xem mảng đang lưu trữ có bao nhiêu số là số nguyên tố?
*/

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include <ctime>
using namespace std;

bool kiemTraSoNguyenTo (int n);

int main()
{
	srand(time(0));
	int **a;
	int dong, cot;
	int dem = 0;

	// Kiểm tra tính hợp lệ của số dòng
	cout << "Nhap so dong (n > 0): ";
	cin >> dong;
	do {
		if (dong <= 0)
		{
			cout << "Nhap sai, vui long nhap so dong (n > 0): ";
			cin >> dong;
		}
	} while(dong <= 0);
	
	// Kiểm tra tính hợp lệ của số cột
	cout << "Nhap so cot (n > 0): ";
	cin >> cot;
	do {
		if (cot <= 0)
		{
			cout << "Nhap sai, vui long nhap so cot (n > 0): ";
			cin >> cot;
		}
	} while(cot <= 0);

	// Cấp phát ra một mảng gồm nhiều con trỏ,
	// mỗi con trỏ sẽ quản lý một dòng
	a = new int *[dong];
	
	// Cấp phát ra số cột cho mỗi dòng
	for (int i = 0; i < dong; i++)
		a[i] = new int [cot];

	// Tự động khởi tạo giá trị cho mảng
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			a[i][j] = rand() % 10;
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}

	// Đếm số lượng số nguyên tố
	cout << "Danh sach cac so nguyen to: ";
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (kiemTraSoNguyenTo(a[i][j]) == true)
			{
				dem++;
				cout << a[i][j] << " ";
			}
		}
	}
	cout << endl;
	cout << "So luong so nguyen to: " << dem << endl;

	for (int i = 0; i < dong; i++)
	{
		delete[]a[i];
	}
	delete[]a;
	a = NULL;

	return 0;
}

bool kiemTraSoNguyenTo (int n)
{
	bool kq = true;
	int i = 2;
	if (n < 2)
		kq = false;
	else
	{
		while (i <= sqrt((double)n) && kq == true)
		{
			if (n % i == 0)
				kq = false;
			i++;
		}
	}
	return kq;
}