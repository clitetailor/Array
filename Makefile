# Cách thêm path cho hệ thống
#	My Computer > Property > Advanced system settings > Enviroment Variables > User variable
#	Nếu có sẵn PATH trong danh sách biến thì vào Edit
#	Nếu không có sẵn PATH thì chọn New
#	Trong Variable value thêm vào C:\MinGW\bin hoặc C:\Program Files (x86)\Dev-Cpp\MinGW32\bin hoặc đường dẫn tương tự
#	Nếu có nhiều đường dẫn thì các đường dẫn cách nhau bởi dấu chấm phẩy, không có dấu cách

# Mở CMD
#	Vào thư mục hiện tại bằng cách copy đường dẫn, nhấn chuột phải vào cmd chọn paste
#	Gõ mingw32-make Makefile all hoặc make hoặc ming64-make Make all


all:
	gcc -Wall -c Array.c
	gcc -Wall -o Array.exe Array.o