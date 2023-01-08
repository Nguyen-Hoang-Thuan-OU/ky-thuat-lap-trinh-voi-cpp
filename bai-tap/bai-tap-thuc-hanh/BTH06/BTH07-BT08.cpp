/*
	Bài 08. Viết chương trình gồm các hàm:
		- Ghi 3 số nguyên ra file.
		- Đọc 3 số nguyên từ file.
		- Hàm main kiểm chứng.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ghi(string path, int a, int b, int c)
{
	ofstream outF;
	outF.open(path);
	if (outF.is_open())
	{
		outF << a << '#' << b << '#' << c << endl;
		outF.close();
		cout << "Ghi file thanh cong! " << endl;
	}
	else
		cout << "Mo file that bai! " << endl;
}

void doc(string path, int &a, int &b, int &c)
{
	ifstream inF;
	inF.open(path);
	if (inF.is_open())
	{
		inF >> a;
		inF.ignore();
		inF >> b;
		inF.ignore();
		inF >> c;
		inF.close();
		cout << "Doc file thanh cong! " << endl;
	}
	else
		cout << "Mo file that bai! " << endl;
}

int main()
{
	int a, b, c, d, e, f;
	string path;
	cout << "Nhap 3 so nguyen: ";
	cin >> a >> b >> c;

	cin.ignore();
	cout << "Nhap duong dan file: ";
	getline(cin, path);
	ghi(path, a, b, c);

	doc(path, d, e, f);
	cout << "3 so nguyen: " << d << e << f << endl;

	system("pause");
	return 0;
}
