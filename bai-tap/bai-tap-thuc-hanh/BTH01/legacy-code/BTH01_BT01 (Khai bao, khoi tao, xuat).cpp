// Khai báo mảng số nguyên gồm 3 hàng và 4 cột
// Khởi tạo giá trị và xuất lại toàn bộ mảng

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int a[3][4];
	int hang, cot;

	// Nhập số lượng hàng và cột

	do{
		cout << "Nhap so hang: ";
		cin >> hang;
		cout << "Nhap so cot: ";
		cin >> cot;
		if ( hang <= 0 || cot <= 0 || hang > 3 || cot > 4 )
			cout << "Nhap sai, vui long nhap lai" << endl;
	}while( hang <= 0 || cot <= 0 || hang > 3 || cot > 4 );

	// Nhập

	for ( int i = 0; i < hang; i++ )
		for ( int j = 0; j < cot; j++ )
		{
			cout << "Phan tu[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}

	// Xuất

	for ( int i = 0; i < hang; i++ )
	{
		for ( int j = 0; j < cot; j++ )
			cout << setw(4) << a[i][j];
		cout << endl;
	}

	return 0;
}