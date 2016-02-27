#include"Array.h";
void insert(struct Array *a, int k, float value) 
{
    int i= k-1;
    while (i > 0 && get(a,i) > value) 
	{
		set(a,i+1,get(a,i));
        i= i - 1;
    }
    set(a,i+1,value);
}

void insertionsort(struct Array *a)				// Sắp xếp chèn
{
    int k= 2;
    length=a->Count;
    while (k < length) 
	{
        insert(a, k, get(a,k));
        k= k + 1;
    }
}

float max(struct Array *a, int **maxArray);			// Tráº£ vá» giÃ¡ trá»‹ lá»›n nháº¥t // Máº£ng maxArray dÃ¹ng Ä‘á»ƒ lÆ°u vá»‹ trÃ­ cÃ¡c pháº§n tá»­ mang giÃ¡ trá»‹ lá»›n nháº¥t

int min(struct Array *a, int *minArray)			// Tráº£ vá» giÃ¡ trá»‹ nhá» nháº¥t // Máº£ng minArray dÃ¹ng Ä‘á»ƒ lÆ°u vá»‹ trÃ­ cÃ¡c phÃ¢n tá»­ nhá» nháº¥t
{
	int i=0,j,h, m=get(a,0);
    h=0;
    i=a->Count;
    for(j=0;j<i;++j)
    {
        if(get(a,j)<=m)
        {
            if(get(a,j)==m) h++;
            else
            {
                h=0;
                m=get(a,j);  
            }
        }         
    }
    
    for(j=0;j<i;++j) 
    if(get(a,j)==m)
    {
        minArray[h]=j;
        h--;
    }
    return m;
}
