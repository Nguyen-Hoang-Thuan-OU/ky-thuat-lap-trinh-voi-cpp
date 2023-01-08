/*
	Bài 07. Viết chương trình lưu hệ số lương của nhân viên
		trong 1 công ty dưới dạng số thực có 2 chữ số phần thập phân,
		nhập liên tục và mỗi số cách nhau bằng khoảng trắng hoặc enter,
		muốn kết thúc việc nhập dữ liệu thì gõ -1.
		Ghi thông tin từng hệ số lương của từng người trên 1 dòng
		trong file BT7.txt.
		Kiểm tra kết quả chương trình.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	double a;
	ofstream outFile;
	outFile.open("BT7.txt", ios::out);

	cout << "Nhap he so luong: ";
	if(outFile.is_open())
	{
		while(cin >> a && a != -1)
		{
			outFile << fixed << setprecision(2) << a << endl;
		}

		outFile.close();
		cout << "Ghi file thanh cong! " << endl;
	}
	else
		cout << "Mo file that bai! " << endl;

	system("pause");
	return 0;
}
