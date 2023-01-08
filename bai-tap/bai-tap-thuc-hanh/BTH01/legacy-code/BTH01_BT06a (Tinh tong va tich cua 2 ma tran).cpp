// Nhập 2 ma trận, tính tổng và tích của 2 ma trận đó

#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
const int MAX=10;

// Tính tổng

int main()
{
	int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX], m, n;
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;

	cout << "Ma tran a:" << endl;
	for ( int i = 0; i < m; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			a[i][j] = rand()%10;
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}

	cout << "Ma tran b:" << endl;
	for ( int i = 0; i < m; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			b[i][j] = rand()%10;
			cout << setw(4) << b[i][j];
		}
		cout << endl;
	}

	cout << "Tong hai tran:" << endl;
	for ( int i = 0; i < m; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			c[i][j] = a[i][j] + b[i][j];
			cout << setw(4) << c[i][j];
		}
		cout << endl;
	}
	return 0;
}