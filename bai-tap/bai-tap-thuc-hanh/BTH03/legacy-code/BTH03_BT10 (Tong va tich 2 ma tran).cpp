//Viết chương trình dùng cấp phát động để khởi tạo ngẫu nhiên giá trị
//của 2 mảng sốnguyên theo dạng thức ma trận.
//Sau đó tính tổng và tích của 2 ma trận đó.

#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

void nhap(int **a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			a[i][j] = rand() % 10;
}
void xuat(int **a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
}

void tongMT(int **a, int **b, int **kq, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			kq[i][j] = a[i][j] + b[i][j];
}
void tichMT(int **a, int **b, int **kq, int dong1, int cot1, int cot2)
{
	for (int i = 0; i < dong1; i++)
		for (int j = 0; j < cot2; j++)
		{
			kq[i][j] = 0;
			for (int k = 0; k < cot1; k++)
				kq[i][j] += a[i][k] * b[k][j];
		}
}

int main()
{
	int **a;
	int **b;
	int **kq;
	int dong, cot;

	//Tính tổng
	cout << "--TINH TONG--" << endl;
	cout << "Nhap so dong cua 2 MT: ";
	cin >> dong;
	cout << "Nhap so cot cua 2 MT: ";
	cin >> cot;

	a = new int* [dong];
	for (int i = 0; i < dong; i++)
		a[i] = new int [cot];

	b = new int* [dong];
	for (int i = 0; i < dong; i++)
		b[i] = new int [cot];

	kq = new int* [dong];
	for (int i = 0; i < dong; i++)
		kq[i] = new int [cot];

	nhap (a, dong, cot);
	cout << "Ma tran 1:\n";
	xuat (a, dong, cot);
	cout << endl;

	nhap (b, dong, cot);
	cout << "Ma tran 2:\n";
	xuat (b, dong, cot);
	cout << endl;

	tongMT(a, b, kq, dong, cot);
	cout << "->Tong 2 ma tran:\n";
	xuat (kq, dong, cot);
	cout << endl;

	//Hủy cấp phát - tính tổng
	for (int i = 0; i < dong; i++)
		delete [] a[i];
	delete [] a;
	a = nullptr;

	for (int i = 0; i < dong; i++)
		delete [] b[i];
	delete [] b;
	b = nullptr;

	for (int i = 0; i < cot; i++)
		delete [] kq[i];
	delete [] kq;
	kq = nullptr;

	//Tính tích
	int dong1, cot1, cot2;

	cout << "--TINH TICH--" << endl;
	cout << "Nhap so dong MT 1: ";
	cin >> dong1;
	cout << "Nhap so cot MT 1 = so dong MT 2: ";
	cin >> cot1;
	cout << "Nhap so cot MT 2: ";
	cin >> cot2;

	a = new int* [dong1];
	for (int i = 0; i < dong1; i++)
		a[i] = new int [cot1];

	b = new int* [cot1];
	for (int i = 0; i < cot1; i++)
		b[i] = new int [cot2];

	kq = new int* [dong1];
	for (int i = 0; i < dong1; i++)
		kq[i] = new int [cot2];

	nhap(a, dong1, cot1);
	cout << "Ma tran 1:\n";
	xuat(a, dong1, cot1);
	cout << endl;

	nhap(b, cot1, cot2);
	cout << "Ma tran 2:\n";
	xuat(b, cot1, cot2);
	cout << endl;

	tichMT(a, b, kq, dong1, cot1, cot2);
	cout << "->Tich 2 ma tran:\n";
	xuat (kq, dong1, cot2);
	cout << endl;

	//Hủy cấp phát - tính tích
	for (int i = 0; i < dong1; i++)
		delete [] a[i];
	delete [] a;
	a = nullptr;

	for (int i = 0; i < cot1; i++)
		delete [] b[i];
	delete [] b;
	b = nullptr;

	for (int i = 0; i < dong1; i++)
		delete [] kq[i];
	delete [] kq;

	return 0;
}