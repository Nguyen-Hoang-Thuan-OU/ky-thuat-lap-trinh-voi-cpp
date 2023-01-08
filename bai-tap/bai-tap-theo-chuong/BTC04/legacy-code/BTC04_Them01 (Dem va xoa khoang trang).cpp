// Đếm số khoảng trắng của 1 chuỗi
// Loại bỏ hết khoảng trắng của 1 chuỗi
//chuahoanthanh//

#include<iostream>
#include<string>
using namespace std;

int demKhoangTrang ( char *a )
{
	int dem = 0;
	for(int i = 0; i < strlen(a); i++)
    {
		if(a[i]== ' ')
		{
			dem++;
		}
	}
	return dem;
}

void xoaKhoangTrang ( char *a )
{
	char *b = strstr (a, " ");
	while ( b!= NULL )
	{
		int t = strlen(a) - strlen(b);
		for ( int i = 0; i < strlen(a); i++ )
		{
			a[i] = a[i + 1];
		}
		b = strstr(a, " ");
	}
	if ( a[0], " " )
		a = a + 1;
	int n = strlen (a);
	if ( a[n - 1], " " )
		a[n - 1] = '\0';
	cout << a << endl;
}

int main()
{
	char a[50];
    int n;

    cout << "Nhap chuoi: ";
    cin.getline(a, 50);
	n = strlen(a);
	cout << "So khoang trang trong chuoi la: " << demKhoangTrang(a) << endl;
	cout << "Chuoi sau khi da xoa khoang trang: ";
	xoaKhoangTrang(a);
	cout << endl;

	return 0;
}