/*
	Bài 04: Viết 01 chương trình thực hiện toàn bộ các công việc sau:

			a. Cho phép người dùng nhập vào một mảng số nguyên
			   gồm r hàng và c cột (tối đa 5 hàng và 6 cột,
			   nếu nhập sai thì yêu cầu nhập lại cho đến khi đúng mới tiếp tục).

			b. Cho người dùng nhập vào một vị trí cột / hàng cần tính tổng.
			   Hãy tiến hành tính tổng các giá trị lưu trữ
			   trong cột / hàng mà người dùng yêu cầu.

			c. Cho người dùng nhập vào một giá trị x bất kỳ.
			   Hãy tìm xem x có tồn tại trong mảng hay không?
			   Nếu có thì tồn tại bao nhiêu lần? Tại các vị trí nào?
*/

#include <iostream>
#include <conio.h>
using namespace std;

const int MAX_DONG = 5, MAX_COT = 6;

void nhapMang(int a[MAX_DONG][MAX_COT], int dong, int cot);
void xuatMang(int a[MAX_DONG][MAX_COT], int dong, int cot);
int tinhTongTrongMotDong(int a[MAX_DONG][MAX_COT], int dong, int cot);
int tinhTongTrongMotCot(int a[MAX_DONG][MAX_COT], int dong, int cot);
void timGiaTriBatKi(int a[MAX_DONG][MAX_COT], int dong, int cot,
					int giaTriCanTim);

int main()
{
	int a[MAX_DONG][MAX_COT], dong, cot;
	int luaChon;
	bool daNhapMang = false;

	do {
		system("cls");

		cout << endl;
		cout << "CHUONG TINH TINH TOAN TREN MANG HAI CHIEU\n"
			<< "1. Nhap mang\n"
			<< "2. Xuat mang (sau khi da nhap mang)\n"
			<< "3. Tinh tong cac gia tri trong mot cot (sau khi da nhap mang)\n"
			<< "4. Tinh tong cac gia tri trong mot hang (sau khi da nhap mang)\n"
			<< "5. Tim gia tri bat ki (sau khi da nhap mang)\n"
			<< "6. Thoat chuong trinh\n"
			<< endl
			<< "Lua chon cua ban (1..6): ";
		cin >> luaChon;
		cout << endl;

		switch (luaChon)
		{
		case 1: // Nhập mảng
			// Kiểm tra số dòng nhập vào có hợp lệ?
			do {
				cout << "Nhap so dong cua ma tran (1..5): ";
				cin >> dong;

				if (dong <= 0 || dong > MAX_DONG)
					cout << "So dong khong hop le, vui long nhap lai (1..5)" << endl;
			} while (dong <= 0 || dong > MAX_DONG);

			// Kiểm tra số cột nhập vào có hợp lệ?
			do {
				cout << "Nhap so cot cua ma tran (1..6): ";
				cin >> cot;

				if (cot <= 0 || cot > MAX_COT)
					cout << "So cot khong hop le, vui long nhap lai (1..6)" << endl;
			} while (cot <= 0 || cot > MAX_COT);

			nhapMang(a, dong, cot);
			daNhapMang = true;
			cout << endl;
			break;

		case 2: // Xuất mảng (sau khi đã nhập mảng)
			if (daNhapMang == true)
			{
				xuatMang(a, dong, cot);
				cout << endl;
			}
			else
			{
				cout << "Ban chua nhap mang!\n";
				cout << "vui long chon 1 de nhap truoc khi xu ly tiep!\n";
			}
			break;

		case 3: // Tính tổng dòng (sau khi đã nhập mảng)
			if (daNhapMang == true)
			{
				int dongCanTinhTong;

				xuatMang(a, dong, cot);
				cout << endl;

				// Kiểm tra số dòng nhập vào có hợp lệ?
				do {
					cout << "Nhap so dong can tinh tong (1.." << dong << "): ";
					cin >> dongCanTinhTong;

					if (dongCanTinhTong <= 0 || dongCanTinhTong > dong)
						cout << "So dong khong hop le, vui long nhap lai (1.." << dong << ")\n";
				} while (dongCanTinhTong <= 0 || dongCanTinhTong > dong);

				cout << "Tong gia tri tai dong " << dongCanTinhTong << " la: "
					<< tinhTongTrongMotDong(a, dongCanTinhTong, cot) << endl;
			}
			else
			{
				cout << "Ban chua nhap mang!\n";
				cout << "vui long chon 1 de nhap truoc khi xu ly tiep!\n";
			}
			break;

		case 4: // Tính tổng cột (sau khi đã nhập mảng)
			if (daNhapMang == true)
			{
				int cotCanTinhTong;

				xuatMang(a, dong, cot);
				cout << endl;

				// Kiểm tra số dòng nhập vào có hợp lệ?
				do {
					cout << "Nhap so cot can tinh tong (1.." << cot << "): ";
					cin >> cotCanTinhTong;

					if (cotCanTinhTong <= 0 || cotCanTinhTong > cot)
						cout << "So cot khong hop le, vui long nhap lai (1.." << cot << ")\n";
				} while (cotCanTinhTong <= 0 || cotCanTinhTong > cot);

				cout << "Tong gia tri tai cot " << cotCanTinhTong << " la: "
					<< tinhTongTrongMotCot(a, dong, cotCanTinhTong) << endl;
			}
			else
			{
				cout << "Ban chua nhap mang!\n";
				cout << "vui long chon 1 de nhap truoc khi xu ly tiep!\n";
			}
			break;

		case 5: // Tìm giá trị bất kì (sau khi đã nhập mảng)
			if (daNhapMang == true)
			{
				int giaTriCanTim;

				xuatMang(a, dong, cot);
				cout << endl;

				cout << "Vui long nhap gia tri can tim: ";
				cin >> giaTriCanTim;
				cout << endl;

				timGiaTriBatKi(a, dong, cot, giaTriCanTim);

				// Kiểm tra giá trị cần tìm có hợp lệ?
			}
			else
			{
				cout << "Ban chua nhap mang!\n";
				cout << "vui long chon 1 de nhap truoc khi xu ly tiep!\n";
			}
			break;

		case 6: // Thoát chương trình
			cout << "Chao tam biet" << endl;
			return 0;

		default:
			if (luaChon >= 1 || luaChon <= 6)
				cout << "Vui long nhap lua chon (1..6)!\n" << endl;
		} // switch-case

		_getch();

	} while (luaChon >= 1 || luaChon <= 6);

	return 0;
} // main()

// 01. Hàm nhập mảng
void nhapMang(int a[MAX_DONG][MAX_COT], int dong, int cot)
{
	// Nhập ma trận
	for (int i = 0; i < dong; i++)
	{
		cout << "Hay nhap cung luc " << cot
			<< " phan tu cua dong thu [" << i + 1
			<< "]: ";
		for (int j = 0; j < cot; j++)
			cin >> a[i][j];
	}
} // nhapMang()

// 02. Hàm xuất mảng
void xuatMang(int a[MAX_DONG][MAX_COT], int dong, int cot)
{
	cout << "Mang cua ban la:\n";
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
} // xuatMang()

// 03. Hàm tính tổng các giá trị lưu trữ trong một dòng
int tinhTongTrongMotDong(int a[MAX_DONG][MAX_COT], int dongCanTinhTong, int cot)
{
	int ketQuaTinhTongDong = 0;

	for (int j = 0; j < cot; j++)
			ketQuaTinhTongDong = ketQuaTinhTongDong + a[dongCanTinhTong - 1][j];

	return ketQuaTinhTongDong;
}

// 04. Hàm tính tổng các giá trị lưu trữ trong một cột
int tinhTongTrongMotCot(int a[MAX_DONG][MAX_COT], int dong, int cotCanTinhTong)
{
	int ketQuaTinhTongCot = 0;

	for (int i = 0; i < dong; i++)
			ketQuaTinhTongCot = ketQuaTinhTongCot + a[i][cotCanTinhTong - 1];

	return ketQuaTinhTongCot;
}

// 05. Hàm tìm giá trị bất kì, tính số lần xuất hiện và in ra các vị trí xuất hiện
void timGiaTriBatKi(int a[MAX_DONG][MAX_COT], int dong, int cot,
					int giaTriCanTim)
{
	int demSoLanXuatHien = 0;

	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			if (a[i][j] == giaTriCanTim)
			{
				demSoLanXuatHien++;

				if (demSoLanXuatHien == 1)
					cout << giaTriCanTim << " co xuat hien trong mang va xuat hien tai: ";
				
				cout << "[" << i + 1 << "][" << j + 1 << "]  ";
			}

	cout << endl;

	cout << giaTriCanTim << " xuat hien tong cong: " << demSoLanXuatHien << " lan\n" << endl;

	if (demSoLanXuatHien == 0)
		cout << giaTriCanTim << " khong co xuat hien trong mang\n";
}