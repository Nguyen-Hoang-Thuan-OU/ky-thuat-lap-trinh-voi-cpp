#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main()
{
	int luaChon;

	do
	{
		system("cls");
		cout << "\n\t ====== MENU =====\n";
		cout << "1. Bai 1\n";
		cout << "2. Bai 2\n";
		cout << "3. Bai 3\n";
		cout << "4. Bai 4\n";
		cout << "5. Bai 5\n";
		cout << "6. Thoat chuong trinh";
		cout << "\n\t ====== END =====\n\n";

		cout << "\t-> Lua chon cua ban la (1..6): ";
		cin >> luaChon;
		cout << endl;

		switch (luaChon)
		{
		case 1:
			cout << "Lua chon cuoi cung cua ban la 1!\n";
			break;

		case 2:
			cout << "Lua chon cuoi cung cua ban la 2!\n";
			break;

		case 3:
			cout << "Lua chon cuoi cung cua ban la 3!\n";
			break;

		case 4:
			cout << "Lua chon cuoi cung cua ban la 4!\n";
			break;

		case 5:
			cout << "Lua chon cuoi cung cua ban la 5!\n";
			break;

		case 6:
			cout << "Chao tam biet!\n";
			return 0;

		default:
			cout << "Nhap sai, vui long nhap lai!\n";
		}

		_getch(); // Thay thế cho system("pause");
	} while (true);
}