#include "Array.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>



int initialize(struct Array **aptr, int size)
{
	(*aptr) = (struct Array*) malloc( sizeof(struct Array) );
	
	if ( (*aptr) == NULL )
	{
		return 2;
	}
	
	(*aptr)->Max = (float*) malloc( sizeof(float) * size);
	
	if ( (*aptr)->Max == NULL )
	{
		return 1;
	}
	
	(*aptr)->Count = size;
	
	return 0;
};

int reallocate(struct Array **aptr, int size)
{
	free( (*aptr)->Max );
	
	(*aptr)->Max = (float*) malloc( sizeof(float) * size);
	
	if ( (*aptr)->Max == NULL )
	{
		return 1;
	}
	
	(*aptr)->Count = size;
	
	return 0;
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
		printf("%d: %7.0f ", i + 1, get(a, i));
	
		if (i % 5 == 4)
			printf("\n\t");
		else
			printf("| ");
	}
}


// Sắp xếp nổi bọt
void bublesort(struct Array *a)
{
	int i, j;
    
    for(i = 0; i < a->Count - 1; ++i)
    {
        for(j = i + 1; j < a->Count; ++j)
        {
            if ( get(a, i) > get(a, j) )
			{
				swap(a, i, j);
			}
        }
    }
};

// Sắp xếp có lựa chọn
void selectionsort(struct Array *a)
{
	int i, j;
	
	for(i = 0; i < a->Count; ++i)
	{
		int min = i;
		
		for(j = i + 1; j < a->Count; ++j)
		{
			if( get(a, j) < get(a, min) )
			{
				min = j;
			}
		}
		
		swap(a, i, min);
	}
};


void insert(struct Array *a, int k, float value);

// Sắp xếp chèn
void insertionsort(struct Array *a)
{
    int k;
	
    for (k = 1; k < a->Count; ++k)
	{
		insert(a, k, get(a, k));
	}
};

void insert(struct Array *a, int k, float value)
{
    int i = k - 1;
	
    while (i > -1 && get(a, i) > value) 
	{
		set(a, i + 1, get(a, i));
        --i;
    }
	
    set(a, i + 1, value);
};



// Trả về giá trị lớn nhất // Mảng maxArray dùng để lưu vị trí các phần tử mang giá trị lớn nhất
float findmax(struct Array *a, int **maxArray, int *length)
{
	float max = get(a, 0);
	int count = 1;
	int i;
	for (i = 1; i < a->Count; ++i)
	{
		if (max < get(a, i))
		{
			max = get(a, i);
			count = 1;
		}
		else if (max == get(a, i))
		{
			++count;
		}
		
	}
	
	(*length) = count;
	(*maxArray) = (int *) malloc (sizeof(int) * count);
	
	int j = 0;
	for (i = 0; i < a->Count; ++i)
	{
		if (get(a, i) == max)
		{
			(*maxArray)[j] = i + 1;
			++j;
		}
	}
	
	
	return max;
};

// Trả về giá trị nhỏ nhất // Mảng minArray dùng để lưu vị trí các phân tử nhỏ nhất
float findmin(struct Array *a, int **minArray, int *length)
{
	float min = get(a, 0);
	int count = 1;
	int i;
	for (i = 1; i < a->Count; ++i)
	{
		if (min > get(a, i))
		{
			min = get(a, i);
			count = 1;
		}
		else if (min == get(a, i))
		{
			++count;
		}
		
	}
	
	(*length) = count;
	(*minArray) = (int *) malloc (sizeof(int) * count);
	
	int j = 0;
	for (i = 0; i < a->Count; ++i)
	{
		if (get(a, i) == min)
		{
			(*minArray)[j] = i + 1;
			++j;
		}
	}
	
	
	return min;
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



/*   Giao diện người sử dụng   */



#ifndef test 				// When "test" is mingw32-make first argument. This part is hidden away

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
		printf("\n\nNhap vao lenh ban muon thuc hien (1-13):");
		scanf("%d", &selection);
	} while (selection < 1 || selection > 13);
	
	return selection;
};


void getfirstarray(struct Array **a)
{
	int n;
	int retval;
	do
	{
		printf("\nNhap vao so luong phan tu cua mang:");
		scanf("%d", &n);
		
		retval = initialize(a, n);
		
		if (retval == 2)
		{
			printf("\nKhong du bo nho de thuc hien chuong trinh\n");
			escape();
		}
		if (retval == 1)
		{
			printf("\nKhong du bo nho de cap phat. Nhap lai so phan tu cua mang hoac nhan Ctrl+C de thoat khoi chuong trinh\n");
		}
		
	} while( n < 1 || retval == 1 );
	
	
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

void escape()
{
	printf("\nThoat khoi chuong trinh! ");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".\n\n");
	exit(0);
}


void getnewarray(struct Array **a)
{
	int n;
	int retval;
	do
	{
		printf("\nNhap vao so luong phan tu cua mang:");
		scanf("%d", &n);
		
		retval = reallocate(a, n);
		
		if (retval == 1)
		{
			printf("\nKhong du bo nho de cap phat. Nhap lai so phan tu cua mang hoac nhan Ctrl+C de thoat khoi chuong trinh\n");
		}
		
	} while( n < 1 || retval == 1 );
	
	
	printf("\n");
	int i;
	float fbuff;
	
	for (i = 0; i < n; ++i)
	{
		printf("%d, ", i+1);
		scanf("%f", &fbuff);
		set(*a, i, fbuff);
	};
	
	print(*a);
};



void printarraywithmark(struct Array *a, int *position, int length)
{
	printf("\nDanh sach mang:\n\t");
	
	int j = 0;
	int i;
	int ii;
	for (i = 0; i < a->Count; ++i)
	{
		printf("%2d: %7.0f ", i + 1, get(a, i));
		
		if (i % 5 == 4)
		{
			printf("\n\t");
			
			if ( position[j] - 1 <= i )
			{
				for (ii = 0; ii < 5; ++ii)
				{
					if ( ((position[j] - 1) % 5) == ii && j < length)
					{
						printf("     ^      ");
						++j;
					}
					else
					{
						printf("            ");
					}
					
					printf("  ");
				}
				
				printf("\n\t");
			}
			
		}
		else
			printf("| ");
	}
	
	
	if ( (i % 5) != 4)
	{
		printf("\n\t");
		
		if ( position[j] - 1 <= i )
		{
			for (ii = 0; ii < 5; ++ii)
			{
				if ( ( (position[j] - 1) % 5) == ii && j < length)
				{
					printf("     ^      ");
					++j;
				}
				else
				{
					printf("            ");
				}
				
				printf("  ");
			}
			
			printf("\n");
		}
		
	}
}


void runcommand(int selection, struct Array *a)
{
	switch (selection)
	{
		case 1:
				{
					getnewarray(&a);
					break;
				}
		case 2:
				{
					// bublesort
					
					bublesort(a);
					print(a);
					break;
				}
		case 3:
				{
					// selectionsort
					
					selectionsort(a);
					print(a);
					break;
				}
		case 4:
				{
					// insertionsort
					
					insertionsort(a);
					print(a);
					break;
				}
		case 5:
				{
					// findmax
					
					int *maxArray;
					int length;
					
					printf("\nGia tri phan tu nho nhat:%f\n", findmax(a, &maxArray, &length) );
					printarraywithmark(a, maxArray, length);
					
					printf("\nVi tri cac phan tu lon nhat la:");
					int i;
					for (i = 0; i < length; ++i)
					{
						printf("%d, ", maxArray[i]);
					}
					
					free(maxArray);
					
					break;
				}
		case 6:
				{
					// findmin
					
					int *minArray;
					int length;
					
					printf("\nGia tri phan tu nho nhat:%f\n", findmin(a, &minArray, &length) );
					printarraywithmark(a, minArray, length);
					
					printf("\nVi tri cac phan tu nho nhat la:");
					int i;
					for (i = 0; i < length; ++i)
					{
						printf("%d, ", minArray[i]);
					}
					
					free(minArray);
					
					break;
				}
		case 7:
				{
					// average
					break;
				}
		case 8:
				{
					// sequentialsearch
					break;
				}
		case 9:
				{
					// binarysearch
					break;
				}
		case 10:
				{
					// difference
					break;
				}
		case 11:
				{
					// deviation
					break;
				}
		case 12:
				{
					// big-O  :(
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
	getfirstarray(&a);
	
	print(a);
	do
	{
		selection = getcommand();
		
		runcommand(selection, a);
	} while(selection != 13);
	
	delete(a);
}


int main(int argc, char ** argv)
{
	commandlineinterface();
	
	return 0;
}

#endif