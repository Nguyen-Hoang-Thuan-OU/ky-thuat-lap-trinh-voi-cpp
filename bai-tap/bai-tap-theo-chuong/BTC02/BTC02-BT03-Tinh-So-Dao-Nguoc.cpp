/*
	Bài 03: Viết hàm đệ qui để tính số đảo ngược của 1 số nguyên dương.
		Sau đó viết chương trình để kiểm tra hàm vừa viết.
*/

// Chưa tối ưu: nếu có nhiều số 0 phía sau
//		Ví dụ: 123000
//			-> 321 (mất các số 0)

#include <iostream>
using namespace std;

int tinhSoDaoNguoc(int n, int soDaoNguoc);

int main()
{
	int n;
	int soDaoNguoc = 0;

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

	//soDaoNguoc = tinhSoDaoNguoc(n, soDaoNguoc);
	cout << "So dao nguoc la: " << tinhSoDaoNguoc(n, soDaoNguoc) << endl;

	return 0;
}

int tinhSoDaoNguoc(int n, int soDaoNguoc)
{
	if (n == 0)
		return soDaoNguoc;
	else
	{
		soDaoNguoc = soDaoNguoc * 10 + n % 10;
		return tinhSoDaoNguoc(n / 10, soDaoNguoc);
	}
}