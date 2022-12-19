/*
	- Bài tập thêm -

	Bài 05. Xây dựng hàm nhập, xuất, tính tổng
			và đếm xem mảng vừa nhập
			có bao nhiêu phần tử là số nguyên tố
*/

#include <iostream>
#include <cmath> // Khai báo thêm thư viện để sử dụng hàm sqrt()
using namespace std;

const int SO_DONG_TOI_DA = 20, SO_COT_TOI_DA = 10;

void nhapMang(int a[][SO_COT_TOI_DA], int &soDongThucTe, int &soCotThucTe);
void xuatMang(int a[][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe);
int tinhTongCuaMang(int a[][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe);
bool laSoNguyenTo(int soNguyen);
int demSoLuongSoNguyenTo(int a[][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe);
void intCacSoLuongSoNguyenTo(int a[][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe);

int main()
{
	int a[SO_DONG_TOI_DA][SO_COT_TOI_DA];

	int soDongThucTe, soCotThucTe;

	// Kiểm soát giá trị khi người dùng nhập số dòng thực tế
	do {
		cout << "Nhap so dong can su dung (1..20): ";
		cin >> soDongThucTe;
		cout << endl;

		if (soDongThucTe <= 0 || soDongThucTe > SO_DONG_TOI_DA)
		{
			cout << "Gia tri nhap khong hop le!\n";
			cout << "Vui long nhap: 0 < So dong <= 20\n";
			cout << endl;
		}
	} while (soDongThucTe <= 0 || soDongThucTe > SO_DONG_TOI_DA);
	
	// Kiểm soát giá trị khi người dùng nhập số cột thực tế
	do {
		cout << "Nhap so cot can su dung (1..10): ";
		cin >> soCotThucTe;
		cout << endl;

		if (soCotThucTe <= 0 || soCotThucTe > SO_COT_TOI_DA)
		{
			cout << "Gia tri nhap khong hop le!\n";
			cout << "Vui long nhap: 0 < So cot <= 10\n";
			cout << endl;
		}
	} while (soCotThucTe <= 0 || soCotThucTe > SO_COT_TOI_DA);
	
	cout << "Vui long nhap mang hai chieu\n" << endl;
	nhapMang(a, soDongThucTe, soCotThucTe);
	cout << endl;
	
	cout << "Mang hai chieu la:\n" << endl;
	xuatMang(a, soDongThucTe, soCotThucTe);
	cout << endl;

	// Gọi hàm tính tổng và truyền tham số vào
	cout << "Mang co tong cac phan tu la: "
		<< tinhTongCuaMang(a, soDongThucTe, soCotThucTe);
	cout << endl;

	// Gọi hàm đếm số lượng số nguyên tố và tuyền tham số vào
	cout << "Mang vua nhap co tong cong "
		<< demSoLuongSoNguyenTo(a, soDongThucTe, soCotThucTe)
		<< " so nguyen to\n";
	cout << endl;
	
	cout << "Cac so nguyen to lan luot la: ";
	intCacSoLuongSoNguyenTo(a, soDongThucTe, soCotThucTe);
	cout << endl;

	return 0;
}

// 01. Hàm nhập mảng
void nhapMang(int a[][SO_COT_TOI_DA], int &soDongThucTe, int &soCotThucTe)
{	
	for (int i = 0; i < soDongThucTe; i++)
	{
		cout << "Nhap mot loat "
			<< soCotThucTe << " phan tu tren dong thu [" << i + 1 << "]: ";
		for (int j = 0; j < soCotThucTe; j++)
			cin >> a[i][j];
	}
	cout << endl;
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

// 03. Hàm tính tổng
int tinhTongCuaMang(int a[][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe)
{
	// Biến trung gian để lưu kết quả tính tổng,
	// khởi tạo giá trị ban đầu = 0
	// để tránh gặp phải những giá trị rác
	// trong quá trình cộng dồn và tính tổng
	int ketQuaTinhTong = 0;
	
	// Duyệt từng dòng
	for (int i = 0; i < soDongThucTe; i++)
		// Duyệt từng cột (của từng dòng)
		for (int j = 0; j < soCotThucTe; j++)
			// Nhồi liên tục để tính tổng
			ketQuaTinhTong += a[i][j];

	return ketQuaTinhTong;
}

// 04. Hàm kiểm tra một số có phải là số nguyên tố
bool laSoNguyenTo(int soNguyen)
{
	// Số nguyên tố là số bắt đầu từ 2,
	// chỉ chia được hết cho 1 và chính nó

	// Nếu nhận vào một số nhỏ hơn 2
	if (soNguyen < 2)
		// Không phải là số nguyên tố
		return false;
	else if (soNguyen == 2) // Nếu nhận vào một số = 2
		// Là số nguyên tố
		// (số 2 là số nguyên tố đầu tiên)
		return true;
	else // Nếu nhận vào một số > 2
	{
		// Sử dụng vòng lặp để kiểm tra.

		// Mọi số đều sẽ chia hết cho 1 và chính nó,
		// nhưng quan trọng là ngoài hai số đó ra,
		// thì nó không còn chia được hết cho số nào khác
		// (phải sử dụng i <= ...,
		//  nếu không sẽ bị sót trường hợp soNguyen = 4)
		for (int i = 2; i <= sqrt(soNguyen * 1.0); i++)
			
			// Nếu số nhận vào "lỡ" chia cho số nào khác
			if (soNguyen % i == 0)
				return false;
	}

	// Đi đến hết chương trình mà không gặp bất kì return nào,
	// thì đích thị đây là số nguyên tố
	return true;
}

// 05. Hàm đếm số lượng số nguyên tố trong mảng
int demSoLuongSoNguyenTo(int a[][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe)
{
	// Biến trung gian, sử dụng để đếm,
	// ban đầu khởi tạo = 0
	// để xem như chưa đếm được giá trị nào
	int tongSoLuongSoNguyenTo = 0;
	
	// Duyệt từng dòng
	for (int i = 0; i < soDongThucTe; i++)
		// Duyệt từng cột (của từng dòng)
		for (int j = 0; j < soCotThucTe; j++)
			// Lấy từng phần tử ra và đưa vào hàm laSoNguyenTo()
			// để kiểm tra xem có phải là số nguyên tố
			if (laSoNguyenTo(a[i][j]) == true)
				// Nếu phát hiện một số nào đó là số nguyên tố
				// thì tăng tổng số lượng lên 1
				tongSoLuongSoNguyenTo++;

	return tongSoLuongSoNguyenTo;
}

// 06. Hàm in ra các số lượng số nguyên tố trong mảng
void intCacSoLuongSoNguyenTo(int a[][SO_COT_TOI_DA], int soDongThucTe, int soCotThucTe)
{
	for (int i = 0; i < soDongThucTe; i++)
		for (int j = 0; j < soCotThucTe; j++)
			if (laSoNguyenTo(a[i][j]) == true)
				cout << a[i][j] << "  ";
}