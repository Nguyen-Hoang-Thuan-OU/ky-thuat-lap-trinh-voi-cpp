// Nhập vào một mảng tối đa 5 hàng và 6 cột
// Nhập vào hàng/cột cần tính tổng, tính tổng
// Nhập vào một giá trị x bất kỳ và tìm xem x có tồn tại trong mảng hay không

#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
const int MAXDONG = 5, MAXCOT = 6;

int tongDong(int a[][MAXCOT], int cot, int dongTinhTong)
{
	int tong = 0;
	for (int j = 0; j < cot; j++)
	{
		tong = tong + a[dongTinhTong - 1][j];
	}
	return tong;
}

int tongCot(int a[][MAXCOT], int dong, int cotTinhTong)
{
	int tong = 0;
	for (int i = 0; i < dong; i++)
	{
		tong = tong + a[i][cotTinhTong - 1];
	}

	return tong;
}

int timKiem ( int a[][MAXCOT], int dong, int cot, int giaTriCanTim )
{
	for ( int i = 0; i < dong; i++ )
	{
		for ( int j = 0; j < cot; j++ )
		{
			if ( a[i][j] == giaTriCanTim)
				return 1;
		}
	}
	return 0;
}

int main()
{
	int a[MAXDONG][MAXCOT];
	int dong, cot;
	int dongTinhTong, cotTinhTong;
	int giaTriCanTim;
	int dem = 0;

	do{
		cout << "Nhap so dong: ";
		cin >> dong;
		cout << "Nhap so cot: ";
		cin >> cot;
		if ( dong <= 0 || dong > 5 || cot <= 0 || cot > 6 )
			cout << "Nhap sai, vui long nhap lai!" << endl;
	}while( dong <= 0 || dong > 5 || cot <= 0 || cot > 6 );

	// Nhap & xuat

	cout << "Ma tran sau khi nhap la: " << endl;
	for ( int i = 0; i < dong; i++ )
	{
		for ( int j = 0; j < cot; j++ )
		{
			a[i][j] = rand()%5;
			cout << setw(8) << a[i][j];
		}
		cout << endl;
	}

	// Tinh tong dong

	cout << "Dong can tinh tong: ";
	cin >> dongTinhTong;
	cout << "Tong dong: " << tongDong(a, cot, dongTinhTong) << endl;

	// Tinh tong cot

	cout << "Cot can tinh tong: ";
	cin >> cotTinhTong;
	cout << "Tong cot: " << tongCot(a, dong, cotTinhTong) << endl;

	// Gia tri can tim

	cout << "Nhap gia tri can tim: ";
	cin >> giaTriCanTim;
	if ( timKiem(a, dong, cot, giaTriCanTim) == 1 )
		cout << "Gia tri " << giaTriCanTim <<  " co ton tai trong mang" << endl;
	else
		cout << "Gia tri " << giaTriCanTim <<  " khong ton tai trong mang" << endl;
	return 0;
}