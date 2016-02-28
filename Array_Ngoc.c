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
		int n = a->Max[i1];
		a->Max[i2] = a->Max[i1];
		a->Max[i1] = n;
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
};



void bublesort(struct Array *a)
{
	int i,j,temp;
    
    for(i=0; i<a->count-1; i++)
    {
        for(j=i+1; j<a->count; j++)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
};



float max(struct Array *a, int **maxArray)
{
	int i=0,k,j,h,m;
    k=1;h=0,m=get(a,0);
    i=a->Count;
    for(j=0;j<i;++j)
    {
        if(get(a,j)>=m) if(get(a,j)==m) k++;
        else
        {
            k=1;
            m=get(a,j);  
        }
    }
    int f[k];
    for(j=0;j<i;++j) if(get(a,j)==m)
    {
        f[h]=j;
        h++;
    }
    *maxArray=f;
    return m;
};