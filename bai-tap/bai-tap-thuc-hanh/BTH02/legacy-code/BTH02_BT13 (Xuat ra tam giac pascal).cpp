// Xuất 1 tam giác Pascal

#include<iostream>
#include<iomanip>
using namespace std;

int giaiThua(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return giaiThua(n - 1) * n;
}

int toHop(int n, int k)
{
	return giaiThua(n) / (giaiThua(k) * giaiThua(n - k));
}

void inTamGiac(int n)
{
	if (n == 1)
		cout << setw(4) << 1;
	else
	{
		inTamGiac(n - 1);
		cout << endl;
		for (int i = 0; i < n; i++)
			cout << setw(4) << toHop(n - 1, i);
	}
}

int main()
{
	int n;
	cout << "Nhap chieu cao tam giac: ";
	cin >> n;
	inTamGiac(n);
	cout << endl;

	return 0;
}