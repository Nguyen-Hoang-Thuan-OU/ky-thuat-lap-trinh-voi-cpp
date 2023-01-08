// So sánh xem chuỗi nào dài hơn
// Chuyển từng chuỗi thành dạng in hoa ký tự đầu tiên
// Nối chuỗi thứ 2 và chuỗi thứ 1

#include<iostream>
#include<string>
using namespace std;

int main()
{
	char a[50];
	char b[50];
	int n, m;

	cout << "Nhap chuoi thu nhat: ";
	cin.getline(a, 50, '\n');
	n = strlen(a);
	cout << "Nhap chuoi thu hai: ";
	cin.getline(b, 50, '\n');
	m = strlen(b);

	// So sánh xem chuỗi nào dài hơn

	cout << "\n--So so do dai 2 chuoi--" << endl;

	if ( strcmp (a, b) == 0)
		cout << "2 chuoi bang nhau\n";
	else
	{
		if ( strcmp (a, b) < 0)
			cout << "chuoi 1 < chuoi 2\n";
		else
			cout << "chuoi 1 > chuoi 2\n";
	}

	// Chuyển từng chuỗi thành dạng in hoa ký tự đầu tiên

	cout << "\n--In hoa ky tu dau tien--" << endl;

	for (int i = 0; i < n; i++)
	{
		a[i] = tolower(a[i]);
		a[0] = toupper(a[0]);
		for(int i = 0; i < n - 1; i++)
		{
			if (isspace(a[i]))
				a[i + 1] = toupper(a[i + 1]);
		}
	}
	cout << "Chuoi thu nhat: " << a << endl;

	for (int i = 0; i < m; i++)
	{
		b[i] = tolower(b[i]);
		b[0] = toupper(b[0]);
		for(int i = 0; i < m - 1; i++)
		{
			if (isspace(b[i]))
				b[i + 1] = toupper(b[i + 1]);
		}
	}
	cout << "Chuoi thu hai: " << b << endl;

	// Nối chuỗi thứ 2 vào chuỗi thứ 1

	strcat(a, b);
		cout << "\nSau khi noi chuoi 2 vao chuoi 1: " << a << endl;

	return 0;
}