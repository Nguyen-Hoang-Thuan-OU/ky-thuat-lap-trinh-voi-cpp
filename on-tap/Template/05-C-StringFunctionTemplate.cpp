/*
	TỰ THIẾT KẾ LẠI CÁC HÀM ĐỂ THAO TÁC VỚI CHUỖI
	TƯƠNG TỰ NHƯ NHỮNG HÀM TRONG THƯ VIỆN STRING
*/

#include <iostream>
using namespace std;

int chiDemKiTuChuVaSo(char* p);
int demTu(char* p);

int demDoDaiCuaChuoi(char s[]);
void saoChepGiaTriCuaChuoi(char chuoiSaoChep[], char chuoiGoc[]);
void xoaTheoViTri(char s[], int viTriCanXoa);
void xoaTheoGiaTri(char s[], int giaTriCanXoa);
void themTheoViTri(char s[], int viTriCanThem, char giaTriCanThem);
int soSanhDoDaiCoPhanBietHoaVaThuong(char s1[], char s2[]);
int soSanhDoDaiKhongPhanBietHoaVaThuong(char s1[], char s2[]);

int main()
{
	/* ĐẾM ĐỘ DÀI (KÍ TỰ) CỦA CHUỖI */
	//char s[50];
	//cout << "Nhap chuoi: ";
	//cin.getline(s, 50);
	//cout << demDoDaiCuaChuoi(s) << endl;

	/* ĐẾM SỐ TỪ - SỬ DỤNG CON TRỎ */
	//char s[100];
	//cout << "Nhap chuoi: ";
	//cin.getline(s, 100);

	//// Sử dụng con trỏ để đếm số từ
	//char* p = s;

	//cout << "Chuoi vua nhap co [" << demTu(p) << "] tu!" << endl;

	/* SAO CHÉP CHUỖI */
	//char s1[50];
	//char s2[50];

	//cout << "Nhap chuoi goc: ";
	//cin.getline(s1, 50);

	//cout << "Chuoi s1 truoc khi sao chep: ";
	//cout << s1 << endl;

	//cout << "Chuoi s2 sau khi sao chep: ";
	//saoChepGiaTriCuaChuoi(s2, s1);
	//cout << s2 << endl;
	//cout << endl;

	/* XOÁ KÍ TỰ THEO VỊ TRÍ */
	//char s[] = "Ky thuat lap trinh";
	//int viTriXoa;

	//cout << "Chuoi truoc khi xoa: " << s << endl;

	//cout << "Nhap vi tri can xoa: ";
	//cin >> viTriXoa;

	//xoaTheoViTri(s, viTriXoa);
	//cout << endl;

	//cout << "Chuoi sau khi xoa: " << s << endl;

	/* XOÁ KÍ TỰ THEO GIÁ TRỊ  - BỊ LỖI*/
	//char s[50] = "Ky thuat lap trinh";
	//int giaTriXoa;

	//cout << "Chuoi truoc khi xoa: " << s << endl;

	//cout << "Nhap ki tu can xoa: ";
	//cin >> giaTriXoa;

	//xoaTheoGiaTri(s, giaTriXoa);
	//cout << endl;

	//cout << "Chuoi sau khi xoa: " << s << endl;

	/* THÊM KÍ TỰ THEO VỊ TRÍ */
	//char s[50] = "ky thuat lap trinh";
	//int vitrithem;
	//char giatrithem;

	//cout << "chuoi truoc khi them: " << s << endl;
	//
	//cout << "nhap vi tri can them: ";
	//cin >> vitrithem;
	//cin.ignore();

	//cout << "nhap ki tu can them: ";
	//cin >> giatrithem;

	//themtheovitri(s, vitrithem, giatrithem);
	//cout << endl;

	//cout << "chuoi sau khi them: " << s << endl;

	/* SO SÁNH HAI CHUỖI - CÓ PHÂN BIỆT HOA VÀ THƯỜNG */
	char s1[50] = "ahihi uhehe";
	char s2[50] = "AHIHI UHEHE";

	// Quy ước: khi so sánh s1 với s2, lấy s1 làm mốc
	//	s1 < s2 => -1
	//	s1 = s2 => 0
	//	s1 > s2 => 1

	if (soSanhDoDaiKhongPhanBietHoaVaThuong(s1, s2) > 0)
		cout << "S1 > S2\n";
	else if (soSanhDoDaiKhongPhanBietHoaVaThuong(s1, s2) < 0)
		cout << "S1 < S2\n";
	else
		cout << "S1 = S2\n";

	return 0;
}

// Giả lập lại hàm strlen();
int demDoDaiCuaChuoi(char s[])
{
	/* CÁCH 1 - Sử dụng thêm một biến khác để đếm */
	//// Biến chứa độ dài cuối cùng của chuỗi
	//// (số lượng kí tự đang có trong chuỗi)
	//int doDaiCuaChuoi = 0;

	//// Duyệt từ đầu đến cuối chuỗi
	//// để đếm từng kí tự có trong chuỗi
	//// (Lặp một cách vô tận
	////  bằng cách cho điều kiện dừng luôn luôn đúng,
	////  vì sẽ không thể biết trước được
	////  độ dài của chuỗi sẽ được nhập vào)
	//for (int i = 0; true; i++)
	//{
	//	// Lập tức dừng vòng lặp
	//	// khi bắt gặp kí tự '\0' (NULL) xuất hiện trong chuỗi
	//	if (s[i] == '\0')
	//		break;

	//	// Nếu điều kiện không thoả (vẫn chưa gặp kí tự '\0')
	//	// thì sẽ tăng độ dài của chuỗi lên một
	//	doDaiCuaChuoi++;
	//}

	//return doDaiCuaChuoi;

	/* CÁCH 2 - Tận dụng biến chỉ số */
	//int i = 0;
	//while (true)
	//{
	//	if (s[i] == '\0')
	//		return i;
	//	i++;
	//}

	/* CÁCH 3 - Tận dụng biến chỉ số */
	int i = 0;
	while (s[i] != '\0')
		i++;

	return i;
}

/* Đếm số từ - Bắt đầu */
int chiDemKiTuChuVaSo(char* p)
{
	int demKiTu = 0;

	while (*p != '\0')
	{
		// Nếu đúng là một kí tự chữ cái hoặc chữ số
		// mà không phải là một kí tự khoảng trắng
		if (isalnum(*p) != 0)
			demKiTu++;

		p++;
	}

	return demKiTu;
}

int demTu(char* p)
{
	// Mỗi từ thường sẽ bắt đầu với:
	//	- Kí tự khoảng trắng
	//	- Kí tự thông thường (chữ hoặc số)
	//	(Từ đầu chuỗi là một trường hợp đặc biệt)
	int soTu = 0;

	if (chiDemKiTuChuVaSo(p) == 0)
		// Nếu không hề có bất kì kí tự (chữ hoặc số) nào
		return 0;
	else
	{
		// Loại bỏ hết toàn bộ kí tự khoảng trắng
		// ở đầu chuỗi (nếu có)
		while (*p != 0)
		{
			if (isspace(*p) != 0)
				p++;
			else
				break;
		}

		// Con trỏ hiện đang dừng tại kí tự đầu tiên
		soTu++;
		p++;

		// Bắt đầu tại từ tiếp theo
		while (*p)
		{
			// Nếu trước đó là một khoảng trắng
			// và ngay sau đó là một kí tự
			if (isspace(*(p - 1)) != 0 && isalnum(*p) != 0)
				soTu++;

			p++;
		}

		return soTu;
	}
}
/* Đếm số từ - Kết thúc */

// Giả lập lại hàm strcpy();
void saoChepGiaTriCuaChuoi(char chuoiSaoChep[], char chuoiGoc[])
{
	// (Chuỗi nhận vào phải có kích thước (số lượng kí tự)
	//  tương đương với chuỗi gốc)

	// Xác định độ dài của chuỗi gốc
	int doDaiChuoiGoc = demDoDaiCuaChuoi(chuoiGoc);

	// Duyệt từ đầu đến cuối chuỗi gốc
	// (bao gồm luôn cả kí tự '\0')
	for (int i = 0; i <= doDaiChuoiGoc; i++)

		// Lấy từng kí tự của chuỗi gốc
		// để đưa sang chuỗi sao chép
		chuoiSaoChep[i] = chuoiGoc[i];
}

// Xoá kí tự tại một vị trí bất kì
// (Không cần truyền vào tham số độ dài / số lượng phần tử
//  vì lúc này ta có thể sử dụng hàm đếm độ dài)
void xoaTheoViTri(char s[], int viTriCanXoa)
{
	int soLuongPhanTu = demDoDaiCuaChuoi(s);

	// Duyệt từ sau vị trí cần xoá đến cuối chuỗi
	// (bao gồm luôn cả kí tự '\0')
	for (int i = viTriCanXoa + 1; i <= soLuongPhanTu; i++)
		s[i - 1] = s[i];
}

// Xoá kí tự theo giá trị - chưa hoàn thành
void xoaTheoGiaTri(char s[], int giaTriCanXoa)
{
	int soLuongPhanTu = demDoDaiCuaChuoi(s);

	for (int i = 0; i <= soLuongPhanTu; i++)
		if (s[i] == giaTriCanXoa)
		{
			xoaTheoViTri(s, i);
			i --;
		}
}

// Thêm kí tự theo vị trí
void themTheoViTri(char s[], int viTriCanThem, char giaTriCanThem)
{
	int soLuongPhanTu = demDoDaiCuaChuoi(s);

	for (int i = soLuongPhanTu; i >= viTriCanThem; i--)
		s[i + 1] = s[i];

	s[viTriCanThem] = giaTriCanThem;
}

// So sánh độ lớn của hai chuỗi - Có phân biệt kí tự hoa và thường
int soSanhDoDaiCoPhanBietHoaVaThuong(char s1[], char s2[])
{
	// Quy ước: khi so sánh s1 với s2, lấy s1 làm mốc
	//	s1 < s2 => -1
	//	s1 = s2 => 0
	//	s1 > s2 => 1

	// Chiều dài của các chuỗi sẽ khác nhau,
	// nếu so sánh từng vị trí thì có thể dẫn đến việc
	// truy xuất vào vùng nhớ không hợp lệ

	// Vì vậy, ta sẽ duyệt từ đầu đến cuối chuỗi
	// dựa theo chuỗi có độ dài nhỏ nhất,
	// để nếu duyệt đến cuối của chuỗi có độ dài ngắn hơn
	// mà vẫn không phát hiện được sự khác biệt,
	// lúc này, chuỗi dài hơn sẽ lớn hơn

	// Kiểm tra độ dài của hai chuỗi trước khi duyệt
	int doDaiNhoNhat = 0;

	if (demDoDaiCuaChuoi(s1) < demDoDaiCuaChuoi(s2))
		doDaiNhoNhat = demDoDaiCuaChuoi(s1);
	else
		doDaiNhoNhat = demDoDaiCuaChuoi(s2);

	// Duyệt từng kí tự và tiến hành so sánh
	for (int i = 0; i < doDaiNhoNhat; i++)

		// Vì có phân biệt hoa thường nên không cần xử lý
		if (s1[i] > s2[i])
			return 1; // s1 > s2 => 1
		else if (s1[i] < s2[i])
			return -1; // s1 < s2 => -1

	// Nếu duyệt hết mảng kí tự nhưng không phát hiện điều khác lạ
	// thì kí tự có độ dài dài hơn sẽ lớn hơn
	if (demDoDaiCuaChuoi(s1) > demDoDaiCuaChuoi(s2))
		return 1;
	else if (demDoDaiCuaChuoi(s1) < demDoDaiCuaChuoi(s2))
		return -1;
	else
		return 0;
}

// So sánh độ lớn của hai chuỗi - Không phân biệt kí tự hoa và thường
int soSanhDoDaiKhongPhanBietHoaVaThuong(char s1[], char s2[])
{

	int doDaiNhoNhat = 0;

	if (demDoDaiCuaChuoi(s1) < demDoDaiCuaChuoi(s2))
		doDaiNhoNhat = demDoDaiCuaChuoi(s1);
	else
		doDaiNhoNhat = demDoDaiCuaChuoi(s2);

	// Chuyển toàn bộ chuỗi s1 về in hoa
	for (int i = 0; i < strlen(s1); i++)
		if (s1[i] >= 'a' && s1[i] <= 'z')
			s1[i] = s1[i] - 32;

	// Chuyển toàn bộ chuỗi s2 về in hoa
	for (int i = 0; i < strlen(s2); i++)
		if (s2[i] >= 'a' && s2[i] <= 'z')
			s2[i] = s2[i] - 32;

	// Duyệt từng kí tự và tiến hành so sánh
	for (int i = 0; i < doDaiNhoNhat; i++)

		// Vì có phân biệt hoa thường nên không cần xử lý
		if (s1[i] > s2[i])
			return 1; // s1 > s2 => 1
		else if (s1[i] < s2[i])
			return -1; // s1 < s2 => -1

	// Nếu duyệt hết mảng kí tự nhưng không phát hiện điều khác lạ
	// thì kí tự có độ dài dài hơn sẽ lớn hơn
	if (demDoDaiCuaChuoi(s1) > demDoDaiCuaChuoi(s2))
		return 1;
	else if (demDoDaiCuaChuoi(s1) < demDoDaiCuaChuoi(s2))
		return -1;
	else
		return 0;
}

/*
	CHUẨN HOÁ CHUỖI
	
		Ví dụ:
			"      NGUYEN      HOANG      THUAN      cs81          "
			-> Nguyen Hoang Thuan Cs81
*/

#include <iostream>
using namespace std;

void xoaTheoViTri(char s[], int viTriXoa);
void xoaToanBoKiTuLaTrongChuoi(char s[]);
void xoaKhoangTrangDauChuoi(char s[]);
void xoaKhoangTrangCuoiChuoi(char s[]);
void xoaKhoangTrangGiuaCacTu(char s[]);
void vietHoaDauMoiTu(char s[]);
void chuanHoaChuoi(char s[]);

int main()
{
	// Chuỗi để kiểm tra: "   n,g.u'y"e{n}  -   h!o@a#n%G &^$( T*H(U)A,N=  _    c/s\8|1      "
	// Chuỗi sau khi chuẩn hoá: "Nguyen Hoang Thuan Cs81"
	char s[100];

	cout << "Nhap chuoi: ";
	cin.getline(s, 100);
	cout << endl;

	cout << "Do dai chuoi truoc khi xoa: " << strlen(s) << endl;

	chuanHoaChuoi(s);
	cout << "Chuoi sau khi chuan hoa: " << s << endl;
	cout << endl;

	cout << "Do dai chuoi sau khi xoa: " << strlen(s) << endl;

	return 0;
}

// Xoá kí tự theo vị trí
void xoaTheoViTri(char s[], int viTriXoa)
{
	int doDaiChuoi = strlen(s);
	for (int i = viTriXoa + 1; i <= doDaiChuoi; i++)
		s[i - 1] = s[i];
}

// Hàm xoá toàn bộ kí tự lạ xuất hiện trong chuỗi
// (Không bao gồm chữ cái, chữ số và khoảng trắng)
void xoaToanBoKiTuLaTrongChuoi(char s[])
{
	for (int i = 0; i < strlen(s); i++)
		if (!(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z'
			|| tolower(s[i]) >= '0' && tolower(s[i]) <= '9'
			|| tolower(s[i]) == ' '))
		{
			xoaTheoViTri(s, i);
			i--;
		}
}

// Xoá khoảng trắng:
//	- Đầu chuỗi: kí tự đầu -> khác ' '
//	- Cuối chuỗi: kí tự cuối -> khác ' '
void xoaKhoangTrangDauChuoi(char s[])
{
	// Nếu gặp khoảng trắng ở đầu chuỗi thì xoá,
	// xoá đến khi nào gặp kí tự chữ hoặc số thì dừng
	while (s[0] == ' ')
		xoaTheoViTri(s, 0);
}

void xoaKhoangTrangCuoiChuoi(char s[])
{
	while (s[strlen(s) - 1] == ' ')
		xoaTheoViTri(s, strlen(s) - 1);
}

// Xoá khoảng trắng thừa ở giữa các từ
void xoaKhoangTrangGiuaCacTu(char s[])
{
	// Cho duyệt vòng lặp từ đầu đến cuối chuỗi,
	// nếu bắt gặp hai khoảng trắng thì sẽ xoá đi một
	for (int i = 0; i < strlen(s) - 1; i++)

		// Nếu hai kí tự liên nhau là khoảng trắng
			if (s[i] == ' ' && s[i + 1] == ' ')
			{
				xoaTheoViTri(s, i);
				// Kiểm tra lại tại vị trí vừa xoá
				i--;
			}
}

// Hàm viết hoa kí tự đầu của mỗi từ
void vietHoaDauMoiTu(char s[])
{
	// Chuyển toàn bộ chuỗi về in thường
	//strlwr(s); // strlwr((char*)s.c_str());
	for (int i = 0; i < strlen(s); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
	
	// Nếu kí tự tại vị trí thứ i là khoảng trắng
	// thì kí tự liền sau nó (i + 1) sẽ phải khác khoảng trắng
	// (Vì có i + 1 nên chỉ duyệt đến phần tử ép chót
	//  để i + 1 là phần tử cuối cùng và không bị vượt biên)
	
	// Xử lý in hoa kí tự đầu tiên của từ đầu tiên
	if (s[0] != ' ')
		if (s[0] >= 'a' && s[0] <= 'z')
			s[0] = s[0] - 32;

	// Xử lý in hoa kí tự đầu tiên của các từ
	// nằm phía sau từ đầu tiên
	for (int i = 0; i < strlen(s) - 1; i++)
		if (s[i] == ' ' && s[i + 1] != ' ')
			if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
				s[i + 1] = s[i + 1] - 32;
}

void chuanHoaChuoi(char s[])
{
	xoaToanBoKiTuLaTrongChuoi(s);
	xoaKhoangTrangDauChuoi(s);
	xoaKhoangTrangCuoiChuoi(s);
	xoaKhoangTrangGiuaCacTu(s);
	vietHoaDauMoiTu(s);
}
