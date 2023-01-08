// Nhập chiều cao và xuất tam giác Pascal

#include<iostream>
#include<iomanip>
using namespace std;

// Khai báo mảng 2 chiều là 1 ma trận vuông cấp h

void Pascal ( int **&a, int h )
{
	for ( int i = 0; i < h; i++ )
	{
		for ( int j = 0; j <= i; j++ )
		{
			if ( j == 0 || i == j )
				a[i][j] = 1;
			else
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
}

int main()
{
	int **a;
	int h;
	cout << "Nhap chieu cao h: ";
	cin >> h;
	a = new int *[h];

	// Lưu trữ giá trị của 1 tam giác Pascal vào chiều cao h

	for ( int i = 0; i < h; i++ )
	{
		a[i] = new int[h];
	}
	Pascal(a, h);

	// Xuất tam giác Pascal

	for ( int i = 0; i < h; i++ )
	{
		for ( int j = 0; j <= i; j++ )
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}

	for ( int i = 0; i < h; i++ )
	{
		delete[]a[i];
	}
	delete[]a;
	a = NULL;

	return 0;
}