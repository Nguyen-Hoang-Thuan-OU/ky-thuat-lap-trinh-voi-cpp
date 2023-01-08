/*
	Bài 02. Viết chương trình dùng câu lệnh while
		để nhập và xuất giá trị cho một mảng số nguyên
		gồm 4 hàng và 3 cột.
*/

#include <iostream>
using namespace std;

const int DONG_TOI_DA = 3, COT_TOI_DA = 4;

void nhapMang(int a[DONG_TOI_DA][COT_TOI_DA]);
void xuatMang(int a[DONG_TOI_DA][COT_TOI_DA]);

int main()
{
	int a[DONG_TOI_DA][COT_TOI_DA];

	// Gọi hàm nhapMang()
	nhapMang(a);
	cout << endl;

	// Gọi hàm xuatMang()
	xuatMang(a);
	cout << endl;

	return 0;
}

// 01. Hàm để nhập một mảng số nguyên
void nhapMang(int a[DONG_TOI_DA][COT_TOI_DA])
{
	int i = 0;
	while (i < DONG_TOI_DA)
	{
		int j = 0;
		cout << "Nhap " << COT_TOI_DA
			<< " so nguyen cho dong thu [" << i + 1 << "]: ";

		while (j < COT_TOI_DA)
		{
			cin >> a[i][j];
			j++;
		}
		i++;
	}
}

// 02. Hàm để nhập một mảng số nguyên
void xuatMang(int a[DONG_TOI_DA][COT_TOI_DA])
{
	cout << "Mang vua nhap la: \n";

	int i = 0;
	while (i < DONG_TOI_DA)
	{
		for (int j = 0; j < COT_TOI_DA; j++)
			cout << a[i][j] << "\t";
		cout << endl;
		i++;
	}
}