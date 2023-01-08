// Nhập số dòng và cột (tối đa 10 dòng và 15 cột)
// Tính tổng
// Tìm giá trị lớn và nhỏ nhất
// Vị trí của giá trị nhỏ nhất hay lớn nhất ở hàng, cột nào

#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main()
{
	int a[10][15];
	int dong, cot;

	do{
		cout << "Nhap so dong: ";
		cin >> dong;
		cout << "Nhap so cot: ";
		cin >> cot;
		if (dong <= 0 || cot <= 0 || dong > 10 || cot > 15)
			cout << "Nhap sai, vui long nhap lai!";
	}while(dong <= 0 || cot <= 0 || dong > 10 || cot > 15);
	
	
	// Nhập ngẫu nhiên & xuất
	cout << "Xuat mang: " << endl;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			a[i][j] = rand()%5;
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}

	// Tính tổng
	int tong = 0;
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			tong = tong + a[i][j];
	cout << "Tong cac gia tri luu trong mang: " << tong << endl;

	//GTNN & GTLN, vị trí của GTNN & GTLN
	int dongmax = 0, cotmax = 0, dongmin = 0, cotmin = 0;
	int max = a[0][0], min = a[0][0];
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
				dongmax = i;
				cotmax = j;
			}
			if (min > a[i][j])
			{
				min = a[i][j];
				dongmin = i;
				cotmin = j;
			}
		}
	cout << "Gia tri lon nhat la " << max << " tai dong " << dongmax << " va cot " << cotmax << endl;
	cout << "Gia tri nho nhat la " << min << " tai dong " << dongmin << " va cot " << cotmin << endl;

	return 0;
}