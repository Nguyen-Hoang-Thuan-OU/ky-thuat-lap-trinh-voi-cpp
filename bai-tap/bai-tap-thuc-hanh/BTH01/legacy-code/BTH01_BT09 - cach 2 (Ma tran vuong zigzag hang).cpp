﻿// Gán giá trị số nguyên từ 1 đến n^2 (VD: n = 4 -> 16).
// Xuất ma trân vuông (2 <= n <= 10) theo zigzag hàng
/* 1   2   3   4
   8   7   6   5
   9  10  11  12
  16  15  14  13 */

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int a[10][10];
	int n;
	int c = 0, gt = 1;

	do{
		cout << "Nhap cap cua ma tran: ";
		cin >> n;
		if ( n < 1 || n > 10 )
			cout << "Nhap sai, vui long nhap lai!" << endl;
	}while( n < 1 || n > 10 );

	while (gt <= n * n)
	{
		// Sang trái
		if (c % 2 == 0)
			for (int j = 0; j < n; j++)
				a[c][j] = gt++;

		// Sang phải
		else
			for (int j = n - 1; j >= 0; j--)
				a[c][j] = gt++;
		c++;
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