// Chuyển 1 số nguyên ở dạng nhị phân (2) sang hệ thập phân (10) và ngược lại

#include <iostream>
using namespace std;

int thapSangNhi ( int n )
{
	int a;
	if ( n == 0 )
		return 0;
	else
	{
		a = n % 2;
		return thapSangNhi (n/2) *10 + a;
	}
}

int nhiSangThap ( int n )
{
	int a;
	if ( n == 0 )
		return 0;
	else
	{
		a = n % 10;
		return nhiSangThap (n/10) *2 + a;
	}
}

int main()
{
	int thap, nhi;
	cout << "Nhap day so thap phan: ";
	cin >> thap;
	cout << "Day so nhi phan la: " << thapSangNhi(thap) << endl;

	cout << "Nhap day so nhi phan: ";
	cin >> nhi;
	cout << "Day so thap phan la: " << nhiSangThap(nhi) << endl;
	return 0;
}