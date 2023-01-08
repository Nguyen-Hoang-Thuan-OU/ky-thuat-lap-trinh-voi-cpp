/*
	Bài 04. Viết chương trình dùng cấp phát động, cho phép:

		- Nhập vào 1 mảng 1 chiều lưu trữ số nguyên tối đa 30 phần tử.

		- Dùng con trỏ và ký pháp độ dời
		  để xuất ra các phần tử nào là số lẻ trong mảng.

		- Trả về địa chỉ của giá trị phần tử lớn nhất trong mảng
		  (giả sử các giá trị trong mảng không trùng nhau).
*/

#include <iostream>
#include <ctime>
using namespace std;

void nhapMang(int* a, int n);
void inMang(int* a, int n);
void inCacPhanTuLaSoLe(int* a, int n);
int* timGiaTriLonNhat(int* a, int n);
void inToanBoDiaChiTrongMang(int* a, int n);

int main()
{
	srand(time(0));
	int* p;
	int n;

	do {
		cout << "Nhap so luong phan tu (1..30): ";
		cin >> n;

		if (n < 1 || n > 30)
			cout << "Vui long nhap so luong phan tu (1..30)\n" << endl;
	} while (n < 1 || n > 30);
	cout << endl;

	p = new int[n];

	cout << "Mang da duoc tao tu dong!";
	nhapMang(p, n);
	cout << endl;

	cout << "Mang hien tai la: ";
	inMang(p, n);
	cout << endl;

	cout << "Cac so le trong mang la: ";
	inCacPhanTuLaSoLe(p, n);
	cout << endl;

	cout << "Dia chi cua gia tri lon nhat trong mang: " << timGiaTriLonNhat(p, n);
	cout << endl;

	cout << "Dia chi de doi chieu:\n";
	inToanBoDiaChiTrongMang(p, n);
	cout << endl;
}

// 01. Hàm nhập mảng
void nhapMang(int* a, int n) 
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 30;
}

// 02. Hàm in mảng
void inMang(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
}

// 03. Hàm sử dụng con trỏ và ký pháp độ dời
//     để in các phần tử là số lẻ trong mảng
void inCacPhanTuLaSoLe(int* a, int n)
{
	for(int i = 0; i < n; i++)
		if (*(a + i) % 2 != 0)
			cout << *(a + i) << "  ";
}

// 04. Hàm trả về địa chỉ
//     của giá trị phần tử lớn nhất trong mảng
//     (Kết quả trả về là một địa chỉ
//	nên cần kiểu dữ liệu con trỏ để nhận)
int* timGiaTriLonNhat(int* a, int n)
{
	int max = a[0];
	int diaChi;

	for (int i = 0; i < n; i++)
		if (a[i] > max)
		{
			max = a[i];
			diaChi = i;
		}
			
	return &a[diaChi];
}

// 05. Hàm in toàn bộ địa chỉ của các phần tử trong mảng
//     để phục vụ cho việc đối chiếu với hàm 04
void inToanBoDiaChiTrongMang(int* a, int n)
{
	for(int i = 0; i < n; i++)
		cout << "a[" << i << "] - " << a[i] << " : " << &a[i] << endl;
}