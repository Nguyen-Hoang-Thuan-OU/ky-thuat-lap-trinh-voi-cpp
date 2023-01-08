/*
	Bài 11. Viết chương trình đặt chỗ ngồi cho 1 máy bay.
		Máy bay có 13 hàng ghế, mỗi hàng có 6 ghế.
		Hàng 1 và 2 là hạng thương gia,
		hàng 3 đến 7 là hạng phổ thông,
		hàng 8 trở đi là hạng tiết kiệm
*/

// Chưa hoàn thiện về các lựa chọn: luaChonHangVe, luaChonDeTiepTucDatVe

#include <iostream>
#include <conio.h>

using namespace std;

const int MAX = 20;

void xuatViTriChoNgoi(int a[][MAX], int hang, int cot);
bool kiemTraChoNgoiCoTrong(int a[][MAX], int viTriHang, int viTriCot);
void khoiTaoViTriDatChoMacDinh(int a[][MAX], int hang, int cot);
int chuyenKiTuThuongThanhHoa(int a[][MAX], char &viTriGheNgoi);

int main()
{
	int a[MAX][MAX] = { {0} };
	int hang = 13, cot = 6;
	int viTriHangDaChon, viTriCotDaChon;
	int luaChonHangVe, luaChonDeTiepTucDatVe;

	do {
		do {
			system("cls");
			cout << endl;

			khoiTaoViTriDatChoMacDinh(a, hang, cot);
			xuatViTriChoNgoi(a, hang, cot);
			cout << endl;

			cout << "Danh sach cac loai ve:\n";
			cout << "1. Hang thuong gia - hang ghe (1..2)\n";
			cout << "2. Hang pho thong - hang ghe (3..7)\n";
			cout << "3. Hang tiet kiem - hang ghe (8..13)\n";
			cout << "Vui long chon hang ve (1..3): ";
			cin >> luaChonHangVe;

			cout << endl;

			switch (luaChonHangVe)
			{
			case 1:
				do {
					cout << "Hang thuong gia - hang ghe (1..2)\n";
					cout << "Moi ban nhap hang ghe (1..2): ";
					cin >> viTriHangDaChon;
					cout << endl;

					if (viTriHangDaChon != 1 && viTriHangDaChon != 2)
						cout << "Nhap sai, vui long nhap lai - hang ghe (1..2)!\n" << endl;
				} while (viTriHangDaChon != 1 && viTriHangDaChon != 2);
				break;

			case 2:
				do {
					cout << "Hang pho thong - hang ghe (3..7)\n";
					cout << "Moi ban nhap hang ghe (3..7): ";
					cin >> viTriHangDaChon;
					cout << endl;

					if (viTriHangDaChon < 3 || viTriHangDaChon > 7)
						cout << "Nhap sai, vui long nhap lai - hang ghe (3..7)!\n" << endl;
				} while (viTriHangDaChon < 3 || viTriHangDaChon > 7);
				break;

			case 3:
				do {
					cout << "Hang tiet kiem - hang ghe (8..13)\n";
					cout << "Moi ban nhap hang ghe (8..13): ";
					cin >> viTriHangDaChon;
					cout << endl;

					if (viTriHangDaChon < 8 && viTriHangDaChon > 13)
						cout << "Nhap sai, vui long nhap lai - hang ghe (8..13)!\n" << endl;
				} while (viTriHangDaChon < 8 && viTriHangDaChon > 13);
				break;

				_getch();

			default:
				cout << "Nhap sai, vui long nhap lai (1..3)!\n";
			}

		} while (luaChonHangVe < 1 || luaChonHangVe > 3);

		char viTriGheNgoi;
		do {
			cout << "Moi nhap vi tri ghe (A..F): ";
			cin >> viTriGheNgoi;

			chuyenKiTuThuongThanhHoa(a, viTriGheNgoi);

			if (viTriGheNgoi < 'A' || viTriGheNgoi > char(65 + (cot - 1)))
				cout << "Nhap sai, vui long nhap lai (A..F)\n";
		} while (viTriGheNgoi < 'A' || viTriGheNgoi > char(65 + (cot - 1)));

		viTriCotDaChon = int(viTriGheNgoi) - 65;

		if (!kiemTraChoNgoiCoTrong(a, viTriHangDaChon - 1, viTriCotDaChon))
		{
			a[viTriHangDaChon - 1][viTriCotDaChon] = 1;
			system("cls");

			cout << "Xin chuc mung! Ban da dat cho thanh cong!\n" << endl;

			cout << "[Hang ghe cua ban la hang " << viTriHangDaChon
				<< " va ghe " << viTriGheNgoi << "]\n" << endl;

			cout << "Bang dat cho hien tai la: \n";
			xuatViTriChoNgoi(a, hang, cot);
		}
		else
			cout << "Rat tiec, vi tri ma ban vua dat hien khong con trong!\n";

		cout << "\nBan co muon tiep tuc dat ve?\n";
		cout << "1. Tiep tuc\n";
		cout << "2. Khong tiep tuc\n";
		cout << "Lua chon: ";
		cin >> luaChonDeTiepTucDatVe;

	} while (luaChonDeTiepTucDatVe == 1);
	cout << "\nHen gap lai, chuc mot ngay tot lanh\n" << endl;

	return 0;
}

void khoiTaoViTriDatChoMacDinh(int a[][MAX], int hang, int cot)
{
	a[1][0] = 1;
	a[5][3] = 1;
	a[9][5] = 1;
}

void xuatViTriChoNgoi(int a[][MAX], int hang, int cot)
{
	cout << "\t";
	for (int i = 0; i < cot; i++)
		cout << char(65 + i) << "\t";

	cout << endl;

	for (int i = 0; i < hang; i++)
	{
		cout << "Hang " << i + 1 << "\t";

		for (int j = 0; j < cot; j++)
			if (kiemTraChoNgoiCoTrong(a, i, j))
				cout << "x" << "\t";
			else
				cout << "*" << "\t";

		cout << endl;
	}
}

bool kiemTraChoNgoiCoTrong(int a[][MAX], int viTriHang, int viTriCot)
{
	if (a[viTriHang][viTriCot] == 1)
		return true;
	return false;
}

int chuyenKiTuThuongThanhHoa(int a[][MAX], char &viTriGheNgoi)
{
	if (viTriGheNgoi >= 'a' && viTriGheNgoi <= 'z')
		viTriGheNgoi = int(viTriGheNgoi - 32);

	return viTriGheNgoi;
}