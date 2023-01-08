// Xây dựng hàm

#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
const int MAX = 10;

void nhap ( int a[][MAX], int dong, int cot )
{
	for ( int i = 0; i < dong; i++ )
	{
		for ( int j = 0; j < cot; j++ )
		{
			a[i][j] = rand()%10;
		}
	}
}

void xuat ( int a[][MAX], int dong, int cot )
{
	for ( int i = 0; i < dong; i++ )
	{
		for ( int j = 0; j < cot; j++ )
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
}

void tongMaTran ( int a[][MAX], int b[][MAX], int c[][MAX], int dong, int cot )
{
	for ( int i = 0; i < dong; i++ )
	{
		for ( int j = 0; j < cot; j++ )
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void tichMaTran ( int a[][MAX], int b[][MAX], int c[][MAX], int dong, int cotDong, int cot )
{
	for ( int i = 0; i < dong; i++ )
	{
		for ( int j = 0; j < cot; j++ )
		{
			c[i][j] = 0;
			for ( int k = 0; k < cotDong; k++ )
			{
				c[i][j] = a[i][j] * b[i][j];
			}
		}
	}
}

int main()
{
	int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
	int a1[MAX][MAX], b1[MAX][MAX], c1[MAX][MAX];
	int dong, cot, cotDong;

	cout << "Nhap so dong cua ma tran 1, 2, 3: ";
	cin >> dong;
	cout << "Nhap so cot cua ma tran 1, 2, 4: ";
	cin >> cot;
	cout << "Nhap so dong cua ma tran 4; cot cua ma tran 3: ";
	cin >> cotDong;

	cout << "Ma tran thu 1: " << endl;
	nhap(a, dong, cot);
	xuat(a, dong, cot);

	cout << "Ma tran thu 2: " << endl;
	nhap(b, dong, cot);
	xuat(b, dong, cot);

	cout << "Tong cua ma tran thu 1 va 2: " << endl;
	tongMaTran(a, b, c, dong, cot);
	xuat(c, dong, cot);

	cout << "Ma tran thu 3: " << endl;
	nhap(a1, dong, cotDong);
	xuat(a1, dong, cotDong);

	cout << "Ma tran thu 4: " << endl;
	nhap(b1, cotDong, cot);
	xuat(b1, cotDong, cot);

	cout << "Tich cua ma tran thu 3 va 4: " << endl;
	tichMaTran(a1, b1, c1, dong, cotDong, cot);
	xuat(c1, dong, cot);

	return 0;
}