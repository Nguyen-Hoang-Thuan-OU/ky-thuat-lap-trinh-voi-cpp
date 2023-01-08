// Viết chương trình định nghĩa struct NhanVien gồm các thông tin:
//• Mã nhân viên kiểu string
//• Họ tên nhân viên kiểu string
//• Năm sinh kiểu int
//• Chức vụ kiểu string
//• Bậc lương kiểu double
// Sau đó khai báo để có thể nhập và xuất thông tin của 1 nhân viên cụ thể.

#include<iostream>
#include<string>
using namespace std;

// Định nghĩa struct NhanVien

struct NhanVien
{
	string MaNhanVien;
	string HoTenNhanVien;
	int NamSinhNhanVien;
	string ChucVuNhanVien;
	double BacLuongNhanVien;
};

void nhapNhanVien(NhanVien &nv)
{
	cout << "Ma nhan vien: ";
	getline(cin, nv.MaNhanVien);

	cin.ignore();

	cout << "Ho ten nhan vien: ";
	getline(cin, nv.HoTenNhanVien);

	cin.ignore();

	cout << "Nam sinh nhan vien: ";
	cin >> nv.NamSinhNhanVien;

	cin.ignore();

	cout << "Chuc vu nhan vien: ";
	getline(cin, nv.ChucVuNhanVien);

	cin.ignore();

	cout << "Bac luong nhan vien: ";
	cin >> nv.BacLuongNhanVien;
	cin.ignore();
}

void xuatNhanVien(const NhanVien nv)
{
	cout << "Ma nhan vien: " << nv.MaNhanVien << endl;
	cout << "Ho ten nhan vien: " << nv.HoTenNhanVien << endl;
	cout << "Nam sinh nhan vien: " << nv.NamSinhNhanVien << endl;
	cout << "Chuc vu nhan vien: " << nv.ChucVuNhanVien << endl;
	cout << "Bac luong nhan vien: " << nv.BacLuongNhanVien << endl;
}

int main()
{
	// Khai báo biến kiểu NhanVien

	NhanVien nv;

	cout << "NHAP THONG TIN NHAN VIEN" << endl;
	nhapNhanVien(nv);

	cout << "\nXUAT THONG TIN NHAN VIEN" << endl;
	xuatNhanVien(nv);

	return 0;
}