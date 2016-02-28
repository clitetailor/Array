#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"


/*
 *
 * Nếu có thêm các hàm để test chèn vào đây. Số các hàm sử dụng để test không hạn chế.
 *
 *
 */

/*   Hàm test_findmin kiểm tra xem hàm findmin đã đúng hay chưa   */
void test_findmin(struct Array *a)
{
	int i;
	
	int *minArray;
	int length;
	
	printf("\nGia tri nho nhat la: %f\n", findmin(a, &minArray, &length));
	
	for (i = 0; i < length; ++i)
	{
		printf("\nVi tri cac phan tu nho nhat la:\n");
		printf("%7d\n", minArray[i]);
	}	
};

/*   Hàm test_order kiểm tra xem dãy đã được sắp xếp theo thứ tự hay chưa   */
void test_order(struct Array *a)
{
	int lts = 0;
	int stl = 0;
	
	/* Kiểm tra xem có số nào không theo thứ tự hay không */
	int i;
	for (i = 1; i < a->Count; ++i)
	{
		if ( get(a, i-1) > get(a, i) )
			++stl;
		
		if ( get(a, i-1) < get(a, i) )
			++lts;
	}
	
	/* In kết quả */
	if (stl == 0)
		printf("\nDay da duoc sap xep theo thu tu tu be den lon\n");
	else if (lts == 0)
		printf("\nDay da duoc sap xep theo thu tu tu lon den be\n");
	else
		printf("\nDay khong xep theo thu tu nao ca\n");
}


/*   Hàm test_autogenerate sử dụng các hàm kiểm tra ở trên kiểm tra với bộ n số ngẫu nhiên máy tự tạo   */
void test_autogenerate()
{
	/* Đọc vào số phần tử của mảng */
	int n;
	printf("\nn:");
	scanf("%d", &n);
	
	
	
	struct Array *a;
	initialize(&a, n);			// Luôn phải có dòng này ở đầu của mỗi chương trình
	
	
	/* Khởi tạo bộ số bất kì cho máy tính */
	time_t t;
	time(&t);
	srand( (unsigned int) t );
	
	
	/* Gán cho các phần tử của mảng các giá trị ngẫu nhiên */
	int i;
	for (i = 0; i < n; ++i)
	{
		set(a, i, rand());
	}
	
	/*
	 *
	 * Đặt các code cần test vào đây
	 *
	 *
	 */
	insertionsort(a);
	
	/* In dãy a ra màn hình */
	print(a);
	
	/*
	 *
	 * Đặt các test vào đây
	 *
	 *
	 */
	test_order(a);
	
	
	delete(a);					// Luôn phải có dòng này ở cuối mỗi chương trình
}


/*   Hàm test_manual sử dụng các hàm test ở trên để kiểm tra với bộ số bất kì nhập từ vào máy tính   */
void test_manual()
{
	/* Đọc vào số phần tử của mảng */
	int n;
	printf("\nn:");
	scanf("%d", &n);
	
	
	struct Array *a;
	initialize(&a, n);			// Luôn phải có dòng này ở đầu của mỗi chương trình
	
	
	/* Đọc vào n phần tử từ màn hình */
	printf("\n");
	int i;
	float buff;
	for (i = 0; i < n; ++i)
	{
		printf("%d,  ", i+1);
		scanf("%f", &buff);
		set(a, i, buff);
	}
	
	/*
	 *
	 * Đặt các code cần test vào đây
	 *
	 *
	 */
	insertionsort(a);
	 
	/* In dãy a ra màn hình */
	print(a);
	
	
	/*
	 *
	 * Đặt các test vào đây
	 *
	 *
	 */
	test_order(a);
	
	delete(a);					// Luôn phải có dòng này ở cuối mỗi chương trình
}


int main(int argc, char ** argv)
{
	
	
	/*
	 * Sử dụng test_manual() hoặc thay bằng test_autogenerate()
	 *
	 *
	 */
	test_manual();
	 
	return 0;
}