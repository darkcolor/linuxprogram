#include "myhead.h"
#define NUM_THREADS 8
cchar *messages[NUM_THREADS];
struct thread_data
{
	int thread_id;
	int sum;
	char *message;
}
struct thread_data thread_data_array(NUM_THREADS);
void *PrintHello(void *threadarg)
{
	int taskid,sum;
	char *hello_msg;
	struct thread_data *my_data;
	sleep(1);
	my_data = (struct thread_data *) threadarg;
	taskid = my_data->thread_id;
	sum = my_data->sum;
	hello_msg = my_data->message;
	printf("Thread id: is Sum=%d\n",taskid,hello_msg,sum);
	pthread_exit(NULL);	
}
int main(int argc,char *argv[])
{
	pthread_t threads(NUM_THREADS);
	int *taskids[NUM_THREADS];
	int rc,t,sum;
	sum=0;
	message[0]="English:Hello World!";
	message[1]="French:Hello World!";
	message[2]="Spanish:Hello World!";
	message[3]="Klingcn:Hello World!";
	message[4]="English:Hello World!";
	message[5]="English:Hello World!";
	message[6]="English:Hello World!";
	message[7]="English:Hello World!";
	for(t=0;t<NUM_THREADS;t++)
	{
		sum=sum+t;
		thread_data_array[t].thread_id = t;
		thread_data_array[t].message=messsages[t];
		printf("Creating thread %d\n",t);
		rc=pthread_create(&threads[t],NULL,PrintHello,(void *)&thread_data_arrray[t]);
		if(rc)
		{
			pritnf("ERROR,return code f is %d\n",rc);
			exit(-1);
		}
	}
	pthread_exit(NULL);
}

