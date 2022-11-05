/*
	Bài 02. Hãy viết chương trình dùng mảng 2 chiều
			xuất ra giá trị dãy số có dạng như sau:

				1    2    3    4    5
				6    7    8    9    10
				11   12   13   14   15
				16   17   18   19   20
*/

#include <iostream>
using namespace std;

const int SO_DONG_TOI_DA = 20, SO_COT_TOI_DA = 10;

void nhapMaTran(int a[SO_DONG_TOI_DA][SO_COT_TOI_DA], int &soDongThucTe, int &soCotThucTe);
void xuatMaTran(int a[SO_DONG_TOI_DA][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe);

int main()
{
	int a[SO_DONG_TOI_DA][SO_COT_TOI_DA];
	int soDongThucTe, soCotThucTe;

	cout << "Nhap ma tran hai chieu\n" << endl;
	nhapMaTran(a, soDongThucTe, soCotThucTe);
	cout << endl;

	cout << "Ma tran hai chieu la:\n" << endl;
	xuatMaTran(a, soDongThucTe, soCotThucTe);
	cout << endl;

	return 0;
}

// 01. Hàm nhập vào ma trận hai chiều
void nhapMaTran(int a[SO_DONG_TOI_DA][SO_COT_TOI_DA], int &soDongThucTe, int &soCotThucTe)
{
	// Kiểm soát giá trị khi người dùng nhập số dòng thực tế
	do {
		cout << "Nhap so dong can su dung (1..20): ";
		cin >> soDongThucTe;
		cout << endl;

		if (soDongThucTe <= 0 || soDongThucTe > SO_DONG_TOI_DA)
		{
			cout << "Gia tri nhap khong hop le!\n";
			cout << "Vui long nhap: 0 < So dong <= 20\n";
			cout << endl;
		}
	} while (soDongThucTe <= 0 || soDongThucTe > SO_DONG_TOI_DA);
	
	// Kiểm soát giá trị khi người dùng nhập số cột thực tế
	do {
		cout << "Nhap so cot can su dung (1..10): ";
		cin >> soCotThucTe;
		cout << endl;

		if (soCotThucTe <= 0 || soCotThucTe > SO_COT_TOI_DA)
		{
			cout << "Gia tri nhap khong hop le!\n";
			cout << "Vui long nhap: 0 < So cot <= 10\n";
			cout << endl;
		}
	} while (soCotThucTe <= 0 || soCotThucTe > SO_COT_TOI_DA);

	int giaTri = 1;

	for (int i = 0; i < soDongThucTe; i++)
	{
		for (int j = 0; j < soCotThucTe; j++)
			a[i][j] = giaTri++;
	}
}

// 02. Hàm in ra ma trận hai chiều
void xuatMaTran(int a[SO_DONG_TOI_DA][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe)
{
	for (int i = 0; i < soDongThucTe; i++)
	{
		for (int j = 0; j < soCotThucTe; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}
