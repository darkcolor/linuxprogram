#include <stdio.h>
int main()
{
   int  a=1,b=1,i,n;
   float sum=0,f=1;
   
   printf("input n:\n");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
    {
       
       sum=sum+b*f/a;
       a=a+b;
       
       b=a-b;
       f=-f;
    }
   printf("sum=%f\n",sum);
   return 0;
 }

