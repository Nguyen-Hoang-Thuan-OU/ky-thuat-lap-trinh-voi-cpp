// Nhập 2 ma trận, tính tổng và tích của 2 ma trận đó

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int M = 20;

int main()
{
	int A[M][M], B[M][M], TONG[M][M], TICH[M][M];
	int n, m;
	do
	{
		cout << "Nhap so dong: ";
		cin >> m;
		cout << "Nhap so cot: ";
		cin >> n;
		if(n <= 0 || n > M || m <= 0 || m > M)
			cout << "Nhap sai! Hay nhap lai\n";
	}while(n <= 0 || n > M || m <= 0 || m > M);

	cout << "Ma tran A:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand()%5;
			cout << setw(4) << A[i][j];
		}
		cout << endl;
	}
	cout << endl;

	cout << "Ma tran B:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = rand()%2;
			cout << setw(4) << B[i][j];
		}
		cout << endl;
	}
	cout << endl;

	// Tong
	cout << "Ma tran tong cua ma tran A va B:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			TONG[i][j] = A[i][j] + B[i][j];
			cout << setw(4) << TONG[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//Tich
	cout << "Ma tran tich cua ma tran A va B:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			TICH[i][j] = 0;
			for (int k = 0; k < n; k++)
				TICH[i][j] += A[i][k] * B[k][j];
			cout << setw(4) << TICH[i][j];
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}