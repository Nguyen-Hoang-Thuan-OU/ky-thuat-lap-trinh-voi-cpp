#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string hoten, namsinh;
	ifstream iFile;
	iFile.open("BT01.txt", ios::in);

	if (iFile.is_open())
	{
		getline (iFile, hoten, '#');
		iFile >> namsinh;
		iFile.close();
	}
	else
		cout << "Ho ten: " << hoten << endl;
		cout << "Nam sinh: " << namsinh << endl;
	return 0;
}