// Xây dựng hàm

#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
const int MAX = 10;

// Hàm nhập 1 mảng số nguyên

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

// Hàm xuất 1 mảng số nguyên

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

// Hàm tính trung bình cộng

double trungBinhCong ( int a[][MAX], int dong, int cot )
{
	double kq;
	int tong = 0;
	for ( int i = 0; i < dong; i++ )
	{
		for ( int j = 0; j < cot; j++ )
		{
			tong = tong + a[i][j];
		}
	}
	kq = (double)tong / ( dong * cot );
	return kq;
}

// Hàm nhập mảng số nguyên, kiểm tra xem x có tồn tại trong mảng hay không

bool kiemTra ( int a[][MAX], int dong, int cot, int x )
{
	for ( int i = 0; i < dong; i++ )
	{
		for ( int j = 0; j < cot; j++ )
		{
			if ( a[i][j] == x )
			{
				return true;
			}
		}
	}
	return false;
}

// Hàm nhập 2 giá trị số nguyên x, y, hoán đổi 2 giá trị x, y

void hoanDoi ( int a[][MAX], int dong, int cot, int x, int y )
{
	bool c1 = false, c2 = false;
	for ( int i = 0; i < dong; i++ )
	{
		for ( int j = 0; j < cot; j++ )
		{
			if ( a[i][j] == x && !c1 )
			{
				a[i][j] = y; c1 = true;
			}
			else if ( a[i][j] == y && !c2  )
			{
				a[i][j] = x; c2 = true;
			}
		}
	}
}

// Hàm tính tích các trị số trong cột
int tinhTichCot ( int a[][MAX], int dong, int cot, int tichCot )
{
	int tich = 1;
	for ( int i = 0; i < dong; i++ )
	{
		tich = tich * a[i][tichCot - 1];
	}
	return tich;
}

int main()
{
	int a[MAX][MAX];
	int dong, cot;
	int giaTriCanTim;
	int cotTinhTich;
	int x, y;

	cout << "Nhap so dong: ";
	cin >> dong;
	cout << "Nhap so cot: ";
	cin >> cot;
	nhap (a, dong, cot);

	cout << "Ma tran: " << endl;
	xuat (a, dong, cot);

	cout << "Nhap gia tri can hoan doi thu nhat: ";
	cin >> x;
	cout << "Nhap gia tri can hoan doi thu hai: ";
	cin >> y;
	hoanDoi (a, dong, cot, x, y);
	cout << "Ma tran sau khi hoan doi:" << endl;
	xuat(a, dong, cot);

	cout << "Nhap gia tri can tim trong mang: ";
	cin >> giaTriCanTim;
	if ( kiemTra(a, dong, cot, giaTriCanTim) == true )
	{
		cout << "Gia tri " << giaTriCanTim << " co ton tai trong mang" << endl;
	}
	else
	{
		cout << "Gia tri " << giaTriCanTim << " khong ton tai trong mang" << endl;
	}


	cout << "Nhap cot can tinh tich: ";
	cin >> cotTinhTich;
	cout << "Tich cua cot " << cotTinhTich << " = " << tinhTichCot (a, dong, cot, cotTinhTich) << endl;

	return 0;
}