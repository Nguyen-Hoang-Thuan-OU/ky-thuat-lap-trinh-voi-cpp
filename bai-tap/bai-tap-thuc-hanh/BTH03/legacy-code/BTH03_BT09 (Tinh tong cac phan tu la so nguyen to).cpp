// Dùng con trỏ để tính tổng các phần tử nào là số nguyên tố //chuahoanthanh//

#include<iostream>
#include<iomanip>
using namespace std;

void nhap(int **a, int &dong, int &cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout << "Nhap phan tu thu [" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

void xuat(int **a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; i < cot; j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
}

bool kiemTra(int x)
{
	if(x < 2)
		return false;
	for(int i = 2; i <= x/2; i++)
	{
		if(x % i == 0)
			return false;
	}
	return true;
}

int tongSNT(int **a, int dong, int cot)
{
	int tong = 0;
	for(int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if(kiemTra(a[i][j]) == true)
				tong = tong + a[i][j];
			return tong;
		}
	}
	return 0;
}

int main()
{
	int **a;
	int dong, cot, kq;

	cout << "Nhap so dong: ";
	cin >> dong;

	cout << "Nhap so cot: ";
	cin >> cot;

	a = new int *[dong];

	for (int i = 0; i < dong; i++)
	{
		a[i] = new int[cot];
	}

	nhap(a, dong, cot);
	xuat(a, dong, cot);

	kq = tongSNT(a, dong, cot);
	cout <<"\nTong cac phan tu la so nguyen to co trong mang la: "<< kq << endl;

	for (int i = 0; i < dong; i++)
	{
		delete[]a[i];
	}
	delete[]a;
	a = NULL;

	return 0;
}