#ifndef _H_ARRAY
#define _H_ARRAY


// Code name: asre12i3uie3 (on Github)
// This project was created using Visual Studio Code, Dev-C, Git, Github, MinGW
// These files were encoded in Unicode (UTF-8) some features may not be compatible in Dev-C


struct Array
{
	float* Max;
	int Count;
};

// Chú ý: Vị trí các phần tử trong mảng tính từ 0

int initialize(struct Array **aptr, int size);		// Khởi tạo mảng a // size là số phần tử của mảng
int reallocate(struct Array **aptr, int size);		// Cấp phát lại bộ nhớ
void delete(struct Array *a);						// Xoá mảng a

float get(struct Array *a, int i);					// Trả về giá trị phần tử thứ i của mảng // Trả về giá trị -1 nếu i không hợp lệ
void set(struct Array *a, int i, float data);		// Gán giá trị cho phần tử thứ i của mảng
void swap(struct Array *a, int i1, int i2);			// Đổi tráo giá trị phần tử thứ i1 và i2

void print(struct Array *a);						// In ra mảng

void bublesort(struct Array *a);					// Sắp xếp nổi bọt
void selectionsort(struct Array *a);				// Sắp xếp có lựa chọn
void insertionsort(struct Array *a);				// Sắp xếp chèn

float findmax(struct Array *a, int **maxArray);			// Trả về giá trị lớn nhất // Mảng maxArray dùng để lưu vị trí các phần tử mang giá trị lớn nhất
float findmin(struct Array *a, int **minArray, int *length);			// Trả về giá trị nhỏ nhất // Mảng minArray dùng để lưu vị trí các phân tử nhỏ nhất
float average(struct Array *a);						// Tìm giá trị trung bình của các phần tử trong mảng

void sequentialsearch(struct Array *a);				// Tìm kiếm lần lượt
void binarysearch(struct Array *a);					// Tìm kiếm nhị phân

float difference(struct Array *a, int i1, int i2);	// Độ lệch giá trị giữa hai phần tử i1 và i2
float deviation(struct Array *a);					// Trả về giá trị độ lệch trung bình của mảng // https://en.wikipedia.org/wiki/Average_absolute_deviation -> Mean absolute deviation around a central point


// Giao diện người sử dụng

void commandlineinterface();						// Giao diện dòng lệnh

int getcommand();									// In ra danh sách các lênh và nhận lệnh của người sử dụng
void runcommand(int selection, struct Array *a);						// Thực hiện lệnh
void getfirstarray(struct Array **a);				// Nhập vào mảng mới lần đầu tiên
void getnewarray(struct Array **a);					// Nhập vào mảng mới

void printarraywithmark(struct Array *a, int *positions, int length);

void escape();										// Thoát khỏi chương trình khi gặp lỗi // Nếu may mắn sẽ gặp được lỗi này! :v



#endif