// Gán giá trị số nguyên từ 1 đến n^2 (VD: n = 4 -> 16).
// Xuất ma trân vuông (2 <= n <= 10) theo dạng xoắn ốc
/* 1   2   3   4
  12  13  14   5
  11  16  15   6
  10   9   8   7 */

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int a[10][10];
	int n;
	int gt = 1;

	do{
		cout << "Nhap cap cua ma tran: ";
		cin >> n;
		if ( n < 1 || n > 10 )
			cout << "Nhap sai, vui long nhap lai!" << endl;
	}while( n < 1 || n > 10 );

	int minDong = 0, minCot = 0;
	int maxDong, maxCot;

	maxDong = n - 1;
	maxCot = n - 1;

	while (gt <= n * n)
	{
		// Hướng sang phải
		for (int j = minCot; j <= maxCot; j++)
			a[minDong][j] = gt++;
		minDong++;

		// Hướng xuống dưới
		for (int i = minDong; i <= maxDong; i++)
			a[i][maxCot] = gt++;
		maxCot--;

		// Hướng sang trái
		for (int j = maxCot; j >= minCot; j--)
			a[maxDong][j] = gt++;
		maxDong--;

		// Hướng lên trên
		for (int i = maxDong; i >= minDong; i--)
			a[i][minCot] = gt++;
		minCot++;
	}

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}

	return 0;
}