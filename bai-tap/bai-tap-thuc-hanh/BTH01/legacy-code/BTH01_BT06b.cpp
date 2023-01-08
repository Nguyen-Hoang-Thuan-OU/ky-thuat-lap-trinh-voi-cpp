// Nhập 2 ma trận, tính tổng và tích của 2 ma trận đó

#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
const int MAX=10;

// Tính tích

int main()
{
	int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX], m, n, p;
	cout << "Nhap so dong ma tran a: ";
	cin >> m;
	cout << "Nhap so cot ma tran b: ";
	cin >> n;
	cout << "Nhap so cot ma tran a, so dong ma tran b: ";
	cin >> p;

	cout << "Ma tran a:" << endl;
	for ( int i = 0; i < m; i++ )
	{
		for ( int j = 0; j < p; j++ )
		{
			a[i][j] = rand()%10;
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}

	cout << "Ma tran b:" << endl;
	for ( int i = 0; i < p; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			b[i][j] = rand()%10;
			cout << setw(4) << b[i][j];
		}
		cout << endl;
	}

	cout << "Tich hai ma tran:" << endl;
	for ( int i = 0; i < m; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			c[i][j] = 0;
			for ( int k = 0; k < p; k++ )
				c[i][j] += a[i][k] * b[k][j];
			cout << setw(4) << c[i][j];
		}
		cout << endl;
	}
	return 0;
}