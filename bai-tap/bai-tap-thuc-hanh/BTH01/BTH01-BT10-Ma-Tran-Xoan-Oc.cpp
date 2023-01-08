/*
	Bài 10: Viết chương trình gán các giá trị số nguyên từ 1 đến n2
		cho các phần tử của ma trận vuông có kích thước n x n
		(2 <= n <= 10) được nhập từ bàn phím theo dạng xoắn ốc.

			Ví dụ: n = 4

				Cột nhỏ nhất		Cột lớn nhất
					|			|
					v			V

		Dòng nhỏ nhất ->	1	2	3	4
					12	13	14	5
					11	16	15	6
		Dòng lớn nhất ->	10	9	8	7
*/

#include <iostream>
using namespace std;

const int SO_CAP_TOI_DA_CUA_MA_TRAN = 10;

void nhapMaTranXoanOc(int a[][SO_CAP_TOI_DA_CUA_MA_TRAN], int soCapThucTe);
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
	
	nhapMaTranXoanOc(a, soCapThucTe);
	cout << endl;

	xuatMaTran(a, soCapThucTe);
	cout << endl;

	return 0;
}


// 01. Hàm nhập ma trận kiểu xoắn ốc

/*
				Cột nhỏ nhất		Cột lớn nhất
					|			|
					v			V

		Dòng nhỏ nhất ->	1	2	3	4
					12	13	14	5
					11	16	15	6
		Dòng lớn nhất ->	10	9	8	7
*/

void nhapMaTranXoanOc(int a[][SO_CAP_TOI_DA_CUA_MA_TRAN], int soCapThucTe)
{
	int dongNhoNhat, dongLonNhat, cotNhoNhat, cotLonNhat;

	// Vi ma trận sẽ bắt đầu từ 0 nên:
	dongNhoNhat = cotNhoNhat = 0;
	dongLonNhat = cotLonNhat = soCapThucTe - 1;

	// Biến để tăng dần và gán giá trị vào ma trận
	int giaTriGan = 1;
	
	// Thực hiện việc xoán ốc nhiều lần,
	// cho đến khi nhận được giá trị cuối cùng
	//		Ví dụ: ma trận cấp 5 -> chạy giá trị đến 25 -> dừng
	while (giaTriGan <= soCapThucTe * soCapThucTe)
	{
		// Xác định có bao nhiêu hướng

		// Hướng 1:
		// dongNhoNhat cố định,
		// chạy giá trị từ cotNhoNhat -> cotLonNhat
		// Vì đây là dongNhoNhat, nên sau khi đã chạy giá trị,
		// để tránh bị gán đè thì phải tăng lên 1
		//			1	2	3	4
		for (int j = cotNhoNhat; j <= cotLonNhat; j++)
			a[dongNhoNhat][j] = giaTriGan++;
		dongNhoNhat++;

		// Hướng 2:
		// cotLonNhat cố định,
		// chạy giá trị từ dongNhoNhat -> dongLonNhat
		// Vì đây là cotLonNhat, nên sau khi đã chạy giá trị,
		// để tránh bị gán đè thì phải giảm xuống 1
		//						5
		//						6
		//						7
		for (int i = dongNhoNhat; i <= dongLonNhat; i++)
			a[i][cotLonNhat] = giaTriGan++;
		cotLonNhat--;

		// Hướng 3:
		// dongLonNhat cố định,
		// chạy giá trị từ cotLonNhat -> cotNhoNhat
		// Vì đây là dongLonNhat, nên sau khi đã chạy giá trị,
		// để tránh bị gán đè thì phải giảm xuống 1
		//			10	9	8
		for (int j = cotLonNhat; j >= cotNhoNhat; j--)
			a[dongLonNhat][j] = giaTriGan++;
		dongLonNhat--;

		// Hướng 4:
		// cotNhoNhat cố định,
		// chạy giá trị từ dongLonNhat -> dongNhoNhat
		// Vì đây là cotNhoNhat, nên sau khi đã chạy giá trị,
		// để tránh bị gán đè thì phải tăng lên 1
		//			12
		//			11
		for (int i = dongLonNhat; i >= dongNhoNhat; i--)
			a[i][cotNhoNhat] = giaTriGan++;
		cotNhoNhat++;
	}
}

// 02. Hàm xuất ma trận
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