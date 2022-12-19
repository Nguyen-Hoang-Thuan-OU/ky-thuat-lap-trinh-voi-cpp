/*
	Bài 01. Hãy viết chương trình:
	
			a. Nhập vào số dòng và cột cần lưu trữ
			   của một mảng 2 chiều lưu trữ toàn số nguyên
			   (tối đa 20 dòng và 10 cột).
			   Nếu sai hãy yêu cầu nhập lại cho đến khi thỏa điều kiện.
			   Nhập vào giá trị từng phần tử trong mảng.
			   
			b. Xuất lại mảng đã nhập.
			
			c. Tính tích các phần tử tại 1 dòng nào đó
			   do người dùng yêu cầu.
*/

#include <iostream>
using namespace std;

// Khai báo tĩnh số dòng và số cột tối đa
const int SO_DONG_TOI_DA = 20, SO_COT_TOI_DA = 10;

// Mặc định, khi mảng được truyền vào trong hàm
// sẽ là truyền tham chiếu (trong hàm thay đổi giá trị
// thì nơi gọi hàm cũng sẽ bị ảnh hưởng theo)

// Khai báo các nguyên mẫu hàm
void nhapMang(int a[SO_DONG_TOI_DA][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe);
void xuatMang(int a[SO_DONG_TOI_DA][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe);
int tinhTichMotDongNaoDo(int a[SO_DONG_TOI_DA][SO_COT_TOI_DA],
							int soCotThucTe, int dongCanTinhTich);

int main()
{
	// Khai báo mảng a
	// với số dòng tối đa là SO_DONG_TOI_DA
	// và số cột tối đa là SO_COT_TOI_DA
	int a[SO_DONG_TOI_DA][SO_COT_TOI_DA];

	// Trong thực tế, có thể không sử dụng hết 20 dòng và 10 cột.
	// Vì vậy, sử dụng thêm hai biến để lưu số dòng và cột
	// mà người dùng thực tế cần sử dụng
	int soDongThucTe, soCotThucTe;

	// Dòng nào đó cần tính tích
	// do người dùng yêu cầu.
	int dongCanTinhTich;

	// Kiểm soát giá trị khi người dùng nhập số dòng thực tế
	do {
		cout << "==================================================\n";
		cout << "Nhap so dong can su dung (1..20): ";
		cin >> soDongThucTe;
		cout << endl;

		if (soDongThucTe <= 0 || soDongThucTe > SO_DONG_TOI_DA)
			cout << "Vui long nhap: 0 < So dong <= 20\n";
	} while (soDongThucTe <= 0 || soDongThucTe > SO_DONG_TOI_DA);

	cout << "Tong so dong dang su dung la: " << soDongThucTe << endl;
	
	// Kiểm soát giá trị khi người dùng nhập số cột thực tế
	do {
		cout << "==================================================\n";
		cout << "Nhap so cot can su dung (1..10): ";
		cin >> soCotThucTe;
		cout << endl;

		if (soCotThucTe <= 0 || soCotThucTe > SO_COT_TOI_DA)
			cout << "Vui long nhap: 0 < So cot <= 10\n";
	} while (soCotThucTe <= 0 || soCotThucTe > SO_COT_TOI_DA);

	cout << "Tong so cot dang su dung la: " << soCotThucTe << endl;
	cout << endl;

	// Gọi hàm nhập mảng và tuyền tham số vào
	cout << "Vui long nhap mang hai chieu\n" << endl;
	nhapMang(a, soDongThucTe, soCotThucTe);
	cout << endl;

	// Gọi hàm xuất mảng và tuyền tham số vào
	cout << "Mang hai chieu la:\n" << endl;
	xuatMang(a, soDongThucTe, soCotThucTe);
	cout << endl;

	// Kiểm soát giá trị khi người dùng nhập số dòng cần tính tích
	do {
		cout << "Tong so dong dang su dung la: " << soDongThucTe << endl;
		cout << "Tong so cot dang su dung la: " << soCotThucTe << endl;
		cout << endl;

		cout << "Nhap dong can tinh tich (1.." << soDongThucTe << "): ";
		cin >> dongCanTinhTich;
		cout << endl;

		if (dongCanTinhTich < 1 || dongCanTinhTich > soDongThucTe)
			cout << "Vui long nhap so dong (1.." << soDongThucTe << ")!\n";
	} while (dongCanTinhTich < 1 || dongCanTinhTich > (soDongThucTe));

	// Gọi hàm tính tích của một dòng nào đó
	cout << "Tich cua dong " << dongCanTinhTich
		<< " la: " << tinhTichMotDongNaoDo(a, soCotThucTe, dongCanTinhTich);
	cout << endl;

	return 0;
}

// a. Hàm nhập mảng
void nhapMang(int a[SO_DONG_TOI_DA][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe)
{
	// Để gọi được hàm này,
	// nơi gọi đã phải có những giá trị tương ứng
	// như những gì mà tham số yêu cầu
	
	// Nhập từng giá trị cho mảng hai chiều,
	// cần phải biết giá trị đó nằm ở dòng và cột nào

	// Sử dụng hai vòng lặp lồng nhau
	// để duyệt từng giá trị

	// Duyệt từng dòng
	for (int i = 0; i < soDongThucTe; i++)
		// Duyệt từng cột (của từng dòng)
		for (int j = 0; j < soCotThucTe; j++)
		{
			// Yêu cầu nhập giá trị
			// cho từng phần tử trong mảng
			cout << "Vui long nhap phan tu a[" << i + 1 << "][" << j + 1 << "]: ";
			cin >> a[i][j];
		}
} // nhapMang()

// b. Hàm xuất mảng
void xuatMang(int a[SO_DONG_TOI_DA][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe)
{
	// Duyệt từng dòng
	for (int i = 0; i < soDongThucTe; i++)
	{
		// Duyệt từng cột (của từng dòng)
		for (int j = 0; j < soCotThucTe; j++)
			// In giá trị vừa mới duyệt ra
			cout << a[i][j] << "\t";

		// Sau khi in ra hết số cột trên một dòng,
		// mới tiến hành xuống hàng để in dòng mới
		cout << endl;
	}
} // xuatMang()

// c. hàm tính tích các phần tử tại 1 dòng nào đó
int tinhTichMotDongNaoDo(int a[SO_DONG_TOI_DA][SO_COT_TOI_DA],
							int soCotThucTe, int dongCanTinhTich)
{
	// Tính tích các phần tử tại 1 dòng nào đó
	// do người dùng yêu cầu.
	int ketQuaTinhTichDong = 1;

	// Sau khi đã chọn được dòng cần tính tích,
	// cố định dòng đó lại
	// và duyệt toàn bộ phần tử theo cột (từ trái sang phải)
	// để tính tích
	for (int j = 0; j < soCotThucTe; j++)
			ketQuaTinhTichDong = ketQuaTinhTichDong * a[dongCanTinhTich - 1][j];

	return ketQuaTinhTichDong;
} // tinhTichMotDongNaoNo()