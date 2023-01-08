/*
	Bài 02. Định nghĩa kiểu dữ liệu PhanSo gồm tử số và mẫu số (số nguyên).
		Sau đó viết chương trình dùng kiểu mới định nghĩa này
		để xây dựng các hàm tính tổng, hiệu, tích, thương của 2 phân số.
			
		* Lưu ý: phân số chỉ có nghĩa khi mẫu số khác 0.
*/

#include <iostream>
using namespace std;

struct PhanSo;

void nhapPhanSo(PhanSo &ps);
void inPhanSo(PhanSo ps);

int timUocChungLonNhat(int soA, int soB);
PhanSo toiGianPhanSo(PhanSo ps);
void xetDau(PhanSo &ps);

PhanSo congPhanSo(PhanSo ps1, PhanSo ps2);
PhanSo truPhanSo(PhanSo ps1, PhanSo ps2);
PhanSo nhanPhanSo(PhanSo ps1, PhanSo ps2);
PhanSo chiaPhanSo(PhanSo ps1, PhanSo ps2);

struct PhanSo
{
	int tuSo;
	int mauSo;
};
typedef struct PhanSo PhanSo;

int main()
{
	PhanSo ps1, ps2;

	PhanSo cong, tru, nhan, chia;

	cout << "Nhap phan so thu nhat:\n";
	nhapPhanSo(ps1);
	cout << endl;

	cout << "Phan so thua nhat vua nhap la: ";
	xetDau(ps1);
	inPhanSo(ps1);
	cout << endl;

	cout << "Nhap phan so thu hai:\n";
	nhapPhanSo(ps2);
	cout << endl;

	cout << "Phan so thu hai vua nhap la: ";
	xetDau(ps2);
	inPhanSo(ps2);
	cout << endl;

	cout << "Tong hai phan so la: ";
	cong = congPhanSo(ps1, ps2);
	xetDau(cong);
	inPhanSo(cong);
	cout << endl;

	cout << "Hieu hai phan so la: ";
	tru = truPhanSo(ps1, ps2);
	xetDau(tru);
	inPhanSo(tru);
	cout << endl;

	cout << "Tich hai phan so la: ";
	nhan = nhanPhanSo(ps1, ps2);
	xetDau(nhan);
	inPhanSo(nhan);
	cout << endl;

	cout << "Thuong hai phan so la: ";
	chia = chiaPhanSo(ps1, ps2);
	xetDau(chia);
	inPhanSo(chia);
	cout << endl;

	return 0;
}

void nhapPhanSo(PhanSo &ps)
{
	cout << "Nhap tu so: ";
	cin >> ps.tuSo;

	do {
		cout << "Nhap mau so (mau so > 0): ";
		cin >> ps.mauSo;

		if (ps.mauSo == 0)
		{
			cout << "Nhap sai. Nhap lai: ";
			cin >> ps.mauSo;
		}
	} while (ps.mauSo == 0);
}

void inPhanSo(PhanSo ps)
{
	cout << ps.tuSo << " / " << ps.mauSo << endl;
}

int timUocChungLonNhat(int soA, int soB)
{
	// Cách 1
	/*soA = abs(soA);
	soB = abs(soB);

	while (soA != soB)
	{
		if (soA > soB)
			soA = soA - soB;
		else
			soB = soB - soA;
	}*/

	// Cách 2
	while (soB != 0)
	{
		int soD = soA % soB;
		soA = soB;
		soB = soD;
	}
	return soA;
}

PhanSo toiGianPhanSo(PhanSo ps)
{
	PhanSo ketQuaToiGian;

	int soD = timUocChungLonNhat(ps.tuSo, ps.mauSo);

	ketQuaToiGian.tuSo = ps.tuSo / soD;
	ketQuaToiGian.mauSo = ps.mauSo / soD;

	return ketQuaToiGian;
}

PhanSo congPhanSo(PhanSo ps1, PhanSo ps2)
{
	PhanSo ketQuaCong;

	ketQuaCong.tuSo = (ps1.tuSo * ps2.mauSo) +
					  (ps2.tuSo * ps1.mauSo);

	ketQuaCong.mauSo = ps1.mauSo * ps2.mauSo;

	ketQuaCong = toiGianPhanSo(ketQuaCong);

	return ketQuaCong;
}

PhanSo truPhanSo(PhanSo ps1, PhanSo ps2)
{
	PhanSo ketQuaTru;

	ketQuaTru.tuSo = (ps1.tuSo * ps2.mauSo) -
					 (ps2.tuSo * ps1.mauSo);

	ketQuaTru.mauSo = ps1.mauSo * ps2.mauSo;

	ketQuaTru = toiGianPhanSo(ketQuaTru);

	return ketQuaTru;
}

PhanSo nhanPhanSo(PhanSo ps1, PhanSo ps2)
{
	PhanSo ketQuaNhan;

	ketQuaNhan.tuSo = ps1.tuSo * ps2.tuSo;

	ketQuaNhan.mauSo = ps1.mauSo * ps2.mauSo;

	ketQuaNhan = toiGianPhanSo(ketQuaNhan);

	return ketQuaNhan;
}

PhanSo chiaPhanSo(PhanSo ps1, PhanSo ps2)
{
	PhanSo ketQuaChia;

	ketQuaChia.tuSo = ps1.tuSo * ps2.mauSo;

	ketQuaChia.mauSo = ps1.mauSo * ps2.tuSo;

	ketQuaChia = toiGianPhanSo(ketQuaChia);

	return ketQuaChia;
}

void xetDau(PhanSo &ps)
{
	if ((ps.tuSo > 0 && ps.mauSo < 0) || (ps.tuSo < 0 && ps.mauSo < 0))
	{
		ps.tuSo = ps.tuSo * (-1);
		ps.mauSo = ps.mauSo * (1);
	}
}
