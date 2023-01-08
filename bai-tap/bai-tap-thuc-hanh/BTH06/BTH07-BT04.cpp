/*
	Bài 04. Viết chương trình cho phép nhập 1 chuỗi ký tự
		tối đa 20 ký tự (lưu trữ dưới dạng mảng và dùng con trỏ trỏ đến).
		Ghi từng ký tự trong chuỗi trên 1 dòng
		trong file BT4.txt sau khi đã in hoa.
		Mở file BT4.txt để kiểm tra.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	char a[21];
	cout << "nhap chuoi ky tu (toi da: 20 ki tu): ";
	cin.getline(a, 21);

	char *b = a;

	while(*b)
	{
		*b = toupper(*b);
		b++;
	}
	b = a;
	ofstream outfile;
	outfile.open("bt4.txt", ios::out);
	if(outfile.is_open())
	{
		while(*b)
		{
			outfile << *b << endl;
			b++;
		}

		outfile.close();
		cout << "Ghi file thanh cong! " << endl;
	}
	else
		cout << "Mo file that bai! " << endl;

	system("pause");
	return 0;
}
