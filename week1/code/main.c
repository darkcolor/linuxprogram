#include "uhead.h"

int main()
{
	int arr[U];
	struct arg res;

	urand(arr, U);
	show(arr, U);

	writedate(arr, U, "row.txt");
	
	sysbsort(arr, U);
	show(arr, U);
	
	sysqsort(arr, U);
	show(arr, U);

	writedate(arr, U, "sort.txt");
	
	res = operater(arr, U);
	printf("%d\t%f\n", res.sum, res.avg);

	showfile("row.txt");
	showfile("sort.txt");

	return 0;
}

