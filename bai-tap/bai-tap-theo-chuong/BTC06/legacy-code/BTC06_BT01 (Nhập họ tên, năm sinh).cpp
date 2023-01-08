#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string hoten, namsinh;
	ofstream oFile;
	oFile.open("BT01.txt", ios::out);
	cout << "Nhap ho ten: ";
	getline (cin, hoten);
	cout << "Nhap nam sinh: ";
	getline (cin, namsinh);
	if (oFile.is_open())
	{
		oFile << hoten << "#" << namsinh << endl;
		cout << "Ghi thanh cong" << endl;
		oFile.close();
	}
	else
		cout <<"Ghi khong thanh cong" << endl;
	return 0;
}