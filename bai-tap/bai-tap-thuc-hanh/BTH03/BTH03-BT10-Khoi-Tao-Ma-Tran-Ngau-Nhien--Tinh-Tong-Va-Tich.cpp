/*
	Bài 10. Viết chương trình dùng cấp phát động để khởi tạo ngẫu nhiên giá trị
		của 2 mảng số nguyên theo dạng thức ma trận.
		Sau đó tính tổng và tích của 2 ma trận đó.
*/

#include <iostream>
#include <ctime>
using namespace std;

void nhapMang(int **a, int dong, int cot);
void inMang(int **a, int dong, int cot);
void tinhTongCuaHaiMaTran(int** a, int** b, int dong, int cot, int** kq);
void tinhTichCuaHaiMaTran(int** a, int** b, int dongMTA, int cotMTA, int cotMTB, int** kq);

int main()
{
	srand(time(0));
	int dongMTA, cotMTA, dongMTB, cotMTB;
	int** a;
	int** b;

	// Nhập số dòng và cột cho ma trận A
	do {
		cout << "Nhap so dong cho ma tran A (1..30): ";
		cin >> dongMTA;

		if (dongMTA < 1 || dongMTA > 30)
			cout << "Vui long nhap so dong (1..30)\n" << endl;
	} while (dongMTA < 1 || dongMTA > 30);
	cout << endl;

	do {
		cout << "Nhap so cot cho ma tran A (1..30): ";
		cin >> cotMTA;

		if (cotMTA < 1 || cotMTA > 30)
			cout << "Vui long nhap so cot (1..30)\n" << endl;
	} while (cotMTA < 1 || cotMTA > 30);
	cout << endl;

	// Nhập số dòng và cột cho ma trận B
	do {
		cout << "Nhap so dong cho ma tran B (1..30): ";
		cin >> dongMTB;

		if (dongMTB < 1 || dongMTB > 30)
			cout << "Vui long nhap so dong (1..30)\n" << endl;
	} while (dongMTB < 1 || dongMTB > 30);
	cout << endl;

	do {
		cout << "Nhap so cot cho ma tran B (1..30): ";
		cin >> cotMTB;

		if (cotMTB < 1 || cotMTB > 30)
			cout << "Vui long nhap so cot (1..30)\n" << endl;
	} while (cotMTB < 1 || cotMTB > 30);
	cout << endl;

	// Cấp phát vùng nhớ cho ma trận A
	a = new int* [dongMTA];
	for (int i = 0; i < dongMTA; i++)
		a[i] = new int[cotMTA];
	
	// Cấp phát vùng nhớ cho ma trận B
	b = new int* [dongMTB];
	for (int i = 0; i < dongMTB; i++)
		b[i] = new int[cotMTB];

	cout << "Ma tran A da duoc khoi tao tu dong!\n";
	nhapMang(a, dongMTA, cotMTA);
	cout << endl;

	cout << "Ma tran A vua duoc tao la:\n";
	inMang(a, dongMTA, cotMTA);
	cout << endl;

	cout << "Ma tran B da duoc khoi tao tu dong!\n";
	nhapMang(b, dongMTB, cotMTB);
	cout << endl;

	cout << "Ma tran B vua duoc tao la:\n";
	inMang(b, dongMTB, cotMTB);
	cout << endl;

	// Kiểm tra điều kiện để tính tổng
	if (dongMTA == dongMTB && cotMTA == cotMTB)
	{
		int** kq;
		kq = new int* [dongMTA];
		for (int i = 0; i < dongMTA; i++)
			kq[i] = new int[cotMTA];

		cout << "Tong ma tran a + b:\n";
		tinhTongCuaHaiMaTran(a, b, dongMTA, cotMTA, kq);
		inMang(kq, dongMTA, cotMTA);
		cout << endl;

		for (int i = 0; i < dongMTA; i++)
			delete[] kq[i];
		delete[] kq;
		kq = NULL;
	}
	else
		cout << "Dieu kien khong phu hop de tinh tong!\n" << endl;
	
	// Kiểm tra điều kiện để tính tích
	if (cotMTA == dongMTB)
	{
		int** kq;
		kq = new int* [dongMTA];
		for (int i = 0; i < dongMTA; i++)
			kq[i] = new int[cotMTB];

		cout << "Tich ma tran a * b:\n";
		tinhTichCuaHaiMaTran(a, b, dongMTA, cotMTA, cotMTB, kq);
		inMang(kq, dongMTA, cotMTB);
		cout << endl;

		for (int i = 0; i < dongMTB; i++)
			delete[] kq[i];
		delete[] kq;
		kq = NULL;
	}
	else
		cout << "Dieu kien khong phu hop de tinh tich!\n" << endl;

	// Huỷ cấp phát vùng nhớ cho con trỏ a
	for (int i = 0; i < dongMTA; i++)
		delete [] a[i];
	delete [] a;
	a = NULL;
	
	// Huỷ cấp phát vùng nhớ cho con trỏ b
	for (int i = 0; i < dongMTA; i++)
		delete [] a[i];
	delete [] a;
	a = NULL;

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

void tinhTongCuaHaiMaTran(int** a, int** b, int dong, int cot, int** kq)
{
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			// kq[i][j] = a[i][j] + b[i][j];
			*(*(kq + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
}

void tinhTichCuaHaiMaTran(int** a, int** b, int dongMTA, int cotMTA, int cotMTB, int** kq)
{
	for (int i = 0; i < dongMTA; i++)
		for (int j = 0; j < cotMTB; j++)
		{
			// kq[i][j] = 0;
			*(*(kq + i) + j) = 0;
			for (int k = 0; k < cotMTA; k++)
				// kq[i][j] += a[i][k] * b[k][j];
				*(*(kq + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);
		}
}
