/*
	CÂU 03. Dùng con trỏ và ký pháp độ dời để thực hiện:
	Viết chương trình dùng cấp phát động, thực hiện các hàm:
		- Nhập 1 mảng số nguyên 1 chiều tối đa 20 phần tử.
		- Xuất 1 mảng số nguyên 1 chiều tối đa 20 phần tử
		- Hàm trả về địa chỉ phần tử là số chính phương cuối cùng trong mảng.
		  Nếu không có số chính phương thì trả về NULL.
		  (Biết rằng số chính phương là số có căn bậc 2 là một số nguyên.)
		- Hàm xóa 1 phần tử tại vị trí x ra khỏi mảng.
		- Hàm main để kiểm chứng toàn bộ chương trình.
*/

#include <iostream>
using namespace std;

void nhap_Mang(int *mang, int phan_Tu)
{
	cout << "Nhap " << phan_Tu << " so nguyen: ";
	for (int i = 0; i < phan_Tu; i++)
		cin >> *(mang + i);
}

void xuat_Mang(int *mang, int phan_Tu)
{
	for (int i = 0; i < phan_Tu; i++)
		cout << *(mang + i) << " ";
}

int* kiem_Tra_Phan_Tu_Cuoi_La_So_Chinh_Phuong(int *mang, int phan_Tu)
{
	for (int i = phan_Tu; i >= 0; i--)
	{
		int dem = 0;
		while (dem * dem <= *(mang + i))
		{
			if (dem * dem == *(mang + i))
			{
				int vi_Tri = i;
				return &mang[vi_Tri];
			}
			dem++;
		}
	}
	return NULL;
}

void xoa_Phan_Tu(int *mang, int &phan_Tu, int vi_Tri_Xoa)
{
	vi_Tri_Xoa--;
	for (int i = vi_Tri_Xoa; i < phan_Tu; i++)
		*(mang + i) = *(mang + i + 1);
	phan_Tu--;
}

int main()
{
	int *mang;
	int phan_Tu, vi_Tri_Xoa, *dia_Chi_Chinh_Phuong;
	cout << "Nhap so phan tu: ";
	cin >> phan_Tu;
	do {
		if (phan_Tu <= 0 || phan_Tu > 20)
		{
			cout << "Nhap phan tu tu 0 den 20 phan tu. Nhap lai: ";
			cin >> phan_Tu;
		}
	} while (phan_Tu <= 0 || phan_Tu >20);
	mang = new int[phan_Tu];
	nhap_Mang(mang, phan_Tu);
	cout << "Mang vua nhap: ";
	xuat_Mang(mang, phan_Tu);
	cout << endl;
	cout << "Dia chi phan tu dau tien cua mang: " << int(&mang[0]) << endl;
	dia_Chi_Chinh_Phuong = kiem_Tra_Phan_Tu_Cuoi_La_So_Chinh_Phuong(mang, phan_Tu);
	if (dia_Chi_Chinh_Phuong == NULL)
		cout << "Khong co phan tu chinh phuong trong mang.\n";
	else
		cout << "Dia chi phan tu chinh phuong cuoi cung trong mang: " << int(dia_Chi_Chinh_Phuong) << endl;
	cout << "Nhap vi tri phan tu can xoa: ";
	cin >> vi_Tri_Xoa;
	cout << "Mang sau khi xoa la: ";
	xoa_Phan_Tu(mang, phan_Tu, vi_Tri_Xoa);
	xuat_Mang(mang, phan_Tu);
	delete[]mang;
	mang = NULL;
}