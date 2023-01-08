/*
	Bài 10. Viết chương trình khai báo 1 struct SinhVien
		gồm mã sinh viên và họ tên kiểu string,
		năm sinh kiểu int.
	
		Sau đó thực hiện các yêu cầu sau:
		- Dùng cấp phát động để khai báo mảng 1 chiều kiểu SinhVien.
		- Nhập thông tin cho tối đa 10 sinh viên.
		- Lưu trữ thông tin của từng sinh viên xuống file BT10.txt
		- Kiểm tra file BT10.txt để xem kết quả.
		- Tiến hành xuất thông tin của 1 sinh viên bất kỳ
		  đọc được từ file BT10.txt
		  (dựa trên mã sinh viên do người dùng nhập).
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct SinhVien
{
	string MaSV, Hoten;
	int Namsinh;
};

int main()
{
	SinhVien *SV;
	int n, InNamsinh;
	string Ma, InMa, InHoten;
	do
	{
		cout << "Nhap so sinh vien: ";
		cin >> n;
		if (n<1 ||n>10)
			cout << "Nhap sai, nhap lai\n";
	}while(n<1 ||n>10);
	SV = new SinhVien[n];
	ofstream oFile;
	oFile.open("D:\\BT10.txt",ios::out);
	if(oFile.is_open())
	{
		for (int i=0; i<n; i++)
		{
			cout << "\nNhap sinh vien thu " << i+1 <<":";
			cout << "\nMa so: "; cin >> SV[i].MaSV;
			cin.ignore();
			cout << "\Ho ten: "; getline(cin, SV[i].Hoten);
			cout << "\Nam sinh: "; cin >> SV[i].Namsinh;
			cin.ignore();
			oFile << SV[i].MaSV << endl;
			oFile << SV[i].Hoten << endl;
			oFile << SV[i].Namsinh << endl;
		}
		oFile.close();
	}
	cout << "Nhap Ma sinh vien : ";
	cin >> Ma;
	ifstream iFile;
	iFile.open("D:\\BT10.txt", ios::in);
	if(iFile.is_open())
	{
		while(!iFile.eof())
		{
			iFile>>InMa;
			iFile.ignore();
			getline(iFile, InHoten);
			iFile >> InNamsinh;
			iFile.ignore();
			if(InMa==Ma)
			{
				cout << "\NMa Sinh vien: " << InMa;
				cout << "\nHo ten: " << InHoten;
				cout << "\nNam sinh: " << InNamsinh;
				cout << endl;
				break;
			}
		}
		iFile.close();
	}
	else
		cout << "Mo File khong thanh cong\n";
	delete []SV;
	SV = NULL;
	system("pause");
	return 0;
}