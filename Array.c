#include "Array.h"
#include <stdlib.h>
#include <stdio.h>



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
	printf("\n");
	int i;
	for (i = 0; i < a->Count; ++i)
	{
		printf("%d: %-5.0f ", i + 1, get(a, i));
	
		if (i % 5 == 4)
			printf("\n");
		else
			printf("| ");
	}
	printf("\n");
}

// Sắp xếp có lựa chọn
void selectionsort(struct Array *a)
{
	//
};


// The nay nhe!
// Ben nay laf cac file co thay doi ne
// Day laf so sanh su thay doi ne
// Nhan dau + de dua len stage
// Dat ten
// Xong nhan Ctrl+Enter de commit
// Nhan vao dong duoi chu git xong nhan Ctrl+Enter
// No se luu vao trong may ong

// De dua len github de mọi người có thể xem thì nhấn sync nhé! Cái vòng tròn dươi góc trái bên cahnj tên ông ý!
//
// Vis duj bay giow muoons xem bai tooi nhas!

// Copy paste code của ông vào đây nhá! Xong nhấn dấu + để đưa các file thay đổi lên stage.
// Xong đặt tên, nhấn Ctrl+Enter đê commit xong nhấn xync thì tôi và mọi người có thể xem được !

// Tìm giá trị trung bình của các phần tử trong mảng
float average(struct Array *a)
{
	//ong dang lam j do // Mang cham wa
    
    return 0;
};

