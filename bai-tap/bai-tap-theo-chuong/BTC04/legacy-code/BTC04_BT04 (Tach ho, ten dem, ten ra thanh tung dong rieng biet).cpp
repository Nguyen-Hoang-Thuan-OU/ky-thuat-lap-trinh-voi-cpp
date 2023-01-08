// Viết chương trình nhập vào 1 chuỗi họ và tên.
// Sau đó tiến hành tách họ, chữ lót, tên ra thành 3 dòng khác nhau.

#include<iostream>
#include<string>
using namespace std;
const int MAX = 50;

void tachTen (char a[])
{
	char *p = strtok(a, " ");
	int i = 0;
	char b[5][10];
	while(p != '\0')
	{
		strcpy(b[i], p);
		i++;
		p = strtok('\0', " ");
	}
	cout << "\nHo: " << b[0];
	cout << "\nTen dem: ";
	for (int j = 1; j < i - 1; j++)
	{
		cout << b[j] << " ";
	}
	cout << "\nTen: " << b[i - 1] << endl;
}

int main()
{
	char a[MAX];
    
    cout << "Nhap chuoi: ";
    cin.getline(a, MAX);
	tachTen(a);
	return 0;
}