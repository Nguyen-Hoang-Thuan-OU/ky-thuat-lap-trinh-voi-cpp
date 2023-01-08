/*
	Bài 02: Viết hàm đệ qui để đếm số chữ số của 1 số nguyên dương.
		Sau đó viết chương trình để kiểm tra hàm vừa viết.
*/

#include <iostream>
using namespace std;

int demSoChuSo(int n);

int main()
{
	int n;

	cout << "Vui long nhap (n > 0): ";
	cin >> n;
	do
	{
		if (n < 1)
		{
			cout << "Nhap sai, vui long nhap (n > 0): ";
			cin >> n;
			cout << endl;
		}
	} while(n < 1);

	cout << "Tong so chu so la: " << demSoChuSo(n) << endl;

	return 0;
}

int demSoChuSo(int n)
{
	// Nếu n chỉ có 1 chữ số
	if (n < 10)
		return 1;
	else
		return 1 + demSoChuSo(n / 10);
}