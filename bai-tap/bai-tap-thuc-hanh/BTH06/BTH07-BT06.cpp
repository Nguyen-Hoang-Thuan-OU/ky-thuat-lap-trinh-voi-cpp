/*
	Bài 06. Viết chương trình đọc các ký tự trong BT4.txt.
		Kiểm tra xem ký tự nào là nguyên âm,
		nếu đúng thì ghi ra file BT6.txt.
		Mở file BT6.txt để kiểm tra.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("BT4.txt");
	ofstream outfile;
	outfile.open("BT6.txt", ios::out);
	if(outfile.is_open())
	{
		char a;
		while(inFile >> a)
		{
			if(a == 'U' || a == 'O' || a == 'E' || a == 'A' || a == 'I')
				outfile << a << endl;
			inFile.ignore();
		}
		inFile.close();
		outfile.close();
		cout << "Ghi file thanh cong! " << endl;
	}
	else
		cout << "Mo file that bai! " << endl;

	system("pause");
	return 0;
}
