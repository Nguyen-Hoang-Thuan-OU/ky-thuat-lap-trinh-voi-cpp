// Viết chương trình nhập vào 1 chuỗi tối đa 50 ký tự.
// Sau đó chuyển toàn bộ các ký tự đầu mỗi chữ đều in hoa,
// các ký tự không phải ký tự đầu sẽ chuyển sang in thường.
// Xuất lại chuỗi để kiểm chứng.

#include<iostream>
#include<string>
using namespace std;
const int MAX = 50;

int main()
{
    char a[MAX];
	int n;
    
    cout << "Nhap chuoi: ";
    cin.getline(a, MAX);
	n = strlen(a);

	for (int i = 0; i < n; i++)
	{
		a[i] = tolower(a[i]);
		a[0] = toupper(a[0]);
		for(int i = 0; i < n - 1; i++)
		{
			if (isspace(a[i]))
				a[i + 1] = toupper(a[i + 1]);
		}
	}
    cout << "Xuat lai chuoi: " << a << endl;

	return 0;
}