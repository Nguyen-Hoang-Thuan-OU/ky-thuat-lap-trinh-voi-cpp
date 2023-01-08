#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	double LCB = 0.00;
	ofstream oFile;
	oFile.open( "BT7.txt", ios::in );
	if ( oFile.is_open() )
	{
		cout << "Nhap luong co ban: ";
		while ( LCB != -1 )
		{
			cin >> LCB;
			oFile << LCB << endl;
		}
		oFile.close();
	}
	return 0;
}