#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char *s;
	int n;
	ofstream oFile;
	cout << "Nhap chieu dai chuoi: ";
	cin >> n;
	s = new char [n];
	cin.ignore();
	cin.getline(s,n);

	oFile.open ( "BT4.txt", ios::out );
	if ( oFile.is_open() )
	{
		for ( int i = 0; i < strlen(s); i++ )
		{
			s[i] = toupper(s[i]);
			oFile << s[i] << endl;
		}
		oFile.close();
	}
	delete[]s;
	s = NULL;
	return 0;
}