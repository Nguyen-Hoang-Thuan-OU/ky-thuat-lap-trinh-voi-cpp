// Nhập ma trận vuông, tính tổng giá trị trên đường chéo chính và đường chéo phụ

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int MAX = 10;

int main()
{
	int a[MAX][MAX];
	int n;
	int tongChinh = 0, tongPhu = 0;

	do{
		cout <<"Nhap cap cua ma tran: ";
		cin >> n;
		if ( n > MAX || n <= 0 )
			cout <<"Nhap sai, vui long nhap lai" << endl;
	}while( n > MAX || n <= 0 );

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			a[i][j] = rand()%10;
			if ( i == j ) //Dieu kien duong cheo chinh
				tongChinh = tongChinh + a[i][j];
			if ( j == n - 1 - i ) //Dieu kien duong cheo phu
				tongPhu = tongPhu + a[i][j];
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}

	cout << "Tong cac phan tu cua duong cheo chinh: " << tongChinh << endl;
	cout << "Tong cac phan tu cua duong cheo phu: " << tongPhu << endl;
	return 0;
}