/*
	Bài 04. Viết chương trình dùng cấp phát động
		để xây dựng hàm nhập, xuất 1 mảng số nguyên gồm m hàng và n cột,
		hàm trả về vị trí lưu trữ
		của giá trị đầu tiên trong mảng là số nguyên tố.
		Viết chương trình kiểm tra các hàm trên.
*/

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include <ctime>
using namespace std;

void nhapMang(int **a, int dong, int cot);
void xuatMang(int **a, int dong, int cot);
bool kiemTraSoNguyenTo (int n);
void viTriCuaSoNguyenToDauTien(int **a, int dong, int cot, int &vtDong, int &vtCot);

int main()
{
	srand(time(0));
	int **a;
	int dong, cot;
	int vtDong = -1, vtCot = 0;

	cout << "Nhap so dong (dong > 0): ";
	cin >> dong;
	do{
		if (dong < 1)
		{
			cout << "Nhap sai, vui long nhap so dong (dong > 0): ";
			cin >> dong;
		}
	} while(dong < 1);
	cout << endl;

	cout << "Nhap so cot (cot > 0): ";
	cin >> cot;
	do{
		if (cot < 1)
		{
			cout << "Nhap sai, vui long nhap so cot (cot > 0): ";
			cin >> cot;
		}
	} while(cot < 1);
	cout << endl;

	a = new int *[dong];
	for (int i = 0; i < dong; i++)
		a[i] = new int[cot];

	nhapMang(a, dong, cot);
	xuatMang(a, dong, cot);
	cout << endl;

	viTriCuaSoNguyenToDauTien(a, dong, cot, vtDong, vtCot);
	
	if(vtDong >= 0)
	{
		cout << "Vi tri cua so nguyen to dau tien trong mang:\n";
		cout << "\tDong: " << vtDong + 1 << endl;
		cout << "\tCot: " << vtCot + 1 << endl;
	}
	else
		cout << "Khong co so nguyen to trong mang\n";

	for (int i = 0; i < dong; i++)
		delete[]a[i];
	delete[]a;
	a = NULL;

	return 0;
}

void nhapMang(int **a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			a[i][j] = rand() % 100;
}

void xuatMang(int **a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
}

bool kiemTraSoNguyenTo(int x)
{
	if (x < 2)
		return false;

	for (int i = 2; i <= sqrt(x * 1.0); i++)
		if (x % i == 0)
			return false;
	return true;
}

//bool kiemTraSoNguyenTo (int n)
//{
//	bool kq = true;
//
//	int i = 2;
//	if (n < 2)
//		kq = false;
//	else
//	{
//		while (i <= sqrt((double)n) && kq == true)
//		{
//			if (n % i == 0)
//				kq = false;
//			i++;
//		}
//	}
//
//	return kq;
//}

void viTriCuaSoNguyenToDauTien(int **a, int dong, int cot, int &vtDong, int &vtCot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (kiemTraSoNguyenTo(a[i][j]) == true)
			{
				vtDong = i;
				vtCot = j;
				return;
			}
		}
	}
	return;
}