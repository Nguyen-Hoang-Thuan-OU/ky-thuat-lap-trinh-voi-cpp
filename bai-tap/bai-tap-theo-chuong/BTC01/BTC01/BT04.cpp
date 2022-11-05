/*
	Bài 04. Viết chương trình cho phép nhập vào
			một mảng số nguyên tối đa 10 dòng và 5 cột.
			Sau đó tìm xem một giá trị x nào đó
			(do người dùng nhập) có trong mảng hay không?
			Bao nhiêu lần? Vị trí đầu tiên xuất hiện là ở đâu?
*/

#include <iostream>
using namespace std;

const int SO_DONG_TOI_DA = 10, SO_COT_TOI_DA = 5;

void nhapMang(int a[][SO_COT_TOI_DA], int &soDongThucTe, int &soCotThucTe);
void xuatMang(int a[][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe);
void kiemTraGiaTriCoTrongMang(int a[][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe,
								int &giaTriCanTim, int &viTriDong, int &viTriCot);

int main()
{
	int a[SO_DONG_TOI_DA][SO_COT_TOI_DA];
	
	int soDongThucTe, soCotThucTe;

	int giaTriCanTim;

	int viTriDong, viTriCot;

	cout << "Nhap mang hai chieu\n" << endl;
	nhapMang(a, soDongThucTe, soCotThucTe);
	cout << endl;

	cout << "Mang hai chieu la:\n" << endl;
	xuatMang(a, soDongThucTe, soCotThucTe);
	cout << endl;
	
	cout << "Tim mot gia tri xem co trong mang hay khong\n" << endl;
	kiemTraGiaTriCoTrongMang(a, soDongThucTe, soCotThucTe,
								giaTriCanTim, viTriDong, viTriCot);
	cout << endl;

	return 0;
}

// 01. Hàm nhập mảng
void nhapMang(int a[][SO_COT_TOI_DA], int &soDongThucTe, int &soCotThucTe)
{
	// Kiểm soát giá trị khi người dùng nhập số dòng thực tế
	do {
		cout << "Nhap so dong can su dung (1..10): ";
		cin >> soDongThucTe;
		cout << endl;

		if (soDongThucTe <= 0 || soDongThucTe > SO_DONG_TOI_DA)
		{
			cout << "Gia tri nhap khong hop le!\n";
			cout << "Vui long nhap: 0 < So dong <= 10\n";
			cout << endl;
		}
	} while (soDongThucTe <= 0 || soDongThucTe > SO_DONG_TOI_DA);
	
	// Kiểm soát giá trị khi người dùng nhập số cột thực tế
	do {
		cout << "Nhap so cot can su dung (1..5): ";
		cin >> soCotThucTe;
		cout << endl;

		if (soCotThucTe <= 0 || soCotThucTe > SO_COT_TOI_DA)
		{
			cout << "Gia tri nhap khong hop le!\n";
			cout << "Vui long nhap: 0 < So cot <= 5\n";
			cout << endl;
		}
	} while (soCotThucTe <= 0 || soCotThucTe > SO_COT_TOI_DA);
	
	for (int i = 0; i < soDongThucTe; i++)
	{
		cout << "Hay nhap cung luc " << soCotThucTe
			<< " phan tu cua dong thu [" << i + 1
			<< "]: ";
		for (int j = 0; j < soCotThucTe; j++)
			cin >> a[i][j];
	}
}

// 02. Hàm xuất mảng
void xuatMang(int a[][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe)
{	
	for (int i = 0; i < soDongThucTe; i++)
	{
		for (int j = 0; j < soCotThucTe; j++)
			cout << a[i][j] << "\t";

		cout << endl;
	}
}

// 03. Hàm tìm giá trị một giá trị có trong mảng,
//	   nếu có thì xuất hiện bao nhiêu lần
//	   và vị trí đầu tiên xuất hiện là ở đâu?
void kiemTraGiaTriCoTrongMang(int a[][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe,
								int &giaTriCanTim, int &viTriDong, int &viTriCot)
{
	int demSoLanXuatHien = 0;

	cout << "Nhap gia tri can tim: ";
	cin >> giaTriCanTim;
	cout << endl;

	for (int i = 0; i < soDongThucTe; i++)
		for (int j = 0; j < soCotThucTe; j++)
			if (a[i][j] == giaTriCanTim)
			{
				demSoLanXuatHien++;

				if (demSoLanXuatHien == 1)
				{
					viTriDong = i;
					viTriCot = j;
				}
			}

	if (demSoLanXuatHien == 0)
		cout << "Khong tim thay " << giaTriCanTim << " trong mang!\n" << endl;
	else
	{
		cout << "Da tim thay " << giaTriCanTim
			<< " xuat hien " << demSoLanXuatHien << " lan!\n" << endl;
		
		cout << "Vi tri dau tien xuat hien la tai dong [" << viTriDong + 1 << "]"
			<< " va cot [" << viTriCot + 1 << "]\n"<< endl;
	}
}