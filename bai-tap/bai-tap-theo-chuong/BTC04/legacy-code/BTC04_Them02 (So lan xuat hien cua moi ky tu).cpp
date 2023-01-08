// Số lần xuất hiện của mỗi ký tự //chuahoanthanh//

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s, st;
	int dem, n;
	cout << "Nhap chuoi: ";
	getline(cin, s);
	st = s;
	n = s.length();
	for (int i = 0; i < n - 1; i++)
	{
		dem = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (st.at(j) == st.at(i))
			{
				dem++;
				for (int k = j; k < n; k++)
				{
					st.at(k) = st.at(k + 1);
					n--;
					j--;
				}
				cout << "So ky tu: " << st.at(i) << " = " << dem;
			}
		}
		return 0;
	}

	return 0;
}