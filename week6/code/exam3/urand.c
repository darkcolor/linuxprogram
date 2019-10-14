#include "lib.h"
void urand(int * a,int n)
{
   int i;
   srand((int)time(0));
   for(i=0;i<n;i++)
    a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
}
