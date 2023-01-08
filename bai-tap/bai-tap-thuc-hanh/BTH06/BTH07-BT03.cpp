/*
	Bài 03. Viết chương trình ghi xuống file BT3.txt
		giá trị 3 số nguyên cách nhau bằng dấu #.
		Sau đó đọc dữ liệu từ file này
		để gán giá trị đọc được lần lượt cho 3 biến a, b, c;
		tính và xuất giá trị trung bình cộng của 3 số nguyên này.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n, m, k;
	int a, b, c;
	cout << "Nhap 3 so nguyen: ";
	cin >> n >> m >> k;

	//Ghi file
	ofstream outFile;
	outFile.open("BT3.txt", ios::out);

	if(outFile.is_open())
	{
		outFile << n << '#' << m << '#' << k;

		outFile.close();
		cout << "Ghi file thanh cong! " << endl;
	}
	else
		cout << "Ghi file that bai! " << endl;

	//Doc file
	ifstream inFile;
	inFile.open("BT3.txt");

	if(inFile.is_open())
	{
		inFile >> a;
		inFile.ignore();
		inFile >> b;
		inFile.ignore();
		inFile >> c;
		inFile.ignore();

		inFile.close();
		cout << "TBC cua 3 so tren: " << (a + b + c) / 3.0 << endl;
	}
	else
		cout << "Doc file that bai! " << endl;
	system("pause");
	return 0;
}
