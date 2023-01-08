/*
	Bài 03. Định nghĩa kiểu dữ liệu NhanVien gồm các thông tin sau:
		- Mã nhân viên kiểu string
		- Họ tên kiểu string
		- Năm vào làm kiểu int
		- Năm sinh kiểu int
			
		Viết các hàm:
		- Nhập vào đầy đủ thông tin của 1 nhân viên.
		- Xuất lại thông tin của nhân viên vừa nhập.
		- Tính tuổi và thâm niên làm việc của nhân viên này.
			Biết rằng:
				tuổi = năm hiện tại – năm sinh
				thâm niên = năm hiện tại – năm vào làm
		- Hàm main kiểm chứng chương trình.
*/

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct NhanVien;

void nhapThongTinMotNhanVien(NhanVien &nv);
void inThongTinMotNhanVien(NhanVien nv);
int tinhNamHienTai();
void tinhTuoiVaThamNienLamViec(NhanVien nv);

struct NhanVien
{
	string maNhanVien;
	string hoVaTenNhanVien;
	int namVaoLamNhanVien;
	int namSinhNhanVien;
};
typedef struct NhanVien NhanVien;

int main()
{
	NhanVien nv;

	cout << "Nhap thong tin nhan vien:\n";
	nhapThongTinMotNhanVien(nv);
	cout << endl;

	cout << "In thong tin nhan vien:\n";
	inThongTinMotNhanVien(nv);
	cout << endl;

	tinhTuoiVaThamNienLamViec(nv);
	cout << endl;

	return 0;
}

void nhapThongTinMotNhanVien(NhanVien &nv)
{
	cout << "Nhap ma nhan vien: ";
	getline(cin, nv.maNhanVien);

	cout << "Nhap ho ten nhan vien: ";
	getline(cin, nv.hoVaTenNhanVien);

	cout << "Nhap nam vao lam cua nhan vien: ";
	cin >> nv.namVaoLamNhanVien;

	cout << "Nhap nam sinh cua nhan vien: ";
	cin >> nv.namSinhNhanVien;
}

void inThongTinMotNhanVien(NhanVien nv)
{
	cout << "Ma nhan vien: " << nv.maNhanVien << endl;
	cout << "Ho ten nhan vien: " << nv.hoVaTenNhanVien << endl;
	cout << "Nam vao lam cua nhan vien: " << nv.namVaoLamNhanVien << endl;
	cout << "Nam sinh cua nhan vien: " << nv.namSinhNhanVien << endl;
}

int tinhNamHienTai()
{
	int namHienTai ;

	time_t thoiGianHienTai = time(0);
	tm * t = localtime(&thoiGianHienTai);
	namHienTai = t -> tm_year + 1900;

	return namHienTai;
}

void tinhTuoiVaThamNienLamViec(NhanVien nv)
{
	// tuổi = năm hiện tại – năm sinh
	// thâm niên = năm hiện tại – năm vào làm

	int namHienTai = tinhNamHienTai();

	cout << "Tuoi cua nhan vien: " << namHienTai - nv.namSinhNhanVien << endl;

	cout << "Tham nien cua nhan vien: " << namHienTai - nv.namVaoLamNhanVien << endl;
}
