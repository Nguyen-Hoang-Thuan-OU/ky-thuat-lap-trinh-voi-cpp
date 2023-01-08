#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int a, b;
	ofstream oFile;
	oFile.open ("BT1.txt", ios::out);
	cout << "Nhap 2 so nguyen a, b: ";
	cin >> a >> b;

	// Tinh tong 2 so a, b

	if (oFile.is_open())
	{
		oFile << a + b;
		oFile.close();
	}
	return 0;
}