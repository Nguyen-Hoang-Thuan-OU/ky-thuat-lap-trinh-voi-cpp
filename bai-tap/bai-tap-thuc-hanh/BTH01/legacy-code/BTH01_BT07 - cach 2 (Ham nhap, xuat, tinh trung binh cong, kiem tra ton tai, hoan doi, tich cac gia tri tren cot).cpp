// Xây dựng hàm

#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
const int MAX = 10;

// Hàm nhập 1 mảng số nguyên

void nhap (int A[][M], int dong, int cot)
{
for (int i = 0; i < dong; i++)
	for (int j = 0; j < cot; j++)
	{
		A[i][j] = rand()%5;
	}
}

// Hàm xuất 1 mảng số nguyên

void xuat (int A[][M], int dong, int cot)
{
	for (int i = 0; i<dong; i++)
	{
		for (int j = 0; j < cot; j++)
			cout << setw(4) << A[i][j];
		cout << endl;
	}
}

// Hàm tính trung bình cộng

double trungBinhCong (int A[][M], int dong, int cot)
{
	double tong = 0;
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			tong += A[i][j];;
	return tong / (dong * cot);
}

// Hàm nhập mảng số nguyên, kiểm tra xem x có tồn tại trong mảng hay không

bool kiemTra (int A[][M], int dong, int cot, int x)
{
	bool kq = false;
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			if(A[i][j] == x)
			{
				kq = true;
				break;
			}
	return kq;
}

// Hàm nhập 2 giá trị số nguyên x, y, hoán đổi 2 giá trị x, y

void hoanDoi (int A[][M], int dong, int cot, int x, int y)
{
	int xi, xj, yi, yj, tam, demx = 0, demy =0;
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
		{
			if(A[i][j] == x && demx == 0)
			{
				xi = i;
				xj = j;
				demx++;
			}

			if(A[i][j] == y && demy == 0)
			{
				yi = i;
				yj = j;
				demy++;
			}

			if(demx > 0 && demy > 0)
			break;
		}

	if (demx > 0 && demy > 0)
	{
		tam = A[xi][xj];
		A[xi][xj] = A[yi][yj];
		A[yi][yj] = tam;
		}
}

// Hàm tính tích các trị số trong cột
int tichCot (int A[][M], int dong, int cot, int tichCot)
{
	int tich = 1;
	for (int i = 0; i < dong; i++)
		tich *= A[i][tichCot];
	return tich;
}

int main()
{
	int A[M][M], dong, cot, giaTriCanTim, cotTinhTich, x, y;
	do
	{
		cout << "Nhap so dong r: ";
		cin >> dong;
		cout << "Nhap so cot c: ";
		cin >> cot;
		if(dong <= 0 || dong > M|| cot <= 0 || cot > M)
			cout << "Nhap sai! Hay nhap lai!\n";
	}while(dong <= 0 || dong > M|| cot <= 0 || cot > M);

	nhap(A, dong, cot);
	cout << "Xuat mang A:\n";
	xuat(A, dong, cot);
	
	cout << "Trung binh cong mang: " << trungBinhCong(A, dong, cot) << endl;
	
	cout << "Nhap gia tri x can tim: ";
	cin >> giaTriCanTim;
	if (kiemTra(A, dong, cot, giaTriCanTim))
		cout << "Tim thay " << giaTriCanTim << " trong mang" << endl;
	else
		cout << "Khong tim thay " << giaTriCanTim << " trong mang" << endl;
	
	cout << "Nhap x, y de hoan doi: ";
	cin >> x >> y;
	cout << "Ma tran A sau hoan doi " << x << " voi " << y << " la:\n";
	hoanDoi(A, dong, cot, x, y);
	xuat(A, dong, cot);

	cout << "Nhap so cot de tinh tich: ";
	cin >> cotTinhTich;
	cout << "Tich cua cot " << cotTinhTich << " = " << tichCot(A, dong, cot, cotTinhTich) << endl;

	return 0;
}