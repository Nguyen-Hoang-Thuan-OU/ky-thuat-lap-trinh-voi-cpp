/*
	Bài 05. Viết chương trình đếm tổng số ký tự
		đang có trong file BT4.txt
		và xuất kết quả đếm đó ra màn hình kết quả.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int dem = 0;
	ifstream inFile;
	inFile.open("BT4.txt");

	if(inFile.is_open())
	{
		char a;
		while(inFile >> a)
		{
			dem++;
			inFile.ignore();
		}
		cout << "Tong so ki tu trong file BT4.txt: " << dem << endl;
		inFile.close();
	}
	else
		cout << "Mo file that bai! " << endl;

	system("pause"); 
	return 0;
}
