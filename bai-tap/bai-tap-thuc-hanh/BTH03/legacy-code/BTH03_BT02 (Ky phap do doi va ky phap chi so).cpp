#include<iostream>
#include<cstdlib>
using namespace std;
const int MAX = 30;

int main()
{
	// Khai báo mảng số nguyên tối đa 30 phần từ

	int a[MAX];

	// Khởi tạo mảng số nguyên với giá trị ngẫu nhiên (giá trị < 10)

	for (int i = 0; i < MAX; i++)
	{
		a[i] = rand()%10;
		cout << " " << a[i];
	}

	// Con trỏ p trỏ đến mảng vừa khởi tạo

	int *p = a;

	// Dùng con trỏ và ký pháp độ dời để xuất mảng

	for (int i = 0; i < MAX; i++)
	{
		cout << " " << a[i];
	}
	cout << endl;

	return 0;
}