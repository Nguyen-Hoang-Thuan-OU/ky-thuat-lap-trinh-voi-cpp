#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int kq;
	ifstream IFile;
	IFile.open("BT1.txt", ios::in);
	if (IFile.is_open())
	{
		IFile >> kq;
		IFile.close();
	}
	cout << "Noi dung: " << kq << endl;
	return 0;
}