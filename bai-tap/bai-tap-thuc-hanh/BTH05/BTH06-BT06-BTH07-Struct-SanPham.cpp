/*
Viết 01 chương trình thực hiện các yêu cầu sau (cấp phát bộ nhớ động cho lưu trữ nhiều đối tượng
struct):
	a. Định nghĩa struct Sach gồm các thông tin: (1 điểm)
		- Mã sách: kiểu chuỗi c-string
		- Tên sách: kiểu chuỗi c-string
		- Ngày tháng năm xuất bản: kiểu NTN
		(NTN là kiểu struct gồm ngày, tháng, năm kiểu số nguyên)

	b. Hàm nhập thông tin cho tối đa 20 sách. (1 điểm)

	c. Giả sử có file DuLieuSach.txt có thông tin như sau:

			5
			Sp01#Tieng Viet#1-1-2019
			Sp02#Khoa Hoc Tu Nhien#2-3-2015
			Sp03#Ngu Van#5-5-2019
			Sp04#Tieng Anh#30-3-2019
			Sp05#Bai Tap Tin Hoc#10-7-2020

	   Hãy viết hàm đọc dữ liệu từ file lên cho danh sách sách
	   theo cấu trúc struct đã định nghĩa.
	   Biết rằng dòng đầu tiên lưu số lượng sách trong file. (1 điểm)

	d. Hàm xuất thông tin của các sách
	   đang lưu trữ trong chương trình. (1 điểm)

	e. Hàm sắp xếp các sách theo năm xuất bản tăng dần. (1 điểm)

	f. Hàm đếm số sách có năm xuất bản vào năm 2019. (1 điểm)

	g. Hàm nhận vào 1 chuỗi c-string.
	   Trả về kết quả loại bỏ khoảng trắng đầu, cuối,
	   chỉ giữ lại 1 khoảng trắng giữa các từ trong chuỗi
	   và chuyển toàn bộ chuỗi về in hoa ký tự đầu mỗi từ
	   và in thường các ký tự còn lại. (1 điểm)

	h. Hàm nhận vào tên sách từ bàn phím
	   và trả ra kết quả gợi ý (dạng thống kê tên sách)
	   cho người dùng dựa trên nguyên tắc chuẩn hoá chuỗi nhận vào
	   đã xây dựng ở câu trên.

	   Ví dụ: khi gõ “Ti” thì sẽ tiến hành chuẩn hoá chuỗi
	          và trả về kết quả gợi ý gồm:
		  “Tieng Viet” và “Tieng Anh”. (1 điểm)

	i. Hàm main kiểm chứng chương trình
	   dưới dạng menu lựa chọn chức năng
	   có kiểm soát dữ liệu nhập phù hợp. (2 điểm)
*/