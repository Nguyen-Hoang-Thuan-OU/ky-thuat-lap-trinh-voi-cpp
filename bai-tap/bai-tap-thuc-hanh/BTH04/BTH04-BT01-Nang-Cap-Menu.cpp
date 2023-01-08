/*
	Bài 01. Viết chương trình nhận vào 2 chuỗi ký tự (kể cả khoảng trắng).
		Sau đó thực hiện:
		
		a. So sánh xem chuỗi nào dài hơn?
		
		b. Chuyển từng chuỗi thành dạng in hoa ký tự đầu tiên mỗi từ.
		   Xuất lại 2 chuỗi sau khi chuyển.
		
		c. Nối chuỗi thứ hai vào chuỗi thứ nhất. Xuất lại kết quả nối.
*/

// Bị lỗi nhập xuất chuỗi

#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

//void nhapChuoi(char *s);
//void inChuoi(char *s);
void soSanhChuoi(char *s1, char *s2);
void chuyenChuoiThanhInHoaDauTu(char *s);
void noiChuoiThuHaiVaoChuoiThuNhat(char *s1, char *s2);

int main()
{
	char *s1;
	char *s2;
	int luaChon;
	bool daNhap = false;
	
	do {
		system("cls");
		cout << "CHUONG TRINH NHAP, TINH TOAN VA IN RA HAI CHUOI\n"
			<< "1. Nhap hai chuoi\n"
			<< "2. In hai chuoi vua nhap\n"
			<< "3. So sanh do dai cua hai chuoi\n"
			<< "4. Chuan hoa chuoi (In hoa ki tu dau tien)\n"
			<< "5. Noi chuoi\n"
			<< "6. Thoat\n"
			<< "\t-> Lua chon cua ban la (1..6): ";
		cin >> luaChon;

		s1 = new char[51];
		s2 = new char[51];

		switch (luaChon)
		{
		case 1:
			cout << "Nhap chuoi s1: ";
			//nhapChuoi(s1);
			cin.ignore();
			cin.get(s1, 51);
			cout << endl;

			cout << "Nhap chuoi s2: ";
			//nhapChuoi(s2);
			cin.ignore();
			cin.get(s2, 51);
			cout << endl;

			daNhap = true;

			break;

		case 2:
			if (daNhap == true)
			{
				cout << "Chuoi s1 vua nhap la: ";
				cout << s1;
				//inChuoi(s1);
				cout << endl;

				cout << "Chuoi s2 vua nhap la: ";
				cout << s2;
				//inChuoi(s2);
				cout << endl;
			}
			else
				cout << "Vui long chon lua chon 1 de nhap chuoi truoc!\n";
			break;

		case 3:
			if (daNhap == true)
			{
				cout << "So sanh do dai cua hai chuoi s1 va s2: ";
				soSanhChuoi(s1, s2);
				cout << endl;
			}
			else
				cout << "Vui long chon lua chon 1 de nhap chuoi truoc!\n";
			break;

		case 4:
			if (daNhap == true)
			{
				cout << "Chuan hoa chuoi sang dang in hoa ki tu dau tien";
				cout << endl;

				cout << "Chuoi s1 sau khi chuan hoa la: ";
				chuyenChuoiThanhInHoaDauTu(s1);
				cout << s1;
				//inChuoi(s1);
				cout << endl;

				cout << "Chuoi s2 sau khi chuan hoa la: ";
				chuyenChuoiThanhInHoaDauTu(s2);
				cout << s2;
				//inChuoi(s2);
				cout << endl;
			}
			else
				cout << "Vui long chon lua chon 1 de nhap chuoi truoc!\n";
			break;

		case 5:
			if (daNhap == true)
			{
				noiChuoiThuHaiVaoChuoiThuNhat(s1, s2);
				cout << "Ket qua sau khi ghep chuoi s2 vao s1: " << s1 << endl;
			}
			else
				cout << "Vui long chon lua chon 1 de nhap chuoi truoc!\n";
			break;

		default:
			return 0;
		}
		_getch();
	} while (true);

}

// 01. Hàm nhập chuỗi
//void nhapChuoi(char *s)
//{
//	cin.ignore();
//	cin.get(s, 51);
//}

// 02. Hàm xuất chuỗi
//void inChuoi(char *s)
//{
//	cout << s;
//	cout << endl;
//}

// 03. Hàm so sánh độ dài của hai chuỗi
void soSanhChuoi(char *s1, char *s2)
{
	if (strlen(s1) == strlen(s2))
		cout << "2 chuoi bang nhau\n";
	else if (strlen(s1) < strlen(s2))
		cout << "s1 ngan hon s2\n";
	else
		cout << "s1 dai hon s2\n";
}

// 04. Chuyển từng chuỗi thành dạng in hoa ký tự đầu tiên mỗi từ
void chuyenChuoiThanhInHoaDauTu(char *s)
{
	while (*s == ' ')
		s++;

	*s = toupper(*s);
	s++;

	while (*s != '\0')
	{
		if (*(s - 1) == ' ' && islower(*s))
			*s = toupper(*s);
		else
			*s = tolower(*s);
		s++;
	}
}

// 05. Nối chuỗi thứ hai vào chuỗi thứ nhất
void noiChuoiThuHaiVaoChuoiThuNhat(char *s1, char *s2)
{
	// Project -> Properties
	//	-> C/C++ -> Preprocessor
	//	-> Preprocessor Definitions"
	//	thêm: _CRT_SECURE_NO_WARNINGS
	strcat(s1, s2);
}
