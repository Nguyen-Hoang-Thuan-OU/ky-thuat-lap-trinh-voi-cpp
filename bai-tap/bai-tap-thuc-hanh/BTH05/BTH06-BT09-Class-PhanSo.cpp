/*
	Bài 09. Viết lớp PhanSo với 2 biến tử số và mẫu số
		có mức độ truy xuất là private.
		Các hàm tính toán và trả dữ liệu đều truy xuất ở mức public.
		Thực hiện các phép tính cộng, trừ, nhân, chia giữa 2 phân số.
		* Lưu ý: toàn bộ định nghĩa class chuyển sang lưu trữ ở header file.
*/

#include<iostream>
#include<cmath>
using namespace std;

class PhanSo
{
private:
	int TS, MS;
public:
	void Nhap();
	void Xuat();
	void ToiGian();
	void Cong(PhanSo P1, PhanSo P2);
	void Tru(PhanSo P1, PhanSo P2);
	void Nhan(PhanSo P1, PhanSo P2);
	void Chia(PhanSo P1, PhanSo P2);
};

void PhanSo::Nhap()
{
	cout << "Nhap Tu So: "; cin >> TS;
	cout << "Nhap Mau So: "; cin >> MS;
}

void PhanSo::Xuat()
{
	cout << TS << "/" << MS;
}

void PhanSo::ToiGian()
{
	int a, b;
	a = abs(TS);
	b = abs(MS);
	while (a != b)
		if (a > b)
			a = a - b;
		else
			b = b - a;
	TS = TS / a;
	MS = MS / b;
}

void PhanSo::Cong(PhanSo P1, PhanSo P2)
{
	TS = P1.TS*P2.MS + P2.TS*P1.MS;
	MS = P1.MS*P2.MS;
	ToiGian();
}

void PhanSo::Tru(PhanSo P1, PhanSo P2)
{
	TS = P1.TS*P2.MS - P2.TS*P1.MS;
	MS = P1.MS*P2.MS;
	if (TS != 0)
		ToiGian();
}

void PhanSo::Nhan(PhanSo P1, PhanSo P2)
{
	TS = P1.TS*P2.TS;
	MS = P1.MS*P2.MS;
	ToiGian();
}

void PhanSo::Chia(PhanSo P1, PhanSo P2)
{
	TS = P1.TS*P2.MS;
	MS = P1.MS*P2.TS;
	ToiGian();
}

int main()
{
	PhanSo P1, P2, P3, P4, P5, P6;

	cout << "Nhap so thu 1: \n";
	P1.Nhap();
	cout << "Nhap so thu 2: \n";
	P2.Nhap();

	P3.Cong(P1, P2);
	P4.Tru(P1, P2);
	P5.Nhan(P1, P2);
	P6.Chia(P1, P2);

	cout << "\nKet qua cac phep Toan: \n";
	// cong
	P1.Xuat();
	cout << " + ";
	P2.Xuat();
	cout << " = ";
	P3.Xuat();
	cout << endl;

	//tru
	P1.Xuat();
	cout << " - ";
	P2.Xuat();
	cout << " = ";
	P4.Xuat();
	cout << endl;

	//nhan
	P1.Xuat(); cout << " * "; P2.Xuat(); cout << " = "; P5.Xuat(); cout << endl;

	//chia
	P1.Xuat(); cout << " : "; P2.Xuat(); cout << " = "; P6.Xuat(); cout << endl;

	system("pause");
	return 0;
}
