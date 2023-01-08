#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char kt;
	ifstream iFile;
	ofstream oFile;
	iFile.open ( "BT4.txt", ios::in );
	oFile.open ( "BT6.txt", ios::out );
	if ( iFile.is_open() )
	{
		while( !iFile.eof() )
		{
			iFile.ignore();
			iFile >> kt;
			if ( kt == 'A' || kt == 'E' || kt == 'I' || kt == 'U' || kt == 'O' )
				if ( oFile.is_open() )
					oFile << kt;
		}
		oFile.close();
		iFile.close();
	}
	return 0;
}