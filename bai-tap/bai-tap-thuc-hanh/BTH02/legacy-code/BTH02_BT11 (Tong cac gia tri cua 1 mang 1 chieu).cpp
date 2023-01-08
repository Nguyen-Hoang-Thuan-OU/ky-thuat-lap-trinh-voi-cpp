// Tổng các giá trị của 1 mảng 1 chiều

#include<iostream>
using namespace std;
const int MAX = 10;

void nhapMang ( int a[], int n )
{
    for ( int i = 0; i < n; i++ )
    {
        cout << "Phan tu thu a[" << i << "]= ";
        cin >> a[i];
    }
}

void xuatMang ( int a[], int n )
{
    for ( int i = 0; i < n; i++ )
    {
        cout << a[i] << "\t";
    }
}

int tong ( int a[], int n )
{
	if ( n == 1 )
		return a[0];
	else
		return tong(a, n-1) + a[n - 1];
}

int main()
{
	int n;
	int a[MAX];
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	nhapMang(a, n);

	cout << "Mang vua nhap la: ";
	xuatMang(a, n);

	cout << "\nTong la: " << tong(a, n) << endl;

	return 0;
}