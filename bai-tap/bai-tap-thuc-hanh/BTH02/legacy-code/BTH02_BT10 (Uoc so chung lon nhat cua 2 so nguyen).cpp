// Tìm ước số chung lớn nhất của 2 số nguyên

#include<iostream>
using namespace std;

int ucln ( int a, int b )
{
	if ( b == 0 )
		return a;
	return ucln ( b, a%b );
}

int main()
{
	int a,b;
	cout << "Nhap so thu nhat: ";
	cin >> a;
	cout << "Nhap so thu hai: ";
	cin >> b;
	cout << "Uoc so chung lon nhat: " << ucln(a,b) << endl;
	return 0;
}