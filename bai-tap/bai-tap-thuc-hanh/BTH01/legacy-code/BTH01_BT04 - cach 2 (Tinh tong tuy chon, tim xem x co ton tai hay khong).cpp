// Nhập vào một mảng tối đa 5 hàng và 6 cột
// Nhập vào hàng/cột cần tính tổng, tính tổng
// Nhập vào một giá trị x bất kỳ và tìm xem x có tồn tại trong mảng hay không, xuất ra các vị trí của x

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int R=5, C=6;

int main()
{
	int A[R][C], m, n, dong, cot, tongc = 0, tongd = 0, x, dem = 0;
	do
	{
		cout << "Nhap so dong: ";
		cin >> m;
		cout << "Nhap so cot: ";
		cin >> n;
		if(m <= 0 || n <= 0 || m > R || n > C)
			cout << "Nhap sai! Hay nhap lai\n";
	}while(m <= 0 || n <= 0 || m > R || n > C);

	cout << "Xuat mang: \n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand()%5;
			cout << setw(4) <<A[i][j];
		}
		cout << endl;
	}

	do
	{
		cout <<"Nhap dong de tinh tong: ";
		cin >> dong;
		if (dong >= m)
			cout << "Nhap sai! nhap lai: \n";
	}while(dong >= m);

	for(int j = 0; j < n; j++)
	tongd += A[dong][j];
	cout << "Tong gia tri tren dong: " << dong << " = " << tongd <<endl;
	do
	{
		cout <<"Nhap cot de tinh tong: ";
		cin >> cot;
		if (cot >= n)
			cout << "Nhap sai! nhap lai: \n";
	}while(cot >= n);

	for(int i = 0; i < m; i++)
		tongc += A[i][cot];
	cout << "Tong gia tri tren cot: " << cot << " = " << tongc << endl;
	cout << "Nhap x: ";
	cin >> x;

	for (int i=0; i<m; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (A[i][j] == x)
			{
				dem++;
				cout << "Tim thay " << x << " tai dong " << i << " va cot " << j << endl;
			}
		}
	}
	cout << "So lan tim thay " << x << " la: "<< dem << endl;

	return 0;
}