/*
	Bài 01. Viết chương trình nhận vào 2 chuỗi ký tự (kể cả khoảng trắng).
		Sau đó thực hiện:

		a. So sánh xem chuỗi nào dài hơn?

		b. Chuyển từng chuỗi thành dạng in hoa ký tự đầu tiên mỗi từ.
		   Xuất lại 2 chuỗi sau khi chuyển.

		c. Nối chuỗi thứ hai vào chuỗi thứ nhất. Xuất lại kết quả nối.
*/

#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

void nhapChuoi(char *s);
void inChuoi(char *s);
void soSanhChuoi(char *s1, char *s2);
void chuyenChuoiThanhInHoaDauTu(char *s);
void noiChuoiThuHaiVaoChuoiThuNhat(char *s1, char *s2);

int main()
{
	char *s1;
	char *s2;
	int luaChon;
	bool daNhap = false;

	s1 = new char[51];
	s2 = new char[51];

	cout << "Nhap chuoi s1: ";
	nhapChuoi(s1);
	cout << endl;

	cout << "Nhap chuoi s2: ";
	nhapChuoi(s2);
	cout << endl;

	cout << "Chuoi s1 vua nhap la: ";
	inChuoi(s1);
	cout << endl;

	cout << "Chuoi s2 vua nhap la: ";
	inChuoi(s2);
	cout << endl;

	cout << "So sanh do dai cua hai chuoi s1 va s2: ";
	soSanhChuoi(s1, s2);
	cout << endl;

	cout << "Chuan hoa chuoi sang dang in hoa ki tu dau tien";
	cout << endl;

	cout << "Chuoi s1 sau khi chuan hoa la: ";
	chuyenChuoiThanhInHoaDauTu(s1);
	inChuoi(s1);
	cout << endl;

	cout << "Chuoi s2 sau khi chuan hoa la: ";
	chuyenChuoiThanhInHoaDauTu(s2);
	inChuoi(s2);
	cout << endl;

	noiChuoiThuHaiVaoChuoiThuNhat(s1, s2);
	cout << "Ket qua sau khi ghep chuoi s2 vao s1: " << s1 << endl;
}

// 01. Hàm nhập chuỗi
void nhapChuoi(char *s)
{
	cin.get(s, 51);
	cin.ignore();
}

// 02. Hàm xuất chuỗi
void inChuoi(char *s)
{
	cout << s;
	cout << endl;
}

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
