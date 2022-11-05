/*
	Bài 05. Viết chương trình cho nhập vào một ma trận vuông cấp n (chứa các số nguyên).
			Sau đó tính tổng các giá trị trên đường chéo chính
			và đường chéo phụ của ma trận vừa nhập.

				Ví dụ: cho ma trận
									1	4	0
									8	15	3
									6	9	2

						Thì tổng các giá trị trên đường chéo chính là = 1 + 15 + 2 = 18,
						tổng các giá trị trên đường chéo phụ là = 6 + 15 + 0 = 21.
*/

#include <iostream>
using namespace std;

const int MAX = 10;

void nhapMaTran(int a[][MAX], int soCapThucTe);
void xuatMaTran(int a[][MAX], int soCapThucTe);
int tinhTongDuongCheoChinh(int a[][MAX], int soCapThucTe);
int tinhTongDuongCheoPhu(int a[][MAX], int soCapThucTe);

int main()
{
	int a[MAX][MAX], soCapThucTe;

	do {
		cout << "Nhap cap cua ma tran (1..10): ";
		cin >> soCapThucTe;

		if (soCapThucTe < 1 || soCapThucTe > MAX)
			cout << "Nhap sai, vui long nhap lai!\n";
	} while (soCapThucTe < 1 || soCapThucTe > MAX);

	nhapMaTran(a, soCapThucTe);
	cout << endl;

	xuatMaTran(a, soCapThucTe);
	cout << endl;

	cout << "Tong duong cheo chinh: " << tinhTongDuongCheoChinh(a, soCapThucTe) << endl;

	cout << "Tong duong cheo phu: " << tinhTongDuongCheoPhu(a, soCapThucTe) << endl;

	return 0;
}


// 01. Hàm nhập ma trận
void nhapMaTran(int a[][MAX], int soCapThucTe)
{
	cout << "Ma tran se co " << soCapThucTe << " dong va " << soCapThucTe << " cot" << endl;
	for (int i = 0; i < soCapThucTe; i++)
	{
		cout << "Nhap mot loat " << soCapThucTe << " phan tu tren dong thu [" << i << "]: ";
		for (int j = 0; j < soCapThucTe; j++)
			cin >> a[i][j];
	}
}

// 02. Hàm xuất ma trận
void xuatMaTran(int a[][MAX], int soCapThucTe)
{
	cout << "Ma tran vua nhap la:\n";
	for (int i = 0; i < soCapThucTe; i++)
	{
		for (int j = 0; j < soCapThucTe; j++)
			cout << a[i][j] << "\t";

		cout << endl;
	}
}

// 03. Hàm tính tổng của đường chéo chính
int tinhTongDuongCheoChinh(int a[][MAX], int soCapThucTe)
{
	int tongDuongCheoChinh = 0;

	for (int i = 0; i < soCapThucTe; i++)
		for (int j = 0; j < soCapThucTe; j++) 
			if (i == j)
				tongDuongCheoChinh = tongDuongCheoChinh + a[i][j];

	return tongDuongCheoChinh;
}

// 04. Hàm tính tổng của đường chéo phụ
int tinhTongDuongCheoPhu(int a[][MAX], int soCapThucTe)
{
	int tongDuongCheoPhu = 0;

	for (int i = 0; i < soCapThucTe; i++)
		for (int j = 0; j < soCapThucTe; j++)
			if (j == (soCapThucTe - i - 1))
				tongDuongCheoPhu = tongDuongCheoPhu + a[i][j];

	return tongDuongCheoPhu;
}