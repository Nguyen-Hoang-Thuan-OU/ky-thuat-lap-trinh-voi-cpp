// Dùng câu lệnh while để nhập và xuất giá trị 

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int A[4][3], i, j;
	i = 0;
	cout << "Nhap mang: \n";

	while(i < 4)
	{
		j = 0;
		while(j < 3)
		{
			cout << "A[" << i << "][" << j << "] = ";
			cin >> A[i][j];
			j++;
		}
		i++;
	}

	cout << "Xuat mang: \n";
	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 3)
		{
			cout << setw(4) << A[i][j];
			j++;
		}
		i++;
	cout << endl;
	}

	return 0;
}