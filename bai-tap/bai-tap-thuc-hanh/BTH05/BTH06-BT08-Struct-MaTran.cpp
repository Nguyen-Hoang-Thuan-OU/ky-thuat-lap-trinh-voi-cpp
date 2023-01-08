/*
	Bài 08. Định nghĩa kiểu dữ liệu MaTran gồm các thông tin:
		- Số dòng, số cột kiểu int
		- Con trỏ kiểu trỏ đến mảng 2 chiều lưu trữ số nguyên.

		Viết chương trình thực hiện các việc sau:
		- Phát sinh ngẫu nhiên giá trị cho 1 biến kiểu MaTran.
		- Xuất giá trị đang lưu trữ
		  trong mảng 2 chiều của biến kiểu MaTran.
		- Tính tổng các phần tử nào là số đối xứng
		  trong mảng 2 chiều của biến kiểu MaTran.
*/

#include <iostream>
using namespace std;

struct MaTran
{
	int r, c;
	int **p;
};

int timSDN(int a, int sdn)
{
	if (a < 10)
		return sdn * 10 + a;
	else
		return timSDN(a / 10, sdn * 10 + a % 10);
}

int main()
{
	MaTran a;
	int tong = 0;

	cout << "Nhap so dong: ";
	cin >> a.r;

	cout << "Nhap so cot: ";
	cin >> a.c;

	a.p = new int *[a.r];
	for (int i = 0; i < a.r; i++)
		a.p[i] = new int[a.c];

	//khoi tao gia tri va tinh tong cac so doi xung
	for (int i = 0; i < a.r; i++)
		for (int j = 0; j < a.c; j++)
		{
			a.p[i][j] = rand();
			if (a.p[i][j] == timSDN(a.p[i][j], 0))
				tong += a.p[i][j];
		}

		//xuat
		cout << "Ma tran co dang: " << endl;
		for (int i = 0; i < a.r; i++)
		{
			for (int j = 0; j < a.c; j++)
				cout << a.p[i][j] << "\t";
			cout << endl;
		}


		if (tong == 0)
			cout << "Ma tran tren ko co so doi xung! " << endl;
		else
			cout << "Tong cac so doi xung trong ma tran tren la: " << tong << endl;
		system("pause");

		for (int i = 0; i < a.r; i++)
			delete[] a.p[i];
		delete[] a.p;
		a.p = nullptr;

		return 0;
}
