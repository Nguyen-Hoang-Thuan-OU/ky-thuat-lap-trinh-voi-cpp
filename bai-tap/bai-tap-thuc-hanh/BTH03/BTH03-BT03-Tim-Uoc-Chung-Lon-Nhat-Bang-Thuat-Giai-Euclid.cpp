/*
	Bài 03. Viết chương trình dùng cấp phát động để cho phép 2 con trỏ lưu trữ giá trị của 2 số nguyên.
		Sau đó dựa trên địa chỉ mà con trỏ trỏ đến
		để tìm ước chung lớn nhất của 2 giá trị số nguyên này bằng thuật giải Euclid.

		* Uớc chung lớn nhất của 2 số nguyên a và b
		  có thể được tính bằng thuật giải Euclid như sau:

			Bước 1: nếu b = 0 thì kết quả là a và kết thúc,
				ngược lại sang bước 2.

			Bước 2: a % b -> d = số dư. Sang bước 3.

			Bước 3: gán a = b, b = d (số dư). Quay lại bước 1.
*/

#include <iostream>
using namespace std;

int tinhUocChungLonNhat(int*& pa, int*& pb);

int main()
{
	int* pa = new int;
	int* pb = new int;

	int tmpa, tmpb;

	cout << "Tim uoc chung lon nhat cua hai so nguyen\n";
	cout << endl;

	// Nhập số thứ nhất
	do {
		cout << "Nhap vao mot so nguyen thu nhat (a > 0): ";
		cin >> *pa;
		cout << endl;

		tmpa = *pa;

		if (*pa <= 0)
			cout << "Nhap sai, vui long nhap lai mot so nhi phan (a > 0)!\n" << endl;
	} while (*pa <= 0);

	// Nhập số thứ hai
	do {
		cout << "Nhap vao mot so nguyen thu hai (b > 0): ";
		cin >> *pb;
		cout << endl;

		tmpb = *pb;

		if (*pb <= 0)
			cout << "Nhap sai, vui long nhap lai mot so nhi phan (b > 0)!\n" << endl;
	} while (*pb <= 0);

	cout << "Uoc chung lon nhat giua hai so " << tmpa << " va " << tmpb
		<< " la: " << tinhUocChungLonNhat(pa, pb) << endl;
	cout << endl;

	delete pa;
	pa = NULL;
	delete pb;
	pb = NULL;

	return 0;
}

// Hàm tìm ước số chung lớn nhất của hai số nguyên
int tinhUocChungLonNhat(int*& pa, int*& pb)
{
	int d;
	
	//int *d;
	//d = new int;

	while (*pb != 0)
	{
		d = *pa % *pb;
		*pa = *pb;
		*pb = d;
	}

	//delete d;
	//d = NULL;

	return *pa;
}