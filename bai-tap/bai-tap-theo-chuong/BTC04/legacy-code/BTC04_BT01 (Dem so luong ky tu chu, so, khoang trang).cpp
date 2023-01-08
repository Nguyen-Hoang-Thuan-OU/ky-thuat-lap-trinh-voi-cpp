// Viết chương trình nhập vào 1 chuỗi tối đa 50 ký tự.
// Sau đó đếm xem có bao nhiêu ký tự là ký tự chữ hoặc số?
// Bao nhiêu ký tự khoảng trắng?

#include<iostream>
#include<string>
using namespace std;

int main()
{
	char s[51];
	int demKiTu = 0, demKhoangTrang = 0;
	int demChu = 0, demSo = 0;

	cout << "Nhap chuoi: ";
	cin.getline(s, 51, '\n');

	char *ps = s;

	while(*ps)
	{
		if (isalnum(*ps))
			demKiTu++;
		if (isalpha(*ps))
			demChu++;
		if (isdigit(*ps))
			demSo++;
		if (isspace(*ps))
			demKhoangTrang++;
		ps++;
	}

	cout << "Tong so luong ki tu: " << demKiTu++ << endl;
	cout << "So luong chu: " << demChu++ << endl;
	cout << "So luong so: " << demSo++ << endl;
	cout << "So luong khoang trang: " << demKhoangTrang++ << endl;

	return 0;
}