/*
	Nhập địa chỉ email theo định dạng: tên-người-dùng@tên-miền-tổ-chức
	Sau đó xuất phần tên người dùng và tên miền của tổ chức
	thành hai dòng.

		Ví dụ:
			thuan.nh7@ou.edu.vn
			-> thuan.nh7
			-> ou.edu.vn
*/

#include <iostream>
using namespace std;

void ngatChuoiEmail(char* email);

int main()
{
	// Khai báo tĩnh
	char s1[100];
	char s2[100] = "thuan.nh7@ou.edu.vn";

	cout << "Nhap dia chi email - 1: ";
	cin.getline(s1, 100);
	cout << endl;

	ngatChuoiEmail(s1);
	cout << endl;

	ngatChuoiEmail(s2);
	cout << endl;

	return 0;
}

// Hàm nhận vào một con trỏ / mảng
void ngatChuoiEmail(char* email)
{
	// Chuỗi email ban đầu sẽ được tách làm hai,
	// phần tử ban đầu sẽ là phần tên người dùng
	// và phần tử thứ hai sẽ là phần tên miền của tổ chức
	char *p = strtok(email, "@");

	// Hàm sẽ trả về danh sách các phần tử
	// và ta chỉ việc duyệt để in từng phần tử ra

	// Nếu hàm strtok() tìm thấy kí hiệu chỉ định
	// sẽ trả về một giá trị khác NULL
	// và con trỏ sẽ trỏ đến phần tử đầu tiên của chuỗi,
	// phần nằm sau kí hiệu ngắt chuỗi sẽ là phần tử thứ hai

	// Nếu giá trị trả về khác NULL - Tìm thấy
	while (p != NULL)
	{
		// In ra phần tử đầu tiên - Trước kí hiệu ngắt
		cout << p << endl;

		// Dịch chuyển con trỏ sang phần tử thứ hai - Sau kí hiệu ngắt
		p = strtok(NULL, "@");

		// Nhờ có vòng lặp while()
		// mà phần tử thứ hai được in ra
	}
}

/*
	In từng từ ra từng dòng
	và in hoa kí tự đầu tiên của mỗi từ,
	sau đó lại nối thành một chuỗi dài.

		Ví dụ:
			nguyen hoang thuan
			-> Nguyen
			-> Hoang
			-> Thuan
			--> Nguyen Hoang Thuan
*/

#include <iostream>
using namespace std;

void ngatChuoiTen(char* ten);

int main()
{
	// Khai báo tĩnh
	//char ten[100] = "nguyen hoang thuan";
	
	//ngatChuoiTen(ten);

	char ten[100];
	cout << "Ten: ";
	cin.getline(ten, 100);

	ngatChuoiTen(ten);
	cout << endl;

	return 0;
}

// Hàm nhận vào một con trỏ / mảng
// và trả về kết quả là một chuỗi
// được ngắt thành từng dòng và in hoa đầu từ
// sau đó lại được gán thành một chuỗi dài
void ngatChuoiTen(char* ten)
{
	// Biến để ngắt chuỗi
	char* ngatTen = strtok(ten, " ");
	
	// Biến để nối lại chuỗi sau khi ngắt
	char ketQua[100];

	while (ngatTen != NULL)
	{
		// Nếu kí tự đầu tiên là kí tự thường
		// thì mới chuyển thành kí tự in hoa
		if (ngatTen[0] >= 97 && ngatTen[0] <= 122)
			ngatTen[0] = ngatTen[0] - 32;

		cout << ngatTen << endl;

		// Nối lại tên đã bị ngắt vào biến kết quả
		// kèm với kí tự khoảng trắng
		strcat(ketQua, ngatTen);
		strcat(ketQua, " ");
		
		ngatTen = strtok(NULL, " ");
	}

	// Trả về chuỗi đã được in hoa từng đầu từ
	// và sau đó nối lại với nhau
	cout << "Sau khi da in va noi: " << ketQua << endl;
}