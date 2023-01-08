/*
	Bài 09. Viết chương trình dùng cấp phát động của con trỏ để viết:
		- Hàm nhập 1 mảng số nguyên r hàng và c cột.
		- Hàm xuất 1 mảng số nguyên r hàng c cột.
		- Hàm dùng con trỏ để tính tổng các phần tử nào là số nguyên tố
		  trong mảng 2 chiều.
		- Hàm dùng để trả về các số nguyên tố trong mảng 2 chiều.
		- Hàm main để kiểm chứng.
*/

#include <iostream>
#include <ctime>
using namespace std;

void nhapMang(int **a, int dong, int cot);
void inMang(int **a, int dong, int cot);
bool coPhaiLaSoNguyenTo(int n);
void inCacSoNguyenTo(int **a, int dong, int cot);
int tinhTongCacSoNguyenTo(int **a, int dong, int cot);

int main()
{
	srand(time(0));
	int **p;
	int dong, cot;

	do {
		cout << "Nhap so dong (1..30): ";
		cin >> dong;

		if (dong < 1 || dong > 30)
			cout << "Vui long nhap so dong (1..30)\n" << endl;
	} while (dong < 1 || dong > 30);
	cout << endl;

	do {
		cout << "Nhap so cot (1..30): ";
		cin >> cot;

		if (cot < 1 || cot > 30)
			cout << "Vui long nhap so cot (1..30)\n" << endl;
	} while (cot < 1 || cot > 30);
	cout << endl;

	p = new int* [dong];
	for ( int i = 0 ; i < dong ; i++ )
		p[i] = new int[cot];

	cout << "Ma tran da duoc khoi tao tu dong!\n";
	nhapMang(p, dong, cot);
	cout << endl;

	cout << "Ma tran vua duoc tao la:\n";
	inMang(p, dong, cot);
	cout << endl;

	cout << "Cac so nguyen to trong ma tran: ";
	inCacSoNguyenTo(p, dong, cot);
	cout << endl;

	cout << "Tong so nguyen to trong ma tran: "
		<< tinhTongCacSoNguyenTo(p, dong, cot);
	cout << endl;

	for (int i = 0; i < dong; i++)
		delete [] p[i];
	delete [] p;
	p = NULL;

	return 0;
}

void nhapMang(int **a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			*(*(a + i) + j) = rand() % 20; // a[i][j]
}

void inMang(int **a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			cout << *(*(a + i) + j) << "\t"; // a[i][j]

		cout << endl;
	}
}

bool coPhaiLaSoNguyenTo(int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i <= sqrt(n * 1.0); i++)
		if (n % i == 0)
			return false;

	return true;
}

void inCacSoNguyenTo(int **a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			if (coPhaiLaSoNguyenTo(a[i][j]) == true) // *(*(a + i) + j)
				cout << *(*(a + i) + j) << " "; // a[i][j]
}

int tinhTongCacSoNguyenTo(int **a, int dong, int cot)	
{
	int tongCacSoNguyenTo = 0;
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			if (coPhaiLaSoNguyenTo(a[i][j]) == true) // *(*(a + i) + j)
				tongCacSoNguyenTo = tongCacSoNguyenTo + a[i][j];

	return tongCacSoNguyenTo;
}