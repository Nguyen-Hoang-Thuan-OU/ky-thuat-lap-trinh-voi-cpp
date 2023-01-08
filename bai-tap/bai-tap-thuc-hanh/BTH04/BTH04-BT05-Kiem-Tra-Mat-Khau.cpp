/*
	Bài 5. Viết chương trình cho phép người dùng nhập password (10 ký tự)
		và hiển thị dưới dạng ký tự “X”.
		Sau đó kiểm tra xem đúng password là “SinhVienCQ”hay không?
		Nếu đúng thông báo đã đăng nhập thành công,
		nếu sai yêu cầu nhập lại. Tối đa cho phép nhập 3 lần.
			
		* Lưu ý: dùng mảng ký tự lưu trữ chuỗi vừa nhập.
			
			Ví dụ:
				Nhap mat khau: X X X X X X X X X X
				Nhap sai! Nhap lai!
				Nhap mat khau: X X X X X X X X X X
				Dang nhap thanh cong!
*/

// Bị lỗi - Sau khi nhập sai, nhập lại vẫn thấy mật khẩu

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	char password[11];
	int i = 0;
	int demSoLanNhapSaiMatKhau = 0;

	cout << "Nhap mat khau (Toi da 10 ky tu - Duoc phep sai toi da 3 lan): ";
	do {
		while ((password[i] = _getch()) != 13 && ++i < 11)
			cout << "X";
		password[i] = '\0';

		if (!strcmp(password, "SinhVienCQ"))
		{
			cout << "\nDang nhap thanh cong!\n";
			return 0;
		}
			
		else
		{
			cout << "\nMat khau sai [" << demSoLanNhapSaiMatKhau + 1
				<< "]. Nhap lai lan [" << demSoLanNhapSaiMatKhau + 2
				<< "]: ";
			cin >> password;
			demSoLanNhapSaiMatKhau++;

			if (demSoLanNhapSaiMatKhau == 2)
			{
				cout << "Ban da nhap mat khau sai ba lan!\n";
				return 0;
			}
		}
			
	} while (true);
}
