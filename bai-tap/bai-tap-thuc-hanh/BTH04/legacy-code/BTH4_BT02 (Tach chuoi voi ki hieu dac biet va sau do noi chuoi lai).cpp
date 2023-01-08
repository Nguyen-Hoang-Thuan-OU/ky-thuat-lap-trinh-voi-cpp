// Viết chương trình nhận vào 1 chuỗi ký tự bao gồm “ho, ten”.
// Sau đó tiến hành tách họ và tên của chuỗi này ra,
// kết hợp chúng lại thành “ho ten” và xuất lại kết quả.

//chuahoanthanh//

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char a[50];
	char b[50];
	cout << " Nhap chuoi: ";
	cin.get(a, 50);

	char* p = a;
	p = strtok (a, " , ");

	char* q = b;
	q = strtok (nullptr, b);

	cout << p << endl;
	cout << q << endl;
	strcat(p,q);

	cout << p << endl;
	return 0;
}