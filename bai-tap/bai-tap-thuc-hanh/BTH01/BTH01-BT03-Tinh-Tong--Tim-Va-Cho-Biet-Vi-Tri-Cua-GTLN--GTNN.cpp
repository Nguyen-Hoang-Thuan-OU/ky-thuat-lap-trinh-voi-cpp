/*
	Bài 03. Viết 01 chương trình thực hiện toàn bộ các công việc sau:
	
		a. Cho phép người dùng nhập vào một mảng số nguyên gồm r hàng và c cột
		   (tối đa 10 hàng và 15 cột, nếu nhập sai thì yêu cầu nhập lại
		    cho đến khi đúng mới tiếp tục).
			   
		b. Thực hiện việc tính tổng các giá trị lưu trữ trong mảng.
			
		c. Tìm giá trị nhỏ nhất, lớn nhất đang lưu trữ trong mảng.
			
		d. Cho biết vị trí của giá trị nhỏ nhất hay lớn nhất ở hàng mấy?
		   Cột bao nhiêu?
		   (Giả sử người dùng nhập không có giá trị nào trùng nhau).
*/

#include <iostream>
#include <conio.h>
using namespace std;

const int MAX_DONG = 10, MAX_COT = 15;

void nhapMang(int a[MAX_DONG][MAX_COT], int dong, int cot);
void xuatMang(int a[MAX_DONG][MAX_COT], int dong, int cot);
int tinhTong(int a[MAX_DONG][MAX_COT], int dong, int cot);
void timGiaTriNhoNhat(int a[MAX_DONG][MAX_COT], int dong, int cot, int &viTriDong, int &viTriCot);
void timGiaTriLonNhat(int a[MAX_DONG][MAX_COT], int dong, int cot, int &viTriDong, int &viTriCot);

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
			<< "3. Tinh tong (sau khi da nhap mang)\n"
			<< "4. Tim gia tri nho nhat va in ra vi tri (sau khi da nhap mang)\n"
			<< "5. Tim gia tri lon nhat va in ra vi tri (sau khi da nhap mang)\n"
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
				cout << "Nhap so dong cua ma tran (1..10): ";
				cin >> dong;

				if (dong <= 0 || dong > MAX_DONG)
					cout << "So dong khong hop le, vui long nhap lai (1..10)" << endl;
			} while (dong <= 0 || dong > MAX_DONG);

			// Kiểm tra số cột nhập vào có hợp lệ?
			do {
				cout << "Nhap so cot cua ma tran (1..15): ";
				cin >> cot;

				if (cot <= 0 || cot > MAX_COT)
					cout << "So cot khong hop le, vui long nhap lai (1..15)" << endl;
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

		case 3: // Tính tổng (sau khi đã nhập mảng)
			if (daNhapMang == true)
			{
				xuatMang(a, dong, cot);
				cout << endl;

				cout << "Tong cua cac gia tri trong mang la: "
					<< tinhTong(a, dong, cot) << endl;
				cout << endl;
			}
			else
			{
				cout << "Ban chua nhap mang!\n";
				cout << "vui long chon 1 de nhap truoc khi xu ly tiep!\n";
			}
			break;

		case 4: // Tìm giá trị nhỏ nhất (sau khi đã nhập mảng)
			if (daNhapMang == true)
			{
				xuatMang(a, dong, cot);
				cout << endl;

				int viTriDong, viTriCot;
				timGiaTriNhoNhat(a, dong, cot, viTriDong, viTriCot);
				cout << "Gia tri nho nhat nam tai dong [" << viTriDong + 1
					<< "] va cot [" << viTriCot + 1 << "]\n";
				cout << endl;
			}
			else
			{
				cout << "Ban chua nhap mang!\n";
				cout << "vui long chon 1 de nhap truoc khi xu ly tiep!\n";
			}
			break;

		case 5: // Tìm giá trị lớn nhất (sau khi đã nhập mảng)
			if (daNhapMang == true)
			{
				xuatMang(a, dong, cot);
				cout << endl;

				int viTriDong, viTriCot;
				timGiaTriLonNhat(a, dong, cot, viTriDong, viTriCot);
				cout << "Gia tri lon nhat nam tai dong [" << viTriDong + 1
					<< "] va cot [" << viTriCot + 1 << "]\n";
				cout << endl;
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
}

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
}

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
}

// 03. Hàm tính tổng các giá trị được lưu trong mảng
int tinhTong(int a[MAX_DONG][MAX_COT], int dong, int cot)
{
	int tongGiaTri = 0;

	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			tongGiaTri = tongGiaTri + a[i][j];

	return tongGiaTri;
}

// 04. Hàm tìm giá trị nhỏ nhất
void timGiaTriNhoNhat(int a[MAX_DONG][MAX_COT], int dong, int cot, int &viTriDong, int &viTriCot)
{
	// Giả sử vị trí a[0][0] là giá trị nhỏ nhất
	int min = a[0][0];
	viTriDong = 0, viTriCot = 0;

	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			if (a[i][j] < min)
			{
				min = a[i][j];
				
				viTriDong = i;
				viTriCot = j;
			}

	cout << "Gia tri nho nhat la: " << min << endl;
}

// 05. Hàm tìm giá trị lớn nhất
void timGiaTriLonNhat(int a[MAX_DONG][MAX_COT], int dong, int cot, int &viTriDong, int &viTriCot)
{
	// Giả sử vị trí a[0][0] là giá trị lớn nhất
	int max = a[0][0];
	viTriDong = 0, viTriCot = 0;

	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			if (a[i][j] > max)
			{
				max = a[i][j];

				viTriDong = i;
				viTriCot = j;
			}

	cout << "Gia tri lon nhat la: " << max << endl;
}