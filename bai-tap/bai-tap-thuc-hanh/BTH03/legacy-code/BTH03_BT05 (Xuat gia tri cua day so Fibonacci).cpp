// Xuất n giá trị của dãy số Fibonacci

#include<iostream>
using namespace std;

void Fibo (int n)
{
	int * p;
	int t;
	int u = 0, v = 1;
	if ( n == 1 )
		cout << " 0 "<< endl;
	else
	{
		if ( n == 2 )
			cout << " 0 1 " << endl;
		else
		{
			for ( int i = 3; i <= n; i++ )
			{
				t = u + v;
				u = v;
				v = t;
				p = &t;
				cout << " " << *p << endl;
			}
		}
	}
}

int main()
{
	int n;
	cout << "Nhap so luong so can xuat: ";
	cin >> n;
	Fibo(n);

	return 0;
}