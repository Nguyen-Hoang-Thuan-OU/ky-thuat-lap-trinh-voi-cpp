/*
	MẢNG HAI CHIỀU - CẤP PHÁT TĨNH
*/

#include <iostream>
#include <ctime>
using namespace std;

const int maxDong = 100;
const int maxCot = 50;

void nhapMaTran(int a[][maxCot], int dong, int cot);
void xuatMaTran(int a[][maxCot], int dong, int cot);
bool coPhaiLaSoNguyenTo(int n);
int tongCacSoNguyenTo(int a[][maxCot], int dong, int cot);
void tongCacPhanTuTrenTungDong(int a[][maxCot], int dong, int cot);
void tongCacPhanTuTrenTungCot(int a[][maxCot], int dong, int cot);
void inRaCacPhanTuTrenDuongCheoChinh(int a[][maxCot], int dong, int cot);
void inRaCacPhanTuTrenDuongCheoPhu(int a[][maxCot], int dong, int cot);

int main()
{
	srand(time(0));

	int a[maxDong][maxCot];
	int dong = 5, cot = 5;

	cout << "Mang duoc tao tu dong!\n";
	nhapMaTran(a, dong, cot);
	cout << endl;

	cout << "Mang vua duoc tao:\n";
	xuatMaTran(a, dong, cot);
	cout << endl;

	cout << "Tong cac so nguyen to trong mang: " << tongCacSoNguyenTo(a, dong, cot) << endl;
	cout << endl;

	cout << "Tong tung dong:\n";
	tongCacPhanTuTrenTungDong(a, dong, cot);
	cout << endl;

	cout << "Tong tung cot:\n";
	tongCacPhanTuTrenTungCot(a, dong, cot);
	cout << endl;

	cout << "Cac phan tu nam tren duong cheo chinh: ";
	inRaCacPhanTuTrenDuongCheoChinh(a, dong, cot);
	cout << endl;

	cout << "Cac phan tu nam tren duong cheo phu: ";
	inRaCacPhanTuTrenDuongCheoPhu(a, dong, cot);
	cout << endl;

	return 0;
}

void nhapMaTran(int a[][maxCot], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			a[i][j] = rand() % 10;
}

void xuatMaTran(int a[][maxCot], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

bool coPhaiLaSoNguyenTo(int n)
{
	if (n < 2)
		return false;
	else if (n == 2)
		return true;
	else if (n % 2 == 0)
		return false;
	else
		for (int i = 2; i < n; i++)
			if (n % i == 0)
				return false;

	return true;
}

int tongCacSoNguyenTo(int a[][maxCot], int dong, int cot)
{
	int tongSoNguyenTo = 0;
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			if (coPhaiLaSoNguyenTo(a[i][j]) == true)
				tongSoNguyenTo = tongSoNguyenTo + a[i][j];

	return tongSoNguyenTo;
}

void tongCacPhanTuTrenTungDong(int a[][maxCot], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		// Tổng cho từng dòng khác nhau,
		// mỗi dòng sẽ có một tổng khác nhau
		int tongTungDong = 0;

		for (int j = 0; j < cot; j++)
			tongTungDong = tongTungDong + a[i][j];
		cout << "Tong dong [" << i << "]: " << tongTungDong << endl;
	}
}

void tongCacPhanTuTrenTungCot(int a[][maxCot], int dong, int cot)
{
	for (int j = 0; j < cot; j++) // j
	{
		// Tổng cho từng cột khác nhau,
		// mỗi cột sẽ có một tổng khác nhau
		int tongTungCot = 0;

		for (int i = 0; i < dong; i++) // i
			tongTungCot = tongTungCot + a[i][j];
		cout << "Tong cot [" << j << "]: " << tongTungCot << endl;
	}
}

// Chỉ xuất hiện trên ma trận vuông
void inRaCacPhanTuTrenDuongCheoChinh(int a[][maxCot], int dong, int cot)
{
	// Vì đây là ma trận vuông
	// nên duyệt theo số dòng hoặc số cột là như nhau
	for (int i = 0; i < dong; i++)
		cout << a[i][i] << " ";
}


void inRaCacPhanTuTrenDuongCheoPhu(int a[][maxCot], int dong, int cot)
{
	// Vì đây là ma trận vuông
	// nên duyệt theo số dòng hoặc số cột là như nhau
	for (int i = 0; i < dong; i++)
		cout << a[i][cot - i - 1] << " ";
}