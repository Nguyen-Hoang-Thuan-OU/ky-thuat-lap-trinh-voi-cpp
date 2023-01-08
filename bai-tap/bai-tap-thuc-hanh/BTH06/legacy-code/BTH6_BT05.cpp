#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char kt;
	int Dem = 0;
	ifstream iFile;
	iFile.open( "BTH4.txt", ios::in );
	if ( iFile.is_open() )
	{
		while ( !iFile.eof() )
		{
			iFile.ignore();
			iFile >> kt;
			Dem++;
		}
		iFile.close();
	}
	cout << "So ki tu: " << Dem << endl;
}