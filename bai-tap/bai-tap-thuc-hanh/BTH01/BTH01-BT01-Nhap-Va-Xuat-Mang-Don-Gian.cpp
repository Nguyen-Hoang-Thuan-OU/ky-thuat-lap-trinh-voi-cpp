/*
	Bài 01. Viết 01 chương trình thực hiện toàn bộ các công việc sau:
	
		a. Khai báo một mảng số nguyên gồm 3 hàng và 4 cột.
			
		b. Khởi tạo giá trị của mảng vừa nhập lần lượt như sau:
			 8	4  -1	5
			 2	2	6	9
			11	2	5	4
					
		c. Xuất lại toàn bộ mảng đang lưu trữ để kiểm chứng.
*/

#include <iostream>
using namespace std;

// Khai số dòng và số cột tối đa
const int DONG_TOI_DA = 3, COT_TOI_DA = 4;

void nhapMang(int a[DONG_TOI_DA][COT_TOI_DA]);
void xuatMang(int a[DONG_TOI_DA][COT_TOI_DA]);

int main()
{
	int a[DONG_TOI_DA][COT_TOI_DA];

	// Gọi hàm nhapMang()
	nhapMang(a);
	cout << endl;

	// Gọi hàm xuatMang()
	xuatMang(a);
	cout << endl;

	return 0;
}

// a. Khai báo một mảng số nguyên gồm 3 hàng và 4 cột.
// b. Khởi tạo giá trị của mảng vừa nhập.
void nhapMang(int a[DONG_TOI_DA][COT_TOI_DA])
{
	for (int i = 0; i < DONG_TOI_DA; i++)
	{
		cout << "Nhap " << COT_TOI_DA
			<< " so nguyen cho dong thu [" << i + 1 << "]: ";
		for (int j = 0; j < COT_TOI_DA; j++)
			cin >> a[i][j];
	}
}

// c. Xuất lại toàn bộ mảng đang lưu trữ để kiểm chứng.
void xuatMang(int a[DONG_TOI_DA][COT_TOI_DA])
{
	cout << "Mang vua nhap la: \n";
	for (int i = 0; i < DONG_TOI_DA; i++)
	{
		for (int j = 0; j < COT_TOI_DA; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}