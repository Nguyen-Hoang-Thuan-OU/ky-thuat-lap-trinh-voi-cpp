// Đếm số chữ số của 1 số nguyên không âm
// Tính số đảo ngược
// Tổng các chữ số chẳn/lẻ

#include <iostream>
using namespace std;

int dem ( int n )
{
	if ( n == 0 )
		return 0;
	else
		return 1 + dem ( n/10 );
}

void soDaoNguoc ( int n )
{
    if ( n != 0 )
	{
		cout << n % 10;
		soDaoNguoc (n / 10);
	}
}

int tongChan ( int n )
{
	if ( n == 0 )
		return 0;
	if ( n % 2 == 0 )
		return tongChan ( n/10 ) + n%10;
	return tongChan ( n/10 );
}

int tongLe ( int n )
{
	if ( n == 0 )
		return 0;
	if ( n % 2 == 1 )
		return tongLe ( n/10 ) + n%10;
	return tongLe ( n/10 );
}

int main()
{
	int n;
	cout << "Nhap so nguyen: ";
	cin >> n;

	cout << "So dao nguoc la: ";
	soDaoNguoc (n);

	cout << "\nSo chu so cua so nguyen " << n << " la: " << dem(n) << endl;
 
	cout << "Tong so chan: " << tongChan (n) << endl;
	cout << "Tong so le: " << tongLe (n) << endl;

	return 0;
}