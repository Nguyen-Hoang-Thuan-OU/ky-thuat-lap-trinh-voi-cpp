/*
	Bài 01. Định nghĩa kiểu dữ liệu PhongBan gồm các thông tin:
		mã phòng ban kiểu string, tên phòng ban kiểu string.
		Sau đó viết chương trình cho phép nhập và xuất thông tin
		của 1 phòng ban cụ thể.
*/


#include <iostream>
#include <string>
using namespace std;

struct PhongBan;

void nhapThongTinMotPhongBan(PhongBan &pb);
void inThongTinMotPhongBan(PhongBan pb);

struct PhongBan
{
	string maPhongBan;
	string tenPhongBan;
};
typedef struct PhongBan PhongBan;

int main()
{
	PhongBan pb;

	cout << "Nhap thong tin cho phong ban:\n";
	nhapThongTinMotPhongBan(pb);
	cout << endl;

	cout << "Thong tin cua phong ban:\n";
	inThongTinMotPhongBan(pb);
	cout << endl;

	return 0;
}

void nhapThongTinMotPhongBan(PhongBan &pb)
{
	cout << "Nhap ma phong ban: ";
	getline(cin, pb.maPhongBan);

	cout << "Nhap ten phong ban: ";
	getline(cin, pb.tenPhongBan);
}

void inThongTinMotPhongBan(PhongBan pb)
{
	cout << "Ma phong ban: " << pb.maPhongBan << endl;
	cout << "Ten phong ban: " << pb.tenPhongBan << endl;
}