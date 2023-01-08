/*
	03. Viết chương trình dùng cấp phát động 
		xây dựng hàm nhập và xuất 1 mảng số nguyên tối đa 15 phần tử.
		Sau đó xây dựng hàm kiểm tra xem mảng vừa nhập
		có phải là mảng đối xứng hay không?
		Viết chương trình kiểm tra các hàm trên.
*/

#include<iostream>
using namespace std;

void nhapMang(int*& a, int n);
void xuatMang(int* a, int n);
bool kiemTraMangCoDoiXung(int* a, int n);

int main()
{
	int* a;
	int n;

	cout << "Nhap so luong phan tu (1..15): ";
	cin >> n;
	do {
		if (n <= 1 || n >= 16)
		{
			cout << "Nhap sai, vui long nhap so luong phan tu (1..15): ";
			cin >> n;
		}
	} while(n <= 1 || n >= 16);
	cout << endl;

	a = new int [n];

	cout << "Nhap mot loat [" << n << "] phan tu cho mang: ";
	nhapMang(a, n);

	cout << "\nXuat mang: ";
	xuatMang(a, n);
	cout << endl;

	if (kiemTraMangCoDoiXung(a, n) == true)
		cout << "Mang doi xung" << endl;
	else
		cout << "Mang khong doi xung" << endl;
	cout << endl;

	delete[]a;
	a = NULL;

	return 0;
}

void nhapMang(int*& a, int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void xuatMang(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

bool kiemTraMangCoDoiXung(int* a, int n)
{
	bool kq = true;
	int* p;
	int* q;

	p = &a[0];
	q = &a[n - 1];

	while(p < q)
	{
		if (*p != *q)
			kq = false;

		p++;
		q--;
	}

	return kq;
}