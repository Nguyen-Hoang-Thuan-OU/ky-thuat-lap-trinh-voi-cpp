//chuahoanthanh//

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	// Nhap vao 1 mang 1 chieu luu tru so nguyen toi da 30 phan tu
	int *a;
	int n, d;
	a = new int [n];
	int Max = a[n];
	
	cout << "Nhap n: ";
	cin >> n;
	// Dung con tro va ky phap do doi de xuat ra cac phan tu nao la so le trong mang
	for ( int i = 0; i < n; i++ )
	{
		a[i] = rand()%10;
		cout << a[i] << " ";
	}
	for ( int i = 0; i < n; i++ )
		if ( a[i] % 2 != 0 )
			cout << a[i] << " ";

	// Tra ve dia chi cua gia tri lon nhat trong mang
	for ( int i = 0; i < n; i++ )
		if ( a[i] > Max )
		{
			Max = a[i];
			d = i;
			cout << "Dia chi cua gia tri lon nhat " << Max << "trong mang la: " << & a + d;
		}
		
		cout << endl;
		delete[]a;
		a = NULL;

	return 0;
}