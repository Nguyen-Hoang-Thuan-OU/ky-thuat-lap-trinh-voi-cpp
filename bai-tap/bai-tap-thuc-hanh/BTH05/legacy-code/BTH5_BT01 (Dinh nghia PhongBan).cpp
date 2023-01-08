// Định nghĩa kiểu dữ liệu Phong

#include<iostream>
#include<string>
using namespace std;

struct PhongBan
{
	string MaPB;
	string TenPB;
};

int main()
{
	PhongBan pb;
	cout << "Nhap ma phong ban: ";
	getline(cin, pb.MaPB);
	cin.ignore();
	cout << "Nhap ten phong ban: ";
	getline(cin, pb.TenPB);

	cout<< "\nThong tin cua phong ban: " << endl;
	cout << "Ten phong: " << pb.TenPB << endl;
	cout << "Ma phong: " << pb.MaPB << endl;
	return 0;
}