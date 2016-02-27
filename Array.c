#include "Array.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h> // Bỏ dòng này
#include <windows.h>



void initialize(struct Array **aptr, int size)
{
	(*aptr) = (struct Array*) malloc( sizeof(struct Array) );
	
	(*aptr)->Max = (float*) malloc( sizeof(float) * size);
	
	(*aptr)->Count = size;
	
};

void delete(struct Array *a)
{
	free(a->Max);
	free(a);
};



float get(struct Array *a, int i)
{
	if (i > -1 && i < a->Count)
		return a->Max[i];
	else
		return -1;
};

void set(struct Array *a, int i, float data)
{
	if (i > -1 && i < a->Count)
		a->Max[i] = data;
};

void swap(struct Array *a, int i1, int i2)
{
	if (i1 > -1 && i1 < a->Count && i2 > -1 && i2 < a->Count)
	{
		float n = a->Max[i1];
		a->Max[i1] = a->Max[i2];
		a->Max[i2] = n;
	}
};


void print(struct Array *a)
{
	printf("\nDanh sach mang:\n\t");
	int i;
	for (i = 0; i < a->Count; ++i)
	{
		printf("%d: %-5.0f ", i + 1, get(a, i));
	
		if (i % 5 == 4)
			printf("\n\t");
		else
			printf("| ");
	}
}


// Sắp xếp nổi bọt
void bublesort(struct Array *a)
{
	
};

// Sắp xếp có lựa chọn
void selectionsort(struct Array *a)
{
	
};

// Sắp xếp chèn
void insertionsort(struct Array *a)
{
	
};



// Trả về giá trị lớn nhất // Mảng maxArray dùng để lưu vị trí các phần tử mang giá trị lớn nhất
float findmax(struct Array *a, int **maxArray)
{
	return 0;
};

// Trả về giá trị nhỏ nhất // Mảng minArray dùng để lưu vị trí các phân tử nhỏ nhất
float findmin(struct Array *a, int **minArray)
{
	return 0;
};

// Tìm giá trị trung bình của các phần tử trong mảng
float average(struct Array *a)
{
	return 0;
};



// Tìm kiếm lần lượt
void sequentialsearch(struct Array *a)
{
	
};

// Tìm kiếm nhị phân
void binarysearch(struct Array *a);



// Độ lệch giá trị giữa hai phần tử i1 và i2
float difference(struct Array *a, int i1, int i2)
{
	return 0;
};

// Trả về giá trị độ lệch trung bình của mảng // https://en.wikipedia.org/wiki/Average_absolute_deviation -> Mean absolute deviation around a central point
float deviation(struct Array *a)
{
	return 0;
};



// Giao diện người sử dụng

int getcommand()
{
	printf("\n");
	
	int menusize = 13;
	char ** menu = (char **) malloc(sizeof(char*) * menusize);
	
	menu[0] = 	"Nhap vao mang moi";
	menu[1] = 	"Sap xep noi bot";
	menu[2] = 	"Sap xep chen";
	menu[3] = 	"Sap xep chon loc";
	menu[4] = 	"Gia tri lon nhat va danh sach cac phan tu mang gia tri lon nhat";
	menu[5] = 	"Gia tri nho nhat va danh sach cac phan tu mang gia tri nho nhat";
	menu[6] = 	"Gia tri trung binh cua mang";
	menu[7] = 	"Tim kiem lan luot";
	menu[8] = 	"Tim kiem nhi phan";
	menu[9] = 	"Do lech gia tri gia tri cua hai phan tu";
	menu[10] = 	"Tra ve gia tri do lech trung binh cua mang";
	menu[11] = 	"Do phuc tap cua thuat toan";
	menu[12] = 	"Ket thuc chuong trinh";
	
	int i;
	printf("\nDanh sach cac lenh:\n");
	for (i = 0; i < menusize; ++i)
	{
		printf("\n\t%d, %s", i+1, menu[i]);
	}
	
	int selection;
	do
	{
		printf("\nNhap vao lenh ban muon thuc hien (1-13):");
		scanf("%d", &selection);
	} while (selection < 1 || selection > 13);
	
	return selection;
};


void getnewarray(struct Array **a)
{
	int n;
	do
	{
		printf("\nNhap vao so luong phan tu cua mang:");
		scanf("%d", &n);
	} while( n < 1 );
	
	initialize(a, n);
	
	
	printf("\n");
	int i;
	float fbuff;
	
	for (i = 0; i < n; ++i)
	{
		printf("%d, ", i+1);
		scanf("%f", &fbuff);
		set(*a, i, fbuff);
	};
	
};


void runcommand(int selection)
{
	switch (selection)
	{
		case 1:
				{
					break;
				}
		case 2:
				{
					break;
				}
		case 3:
				{
					break;
				}
		case 4:
				{
					break;
				}
		case 5:
				{
					break;
				}
		case 6:
				{
					break;
				}
		case 7:
				{
					break;
				}
		case 8:
				{
					break;
				}
		case 9:
				{
					break;
				}
		case 10:
				{
					break;
				}
		case 11:
				{
					break;
				}
		case 12:
				{
					break;
				}
		case 13:
				{
					printf("\nChuong trinh dang ket thuc! ");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".\n\n");
					break;
				}
	}
}



void commandlineinterface()
{
	struct Array *a;
	int selection;
	getnewarray(&a);
	
	print(a);
	do
	{
		selection = getcommand();
		
		runcommand(selection);
	} while(selection != 13);
	
	delete(a);
}


int main(int argc, char ** argv)
{
	commandlineinterface();
	
	return 0;
}