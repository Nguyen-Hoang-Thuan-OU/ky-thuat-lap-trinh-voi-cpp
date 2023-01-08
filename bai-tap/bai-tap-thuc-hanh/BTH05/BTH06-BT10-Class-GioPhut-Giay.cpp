/*
	Bài 10. Viết lớp GPG để lưu trữ thông tin giờ phút giây
	và tính được khoảng cách giữa 2 giá trị giờ phút giây.
	Sử dụng header file.
*/

#include<iostream>
#include<cmath>
using namespace std;

class Thoigian
{
private:
	int h, m, s;
public:
	void Nhap();
	void Xuat();
	void KhoangCach(Thoigian T1, Thoigian T2);
};

void Thoigian::Nhap()
{
	cout << "Nhap gio: "; cin >> h;
	cout << "Nhap phut: "; cin >> m;
	cout << "Nhap giay: "; cin >> s;

}

void Thoigian::Xuat()
{
	cout << h << ":" << m << ":" << s;
}

void Thoigian::KhoangCach(Thoigian T1, Thoigian T2)
{
	int giay;
	giay = (T1.h * 3600 + T1.m * 60 + T1.s) - (T2.h * 3600 + T2.m * 60 + T2.s);
	h = giay / 3600;
	m = (giay % 3600) / 60;
	s = giay % 3600 % 60;
}

int main()
{
	Thoigian KC, T1, T2;
	cout << "Nhap thoi gian truoc: ";
	T2.Nhap();
	cout << "Nhap thoi gian sau: ";
	T1.Nhap();
	KC.KhoangCach(T1, T2);
	cout << "\nKhoang Cach la: ";
	KC.Xuat();
	system("pause");
	return 0;
}