#include "uhead.h"

int usum(int *a,int n)
{
   int s=0,i;
   for(i=0;i<n;i++)
      s=s+a[i];
   return s;
} 
void urand(int * a,int n)
{
   int i;
   srand((int)time(0));
   for(i=0;i<n;i++)
    a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
}
void show(int *a,int n)
{
    int i;
   for(i=0;i<n;i++)
       printf("a[%d]=%d\n",i,a[i]);

}


