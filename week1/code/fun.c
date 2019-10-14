#include "uhead.h"


void bsort(int *a,int n)
{
	int i,j;
	int temp;
	for(i=0;i<n-1;i++)
	{	
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
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

