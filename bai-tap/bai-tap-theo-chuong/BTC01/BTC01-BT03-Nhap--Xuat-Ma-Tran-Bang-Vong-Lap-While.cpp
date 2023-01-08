/*
	Bài 03. Hãy viết chương trình dùng câu lệnh while
		để nhập và xuất giá trị một mảng số nguyên
		gồm 5 hàng và 3 cột.
*/

#include <iostream>
using namespace std;

void nhapMang(int a[5][3]);
void xuatMang(int a[5][3]);

int main()
{
	int a[5][3];

	cout << "\t--- Ma tran 5 hang và 3 cot ---\n";
	cout << endl;

	cout << "Nhap ma tran hai chieu\n" << endl;
	nhapMang(a);
	cout << endl;

	cout << "Ma tran hai chieu la:\n" << endl;
	xuatMang(a);
	cout << endl;

	return 0;
}

// 01. Hàm nhập mảng
void nhapMang(int a[5][3])
{
	// Duyệt từng dòng
	int i = 0;
	while(i < 5)
	{
		// Duyệt từng cột (của từng dòng)
		int j = 0;

		// Nhập một loạt tất cả các phần tử của một dòng
		cout << "Nhap mot loat 3 phan tu cua dong thu [" << i + 1 << "]: ";

		while (j < 3)
		{
			// Đưa một loạt các giá trị vào một dòng
			cin >> a[i][j];
			j++;
		}

		i++;
	}
}

// 02. Hàm xuất mảng
void xuatMang(int a[5][3])
{
	// Duyệt từng dòng
	int i = 0;
	while (i < 5)
	{
		// Duyệt từng cột (của từng dòng)
		int j = 0;
		while (j < 3)
		{
			// In giá trị vừa mới duyệt ra
			cout << a[i][j] << "\t";
			j++;
		}

		// Sau khi in ra hết số cột trên một dòng,
		// mới tiến hành xuống hàng để in dòng mới
		cout << endl;

		i++;
	}
}
