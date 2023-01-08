/*
	Bài 04. Định nghĩa kiểu dữ liệu SinhVien gồm các thông tin:
		- Mã số sinh viên kiểu string
		- Họ tên kiểu string
		- Địa chỉ kiểu string
		- Năm sinh kiểu int
		- Điểm toán kiểu double
		- Điểm văn kiểu double
		- Điểm ngoại ngữ kiểu double

		Viết các hàm:
		- Nhập vào thông tin của sinh viên trong 1 lớp học (sĩ số không quá 45).
		- Xuất lại thông tin của sinh viên nào do người dùng yêu cầu
		  (thông qua việc nhập số thứ tự của sinh viên).
		- Tính điểm trung bình và xuất lại thông tin mã số sinh viên,
		  họ tên và điểm trung bình của từng sinh viên.
		  Biết:
			điểm trung bình = ((điểm toán + điểm văn) * 2 + điểm ngoại ngữ) / 5
		- Xếp loại sinh viên:
			Nếu điểm trung bình từ 8 trở lên thì xếp loại là “Giỏi”
			Nếu điểm trung bình từ 6.5 đến < 8 thì xếp loại là “Khá”
			Nếu điểm trung bình từ 5 đến < 6.5 thì xếp loại là “TB”
			Nếu điểm dưới 5 thì xếp loại “Dưới TB”
		- Viết hàm main kiểm chứng chương trình.
*/

#include <iostream>
#include <conio.h>
using namespace std;

struct SinhVien;

void nhapThongTinMotSinhVien(SinhVien &sv);
void nhapDanhSachSinhVien(SinhVien *dssv, int soLuongSinhVien);
void inThongTinMotSinhVien(SinhVien sv);
void InDanhSachSinhVien(SinhVien *dssv, int soLuongSinhVien);
double tinhDiemTrungBinh(SinhVien sv);
void xepLoaiSinhVien(SinhVien sv);
void inThongTinSinhVienKemDiemTrungBinhVaHocLuc(SinhVien *dssv, int soLuongSinhVien);

struct SinhVien
{
	string maSoSinhVien;
	string hoTenSinhVien;
	string diaChiSinhVien;
	int namSinhSinhVien;
	double diemToanSinhVien;
	double diemVanSinhVien;
	double diemNgoaiNguSinhVien;
};
typedef struct SinhVien SinhVien;

int main()
{
	SinhVien *sv;
	int luaChon;
	int n;
	bool kiemTra = false;

	// Nâng cấp thành menu
	do {
		system("cls");
		cout << "\n\t ====== MENU =====\n";
		cout << "1. Nhap danh sach sinh vien\n";
		cout << "2. In danh sach sinh vien\n";
		cout << "3. In diem trung binh va xep loai hoc luc\n";
		cout << "4. Thoat chuong trinh";
		cout << "\n\t ====== END =====\n\n";

		cout << "\t-> Lua chon cua ban la (1..6): ";
		cin >> luaChon;
		cout << endl;

		switch (luaChon)
		{

		// Nhập danh sách sinh viên
		case 1:
			cout << "Nhap so luong sinh vien cua mot lop (1..45): ";
			do {
				cin >> n;

				if (n < 1 || n > 45)
					cout << "Nhap sai, vui long nhap so luong sinh vien cua mot lop (1..45): ";
			} while(n < 1 || n > 45);
			cout << endl;

			sv = new SinhVien[n];

			cout << "----Nhap thong tin sinh vien-----\n";
			nhapDanhSachSinhVien(sv, n);
			cout << endl;

			kiemTra = true;
			break;

		// In danh sách sinh viên
		case 2:
			if (kiemTra == true)
			{
				cout << "-----In thong tin sinh vien-----\n";
				InDanhSachSinhVien(sv, n);
				cout << endl;
			}
			else
				cout << "Vui long chon lua chon [1] de nhap danh sach sinh vien!\n";

			break;

		// In thông tin điểm trung bình
		case 3:
			if (kiemTra == true)
			{
				cout << "-----In thong tin diem trung binh-----\n";
				inThongTinSinhVienKemDiemTrungBinhVaHocLuc(sv, n);
				cout << endl;
			}
			else
				cout << "Vui long chon lua chon [1] de nhap danh sach sinh vien!\n";
			
			break;

		// Thoát chương trình
		case 4:
			cout << "Chao tam biet!\n";
			delete[] sv;
			sv = NULL;
			return 0;

		default:
			cout << "Nhap sai, vui long nhap lai!\n";
		}

		_getch();
	} while (true);
}

// Nhập thông tin cho một sinh viên trong một lớp học
void nhapThongTinMotSinhVien(SinhVien &sv)
{
	cin.ignore();
	cout << "Nhap ma so sinh vien: ";
	getline(cin, sv.maSoSinhVien);
	
	cout << "Nhap ho ten sinh vien: ";
	getline(cin, sv.hoTenSinhVien);
	
	cout << "Nhap dia chi cua sinh vien: ";
	getline(cin, sv.diaChiSinhVien);
	
	cout << "Nhap nam sinh cua sinh vien: ";
	cin >> sv.namSinhSinhVien;
	
	cout << "Nhap diem toan cua sinh vien: ";
	cin >> sv.diemToanSinhVien;
	
	cout << "Nhap diem van cua sinh vien: ";
	cin >> sv.diemVanSinhVien;
	
	cout << "Nhap diem ngoai ngu cua sinh vien: ";
	cin >> sv.diemNgoaiNguSinhVien;
}

// Nhập danh sách (mảng) sinh viên trong một lớp học
void nhapDanhSachSinhVien(SinhVien *dssv, int soLuongSinhVien)
{
	for (int i = 0; i < soLuongSinhVien; i++)
	{
		cout << "\n=======================================\n";
		cout << "Nhap thong tin cho sinh vien thu [" << i + 1 << "]:\n";
		nhapThongTinMotSinhVien(dssv[i]);
		cout << endl;
	}
}

// In thông tin của một sinh viên trong một lớp học
void inThongTinMotSinhVien(SinhVien sv)
{
	cout << "Ma so sinh vien: " << sv.maSoSinhVien << endl;
	cout << "Ho ten sinh vien: " << sv.hoTenSinhVien << endl;
	cout << "Dia chi cua sinh vien: " << sv.diaChiSinhVien << endl;
	cout << "Nam sinh cua sinh vien: " << sv.namSinhSinhVien << endl;
	cout << "Diem toan cua sinh vien: " << sv.diemToanSinhVien << endl;
	cout << "Diem van cua sinh vien: " << sv.diemVanSinhVien << endl;
	cout << "Diem ngoai ngu cua sinh vien: " << sv.diemNgoaiNguSinhVien << endl;
}

// In danh sách (mảng) sinh viên trong một lớp học
void InDanhSachSinhVien(SinhVien *dssv, int soLuongSinhVien)
{
	for (int i = 0; i < soLuongSinhVien; i++)
	{
		cout << "\n=======================================\n";
		cout << "Thong tin cho sinh vien thu [" << i + 1 << "]:\n";
		inThongTinMotSinhVien(dssv[i]);
	}
}

// Tính điểm trung bình
double tinhDiemTrungBinh(SinhVien sv)
{
	// điểm trung bình = ((điểm toán + điểm văn) * 2 + điểm ngoại ngữ) / 5
	double diemTrungBinh;
	diemTrungBinh = ((sv.diemToanSinhVien + sv.diemVanSinhVien) * 2 + sv.diemNgoaiNguSinhVien) * 1.0 / 5;

	return diemTrungBinh;
}

// Xếp loại học thực theo điểm trung bình
void xepLoaiSinhVien(SinhVien sv)
{
	double diemTrungBinh = tinhDiemTrungBinh(sv);

	if (diemTrungBinh >= 8)
		cout << "Xep loai: GIOI\n";

	else if (diemTrungBinh >= 6.5 && diemTrungBinh < 8)
		cout << "Xep loai: KHA\n";

	else if (diemTrungBinh >= 5 && diemTrungBinh < 6.5)
		cout << "Xep loai: TRUNG BINH\n";

	else
		cout << "Xep loai: DUOI TRUNG BINH\n";
}

// In thông tin điểm trung binh kèm học lực
void inThongTinSinhVienKemDiemTrungBinhVaHocLuc(SinhVien *dssv, int soLuongSinhVien)
{
	for (int i = 0; i < soLuongSinhVien; i++)
	{
		cout << "\n=======================================\n";
		cout << "Ma so sinh vien: " << dssv[i].maSoSinhVien << endl;
		cout << "Ho ten sinh vien: " << dssv[i].hoTenSinhVien << endl;
		cout << "Diem trung binh cua sinh vien: " << tinhDiemTrungBinh(dssv[i]) << endl;
		cout << "Xep loai cua sinh vien: ";
		xepLoaiSinhVien(dssv[i]);
		cout << endl;
	}
}