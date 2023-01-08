/*
	Bài 05. Viết hàm đệ qui đếm số chữ số của một số nguyên không âm.
		Sau đó xây dựng chương trình để mô phỏng và kiểm tra hàm vừa xây dựng.
*/

#include <iostream>
using namespace std;

int demChuSoNguyenDuong(int n);
int tinhTongCacChuSo(int n);

int main()
{
	int n;

	cout << "Dem so chu so\n";
	cout << endl;

	do {
		cout << "Nhap vao mot so nguyen (n > 0): ";
		cin >> n;
		cout << endl;

		if (n <= 0)
			cout << "Nhap sai, vui long nhap lai mot so nguyen (n > 0)!\n" << endl;
	} while (n <= 0);

	cout << "So nguyen " << n << " co tong so chu so la: "
		<< demChuSoNguyenDuong(n) << endl;
	
	cout << "So nguyen " << n << " co tong cac chu so la: "
		<< tinhTongCacChuSo(n) << endl;
	cout << endl;

	return 0;
}

// 01. Hàm đệ qui đếm số chữ số của một số nguyên không âm
int demChuSoNguyenDuong(int n)
{
	// Chỉ có một chữ số
	if (n >= 0 && n <= 9) // n < 10
		// Trả về kết quả chỉ có một chữ số,
		// không trả về n vì n có thể là số khác một
		return 1;
	else
		return 1 + demChuSoNguyenDuong(n / 10);
}

// 02. Hàm tình tổng các chữ số
int tinhTongCacChuSo(int n)
{
	if (n >= 0 && n <= 9) // n < 10
		return n;
	else
		return n % 10 + tinhTongCacChuSo(n / 10);
}