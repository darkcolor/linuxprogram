#include "uhead.h"
struct arg operater(int *a,int n)
{
	struct arg k;
	int i;
	k.sum=0;
	k.avg=0.0;
	for(i=0;i<n;i++)
	{
		k.sum=k.sum+a[i];
	}
	k.avg=((float)k.sum)/n;
	return k;
}
void bsort(void* base, size_t num, size_t width, int (*compar)(const void*, const void*))
{
    
	void* temp = malloc(width);
	int i, j;
	
    for (i = 0; i < num-1; i++)
	{
        for (j = 0; j < num-1-i; j++)
		{
            if (compar(base + width*j, base + width*(j+1)) > 0)
			{
				memcpy(temp, base + width*(j+1), width);
  				memcpy(base + width*(j+1), base + width*j, width);
				memcpy(base + width*j, temp, width);
            }
        }
    }
	free(temp);

	return;
}
int compar(const void *a,const void *b)
{	
	int *aa=(int *)a,*bb=(int *)b;
	if(* aa>* bb) return 1;
	if(* aa==* bb) return 0;
	if(* aa<* bb) return -1;
}
void sysbsort(int *arr, int n)
{
	struct timeval tv1, tv2;

	gettimeofday(&tv1, NULL);
	bsort((void*)arr, n, sizeof(int), compar);
	gettimeofday(&tv2, NULL);
	printf("bsort spend %ld us:\n", tv2.tv_usec - tv1.tv_usec);
}

void sysqsort(int *arr, int n)
{
	struct timeval tv1, tv2;

	gettimeofday(&tv1, NULL);
	qsort((void*)arr, n, sizeof(int), compar);
	gettimeofday(&tv2, NULL);
	printf("qsort spend %ld us:\n", tv2.tv_usec - tv1.tv_usec);
}
