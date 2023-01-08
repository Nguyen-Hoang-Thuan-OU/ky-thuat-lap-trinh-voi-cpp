// Viết chương trình nhập vào 1 chuỗi tối đa 50 ký tự.
// Sau đó xuất từng từ của chuỗi vừa nhập dưới dạng trên từng dòng.

#include<iostream>
#include<string>
using namespace std;
const int MAX = 50;

int main()
{
    char a[MAX];
    
    cout << "Nhap chuoi: ";
    cin.getline(a, MAX);
    
	for (int i = 0; i < strlen(a); i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}