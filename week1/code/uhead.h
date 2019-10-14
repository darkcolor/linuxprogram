#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <fcntl.h>
#define U 100
#define BUFFER_SIZE 64
int usum(int *,int);
void urand(int *,int);
void show(int *,int);
void bsort(void*, size_t, size_t, int (*)(const void*, const void*));
int compare(const void *,const void *);
void runtime(int *,int);
void sysbsort(int *, int);
void sysqsort(int *, int);
int writedate(int*, int, const char*);
int showfile(const char*);
struct arg 
{
	float avg;
	int sum;
};
struct arg operater(int *,int);
