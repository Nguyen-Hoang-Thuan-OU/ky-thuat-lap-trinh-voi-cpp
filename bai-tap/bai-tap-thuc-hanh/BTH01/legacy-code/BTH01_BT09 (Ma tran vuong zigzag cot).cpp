﻿// Gán giá trị số nguyên từ 1 đến n^2 (VD: n = 4 -> 16).
// Xuất ma trân vuông (2 <= n <= 10) theo zigzag cột
/* 1   8   9  16
   2   7  10  15
   3   6  11  14
   4   5  12  13 */

#include<iostream>
#include<iomanip>
using namespace std;
const int MAX = 10;

int main()
{
	int a[MAX][MAX];
	int n;
	int c = 0, gt = 1;

	do{
		cout << "Nhap cap cua ma tran: ";
		cin >> n;
		if ( n < 1 || n > 10 )
			cout << "Nhap sai, vui long nhap lai!" << endl;
	}while( n < 1 || n > 10 );

	do{
		for ( int i = 0; i < n; i++ )
		{
			a[i][c] = gt++;
		}
		c++;

		for ( int i = n - 1; i >= 0; i-- )
		{
			a[i][c] = gt++;
		}
		c++;
	}while(gt <= (n * n));

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