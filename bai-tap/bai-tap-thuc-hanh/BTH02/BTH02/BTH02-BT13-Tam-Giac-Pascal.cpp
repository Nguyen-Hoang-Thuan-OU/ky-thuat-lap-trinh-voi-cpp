/*
	Bài 13. Viết hàm đệ qui để xuất ra 1 tam giác Pascal.
	Biết rằng 1 tam giác Pascal có dạng như sau với chiều cao là 5:

		1
		1	1
		1	2	1
		1	3	3	1
		1	4	6	4	1
*/

#include <iostream>
using namespace std;

const int MAX = 20;

int inTamGiacPascal(int a, int b);

int main()
{
	int h;

	cout << "In tam giac Pascal\n";
	cout << endl;

	do {
		cout << "Nhap chieu cao cua tam gia Pascal (h > 0): ";
		cin >> h;
		cout << endl;

		if (h <= 0)
			cout << "Nhap sai, vui long nhap lai chieu cao cua tam gia Pascal (h > 0)!\n" << endl;
	} while (h <= 0);

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << inTamGiacPascal(i, j) << "  ";
		cout << endl;
	}

	return 0;
}

// Hàm xuất ra 1 tam giác Pascal
int inTamGiacPascal(int a, int b)
{
	if (b == 0 || a == b)
		return 1;

	if (b == 1)
		return a;
	else
		return inTamGiacPascal(a - 1, b - 1) + inTamGiacPascal(a - 1, b);
}