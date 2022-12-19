/*
	Bài 08. Viết chương trình dùng cấp phát động, cho phép:

			- Khai báo mảng 2 chiều là một ma trận vuông cấp h (h > 0).

			- Lưu trữ giá trị của một tam giác Pascal với chiều cao h.

			- Xuất lại tam giác Pascal ra màn hình.

			Gợi ý: tam giác Pascal xem lại ở BTH02

					1
					1 1
					1 2 1
					1 3 3 1
					1 4 6 4 1
*/

#include <iostream>
using namespace std;

int inTamGiacPascal(int x, int y);

int main()
{
	int h;
	int** a;

	cout << "In tam giac Pascal\n";
	cout << endl;

	do {
		cout << "Nhap chieu cao cua tam gia Pascal (h > 0): ";
		cin >> h;
		cout << endl;

		if (h <= 0)
			cout << "Nhap sai, vui long nhap lai chieu cao cua tam gia Pascal (h > 0)!\n" << endl;
	} while (h <= 0);

	a = new int* [h];
	for (int i = 0; i < h; i++)
		a[i] = new int[h];

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << inTamGiacPascal(i, j) << "  ";
		cout << endl;
	}

	for (int i = 0; i < h; i++)
		delete[] a[i];
	delete[] a;
	a = nullptr;

	return 0;
}

int inTamGiacPascal(int x, int y)
{
	if (y == 0 || x == y)
		return 1;
	else
		return inTamGiacPascal(x - 1, y - 1) + inTamGiacPascal(x - 1, y);
}
