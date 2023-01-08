/*
	Bài 02. Viết chương trình thực hiện các yêu cầu sau:
		a. Khai báo 1 mảng số nguyên tối đa 30 phần tử.
		b. Khởi tạo 1 mảng số nguyên với giá trị ngẫu nhiên (các giá trị nhỏ hơn 10).
		c. Khai báo biến con trỏ p trỏ đến mảng vừa khởi tạo.
		d. Dùng con trỏ và ký pháp độ dời để xuất các giá trị đang lưu trữ trong mảng.
		e. Dùng con trỏ và ký pháp chỉ số để xuất các giá trị đang lưu trữ trong mảng.
*/

#include <iostream>
#include <ctime>
using namespace std;

const int MAX = 30;

void mangNgauNhien(int a[], int n);
void inMangBangConTroVaKyPhapDoDoi(int*& p, int n);
void inMangBangConTroVaKyPhapChiSo(int*& p, int n);

int main()
{
	srand(time(0));
	int a[MAX];
	int n;
	int* p;
	
	do {
		cout << "Nhap so luong phan tu cua mang (1..30): ";
		cin >> n;
		cout << endl;

		if (n <= 0 || n > MAX)
			cout << "Nhap sai, vui long nhap lai (1..30)!\n" << endl;
	} while (n <= 0 || n > MAX);

	p = a;

	cout << "Mang duoc tao ngau nhien!";
	mangNgauNhien(a, n);
	cout << endl;

	cout << "Mang duoc in bang con tro theo ky phap do doi\n";
	inMangBangConTroVaKyPhapDoDoi(p, n);
	cout << endl;

	cout << "Mang duoc in bang con tro theo ky phap chi so\n";
	inMangBangConTroVaKyPhapChiSo(p, n);
	cout << endl;

	return 0;
}

// 01. Hàm nhập mảng ngẫu nhiên
void mangNgauNhien(int a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
	cout << endl;
}

// 02. In mảng bằng ký pháp độ dời
void inMangBangConTroVaKyPhapDoDoi(int*& p, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(p + i) << "  ";
	cout << endl;
}

// 03. In mảng bằng ký pháp chỉ số
void inMangBangConTroVaKyPhapChiSo(int*& p, int n)
{
	for (int i = 0; i < n; i++)
		cout << p[i] << "  ";
	cout << endl;
}