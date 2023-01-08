/*
	MẢNG HAI CHIỀU - CẤP PHÁT ĐỘNG
*/

/*
Using Lv 2 Pointer: Input Int data type 2D array, then delete row and column has
the index does not correspond (No input by users, requirement is valid).
NOTE: Need to delete all memories too.
*/

#include <iostream>
using namespace std;

void Input(int **a, int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout << "a[" << i << "][" << j << "] = "; cin >> a[i][j];
			//2/ cin >> *(*(a[i] + j));
			//3/ cin >> *(*(a + i) + j);
		}
	}
}

void Output(int **a, int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout << a[i][j] << "\t";
			//2/ cout >> *(*(a[i] + j));
			//3/ cout >> *(*(a + i) + j);
		}
		cout << "\n";
	}
}

void REALLOC(int *&a, int newSize)
{
	if(newSize == 0)
	{
		a = new int[newSize];
	}
	else
	{
		//To point temp to a 
		int *temp = a;

		a = new int[newSize];

		//int size = oldSize < newSize ? oldSize : newSize;

		for(int i = 0; i < newSize; i++)
		{
			a[i] = temp[i];
		}

		delete[] temp;
	}
}

/*
// Cấp phát động - Thêm mới một dòng vào một vị trí bất kì
void themMotDong(int**& a, int &dong, in cot, int viTriThem, int* giaTriThem)
{
// Sử dụng mảng b để lưu lại mảng a
// trước khi a được cấp phát vùng nhớ mới
int** b = a;

// Tiến hành cấp phát vùng nhớ mới cho a
// với số dòng nhiều hơn trước
a = new int* [dong + 1];

// Có thể bỏ //
//int* b;
//b = new int[cot];
//for (int i = 0; i < cot; i++)
//	cin >> b[i];

// Sau khi cấp phát vùng nhớ mới cho a xong,
// tiến hành trả lại giá trị mà b đã tạm giữ
for (int i = 0; i < dong; i++)
a[i] = b[i];

// Cấp phát bộ nhớ (cột)
// tại vị trí của dòng vừa được thêm
a[dong] = new int[cot];

for (int i = dong - 1; i >= viTriThem; i--)
a[i + 1] = a[i];
a[viTriThem] = giaTriThem;
dong++;
}
*/

void AddOneRow(int **&a, int &row, int col, int *newElements, int position)
{
	int **temp = a;

	a = new int*[row+1];

	for(int i = 0; i < row; i++)
	{
		a[i] = temp[i];
	}
	//a[row] = new int[col * sizeof(int)];

	for(int i = row - 1; i >= position; i--)
	{
		a[i + 1] = a[i];
	}
	a[position] = newElements;
	row++;
	delete[] temp;
}

void AddOneCol(int **&a, int row, int &col, int *newElements, int position)
{
	// Một con trỏ cấp hai
	// có nhiệm vụ tạm thời thay mặt con trỏ a
	// để quản lý các con trỏ cấp một
	// trong lúc a đi tìm vùng nhớ mới
	int **temp = a;

	// Vì con trỏ cấp hai sẽ quản lý một mảng
	// gồm nhiều con trỏ cấp một,
	// nếu từng con trỏ cấp một đều "bỏ xứ mà đi"
	// thì con trỏ cấp hai
	// cũng phải cấp phát một vùng nhớ mới tương ứng
	a = new int*[row];

	// Duyệt từng dòng trong ma trận
	for(int i = 0; i < row; ++i)
	{
		// Từng con trỏ đứng đầu mỗi dòng
		// sẽ tự tạo riêng cho mình một vùng nhớ mới
		// với một địa chỉ mới hoàn toàn,
		// nhiều con trỏ làm vậy sẽ tạo thành một cột mới
		a[i] = new int[col + 1];

		/* CÁCH 1 - TRUYỀN THỐNG */
		// Đưa toàn bộ giá trị từ mảng một chiều
		// sang mảng mới (mảng mới dư ra một cột)
		for (int j = col - 1; j >= 0; --j)
			a[i][j] = temp[i][j];

		// Sau đó mới tiến hành dời cách phần tử về phía sau
		// và thêm phần tử vào vị trí
		for (int j = col - 1; j >= position; --j)
			a[i][j + i] = a[i][j];

		a[i][position] = newElements[i];
		/* HẾT - CÁCH 1 - TRUYỀN THỐNG */

		/* CÁCH 2 - HIỆN ĐẠI */
		// Duyệt từ cột cuối cùng đến đúng vị trí cần thêm
		for(int j = col - 1; j >= position; --j)
		{
			// Gán giá trị tại vùng nhớ cũ
			// về lại cho vùng nhớ mới,
			a[i][j + 1] = temp[i][j];
		}
		// Vừa dịch chuyển các phần tử về phía sau,
		// vừa gán luôn giá trị sang ma trận mới

		// Gán nguyên cả mảng (một chiều)
		// vào vị trí cột cần thêm
		//	-> Đưa cột cần thêm vào đúng vị trí
		a[i][position] = newElements[i];

		// Duyệt các phần tử còn lại từ vị trí thêm
		// đến đầu ma trận
		for(int j = position - 1; j >= 0; --j)
		{
			// Vì không có sự thay đổi
			// nến ta chỉ việc gán tương đương
			a[i][j] = temp[i][j];
		}
		// Giữ nguyên các giá trị ở phía trước cột cần thêm
		/* HẾT - CÁCH 2 - HIỆN ĐẠI */

		// Sau khi từng giá trị của mảng cấp một cũ
		// đã được đưa hết sang cho mảng cấp một mới,
		// thì ta tiến hành xoá đi từng vùng nhớ tạm (vùng nhớ cũ)
		delete[] temp[i];
	}

	// Tăng số lượng cột lên
	col++;

	// Giải phóng luôn con trỏ cấp hai
	// sau khi từng con trỏ cấp một được giải phóng
	delete temp;
}

void DeleteOneRow(int **a, int row, int col, int opt)
{
	int *temp = a[opt];

	for(int i = opt; i < row - 1; i++)
	{
		a[i] = a[i + 1];
	}

	a[row - 1] = temp;
}

void DeleteOneColumn(int **a, int row, int col, int opt)
{
	/* Non-optimal way */
	for(int i = 0; i < row; i++)
	{
		for(int j = opt; j < col - 1; j++)
		{
			a[i][j] = a[i][j+1];
		}
	}
}

int main()
{
	int row = 3, col = 3;

	//Declare a
	int **a;

	//Create pointers to manage the head of each row.
	a = new int*[row];

	//Each head of row will create each elemet.
	for(int i = 0; i < row; i++)
	{
		a[i] = new int[col];
	}

	cout << "--------------INPUT SECTION--------------" << endl;
	Input(a, row, col);
	cout << "=============OUTPUT==============\n";
	Output(a, row, col);

	int *b;

	b = new int[row];

	for(int i = 0; i < col; i++)
	{
		cout << "b[" << i << "] = ";
		cin >> b[i];
	}

	cout << "=============OUTPUT AFTER DELETING==============\n";
	//DeleteOneRow(a, row, col, 1);
	//REALLOC(a[row-1], 0);
	//Output(a, row-1, col);

	//DeleteOneColumn(a, row, col, 0);

	//for(int i = 0; i < row; i++)
	//{
	//	REALLOC(a[i], col - 1);
	//}
	//Output(a, row, col - 1);

	//AddOneRow(a, row, col, b, 0);
	AddOneCol(a, row, col, b, 2);
	Output(a, row, col);

	for(int i = 0; i < row - 1; i++)
	{
		delete[] a[i];
	}

	delete[] a;

	system("pause");
	return 0;
}