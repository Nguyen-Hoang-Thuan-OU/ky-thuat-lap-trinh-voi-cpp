/*
	Bài 02. Viết chương trình nhận vào 1 chuỗi ký tự bao gồm “ho, ten”.
		Sau đó tiến hành tách họ và tên của chuỗi này ra,
		kết hợp chúng lại thành “ho ten” và xuất lại kết quả.
*/

#include <iostream>
using namespace std;

char* timViTriCuaDauPhayTrongChuoi(char *s);

int main()
{
	char chuoiGoc[101];
	cout << "Nhap chuoi ho, ten: ";
	cin.getline(chuoiGoc, 101);

	char *pPhay = timViTriCuaDauPhayTrongChuoi(chuoiGoc);
	char *sGoc = chuoiGoc;

	// In ra địa chỉ của chuỗi gốc
	cout << int(sGoc) << endl;

	// In ra địa chỉ tìm thấy của dấu phẩy
	cout << int(pPhay) << endl;

	// Vị trí dấu phẩy cách con trỏ bao nhiêu kí tự,
	// lưu lại số lượng kí tự
	int n = int(pPhay) - int(sGoc);
	cout << n << endl;

	char hoSauKhiTach[101] = "";
	char tenSauKhiTach[101] = "";

	// Gán chuỗi gốc cho biến họ (ban đầu bằng rỗng)
	// với số lượng kí tự tính đến khi tìm được dấu phẩy
	strncpy(hoSauKhiTach, chuoiGoc, n);
	cout << hoSauKhiTach << endl;

	// Lướt qua dấu phẩy để tiếp tục sao chép chuỗi
	pPhay++;

	// Lấy đoạn chuỗi nằm sau dấu phẩy
	// và gán cho biến tên (ban đầu bằng rỗng)
	strcpy(tenSauKhiTach, pPhay);
	cout << tenSauKhiTach << endl;

	// In ra kết quả của việc tách chuỗi
	// để loại bỏ dấu phẩy
	char ketQuaTachChuoi[101] = "";
	strcat(ketQuaTachChuoi, hoSauKhiTach);
	strcat(ketQuaTachChuoi, tenSauKhiTach);
	cout << ketQuaTachChuoi << endl;

	return 0;
}

char * timViTriCuaDauPhayTrongChuoi(char *s) // strchr
{
	while (*s)
	{
		if (*s == ',')
			return s;
		else
			s++;
	}
	return s;
}

