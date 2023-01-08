/*
	Bài 07. Viết 01 chương trình thực hiện các yêu cầu sau:

		a. Xây dựng các hàm:
			- Nhập vào 1 mảng số nguyên gồm r hàng và c cột;
			- Xuất giá trị 1 mảng số nguyên gồm r hàng và c cột.

		b. Xây dựng hàm trả về giá trị trung bình cộng
		   của các phần tử trong 1 mảng số nguyên gồm r hàng và c cột

		c. Xây dựng hàm nhận vào 1 mảng số nguyên gồm r hàng và c cột;
		   giá trị số nguyên x.
		   Kiểm tra xem x có tồn tại trong mảng hay không
		   và trả về kết quả tương ứng.

		d. Xây dựng hàm nhận vào 1 mảng số nguyên gồm r hàng và c cột
		   (giả sử các giá trị nhập không trùng nhau) và 2 giá trị số nguyên x và y
		   (x và y phải đều tồn tại trong mảng).
		   Tiến hành hoán đổi 2 giá trị x và y này.
		   * Lưu ý: sử dụng lại hàm đã xây dựng ở câu c.

		e. Xây dựng hàm nhận vào 1 mảng số nguyên gồm r hàng và c cột;
		   vị trí cột cần tính tích.
		   Sau đó trả về tích các giá trị số trong cột đã nhận vào.

		f. Viết hàm main để kiểm tra các hàm đã xây dựng.
*/

#include <iostream>
#include <ctime>
using namespace std;

const int MAX = 10;

void nhapMang(int a[][MAX], int dong, int cot);
void xuatMang(int a[][MAX], int dong, int cot);
double tinhTrungBinhCong(int a[][MAX], int dong, int cot);
bool kiemTraCoTonTai(int a[][MAX], int dong, int cot, int soCanTim);
void hoanDoiGiaTri(int a[][MAX], int dong, int cot, int &x, int &y);
int tinhTichCot(int a[][MAX], int dong, int cot, int cotTinhTich);

int main()
{
	srand(time(0));

	int a[MAX][MAX], dong, cot;
	int x, y;
	int cotTinhTich;
	//int soCanTim;

	do {
		cout << "Nhap so dong (1..50): ";
		cin >> dong;

		if (dong <= 0 || dong > MAX)
			cout << "Nhap sai, vui long nhap lai";
	} while (dong <= 0 || dong > MAX);

	do {
		cout << "Nhap so cot (1..50): ";
		cin >> cot;

		if (cot <= 0 || cot > MAX)
			cout << "Nhap sai, vui long nhap lai";
	} while (cot <= 0 || cot > MAX);

	// Nhập mảng
	nhapMang(a, dong, cot);
	cout << endl;

	// Xuất mảng
	cout << "Ma tran la:\n";
	xuatMang(a, dong, cot);
	cout << endl;

	// Tính trung bình cộng
	cout << "Trung binh cong cua cac phan tu trong mang la: "
		<< tinhTrungBinhCong(a, dong, cot) << endl;
	cout << endl;

	// Kiểm tra tồn tại
	//cout << "Nhap so can tim trong mang: ";
	//cin >> soCanTim;
	//cout << endl;

	//if (kiemTraCoTonTai(a, dong, cot, soCanTim) == true)
	//	cout << "So [" << soCanTim << "] co ton tai trong mang!\n";
	//else
	//	cout << "So [" << soCanTim << "] khong ton tai trong mang!\n";

	cout << endl;

	// Nhập các giá trị để hoán đổi
	cout << "Nhap 2 gia tri x va y de hoan doi\n";
	cout << "(Hoan doi 2 gia tri hien co trong ma tran)\n";
	cout << endl;

	// Hoán đổi x và y sau khi đã hợp lệ
	hoanDoiGiaTri(a, dong, cot, x, y);
	cout << endl;

	// Xuất ma trận sau khi đã hoán đổi
	cout << "Ma tran sau khi hoan doi " << x << " va " << y << " la:\n";
	xuatMang(a, dong, cot);
	cout << endl;

	// Tính tích của cột tuỳ chọn
	do {
		cout << "Nhap cot can tinh tich (1.." << cot << "): ";
		cin >> cotTinhTich;
		cout << endl;

		if (cotTinhTich <= 0 || cotTinhTich > cot)
			cout << "Vui long nhap cot tinh tich (1.." << cot << ")\n" << endl;
	} while (cotTinhTich <= 0 || cotTinhTich > cot);

	cout << "Tich cua cot " << cotTinhTich << " la: "
		<< tinhTichCot(a, dong, cot, cotTinhTich) << endl;
	cout << endl;

	return 0;
}

// 01. Hàm nhập mảng
void nhapMang(int arr[][MAX], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			arr[i][j] = rand() % 5;
}

// 02. Hàm xuất mảng
void xuatMang(int arr[][MAX], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			cout << arr[i][j] << "\t";

		cout << endl;
	}
}

// 03. Hàm tính trung bình cộng
double tinhTrungBinhCong(int a[][MAX], int dong, int cot)
{
	double ketQua;
	int tong = 0;

	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			tong = tong + a[i][j];

	ketQua = (double)tong / (dong * cot);

	return ketQua;
}

// 04. Hàm kiểm tra một số có tồn tại trong mảng
bool kiemTraCoTonTai(int a[][MAX], int dong, int cot, int soCanTim)
{
	bool ketQua = false;

	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			if (a[i][j] == soCanTim)
				ketQua = true;

	return ketQua;
}

// 05. Hàm hoán đổi vị trí của hai số
void hoanDoiGiaTri(int a[][MAX], int dong, int cot, int &x, int &y)
{
	// Kiểm tra x có tồn tại
	do {
		cout << "Nhap x = ";
		cin >> x;

		if (kiemTraCoTonTai(a, dong, cot, x) == false)
		{
			cout << "So [" << x << "] khong ton tai trong mang!\n";
			cout << endl;
		}
	} while (kiemTraCoTonTai(a, dong, cot, x) == false);

	// Kiểm tra y có tồn tại
	do {
		cout << "Nhap y = ";
		cin >> y;

		if (kiemTraCoTonTai(a, dong, cot, y) == false)
		{
			cout << "So [" << y << "] khong ton tai trong mang!\n";
			cout << endl;
		}
	} while (kiemTraCoTonTai(a, dong, cot, y) == false);

	// Nếu nhập x và y hợp lệ
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			if (a[i][j] == x)
				a[i][j] = y;
			else
				if (a[i][j] == y)
					a[i][j] = x;
}

// 06. Hàm tính tích của một cột tuỳ chọn
int tinhTichCot(int a[][MAX], int dong, int cot, int cotTinhTich)
{
	int ketQua = 1;

	for (int i = 0; i < dong; i++)
		ketQua = ketQua * a[i][cotTinhTich - 1];

	return ketQua;
}