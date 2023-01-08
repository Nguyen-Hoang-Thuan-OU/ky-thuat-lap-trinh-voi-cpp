/*
	Bài 02. Viết chương trình đọc giá trị của file BT1.txt
		vừa ghi được ở Bài 1 và lưu vào biến m.
		Xuất lại giá trị m này lên màn hình kết quả
		khi biên dịch chương trình.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int m;
	ifstream inFile;
	inFile.open("BT1.txt");

	if(inFile.is_open())
	{
		inFile >> m;

		inFile.close();
		cout << "KQ da luu trong file: " << m << endl;
	}
	else
		cout << "Ghi file that bai! " << endl;
	system("pause");
	return 0;
}
