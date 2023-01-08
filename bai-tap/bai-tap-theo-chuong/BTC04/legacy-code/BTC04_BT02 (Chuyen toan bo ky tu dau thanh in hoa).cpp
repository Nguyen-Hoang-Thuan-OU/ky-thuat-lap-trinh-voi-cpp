// Viết chương trình nhập vào 1 chuỗi tối đa 50 ký tự.
// Sau đó chuyển toàn bộ các ký tự đầu mỗi chữ đều in hoa,
// các ký tự không phải ký tự đầu sẽ chuyển sang in thường.
// Xuất lại chuỗi để kiểm chứng.

#include<iostream>
#include<string>
using namespace std;
const int MAX = 50;

void vietHoa(char *a)
{
	a[0] = toupper(a[0]);
	while (strstr(a, " ") != NULL)
	{
		a = strstr(a, " ") + 1;
		a[0] = toupper(a[0]);
	}
}

int main()
{
    char a[MAX];
    
    cout << "Nhap chuoi: ";
    cin.getline(a, MAX);
    
	vietHoa(a);

    cout << a << endl;

	return 0;
}