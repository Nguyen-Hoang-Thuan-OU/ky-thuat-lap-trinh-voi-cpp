// Định nghĩa kiểu dữ liệu Sach, xuất tên sách, tác giả và ngày tháng năm xuất bản //chuahoanthanh//

#include<iostream>
using namespace std;

struct ngayThangNam
{
	int ngay;
	int thang;
	int nam;
};

struct Sach
{
	char tenSach[21];
	char tacGiaSach[21];
	ngayThangNam thoiGianXuatBan;
};

void nhap(Sach s[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap sach thu: " << i + 1 << endl;

		cin.ignore();

		cout << "Nhap ten sach: ";
		cin.getline(s[i].tenSach, 20);

		cout << "Nhap ten tac gia: ";
		cin.getline(s[i].tacGiaSach, 20);

		cout << "\nThoi gian xuat ban: " << endl;

		cout << "Nhap ngay xuat ban: ";
		cin >> s[i].thoiGianXuatBan.ngay;

		cout << "Nhap thang xuat ban: ";
		cin >> s[i].thoiGianXuatBan.thang;

		cout << "Nhap nam xuat ban: ";
		cin >> s[i].thoiGianXuatBan.nam;

		cin.ignore();
	}
}

void xuat(Sach s[], int n, char tacGia[20])
{
	for (int i = 0; i < n; i++)
	{
		if (tacGia == s[i].tacGiaSach)
		{
			cout << "\nTen sach: " << s[i].tenSach;
			cout << "\nThoi gian xuat ban: " << s[i].thoiGianXuatBan.ngay << "/" << s[i].thoiGianXuatBan.thang << "/" <<s[i].thoiGianXuatBan.nam << endl;
		}
	}
}

int main()
{
	Sach s[50];
	int n;
	char tacGia[20];

	cout << "Nhap so sach: ";
	cin >> n;
	cin.ignore();
	nhap(s, n);

	cout << "\nNhap ten tac gia can tim: ";
	cin.getline(tacGia, 20);
	xuat(s, n, tacGia);
	cin.ignore();

	return 0;
}