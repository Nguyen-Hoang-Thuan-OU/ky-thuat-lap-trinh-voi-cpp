// Tính giá trị Fibonacci

#include <iostream>
using namespace std;

int Fibonacci (int n)
{
	if ( n == 1 || n == 2 )
		return 1;
	else
		return Fibonacci (n - 1) + Fibonacci (n - 2);
}

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "So Fibonacci thu " << n << " la: " << Fibonacci (n);
	return 0;
}