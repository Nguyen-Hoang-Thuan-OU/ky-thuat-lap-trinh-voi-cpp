#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int a, b, c;
	ofstream oFile;
	ifstream iFile;
	cout << "Nhap 3 so nguyen: ";
	cin >> a >> b >> c;
	oFile.open ( "BT3.txt", ios::out );
	if ( oFile.is_open() )
	{
		oFile << a << '#' << b << '#' << c;
		cout << "Ghi file thanh cong" << endl;
		oFile.close();
	}
	else
		cout << "Ghi file khong thanh cong" << endl;

	// Doc gia tri
	iFile.open ( "BT3.txt", ios::in );
	if ( iFile.is_open() )
	{
		iFile >> a >> b >> c;
		iFile.close();
	}

	// Tinh va xuat
	cout << "Gia tri trung binh cong: " << (double)(a+b+c)/3 << endl;
	return 0;
}