/*
	Bài 01. Viết chương trình nhập vào 2 số nguyên a và b.
		Tính tổng 2 số này. Sau đó ghi kết quả tổng xuống file BT1.txt.
		Mở file BT1.txt để kiểm tra kết quả ghi.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int a, b;
	cout << "Nhap 2 so nguyen a, b: ";
	cin >> a >> b;
	ofstream outFile;
	outFile.open("BT1.txt", ios::out);

	if(outFile.is_open())
	{
		outFile << a + b;

		outFile.close();
		cout << "Ghi file thanh cong! " << endl;
	}
	else
		cout << "Ghi file that bai! " << endl;
	system("pause");
	return 0;
}