#include <iostream>
#include <cmath>
using namespace std;

int tongDuong (int n)
{
	if ( n == 1 )
		return 1;
	else
		return n + tongDuong (n - 1);
}

int tongBinh (int n)
{
	if ( n == 0 )
		return 0;
	else
		return n*n + tongBinh (n - 1);
}


int giaiThua (int n)
{
	if ( n == 1 )
		return 1;
	else
		return n * giaiThua (n - 1);
}

int main()
{
	int n;
	cout << "Nhap so nguyen: ";
	cin >> n;
	cout << "Tong so duong: " << tongDuong (n);
	cout << "Tong so duong binh phuong: " << tongBinh (n);
	cout << "Tong giai thua: " << giaiThua (n);
	return 0;
}