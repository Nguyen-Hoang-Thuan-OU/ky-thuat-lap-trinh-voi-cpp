/*
	CÂU 01. Xây dựng 1 chương trình gồm các hàm sau:

			- Nhập mảng số nguyên gồm m hàng n cột (tối đa 10 hàng, 15 cột).

			- Xuất mảng số nguyên gồm m hàng n cột (tối đa 10 hàng, 15 cột).

			- Trả về kết quả tích các số lẻ tại 1 hàng nào đó do người dùng yêu cầu
			  trong mảng số nguyên m hàng n cột.

			  Lưu ý: hàng phải hợp lệ
					 (từ 1 đến số hàng tối đa mà ma trận đang có).

					 Nếu không có số lẻ trong hàng đó thì báo không có
					 và không xuất kết quả tích.

			- Hàm main để kiểm chứng toàn bộ chương trình.
*/

// Sử dụng con trỏ

#include <iostream>
using namespace std;

void nhapMang(int **a, int dong, int cot);
void inMang(int **a, int dong, int cot);
int tinhTichCacSoLeTaiMotDong(int **a, int cot, int dongCanTinhTich);

int main()
{
	int **a;
	int dongThucTe, cotThucTe;
	int dongCanTinhTich;

	// Nhập số dòng thực tế cần sử dụng
	cout << "Nhap so dong thuc te can su dung (1..10): ";
	cin >> dongThucTe;
	cout << endl;
	do {
		if (dongThucTe < 1 || dongThucTe > 10)
		{
			cout << "Vui long nhap so dong thuc te can su dung (1..10). Nhap lai: ";
			cin >> dongThucTe;
			cout << endl;
		}
	} while(dongThucTe < 1 || dongThucTe > 10);
	
	// Nhập số cột thực tế cần sử dụng
	cout << "Nhap so cot thuc te can su dung (1..15): ";
	cin >> cotThucTe;
	cout << endl;
	do {
		if (cotThucTe < 1 || cotThucTe > 15)
		{
			cout << "Vui long nhap lai so cot thuc te can su dung (1..10). Nhap lai: ";
			cin >> cotThucTe;
			cout << endl;
		}
	} while(cotThucTe < 1 || cotThucTe > 15);

	// Cấp phát mảng các con trỏ (số dòng)
	a = new int* [dongThucTe];
	// Cấp phát vùng nhớ cho mỗi con trỏ (số cột)
	for (int i = 0; i < dongThucTe; i++)
		a[i] = new int[cotThucTe];

	// Gọi hàm nhập mảng
	cout << "Nhap mang\n";
	nhapMang(a, dongThucTe, cotThucTe);
	cout << endl;

	// Gọi hàm in mảng
	cout << "Mang vua nhap la:\n";
	inMang(a, dongThucTe, cotThucTe);
	cout << endl;

	// Nhập dòng cần tính tích
	cout << "Nhap dong can tinh tich cac so le (1.." << dongThucTe << "): ";
	cin >> dongCanTinhTich;
	cout << endl;
	do {
		if (dongCanTinhTich < 1 || dongCanTinhTich > dongThucTe)
		{
			cout << "Vui long nhap lai dong can tinh tich (1.."
				<< dongThucTe << "). Nhap lai: ";
			cin >> dongCanTinhTich;
			cout << endl;
		}
	} while (dongCanTinhTich < 1 || dongCanTinhTich > dongThucTe);
	
	// Gọi hàm tính tích các giá trị tại một dòng bất kì

	// Nếu hàm có trả về giá trị, nghĩa là có số lẻ để tính tích
	if (tinhTichCacSoLeTaiMotDong(a, cotThucTe, dongCanTinhTich) != 0)
		cout << "Tich cua cac phan tu la so le tai dong [" << dongCanTinhTich << "] la: "
			<< tinhTichCacSoLeTaiMotDong(a, cotThucTe, dongCanTinhTich) << endl;
	else // Nếu hàm trả về giá trị = 0
		cout << "Tai dong [" << dongCanTinhTich
			<< "] khong co bat ki gia tri nao la so le!" << endl;
	cout << endl;

	// Huỷ vùng nhớ của con trỏ
	for (int i = 0; i < dongThucTe; i++)
		delete[] a[i];
	delete[]a;
	a = nullptr;

	return 0;
}

// 01. Hàm nhập mảng
void nhapMang(int **a, int dong, int cot) // a[MAX_DONG][MAX_COT]
{
	for (int i = 0; i < dong; i++)
	{
		cout << "Nhap mot loat " << cot
			<< " phan tu cho dong thu [" << i + 1 << "]: ";

		for (int j = 0; j < cot; j++)
			cin >> *(*(a + i) + j); // a[i][j]
	}
}

// 02. Hàm in mảng
void inMang(int **a, int dong, int cot) // a[MAX_DONG][MAX_COT]
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			cout << *(*(a + i) + j) << "  "; // a[i][j]

		cout << endl;
	}
}

// 03. Hàm tính tích (nhân) các giá số lẻ
//	   tại một hàng do người dùng yêu cầu
int tinhTichCacSoLeTaiMotDong(int **a, int cot, int dongCanTinhTich) // a[MAX_DONG][MAX_COT]
{
	int tichCacSoLe = 0;
	dongCanTinhTich--;

	for (int j = 0; j < cot; j++)
		if (*(*(a + dongCanTinhTich) + j) % 2 != 0) // a[dongCanTinhTich][j]
		{
			if (tichCacSoLe == 0)
				tichCacSoLe = 1;
			tichCacSoLe = tichCacSoLe * *(*(a + dongCanTinhTich) + j); // a[dongCanTinhTich][j]
		}

	return tichCacSoLe;
}