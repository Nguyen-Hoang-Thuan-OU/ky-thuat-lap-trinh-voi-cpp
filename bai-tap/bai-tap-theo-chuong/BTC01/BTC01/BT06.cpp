/*
	- Bài tập thêm -

	Bài 06. Hãy viết chương trình dùng mảng 2 chiều
			xuất ra giá trị dãy số có dạng như sau:

				1   12   11   10
				2   13   16   9
				3   14   15   8
				4   5    6    7
*/

#include <iostream>
using namespace std;

const int CAP_CUA_MA_TRAN = 10;

void nhapMaTran(int a[][CAP_CUA_MA_TRAN], int &soCapThucTeCuaMaTran);
void xuatMaTran(int a[][CAP_CUA_MA_TRAN], int soCapThucTeCuaMaTran);

int main()
{
	int a[CAP_CUA_MA_TRAN][CAP_CUA_MA_TRAN];
	int soCapThucTeCuaMaTran;
	
	cout << "Nhap ma tran hai chieu\n" << endl;
	nhapMaTran(a, soCapThucTeCuaMaTran);
	cout << endl;

	cout << "Ma tran hai chieu la:\n" << endl;
	xuatMaTran(a, soCapThucTeCuaMaTran);
	cout << endl;

	return 0;
}

// 01. Hàm nhập mảng
void nhapMaTran(int a[][CAP_CUA_MA_TRAN], int &soCapThucTeCuaMaTran)
{
	int giaTri = 1;

	int minDong, maxDong;
	int minCot, maxCot;

	// Kiểm soát giá trị khi người dùng nhập số cấp thực tế
	do {
		cout << "Nhap so cap can su dung (1..10): ";
		cin >> soCapThucTeCuaMaTran;
		cout << endl;

		if (soCapThucTeCuaMaTran <= 0 || soCapThucTeCuaMaTran > CAP_CUA_MA_TRAN)
		{
			cout << "Gia tri nhap khong hop le!\n";
			cout << "Vui long nhap: 0 < So cap <= 10\n";
			cout << endl;
		}
	} while (soCapThucTeCuaMaTran <= 0 || soCapThucTeCuaMaTran > CAP_CUA_MA_TRAN);

	minDong = minCot = 0;
	maxDong = maxCot = soCapThucTeCuaMaTran - 1;
	
	while (giaTri <= soCapThucTeCuaMaTran * soCapThucTeCuaMaTran)
	{
		// Hướng 01 - Từ trên xuống dưới
		// minCot cố định, minDong -> maxDong
		for (int i = minDong; i <= maxDong; i++)
			a[i][minCot] = giaTri++;
		minCot++;

		// Hướng 02 - Từ trái sang phải
		// maxDong cố định, minCot -> maxCot
		for (int j = minCot; j <= maxCot; j++)
			a[maxDong][j] = giaTri++;
		maxDong--;

		// Hướng 03 - Từ dưới lên trên
		// maxCot cố định, maxDong -> minDong
		for (int i = maxDong; i >= minDong; i--)
			a[i][maxCot] = giaTri++;
		maxCot--;

		// Hướng 04 - Từ phải sang trái
		// minDong cố định, maxCot -> minCot
		for (int j = maxCot; j >= minCot; j--)
			a[minDong][j] = giaTri++;
		minDong++;
	}
}

// 02. Hàm xuất mảng
void xuatMaTran(int a[][CAP_CUA_MA_TRAN], int soCapThucTeCuaMaTran)
{	
	for (int i = 0; i < soCapThucTeCuaMaTran; i++)
	{
		for (int j = 0; j < soCapThucTeCuaMaTran; j++)
			cout << a[i][j] << "\t";

		cout << endl;
	}
}
