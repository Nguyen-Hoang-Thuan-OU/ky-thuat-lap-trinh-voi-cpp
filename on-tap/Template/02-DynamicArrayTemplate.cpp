/*
	MẢNG MỘT CHIỀU - CẤP PHÁT ĐỘNG
	NHẬP, XUẤT MẢNG; THÊM-XOÁ-SỬA-TÌM-KIẾM
*/

#include <iostream>
#include <ctime>
using namespace std;

void nhapMang(int* a, int n);
void xuatMang(int* a, int n);
void capPhatLaiVungNho(int*& a, int vungNhoCu, int vungNhoMoi);
void themPhanTu(int*& a, int &n, int viTriThem, int giaTriThem);
void xoaPhanTuTheoViTri(int*& a, int &n, int viTriXoa);
void xoaPhanTuTheoGiaTri(int*& a, int &n, int giaTriXoa);
int* timKiemPhanTu(int* a, int n, int giaTriCanTim);
void viTriPhanTuDauTienXuatHien(int* a, int n, int &x);
void inRaDiaChiCuaCacPhanTu(int* a, int n);

int main()
{
	srand(time(0));
	int* a;
	int n;
	int viTriThem, giaTriThem;
	int viTriXoa, giaTriXoa;

	cout << "Nhap so luong cua mang (n > 0): ";
	cin >> n;
	do {
		if (n < 0)
		{
			cout << "Nhap sai, vui long nhap so luong cua mang (n > 0): ";
			cin >> n;
		}
	} while (n < 0);

	a = new int[n];

	// Nhập mảng
	cout << "Mang da duoc tao tu dong!";
	nhapMang(a, n);
	cout << endl;

	// In mảng
	cout << "Mang vua tao: ";
	xuatMang(a, n);
	cout << endl;

	/* Thêm giá trị vào vị trí bất kì */
	cout << "Gia tri can them: ";
	cin >> giaTriThem;
	cout << "Them tai vi tri: ";
	cin >> viTriThem;
	cout << endl;

	cout << "Mang sau khi them la: ";
	themPhanTu(a, n, viTriThem, giaTriThem);
	xuatMang(a, n);
	cout << endl;

	/* Xoá giá trị tại vị trí bất kì */
	cout << "Vi tri can xoa: ";
	cin >> viTriXoa;
	cout << endl;

	cout << "Mang sau khi xoa theo vi tri la: ";
	xoaPhanTuTheoViTri(a, n, viTriXoa);
	xuatMang(a, n);
	cout << endl;

	/* Xoá toàn bộ giá trị */
	cout << "Gia tri can xoa: ";
	cin >> giaTriXoa;
	cout << endl;

	cout << "Mang sau khi xoa theo gia tri la: ";
	xoaPhanTuTheoGiaTri(a, n, giaTriXoa);
	xuatMang(a, n);
	cout << endl;

	delete[] a;
	a = NULL;

	return 0;
}

// 01. Hàm nhập mảng
void nhapMang(int* a, int n)
{
	for (int i = 0; i < n; i++)
		*(a + i) = rand() % 3;
}

// 02. Hàm xuất mảng
void xuatMang(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(a + i) << " ";
}

// 03. Hàm giả lập lại hàm realloc() của ngôn ngữ C
//     (Nới rộng hoặc thu hẹp ô nhớ cho vùng nhớ cấp phát động)
void capPhatLaiVungNho(int*& a, int vungNhoCu, int vungNhoMoi)
{
	// Tạo ra một mảng phụ với số lượng phần tử giống hệ mảng gốc
	// để nhận các phần tử từ mảng gốc gửi sang
	int* b = new int[vungNhoCu];
	for (int i = 0; i < vungNhoCu; i++)
		b[i] = a[i];

	// Giải phóng vùng nhớ cũ của mảng gốc
	delete[] a;

	// Cấp phát lại vùng nhớ mới cho mảng gốc
	// và nhận lại tất cả các phần tử từ mảng phụ trả về
	// (Duyệt theo kích thước cũ để đưa sang kích thước mới)
	a = new int[vungNhoMoi];
	for(int i = 0; i < vungNhoCu; i++)
		a[i] = b[i];

	// Giải phóng vùng nhớ cho mảng phụ
	delete[] b;
	b = NULL;
}

// 04. Hàm thêm một phần tử vào một vị trí
// * Cần phải truyền tham chiếu cho mảng gốc
//   để lưu lại việc mảng bị thay đổi vùng nhớ
void themPhanTu(int*& a, int &n, int viTriThem, int giaTriThem)
{
	// Nới rộng ô nhớ của vùng nhớ cấp phát động
	// trước khi thực hiện thêm phần tử vào mảng
	capPhatLaiVungNho(a, n, n + 1);

	if (viTriThem == n)
		a[viTriThem] = giaTriThem;
	else
	{
		for (int i = n - 1; i >= viTriThem; i--)
			a[i + 1] = a[i];
		a[viTriThem] = giaTriThem;
	}
	n++;
}

// 05. Hàm xoá một phần tử tại một vị trí
// * Cần phải truyền tham chiếu cho mảng gốc
//   để lưu lại việc mảng bị thay đổi vùng nhớ
void xoaPhanTuTheoViTri(int*& a, int &n, int viTriXoa)
{
	for (int i = viTriXoa + 1; i < n; i++)
		a[i - 1] = a[i];

	n--;
	
	// Thu hẹp ô nhớ của vùng nhớ cấp phát động
	// sau khi thực hiện xoá phần tử khỏi mảng
	// (Do số lượng phần tử đã được giảm đi 1 ở trước đó
	//  nên không cần phải giảm tiếp khi gọi hàm)
	capPhatLaiVungNho(a, n, n);
}

// 06. Hàm xoá một phần tử theo một giá trí
// * Cần phải truyền tham chiếu cho mảng gốc
//   để lưu lại việc mảng bị thay đổi vùng nhớ
void xoaPhanTuTheoGiaTri(int*& a, int &n, int giaTriXoa)
{
	for (int i = 0; i < n; i++)
		if (a[i] == giaTriXoa)
		{
			xoaPhanTuTheoViTri(a, n, i);
			i--;
		}
}

// 07. Hàm tìm kiếm
//     và trả về địa chỉ đầu tiên của phần tử trong mảng
int* timKiemPhanTu(int* a, int n, int giaTriCanTim)
{
	for (int i = 0; i < n; i++)
		if (a[i] == giaTriCanTim)
			return &*(a + i);

	return NULL;
}

// 08. Hàm trả về vị trí
//     của phần tử đầu tiên xuất hiện
void viTriPhanTuDauTienXuatHien(int* a, int n, int &x)
{
	// In ra duy nhất một vị trí & địa chỉ
	int* diaChi = timKiemPhanTu(a, n, x);

	if (diaChi == NULL)
		cout << x << " khong xuat hien trong mang!\n";
	else
	{
		// Cách 1 - Sử dụng vòng lặp và tận dụng chỉ số để in ra vị trí
		//for(int i = 0; i < n; i++)
		//	if ((a + i) == diaChi)
		//	{
		//		cout << "Dia chi cua " << x << " trong mang: " << diaChi << endl;
		//		cout << "Nam tai vi tri [" << i << "] trong mang!";
		//	}
		
		// Cách 2 - Quy đổi địa chỉ về vị trí
		cout << "Dia chi cua " << x << " trong mang: " << diaChi << endl;
		int viTri = (diaChi - a); // diaChi - &a[0]
		cout << "Nam tai vi tri [" << viTri << "] trong mang!";
	}

	// In ra nhiều vị trí & địa chỉ
	//for (int i = 0; i < n; i++)
	//	if (*(a + i) == x)
	//		cout << "Nam tai vi tri [" << i << "] trong mang | " << &*(a + i) << endl;
}

// 09. Hàm in ra toàn bộ vị trí & địa chỉ để kiểm chứng
void inRaDiaChiCuaCacPhanTu(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << "a[" << i << "] - " << *(a + i) << " : " << &*(a + i) << endl;
}