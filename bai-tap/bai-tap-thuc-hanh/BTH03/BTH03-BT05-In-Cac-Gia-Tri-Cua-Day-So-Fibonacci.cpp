/*
	Bài 05. Dùng con trỏ viết hàm xuất n giá trị của dãy số Fibonacci
		(n do người dùng nhập, là số nguyên > 1).
		Sau đó viết chương trình kiểm chứng lại hàm vừa xây dựng.
*/

#include <iostream>
using namespace std;

int tinhFibonacci(int n);
void inFibonacci(int n);

int main()
{
	int *p;
	p = new int;

	cout << "Nhap do dai day Fibonacci: ";
	cin >> *p;
	do{
		if (*p <= 1)
		{
			cout << "Nhap sai, vui long nhap so luong so can xuat (n > 1): ";
			cin >> *p;
		}
	}while (*p <= 1);

	cout << *p << " gia tri cua day Fibonacci: ";
	inFibonacci(*p);

	delete p;
	p = NULL;

	return 0;
}

int tinhFibonacci(int n)
{
	if (n == 0 || n == 1)
		return n;
	else
		return tinhFibonacci(n - 1) + tinhFibonacci(n - 2);
}

void inFibonacci(int n)
{
	for (int i = 0; i < n; i++)
		cout << tinhFibonacci(i) << " ";
	cout << endl;
}