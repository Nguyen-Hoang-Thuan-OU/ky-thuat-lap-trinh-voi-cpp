//Cấp phát động		//chuahoanthanh//

#include<iostream>
using namespace std;

int demKT (char *s)
{
	int dem = 0;
	while (*s)
	{
		dem++;
		s++;
	}
	 return dem;
}
void chuyenInHoa (char * s)
{
	while (*s)
	{
		if (*s ==' ')
			s++;
		else 
			break;
	}

	if ( *s && * s >='a' && *s <='z')
	{
		*s = char(int (*s) -32);
	s++;
	}

	while (*s)
	{
		if( *(s-1)==' ' && *s >='a ' && *s <='z')
			*s = char(int (*s) -32);
		else if (*(s -1 ) != ' ' && *s >='A' && *s <= 'Z')
			*s =char (int (*s)+32);
		s++;
	}
}

void noiChuoi (char * s1, char *s2)
{
	int n =demKT (s1);
		while (*s2)
		{
			s1[n++]= *s2;
			s2++;
		}
		s1[n]= '\0';
}
int main()
{
	char a[50];
	char b[50];
	char *p = a;
	char *q = b;
	cout << "Nhap vao chuoi ki tu thu nhat: ";
	cin.getline(a,50);
	cout << "nhap chuoi ki tu thu 2: ";
	cin.getline(b,50);

	cout << "\n--So sanh do dai 2 chuoi--\n";
	if (demKT(a) > demKT(b))
		cout <<"Chuoi thu nhat dai hon chuoi thu 2"<< endl;
	else 
		cout <<"Chuoi thu 2 dai hon chuoi thu nhat"<< endl;

	cout << "\n--Chuyen ky tu dau thanh in hoa--\n";
	chuyenInHoa(p);
	cout <<" Chuoi thu 1 sau khi chuyen la: ";
	cout <<p << endl;
	chuyenInHoa(q);
	cout <<" Chuoi thu 1 sau khi chuyen la: ";
	cout<< q <<endl;

	cout << "\n--Noi 2 chuoi--\n";
	noiChuoi(p,q);
	cout << p << endl;

	return 0;

}