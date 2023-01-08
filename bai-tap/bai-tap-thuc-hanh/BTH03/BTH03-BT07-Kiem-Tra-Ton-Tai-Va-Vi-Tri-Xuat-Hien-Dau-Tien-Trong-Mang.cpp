/*
	Bài 07. Dùng con trỏ viết hàm tìm kiếm 1 số nguyên
		có tồn tại trong mảng 1 chiều lưu trữ số nguyên hay không?
		Nếu có thì trả về vị trí đầu tiên xuất hiện số nguyên đó.
		Nếu không thì trả con trỏ về NULL.
		Sau đó viết chương trình kiểm chứng lại hàm vừa xây dựng.
*/

#include <iostream>
#include <ctime>
using namespace std;

void nhapMang(int* a, int n);
void xuatMang(int* a, int n);
int* diaChiPhanTuDauTienXuatHien(int* a, int n, int x);
void viTriPhanTuDauTienXuatHien(int* a, int n, int &x);
void inRaDiaChiCuaCacPhanTu(int* a, int n);

int main()
{
	srand(time(0));
	int* a;
	int n;
	int x;

	cout << "Nhap so luong cua mang (n > 0): ";
	cin >> n;
	do{
		if (n < 0)
		{
			cout << "Nhap sai, vui long nhap so luong cua mang (n > 0): ";
			cin >> n;
		}
	}while(n < 0);

	a = new int[n];

	cout << "Mang da duoc tao tu dong!";
	nhapMang(a, n);
	cout << endl;

	cout << "Mang vua tao: ";
	xuatMang(a, n);
	cout << endl;

	cout << "Nhap gia tri can tim: ";
	cin >> x;
	cout << endl;

	viTriPhanTuDauTienXuatHien(a, n, x);
	cout << endl;

	cout << "Dia chi cua toan bo phan tu trong mang:\n";
	inRaDiaChiCuaCacPhanTu(a, n);
	cout << endl;

	delete[] a;
	a = NULL;

	return 0;
}

// 01. Hàm nhập mảng
void nhapMang(int* a, int n)
{
	for (int i = 0; i < n; i++)
		*(a + i) = rand() % 10;
}

// 02. Hàm xuất mảng
void xuatMang(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(a + i) << " ";
}

// 03. Hàm trả về địa chỉ
//     của phần tử đầu tiên xuất hiện
int* diaChiPhanTuDauTienXuatHien(int* a, int n, int x)
{
	for (int i = 0; i < n; i++)
		if (*(a + i) == x)
			return &*(a + i);

	return NULL;
}

// 04. Hàm trả về vị trí
//     của phần tử đầu tiên xuất hiện
void viTriPhanTuDauTienXuatHien(int* a, int n, int &x)
{
	// In ra duy nhất một vị trí & địa chỉ
	int* diaChi = diaChiPhanTuDauTienXuatHien(a, n, x);

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

// 05. Hàm in ra toàn bộ vị trí & địa chỉ để kiểm chứng
void inRaDiaChiCuaCacPhanTu(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << "a[" << i << "] - " << *(a + i) << " : " << &*(a + i) << endl;
}