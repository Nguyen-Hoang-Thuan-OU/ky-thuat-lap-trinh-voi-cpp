// Tìm giá trị nhỏ nhất của 1 mảng 1 chiều //chuahoanthanh//

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

 // Cách 1

int Min ( int a[], int n )
{
	int min;
	if (n == 1)
		min = a[0];
	else
	{
		min = Min(a, n - 1);
		if ( min > a[n - 1] )
			min = a[n - 1];
	}
	return min;
}

// Cách 2

//void Min(int a[], int n, int &min)
//{
//	int m;
//	if ( n == 1 )
//		min = a[0];
//	else
//	{
//		min = a[n - 1];
//		Min(a, n - 1, min);
//		if ( m < min )
//			min = m;
//	}
//}

int main()
{
	int n;
	int min;
	int a[MAX];
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	nhapMang(a, n);

	cout << "Mang vua nhap la: ";
	xuatMang(a, n);

	Min(a, min);
	cout << "\nGia tri nho nhat la: " << min << endl;

	return 0;
}