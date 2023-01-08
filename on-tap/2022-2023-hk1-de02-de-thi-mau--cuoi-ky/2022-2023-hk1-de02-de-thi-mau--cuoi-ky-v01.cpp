/* T */

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;


#pragma region a. Định nghĩa Struct Sach, NTN
struct NTN
{
	int ngay, thang, nam;
};
struct Sach
{
	char maSach[21];
	char tenSach[21];
	NTN nxb;
};
#pragma endregion
#pragma region b. Hàm nhập thông tin cho tối đa 20 sách
void nhapSach(Sach& s)
{
	cin.ignore();
	cout << "Nhap ma sach: ";
	cin.getline(s.maSach, 21);
	cout << "Nhap ten sach: ";
	cin.getline(s.tenSach, 21);
	cout << "Ngay xuan ban: ";
	cin >> s.nxb.ngay;
	cin.ignore();
	cout << "Thang xuat ban: ";
	cin >> s.nxb.thang;
	cin.ignore();
	cout << "Nam xuat ban: ";
	cin >> s.nxb.nam;
}
// Nhap thong tin toi da 20 sach
void nhapDS(Sach s[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Thong tin quyen sach thu " << i + 1 << ": " << endl;
		nhapSach(s[i]);
	}
}
#pragma endregion
#pragma region c. Đọc dữ liệu từ file lên cho danh sách sách theo cấu trúc struct đã định nghĩa
// Doc danh sach tu file
void docDuLieuSach(Sach *&sach, int &n)
{
	ifstream docFile;
	docFile.open("DuLieuSach.txt");
	string s;

	if (docFile.is_open())
	{
		docFile >> n;
		sach = new Sach[n];
		while (!docFile.eof())
		{
			docFile.ignore(1);
			for (int i = 0; i < n; i++)
			{
				docFile.getline(sach[i].maSach, 21, '#');
				docFile.getline(sach[i].tenSach, 21, '#');

				docFile >> sach[i].nxb.ngay;
				docFile.ignore(1);
				docFile >> sach[i].nxb.thang;
				docFile.ignore(1);
				docFile >> sach[i].nxb.nam;
				docFile.ignore(1);
			}
		}
		docFile.close();
	}
	else
	{
		cout << "Khong mo duoc file de ghi du lieu" << endl;
	}
}
#pragma endregion
#pragma region d. Hàm xuất thông tin của các sách đang lưu trữ trong chương trình
// Xuat thong tin sach
void xuatSach(Sach& s)
{
	cout << "Ma sach: " << s.maSach << endl;
	cout << "Ten sach: " << s.tenSach << endl;
	cout << "Thoi gian xuat ban: " << s.nxb.ngay << "/" << s.nxb.thang << "/" << s.nxb.nam << endl;
}
void xuatDS(Sach*& s, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "_______________________________________\n";
		cout << "Thong tin quyen sach thu " << i + 1 << ": " << endl;
		xuatSach(s[i]);
	}
}
#pragma endregion
#pragma region e. Hàm sắp xếp các sách theo năm xuất bản tăng dần
// Sap xep cac sach theo nam xuat ban
void sapXepTangTheoNamXB(Sach* sach, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (sach[i].nxb.nam > sach[j].nxb.nam)
			{
				Sach tam = sach[i];
				sach[i] = sach[j];
				sach[j] = tam;
			}
}
#pragma endregion
#pragma region f. Dem so sach co nam xuat ban vao nam 2019
int demSachNam2019(Sach s[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (s[i].nxb.nam == 2019)
		{
			dem++;
		}
	}
	return dem;
}
#pragma endregion
#pragma region g. Chuyen in hoa dau tu
// xoa bat ky
void xoa(char s[], int vitrixoa)
{
	int n = strlen(s);//gán n= độ dài của chuỗi
	for (int i = vitrixoa; i < n; i++)//duyệt chuỗi từ vị trí cần xóa
		s[i] = s[i + 1];
	s[n - 1] = '\0'; //kết thúc
}
// xoa khoang trang
void xoaKhoangTrang(char* s)
{
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			xoa(s, i);
			i--;
		}
		if (s[0] == ' ')
			xoa(s, 0);
		if (s[strlen(s) - 1] == ' ')
			xoa(s, strlen(s) - 1);
}
void chuyenInHoaDau(char *x)
{
	// xoa cac ki tu khoang trang
	xoaKhoangTrang(x);

	// Chuyen hoa
	for (int i = 0; i < strlen(x); i++) {
		if (i == 0 || (i > 0 && x[i - 1] == 32)) {
			if (x[i] >= 97 && x[i] <= 122)
				x[i] = x[i] - 32;
		}
		else {
			if (x[i] >= 65 && x[i] <= 90)
				x[i] = x[i] + 32;
		}
	}
}
#pragma endregion
#pragma region h. Hàm nhận vào tên sách từ bàn phím và trả ra kết quả gợi ý
void thongKeSach(Sach* sach, char ten[], int &n)
{
	// Chuan hoa
	chuyenInHoaDau(ten);
	// Kiem tra
	int dem = 0;

	for (int i = 0; i < n; i++)
	{
		if (strstr(sach[i].tenSach, ten))
		{
			xuatSach(sach[i]);
		}
	}
}
#pragma endregion



int main()
{
	Sach sp[21];
	Sach* p;
	p = sp;
	char tuKhoa[51], chuoi[51];
	char *str = tuKhoa;
	char *s = chuoi;
	int n = 20, chon;

	bool in = false;

	// cap phat
	p = new Sach[n];
	// xu li
	do {
		cout << "-----------Menu lua chon-------------\n"
			<< "1. Nhap thong tin sach (toi da 20 quyen)\n"
			<< "2. Doc danh sach sach tu file\n"
			<< "3. Xuat thong tin cac sach\n"
			<< "4. Sap xep cac sach theo nam xuat ban\n"
			<< "5. Dem so sach co nam xuat ban la 2019\n"
			<< "6. Chuan hoa chuoi\n"
			<< "7. Tim kiem sach theo ten sach\n"
			<< "Ban chon : ";
		cin >> chon;

		switch (chon)
		{
		case 1:
			do {
				cout << "Nhap so luong sach can nhap: ";
				cin >> n;
				if (n < 1 || n > 20)
					cout << "Vuot qua so luong. Moi nhap lai\n";
			} while (n < 1 || n > 20);
			in = true;
			nhapDS(p, n);
			break;
		case 2:
			docDuLieuSach(p, n);
			in = true;
			break;
		case 3:
			if (in)
			{
				xuatDS(p, n);
			}
			else
			{
				cout << "Chua co du lieu. Moi lua chon phuong thuc nhap!!!" << endl;
				cout << "-----------Menu lua chon-------------\n"
					<< "1. Nhap thong tin sach (toi da 20 quyen)\n"
					<< "2. Doc danh sach sach tu file\n"
					<< "Ban chon : ";
				switch (chon)
				{
				case 1:
					nhapDS(p, n);
				case 2: 
					docDuLieuSach(p, n);
				default:
					break;
				}
				in = true;
			}
			break;
		case 4:
			if (in)
			{
				sapXepTangTheoNamXB(p, n);
				cout << "Da sap xep thanh cong. Chon xuat de xem ket qua\n";
			}
			else
			{
				cout << "Chua co du lieu. Moi lua chon phuong thuc nhap!!!" << endl;
				cout << "-----------Menu lua chon-------------\n"
					<< "1. Nhap thong tin sach (toi da 20 quyen)\n"
					<< "2. Doc danh sach sach tu file\n"
					<< "Ban chon : ";
				switch (chon)
				{
				case 1:
					nhapDS(p, n);
				case 2:
					docDuLieuSach(p, n);
				default:
					break;
				}
				in = true;
			}
			break;
		case 5:
			if (in)
			{
				cout << "So sach co nam xuat ban o nam 2019: " << demSachNam2019(p, n) << endl;
			}
			else
			{
				cout << "Chua co du lieu. Moi lua chon phuong thuc nhap!!!" << endl;
				cout << "-----------Menu lua chon-------------\n"
					<< "1. Nhap thong tin sach (toi da 20 quyen)\n"
					<< "2. Doc danh sach sach tu file\n"
					<< "Ban chon : ";
				switch (chon)
				{
				case 1:
					nhapDS(p, n);
				case 2:
					docDuLieuSach(p, n);
				default:
					break;
				}
				in = true;
			}
			break;
		case 6:
			cout << "Nhap chuoi can chuan hoa: ";
			cin.ignore();
			cin.get(s, 51);

			cout << "Chuoi sau khi chuan hoa: ";
			chuyenInHoaDau(s);
			cout << s << endl;
			break;
		case 7:
			if (in)
			{
				cout << "Nhap ten sach can tim: ";
				cin >> str;

				thongKeSach(p, str, n);
			}
			else
			{
				cout << "Chua co du lieu. Moi lua chon phuong thuc nhap!!!" << endl;
				cout << "-----------Menu lua chon-------------\n"
					<< "1. Nhap thong tin sach (toi da 20 quyen)\n"
					<< "2. Doc danh sach sach tu file\n"
					<< "Ban chon : ";
				switch (chon)
				{
				case 1:
					nhapDS(p, n);
				case 2:
					docDuLieuSach(p, n);
				default:
					break;
				}
				in = true;
			}
			break;
		default:
			cout << "Hen gap lai";
		}
		_getch();
		system("cls");

	} while (chon >= 1 && chon <= 7);

	// thu hoi
	delete[] p;
	p = NULL;
	return 0;
}