﻿/*
	Bài 06: Viết chương trình cho nhập vào 2 ma trận (chứa các số nguyên).
		Sau đó tính kết quả tổng và tích hai ma trận đó.
*/

#include <iostream>
#include <ctime>
using namespace std;

const int MAX = 50;

void nhapMaTran(int arr[][MAX], int &dong, int &cot);
void xuatMaTran(int arr[][MAX], int dong, int cot);
void tinhTongMaTran(int maTranA[][MAX], int maTranB[][MAX], int maTranKetQua[][MAX],
					int dong, int cot);
void tinhTichMaTran(int maTranA[][MAX], int dongA, int cotA,
					int maTranB[][MAX], int dongB, int cotB,
					int maTranKetQua[][MAX]);

int main()
{
	// Kết hợp với hàm tạo giá trị ngẫu nhiên rand()
	// để giá trị của mảng khác nhau sau mỗi lần thực thi
	srand(time(0));

	int maTranA[MAX][MAX], maTranB[MAX][MAX], maTranKetQua[MAX][MAX];

	int dongA, cotA, dongB, cotB;

	// Nhập hai ma trận
	cout << "Ma tran a:\n";
	nhapMaTran(maTranA, dongA, cotA);
	cout << endl;
	
	cout << "Ma tran b:\n";
	nhapMaTran(maTranB, dongB, cotB);
	cout << endl;

	// Xuất hai ma trận
	cout << "Ma tran a:\n";
	xuatMaTran(maTranA, dongA, cotA);
	cout << endl;

	cout << "Ma tran b:\n";
	xuatMaTran(maTranB, dongB, cotB);
	cout << endl;

	// Tính tổng hai ma trận
	if (dongA == dongB && cotA == cotB)
	{
		tinhTongMaTran(maTranA, maTranB, maTranKetQua, dongA, cotA);

		cout << "Tong ma tran a + b:\n";
		xuatMaTran(maTranKetQua, dongA, cotA);
		cout << endl;
	}
	else
	{
		cout << "Hai ma tran nay khong the tinh tong\n";
		cout << endl;
	}

	// Tính tích hai ma trận
	if (cotA == dongB)
	{
		tinhTichMaTran(maTranA, dongA, cotA, maTranB, dongB, cotB, maTranKetQua);

		cout << "Tich ma tran a * b:\n";
		
		// Sử dụng riêng hàm in ma trận
		// với tham số khác với hàm tính tổng
		/*for (int i = 0; i < dongA; i++)
		{
			for (int j = 0; j < cotB; j++)
				cout << maTranKetQua[i][j] << "\t";

			cout << endl;
		}*/
		
		xuatMaTran(maTranKetQua, dongA, cotB);

		cout << endl;
	}
	else
	{
		cout << "Hai ma tran nay khong the tinh tong\n";
		cout << endl;
	}

	return 0;
}

// 01. Hàm nhập ma trận
void nhapMaTran(int arr[][MAX], int &dong, int &cot)
{
	do {
		cout << "Nhap so dong (1..50): ";
		cin >> dong;

		if (dong < 1 || dong > MAX)
			cout << "Nhap sai, vui long nhap lai!";
	} while (dong < 1 || dong > MAX);

	do {
		cout << "Nhap so cot (1..50): ";
		cin >> cot;

		if (cot < 1 || cot > MAX)
			cout << "Nhap sai, vui long nhap lai!";
	} while (cot < 1 || cot > MAX);

	// --- Legacy ---
	//cout << "Ma tran se co " << dong << " dong va " << cot << " cot" << endl;
	//for (int i = 0; i < dong; i++)
	//{
	//	cout << "Nhap mot loat " << cot << " phan tu tren dong thu [" << i << "]: ";
	//	for (int j = 0; j < cot; j++)
	//		cin >> arr[i][j];
	//}
	// --- Legacy ---

	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			arr[i][j] = rand() % 5;
}

// 02. Hàm xuất ma trận
void xuatMaTran(int arr[][MAX], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			cout << arr[i][j] << "\t";

		cout << endl;
	}
}

// 03. Hàm tính tổng hai ma trận
void tinhTongMaTran(int maTranA[][MAX], int maTranB[][MAX], int maTranKetQua[][MAX],
					int dong, int cot)
{
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			maTranKetQua[i][j] = maTranA[i][j] + maTranB[i][j];
}

// 04. Hàm tính tích hai ma trận
void tinhTichMaTran(int maTranA[][MAX], int dongA, int cotA,
					int maTranB[][MAX], int dongB, int cotB,
					int maTranKetQua[][MAX])
{
	for (int i = 0; i < dongA; i++)
		for (int j = 0; j < cotB; j++)
		{
			maTranKetQua[i][j] = 0;

			for (int k = 0; k < cotA; k++)
				maTranKetQua[i][j] += maTranA[i][k] * maTranB[k][j];
		}
}