// Viết hàm đảo ngược 1 mảng 1 chiều lưu trữ số nguyên

#include <iostream>
using namespace std;

void hoanVi2So(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void daoNguocMang(int *&a, int n)
{
    int tBinh = n / 2;
    int j = n - 1;
    for (int i = 0; i < tBinh; i++)
	{
        hoanVi2So(a[i], a[j]);
        j--;
    }
}

int main()
{
    int *a;
    int n;

    cout << "Nhap vao so luong phan tu: ";
    cin >> n;

    // Cấp phát bộ nhớ

    a = new int[n];

    // Nhập mảng

    for (int i = 0; i < n; i++)
	{
        cout << "Nhap vao phan tu thu a[" << i << "] = ";
        cin >> a[i];
    }

	// Xuất mảng kết quả ra màn hình.

	cout << "Mang truoc khi dao nguoc: ";
    for (int i = 0; i < n; i++)
	{
        cout << a[i] << "\t";
    }
	cout << endl;

    // Gọi hàm đảo ngược mảng

    daoNguocMang(a, n);

    // Xuất lại mảng kết quả ra màn hình.

	cout << "Mang sau khi dao nguoc: ";
    for (int i = 0; i < n; i++)
	{
        cout << a[i] << "\t";
    }
	cout << endl;

    delete[]a;
	a = NULL;

	return 0;
}