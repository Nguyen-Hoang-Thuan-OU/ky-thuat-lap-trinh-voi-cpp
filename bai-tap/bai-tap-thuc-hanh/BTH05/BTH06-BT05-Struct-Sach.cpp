/*
	Bài 05. Định nghĩa kiểu dữ liệu Sach gồm các thông tin sau:
		- Tên sách kiểu mảng 1 chiều char, tối đa 20 ký tự.
		- Tên tác giả kiểu mảng 1 chiều char, tối đa 20 ký tự.
		- Ngày tháng năm xuất bản kiểu struct NTN
		  (ngày, tháng, năm đều là số nguyên)

		Viết các hàm sau:
		- Nhập vào thông tin của tối đa 50 quyển sách.
		- Xuất lại thông tin của quyển sách nào
		  có tên tác giả là “Tran Dung”
		  (Mở rộng ra thành tên của bất kì tác giả nào)
*/

#include <iostream>
#include <conio.h>
using namespace std;

struct NTN;
struct Sach;

void nhapMotQuyenSach(Sach &sach);
void nhapDanhSachCacQuyenSach(Sach *dsqs, int soLuongQuyenSach);
void inMotQuyenSach(Sach sach);
void inDanhSachCacQuyenSach(Sach *dsqs, int soLuongQuyenSach);
int soSanhDoDaiKhongPhanBietHoaVaThuong(char *s1, char *s2);
void vietHoaDauMoiTu(char s[]);
void timSachTheoTenTacGia(Sach *dsqs, int soLuongQuyenSach, char *tenTacGia);

struct NTN
{
	int ngayXuatBan;
	int thangXuatBan;
	int namXuatBan;
};
typedef struct NTN NTN;

struct Sach
{
	char tenSach[21];
	char tenTacGia[21];
	NTN thoiGianXuatBan;
};
typedef struct Sach Sach;

int main()
{
	Sach *sach;
	int luaChon;
	int n;
	char tenTacGia[21];
	bool kiemTra = false;

	// Nâng cấp thành menu
	do {
		system("cls");
		cout << "\n\t ====== MENU =====\n";
		cout << "1. Nhap danh sach cac quyen sach\n";
		cout << "2. In danh sach cac quyen sach\n";
		cout << "3. Tim sach theo ten tac gia\n";
		cout << "4. Thoat chuong trinh";
		cout << "\n\t ====== END =====\n\n";

		cout << "\t-> Lua chon cua ban la (1..6): ";
		cin >> luaChon;
		cout << endl;

		switch (luaChon)
		{

		// Nhập danh sách các quyển sách
		case 1:
			cout << "Nhap so luong sach (1..50): ";
			do {
				cin >> n;

				if (n < 1 || n > 50)
					cout << "Nhap sai, vui long nhap so luong sach (1..50): ";
			} while(n < 1 || n > 50);
			cout << endl;

			sach = new Sach[n];

			cout << "----Nhap thong tin sach-----\n";
			nhapDanhSachCacQuyenSach(sach, n);
			cout << endl;

			kiemTra = true;
			break;

		// In danh sách các quyển sách
		case 2:
			if (kiemTra == true)
			{
				cout << "-----In thong tin sach-----\n";
				inDanhSachCacQuyenSach(sach, n);
				cout << endl;
			}
			else
				cout << "Vui long chon lua chon [1] de nhap danh sach cac quyen sach!\n";

			break;

		// Tìm và in ra danh sách các quyển sách theo tên của một tác giả
		case 3:
			if (kiemTra == true)
			{
				cout << "-----Tim cac dau sach theo ten tac gia-----\n";
				
				cin.ignore();
				cout << "Nhap ten tac gia can tim: ";
				cin.getline(tenTacGia, 21);

				timSachTheoTenTacGia(sach, n, tenTacGia);
				cout << endl;
			}
			else
				cout << "Vui long chon lua chon [1] de nhap danh sach cac quyen sach!\n";
			
			break;

		// Thoát chương trình
		case 4:
			cout << "Chao tam biet!\n";
			delete[] sach;
			sach = NULL;
			return 0;

		default:
			cout << "Nhap sai, vui long nhap lai!\n";
		}

		_getch();
	} while (true);
}

// Một một quyển sách
void nhapMotQuyenSach(Sach &sach)
{
	cin.ignore();
	cout << "Nhap ten sach: ";
	cin.getline(sach.tenSach, 21);
	
	cout << "Nhap ten tac gia: ";
	cin.getline(sach.tenTacGia, 21);
	
	cout << "Nhap ngay xuat ban: ";
	cin >> sach.thoiGianXuatBan.ngayXuatBan;
	
	cout << "Nhap thang xuat ban: ";
	cin >> sach.thoiGianXuatBan.thangXuatBan;
	
	cout << "Nhap nam xuat ban: ";
	cin >> sach.thoiGianXuatBan.namXuatBan;
}

// Danh sách các quyển sách
void nhapDanhSachCacQuyenSach(Sach *dsqs, int soLuongQuyenSach)
{
	for (int i = 0; i < soLuongQuyenSach; i++)
	{
		cout << "\n=======================================\n";
		cout << "Nhap thong tin cho quyen sach thu [" << i + 1 << "]:\n";
		nhapMotQuyenSach(dsqs[i]);
	}
}

void inMotQuyenSach(Sach sach)
{
	vietHoaDauMoiTu(sach.tenSach);
	vietHoaDauMoiTu(sach.tenTacGia);
	cout << "Ten sach: " << sach.tenSach << endl;
	cout << "Ten tac gia: " << sach.tenTacGia << endl;
	cout << "Thoi gian xuat ban: "
		<< sach.thoiGianXuatBan.ngayXuatBan << "/"
		<< sach.thoiGianXuatBan.thangXuatBan << "/" 
		<< sach.thoiGianXuatBan.namXuatBan << endl;
}

void inDanhSachCacQuyenSach(Sach *dsqs, int soLuongQuyenSach)
{
	for (int i = 0; i < soLuongQuyenSach; i++)
	{
		cout << "\n=======================================\n";
		cout << "Thong tin cho quyen sach thu [" << i + 1 << "]:\n";
		inMotQuyenSach(dsqs[i]);
	}
}

// So sánh độ lớn của hai chuỗi - Không phân biệt kí tự hoa và thường
int soSanhDoDaiKhongPhanBietHoaVaThuong(char *s1, char *s2)
{

	int doDaiNhoNhat = 0;

	if (strlen(s1) < strlen(s2))
		doDaiNhoNhat = strlen(s1);
	else
		doDaiNhoNhat = strlen(s2);

	for (int i = 0; i < strlen(s1); i++)
		if (s1[i] >= 'a' && s1[i] <= 'z')
			s1[i] = s1[i] - 32;

	for (int i = 0; i < strlen(s2); i++)
		if (s2[i] >= 'a' && s2[i] <= 'z')
			s2[i] = s2[i] - 32;

	for (int i = 0; i < doDaiNhoNhat; i++)
		if (s1[i] > s2[i])
			return 1;
		else if (s1[i] < s2[i])
			return -1;

	if (strlen(s1) > strlen(s2))
		return 1;
	else if (strlen(s1) < strlen(s2))
		return -1;
	else
		return 0;
}

// Viết hoa kí tự đầu của mỗi từ
void vietHoaDauMoiTu(char s[])
{
	for (int i = 0; i < strlen(s); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;

	if (s[0] != ' ')
		if (s[0] >= 'a' && s[0] <= 'z')
			s[0] = s[0] - 32;

	for (int i = 0; i < strlen(s) - 1; i++)
		if (s[i] == ' ' && s[i + 1] != ' ')
			if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
				s[i + 1] = s[i + 1] - 32;
}

// Tìm theo tên của một tác giả được nhập từ bàn phím
// thay vì chỉ tìm cố định một tác giả
// và không cần phải viết hoa tên tác giả khi tìm
void timSachTheoTenTacGia(Sach *dsqs, int soLuongQuyenSach, char *tenTacGia)
{
	int demSoLuongQuyenSach = 0;
	for (int i = 0; i < soLuongQuyenSach; i++)
	{
		//if (strcmp(dsqs[i].tenTacGia, tenTacGia) == 0)
		if (soSanhDoDaiKhongPhanBietHoaVaThuong(dsqs[i].tenTacGia, tenTacGia) == 0)
		{
			vietHoaDauMoiTu(tenTacGia);
			vietHoaDauMoiTu(dsqs[i].tenTacGia);
			cout << "\n=======================================\n";
			cout << "Danh sach cac quyen sach cua tac gia [" << tenTacGia << "] la:\n";
			inMotQuyenSach(dsqs[i]);
			cout << endl;

			demSoLuongQuyenSach++;
		}
	}
	
	vietHoaDauMoiTu(tenTacGia);
	if (demSoLuongQuyenSach == 0)
		cout << "Khong tim thay sach cua tac gia [" << tenTacGia << "]!\n";
}