/*
	CÂU 04. Dùng con trỏ và ký pháp độ dời để thực hiện:
	Viết chương trình dùng cấp phát động, thực hiện các hàm:

	- Khởi tạo giá trị cho tam giác Pascal ngược có chiều cao h (h > 0).
		Ví dụ: h = 4

	- Hàm xuất tam giác pascal ngược có chiều cao h.

	- Hàm khởi tạo giá trị zigzag cho ma trận vuông cấp n chứa các số nguyên.
		Ví dụ: n = 4

	- Hàm main để kiểm chứng toàn bộ chương trình.
*/

#include <iostream>
using namespace std;
int tam_Giac_Pas_Cal(int x, int y)
{
	if (y == 0 || x == y)
		return 1;
	else
		return tam_Giac_Pas_Cal(x- 1, y) + tam_Giac_Pas_Cal(x - 1, y - 1);
}

void ve_Tam_Giac_Pas_Cal(int chieu_Cao)
{
	int dem = 0;
	for (int i = 0; i < chieu_Cao; i++)
	{
		int tam = dem;
		for (int j = 0; j < chieu_Cao; j++)
			if (i + j >= chieu_Cao - 1)
			{
				cout << tam_Giac_Pas_Cal(i, tam);
				tam--;
			}
			else
				cout << " ";
		cout << endl;
		dem++;
	}
}

int main()
{
	int chieu_Cao;
	int **mang;
	cout << "Nhap chieu cao cua tam giac: ";
	cin >> chieu_Cao;
	mang = new int*[chieu_Cao];
	for (int i = 0; i < chieu_Cao; i++)
		mang[i] = new int[chieu_Cao];
	cout << "Tam giac pascal co chieu cao " << chieu_Cao << ": \n";
	ve_Tam_Giac_Pas_Cal(chieu_Cao);
	for (int i = 0; i < chieu_Cao; i++)
		delete[]mang[i];
	delete[]mang;
	mang = nullptr;
}