/*
	Bài 09. Viết chương trình gán các giá trị số nguyên từ 1 đến n^2
		cho các phần tử của ma trận vuông có kích thước n x n
		(2 <= n <= 10) được nhập từ bàn phím theo dạng zigzag cột.

			Ví dụ: n = 4

				Cột nhỏ nhất		Cột lớn nhất
					|			|
					v			V

		Dòng nhỏ nhất ->	1	8	9	16
					2	7	10	15
					3	6	11	14
		Dòng lớn nhất ->	4	5	12	13
*/

#include <iostream>
using namespace std;

const int SO_CAP_TOI_DA_CUA_MA_TRAN = 10;

void nhapMaTranZigzag(int a[][SO_CAP_TOI_DA_CUA_MA_TRAN], int soCapThucTe);
void xuatMaTran(int a[][SO_CAP_TOI_DA_CUA_MA_TRAN], int soCapThucTe);

int main()
{
	// Vì là ma trận vuông
	// nên số dòng và cột là bằng nhau
	// (sử dụng chung một giá trị)
	int a[SO_CAP_TOI_DA_CUA_MA_TRAN][SO_CAP_TOI_DA_CUA_MA_TRAN];

	// Số cấp thực tế của ma trận
	int soCapThucTe;

	do {
		cout << "Vui long nhap so cap cua ma tran (2 <= n <= 10): ";
		cin >> soCapThucTe;

		if (soCapThucTe < 2 || soCapThucTe > SO_CAP_TOI_DA_CUA_MA_TRAN)
		{
			cout << "Gia tri nhap khong hop le!\n";
			cout << "Vui long nhap: 0 < So cap <= 10\n";
			cout << endl;
		}
	} while (soCapThucTe < 2 || soCapThucTe > SO_CAP_TOI_DA_CUA_MA_TRAN);

	nhapMaTranZigzag(a, soCapThucTe);
	cout << endl;

	xuatMaTran(a, soCapThucTe);
	cout << endl;

	return 0;
}

// Hàm in ma trận Zigzag (cột)
void nhapMaTranZigzag(int a[][SO_CAP_TOI_DA_CUA_MA_TRAN], int soCapThucTe)
{
	// Xác định có bao nhiêu hướng
	//	- Cột chẵn: số tăng dần từ dòng nhỏ nhất -> lớn nhất
	//	- Cột lẻ: số tăng dần từ dòng lớn nhất -> nhỏ nhất
	//		-> Tuỳ vào cột mà giá trị tương ứng sẽ được gán


	// Biến để tăng dần và gán giá trị vào ma trận
	int giaTri = 1;
	
	// Vòng lặp đầu tiên sẽ là cột - đối tượng phụ thuộc
	for (int j = 0; j < soCapThucTe; j++)
		// Cột chẵn
		if (j % 2 == 0)
			// Gán giá trị từ dòng nhỏ nhất -> lớn nhất
			for (int i = 0; i < soCapThucTe; i++)
				a[i][j] = giaTri++;
		else // Cột lẻ
			// Gán giá trị từ dòng lớn nhất -> nhỏ nhất
			for (int i = soCapThucTe - 1; i >= 0; i--)
				a[i][j] = giaTri++;
}

void xuatMaTran(int a[][SO_CAP_TOI_DA_CUA_MA_TRAN], int soCapThucTe)
{
	// In ma trận ra
	cout << "Mang dang luu tru:\n";
	
	// Duyệt từng dòng
	for (int i = 0; i < soCapThucTe; i++)
	{
		// Duyệt từng cột (của từng dòng)
		for (int j = 0; j < soCapThucTe; j++)
			// In giá trị vừa mới duyệt ra
			cout << a[i][j] << "\t";

		// Sau khi in ra hết số cột trên một dòng,
		// mới tiến hành xuống hàng để in dòng mới
		cout << endl;
	}
}