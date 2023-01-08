/* L */

#include <iostream>
#include <algorithm>
#include <fstream>
#include<string>
#include <conio.h>
#include <conio.h>
using namespace std;
struct NTN
{
	int ngay;
	int thang;
	int nam;
};
struct Sach {
	char IDSach[21];
	char NameSach[21];
	NTN NTN;
};
void nhap1s(Sach& sach) {
	char dem[10];
	cin.getline(dem, 10);
	cout << "Nhap ma ";
	cin.getline(sach.IDSach, 21);

	cout << "Nhap Ten ";
	cin.getline(sach.NameSach, 21);

	cout << "Nhap ngay : ";
	cin >> sach.NTN.ngay;

	cout << "Nhap thang : ";
	cin >> sach.NTN.thang;

	cout << "Nhap nam : ";
	cin >> sach.NTN.nam;
}
void nhapDS(Sach* ds, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin của sach thu " << i + 1 << " : " << endl;
		nhap1s(ds[i]);
		cout << "-----------------------" << endl;
	}
}
void xuat1Sach(Sach &s)
{
	cout << s.IDSach;
	cout << "   " << s.NameSach;
	cout << "   " << s.NTN.ngay << "-" << s.NTN.thang << "-" << s.NTN.nam;
}
void xuatDS(Sach *&ds, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Thong tin sach " << i + 1 << " la : " << endl;
		xuat1Sach(ds[i]);
		cout << endl;
	}
}
void swap(int& a, int& b) {
	int c;
	c = a;
	a = b;
	b = c;
}
void sortDS(Sach ds[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (ds[i].NTN.nam > ds[j].NTN.nam)
				swap(ds[i].NTN.nam, ds[j].NTN.nam);
}
void demSTN(Sach ds[], int n, int nam) {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (ds[i].NTN.nam == nam)
			dem++;
	}
	if (dem == 0)
		cout << "Khong co sach san xuat vao nam " << nam << " trong kho du lieu!" << endl;
	else
		cout << "So sach co nam xuat ban vao nam " << nam << "la :" << dem << endl;
}
void DocFile() {  //doc file ngoai bai
	string id, name, time;
	int n;
	ifstream inData;
	inData.open("W.txt");
	if (inData.is_open()) {
		inData >> n;
		cout << "So sach trong file la : " << n << endl;
		while (!inData.eof()) {
			getline(inData, id, '#');  //đọc dữ liệu kiểu string
			getline(inData, name, '#');
			getline(inData, time);
			inData.ignore(1);
			cout << id << "  ";
			cout << name << " ";
			cout << time << endl;

		}
		inData.close();
		cout << "So sach trong file la : " << n << endl;

	}
	else
		cout << "Không mở được file! " << endl;

}
void DocFile2(Sach& ds, int& n, Sach List[]) {
	ifstream inData;
	int dem=0;
	inData.open("dulieu.txt");
	if (inData.is_open()) {
		inData >> n;
		cout << "So sach trong file la : " << n << endl;
		while (!inData.eof()) {
			inData.getline(ds.IDSach, sizeof(ds.IDSach), '#');// đọc dữ liệu bằng kiểu char
			inData.getline(ds.NameSach, sizeof(ds.NameSach), '#');
			//getline(inData,NTN);
			inData >> ds.NTN.ngay;
			inData.ignore(1);
			inData >> ds.NTN.thang;
			inData.ignore(1);
			inData >> ds.NTN.nam;
			List[dem] = ds;
			dem++;
		}
		inData.close();
	}
	else
		cout << "Không mở được file! " << endl;

}

// Xoá kí tự theo vị trí
void xoaTheoViTri(char s[], int viTriXoa)
{
	int doDaiChuoi = strlen(s);
	for (int i = viTriXoa + 1; i <= doDaiChuoi; i++)
		s[i - 1] = s[i];
}

// Hàm xoá toàn bộ kí tự lạ xuất hiện trong chuỗi
// (Không bao gồm chữ cái, chữ số và khoảng trắng)
void xoaToanBoKiTuLaTrongChuoi(char *s)
{
	for (int i = 0; i < strlen(s); i++)
		if (!(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z'
			|| tolower(s[i]) >= '0' && tolower(s[i]) <= '9'
			|| tolower(s[i]) == ' '))
		{
			xoaTheoViTri(s, i);
			i--;
		}
}
void xoaKhoangTrangDauChuoi(char *s)
{
	// Nếu gặp khoảng trắng ở đầu chuỗi thì xoá,
	// xoá đến khi nào gặp kí tự chữ hoặc số thì dừng
	/*  while (s[0] == ' ')*/
	for (int i = 0;; i++)
	{
		if (s[0] ==' ')
		{
			xoaTheoViTri(s, 0);
		}
		else
		{
			break;
		}
	}

}

void xoaKhoangTrangCuoiChuoi(char *s)
{
	while (s[strlen(s) - 1] == ' ')
		xoaTheoViTri(s, strlen(s) - 1);
}

// Xoá khoảng trắng thừa ở giữa các từ
void xoaKhoangTrangGiuaCacTu(char*& s)
{
	// Cho duyệt vòng lặp từ đầu đến cuối chuỗi,
	// nếu bắt gặp hai khoảng trắng thì sẽ xoá đi một
	for (int i = 0; i < strlen(s) - 1; i++)

		// Nếu hai kí tự liên nhau là khoảng trắng
			if (s[i] == ' ' && s[i + 1] ==' ')
			{
				xoaTheoViTri(s, i);
				// Kiểm tra lại tại vị trí vừa xoá
				i--;
			}
}

void vietHoaDauMoiTu(char *s)
{
	// Chuyển toàn bộ chuỗi về in thường
	//strlwr(s); // strlwr((char*)s.c_str());
	for (int i = 0; i < strlen(s); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;

	// Nếu kí tự tại vị trí thứ i là khoảng trắng
	// thì kí tự liền sau nó (i + 1) sẽ phải khác khoảng trắng
	// (Vì có i + 1 nên chỉ duyệt đến phần tử ép chót
	//  để i + 1 là phần tử cuối cùng và không bị vượt biên)

	// Xử lý in hoa kí tự đầu tiên của từ đầu tiên
	if (s[0] != ' ')
		if (s[0] >= 'a' && s[0] <= 'z')
			s[0] = s[0] - 32;

	// Xử lý in hoa kí tự đầu tiên của các từ
	// nằm phía sau từ đầu tiên
	for (int i = 0; i < strlen(s) - 1; i++)
	{
		if (s[i] == ' ' && s[i + 1] != ' ')
		{
			if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
			{
				s[i + 1] = s[i + 1] - 32;
			}
		}
	}



}
void chuanHoaChuoi(char s[])
{
	xoaToanBoKiTuLaTrongChuoi(s);
	xoaKhoangTrangDauChuoi(s);
	xoaKhoangTrangCuoiChuoi(s);
	xoaKhoangTrangGiuaCacTu(s);
	vietHoaDauMoiTu(s);
}
void thongKeSach(Sach* sach, char ten[], int& n)
{
	// Chuan hoa
	chuanHoaChuoi(ten);
	// Kiem tra
	int dem = 0;

	for (int i = 0; i < n; i++)
	{
		if (strstr(sach[i].NameSach, ten))
		{
			xuat1Sach(sach[i]);
		}
	}
}
void XoaPt(char* s, int& n, int vt)
{
	//int n = strlen(s);
	for (int i = vt + 1; i < strlen(s); i++)
	{
		s[i - 1] = s[i];
	}
	s[strlen(s) - 1] = '\0';
}
void ThemPt(char s[], int n, int vt,char ktthem)
{
	//int n = strlen(s);
	for (int i = strlen(s) - 1; i >=vt; i--)
	{
		s[i + 1] = s[i];
	}
	s[vt] = ktthem;
	s[strlen(s) + 1]='\0';
}
int main() {
	const int maxsize = 20;
	bool flag = false;
	Sach* ds;
	ifstream inData;
	int menu;
	int n=maxsize, dem = 0;
	int nam;
	char x[50];
	Sach sach;
	ds = new Sach[n];   
	char s[100];
	char ktthem[100];
	int vt;

	do {
		cout << "=============Menu==============";
		cout << "\n1. nhap bang tay." << endl;
		cout << "2.Ban muon doc thong tin sach tu file. " << endl;
		cout << "3.xuat thong tin sach. " << endl;
		cout << "4.Sap xep tang dang theo nam. " << endl;
		cout << "5.Dem so sach theo nam san xuat" << endl;
		cout << "6.In hoa chu dau va cac chu sau in thuong theo chuoi ban muon nhap." << endl;
		cout << "7.Tim kiem sach. " << endl;
		cout << "8.xoa kt. " << endl;
		cout << "9.them kt. " << endl;
		cout << "10.Ban muon ket thuc " << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			do {
				cout << "Ban muon bao nhieu sach : ";
				cin >> n;
				if (n <= 0 || n > maxsize)
					cout << "Ban chi duoc nhap toi da 20 sach . hay nhap lai!  " << endl;
			} while (n <= 0 || n > maxsize);
			nhapDS(ds, n);
			flag = true;
			continue;
		case 2:
			//cout<<"Se som cap nhat chuc nang nay "<<endl;

			cout << "-----------" << endl;
			DocFile2(sach, n, ds);
			flag = true;
			break;
		case 3:
			if (flag == true)
			{
				xuatDS(ds, n);
			}
			else
				cout << "Chua co du lieu.Vui long nhap du lieu\n";

			break;
		case 4:
			if (flag == true)
			{
				sortDS(ds, n);
				cout << "da xap xep thanh cong chon xuat de xem ket qua ";
			}
			else
				cout << "Chua co du lieu.Vui long nhap du lieu\n";

			break;
		case 5:
			cout << "Nam ban muon tim kim la nam nao : ";
			cin >> nam;
			demSTN(ds, n, nam);
			break;
		case 6:
			cout << "Nhap chuoi: ";
			cin.ignore();
			cin.getline(s, 100);
			cout << endl;
			cout << "in hoa va chuan hoa chuoi " << endl;
			cout << "Do dai chuoi truoc khi xoa: " << strlen(s) << endl;
			chuanHoaChuoi(s);
			cout << "Chuoi sau khi chuan hoa: " << s << endl;
			cout << endl;
			break;
		case 7:
			if (flag==true)
			{
				cout << "Nhap ten sach can tim,sau đó nhấn enter : ";
				cin >> x;

				thongKeSach(ds, x, n);
			}
			else
			{
				cout << "Chua co du lieu. Moi lua chon phuong thuc nhap!!!" << endl;
				cout << "-----------Menu lua chon-------------\n"
					<< "1. Nhap thong tin sach (toi da 20 quyen)\n"
					<< "2. Doc danh sach sach tu file\n"
					<< "Ban chon : ";
				switch (menu)
				{
				case 1:
					nhapDS(ds, n);
				case 2:
					DocFile2(sach, n, ds);
				default:
					break;
				}
				flag = true;
			}
			break;
		case 8:

			cout << "Nhap chuoi: ";
			cin.ignore();
			cin.getline(s, 100);
			cout << "Nhap vi tri can xoa: ";
			cin >> vt;
			XoaPt(s, n, vt);
			cout << "chuoi sau khi xoa: "<<endl;
			cout << s<<endl;
			break;
		case 9:
			cout << "Nhap chuoi: ";
			cin.ignore();
			cin.getline(s, 100);
			cout << "Nhap vi tri can them: ";
			cin >> vt;
			cout << "Nhap ki tu can them: ";
			cin.ignore();
			cin.getline(ktthem, 100);
			ThemPt(s, n, vt, ktthem);
			cout << "chuoi sau khi them: " << endl;
			cout << s << endl;
			break;
		default:
			break;
		}
		_getch();

	} while (menu != 10);


	delete[] ds;
}