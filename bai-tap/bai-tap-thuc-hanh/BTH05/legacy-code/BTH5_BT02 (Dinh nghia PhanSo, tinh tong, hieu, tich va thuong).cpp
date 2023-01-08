// Định nghĩa kiểu dữ liệu PhanSo. Xây dựng hàm tính tổng, hiệu, tích và thương của 2 phân số


#include<iostream>
#include<string>
using namespace std;

struct PhanSo
{
	int mauSo;
	int tuSo;
};

// Hàm nhập phân số

void nhapPhanSo(PhanSo &ps)
{
	do{
		cout << "Nhap tu so: ";
		cin >> ps.tuSo;
		cout << "Nhap mau so: ";
		cin >> ps.mauSo;
	}while(ps.mauSo == 0);
}

// Hàm xuất phân số

void xuatPhanSo(const PhanSo ps)
{
	cout << ps.tuSo << "/" << ps.mauSo << endl;
}

// Hàm nhận vào 2 phân số, trả về kết quả cộng, hiệu, tích và thương của 2 phân số này

// Hàm tìm ước chung lớn nhất

int UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while(a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

// Hàm tối giản phân số

PhanSo toiGian(PhanSo ps)
{
	PhanSo kq;
	int d = UCLN(ps.tuSo, ps.mauSo);

	kq.tuSo = ps.tuSo/d;
	kq.mauSo = ps.mauSo/d;

	return kq;
}

// Hàm cộng phân số

PhanSo congPhanSo(PhanSo p1, PhanSo p2)
{
	PhanSo kq;
	kq.tuSo = (p1.tuSo * p2.mauSo) + (p2.tuSo * p1.mauSo);
	kq.mauSo = p1.mauSo * p2.mauSo;
	kq = toiGian(kq);

	return kq;
}

// Hàm trừ phân số

PhanSo truPhanSo(PhanSo p1, PhanSo p2)
{
	PhanSo kq;
	kq.tuSo = (p1.tuSo * p2.mauSo) - (p2.tuSo * p1.mauSo);
	kq.mauSo = p1.mauSo * p2.mauSo;
	if ( kq.tuSo != 0 )
		kq = toiGian(kq);

	return kq;
}

// Hàm nhân phân số

PhanSo nhanPhanSo(PhanSo p1, PhanSo p2)
{
	PhanSo kq;
	kq.tuSo = p1.tuSo * p2.tuSo;
	kq.mauSo = p1.mauSo * p2.mauSo;
	kq = toiGian(kq);

	return kq;
}

// Hàm chia phân số

PhanSo chiaPhanSo(PhanSo p1, PhanSo p2)
{
	PhanSo kq;
	kq.tuSo = p1.tuSo * p2.mauSo;
	kq.mauSo = p1.mauSo * p2.tuSo;
	kq = toiGian(kq);

	return kq;
}

int main()
{
	PhanSo p1, p2;

	cout << "Nhap phan so thu 1: " << endl;
	nhapPhanSo(p1);
	xuatPhanSo(p1);
	cout << endl;

	cout << "Nhap phan so thu 2: " << endl;
	nhapPhanSo(p2);
	xuatPhanSo(p2);
	cout << endl;

	PhanSo Tong = congPhanSo (p1, p2);
	cout << "Tong: ";
	xuatPhanSo (Tong);

	PhanSo Hieu = truPhanSo (p1, p2);
	cout << "Hieu: ";
	xuatPhanSo (Hieu);

	PhanSo Tich = nhanPhanSo (p1, p2);
	cout << "Tich: ";
	xuatPhanSo (Tich);

	PhanSo Thuong = chiaPhanSo (p1, p2);
	cout << "Thuong: ";
	xuatPhanSo (Thuong);

	return 0;
}