/*
	Bài 10. Viết hàm đệ qui tìm ước số chung lớn nhất của hai số nguyên.
		Sau đó xây dựng chương trình để mô phỏng và kiểm tra hàm vừa xây dựng.

		* Uớc chung lớn nhất của 2 số nguyên a và b
		  có thể được tính bằng thuật giải Euclid như sau:

			Bước 1: nếu b = 0 thì kết quả là a và kết thúc,
				ngược lại sang bước 2.

			Bước 2: a % b -> d = số dư. Sang bước 3.

			Bước 3: gán a = b, b = d (số dư). Quay lại bước 1.
*/

#include <iostream>
using namespace std;

int tinhUocChungLonNhat(int a, int b);

int main()
{
	int a, b;

	cout << "Tim uoc chung lon nhat cua hai so nguyen\n";
	cout << endl;

	// Nhập số thứ nhất
	do {
		cout << "Nhap vao mot so nguyen thu nhat (a > 0): ";
		cin >> a;
		cout << endl;

		if (a <= 0)
			cout << "Nhap sai, vui long nhap lai mot so nhi phan (a > 0)!\n" << endl;
	} while (a <= 0);

	// Nhập số thứ hai
	do {
		cout << "Nhap vao mot so nguyen thu hai (b > 0): ";
		cin >> b;
		cout << endl;

		if (b <= 0)
			cout << "Nhap sai, vui long nhap lai mot so nhi phan (b > 0)!\n" << endl;
	} while (b <= 0);

	cout << "Uoc chung lon nhat giua hai so " << a << " va " << b
		<< " la: " << tinhUocChungLonNhat(a, b) << endl;
	cout << endl;

	return 0;
}

// Hàm tìm ước số chung lớn nhất của hai số nguyên
int tinhUocChungLonNhat(int a, int b)
{
	int d;

	if (b == 0)
		return a;
	else
	{
		d = a % b;
		a = b;
		b = d;

		return tinhUocChungLonNhat(a, b);
	}
}