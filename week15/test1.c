#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
 
#define CONSUMER_NUM 1   //消费者数量
#define PRODUCER_NUM 1	 //生产者数量
#define MAXCAPACITY 5   //缓冲区最大数量
 
pthread_mutex_t mutex;
pthread_cond_t condCon;
pthread_cond_t condPro;
int g_count = 0;
int proIndex[PRODUCER_NUM];
int conIndex[CONSUMER_NUM];

void *producer_function(void *args);//生产者生产
void *consumer_function(void *args);//消费者消费
 
int main()
{
	pthread_t producer_thread[PRODUCER_NUM];
	pthread_t consumer_thread[CONSUMER_NUM];
	int ret;
	int i;
	void *thread_result;
 
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&condCon,NULL);
	pthread_cond_init(&condPro,NULL);
 
	for(i = 0;i < PRODUCER_NUM; ++ i)
	{
        proIndex[i] = i + 1;
		ret = pthread_create(&producer_thread[i], NULL, producer_function, (void*)&proIndex[i]);
		if(ret != 0)
		{
			perror("create thread producer error");
			exit(EXIT_FAILURE);
		}
		printf("Starting producer %d success!\n", i);
	}
 
	for(i = 0; i < CONSUMER_NUM; ++ i)
	{
        conIndex[i] = i + 1;
		ret= pthread_create(&consumer_thread[i], NULL, consumer_function, (void*)&conIndex[i]);
		if(ret != 0)
		{
			perror("create thread producer error");
			exit(EXIT_FAILURE);
		}
		printf("Starting consumer %d success!\n",i);
	}
 
	for(i = 0; i < PRODUCER_NUM; ++i)
	{
		ret = pthread_join(producer_thread[i],&thread_result);
		if(ret != 0)
		{
			perror("thread producer failed");
			exit(EXIT_FAILURE);
		}
		printf("thread producer %d joined\n", i);
	}
 
	for(i = 0; i < PRODUCER_NUM; ++i)
	{
		ret = pthread_join(consumer_thread[i],&thread_result);
		if(ret != 0)
		{
			perror("thread consumer failed");
			exit(EXIT_FAILURE);
		}
		printf("thread consumer %d joined\n",i);
	}
 
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&condCon);
	pthread_cond_destroy(&condPro);
 
    return 0;
}
 
void *producer_function(void *args)
{
	int index = *(int*)args;
	while(1){
		pthread_mutex_lock(&mutex);
		while(g_count >= MAXCAPACITY){
			printf("产品已满，生产者%d等待中\n", index);
			pthread_cond_wait(&condCon, &mutex);
			sleep(5);
		}
 
		++g_count;
		printf("生产者%d生产了1个产品，现在共有%d个产品\n", index, g_count);
		pthread_cond_signal(&condPro);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}
 
void *consumer_function(void *args)
{
	int index = *(int*)args;
	while(1){
		pthread_mutex_lock(&mutex);
		while(g_count == 0){
			printf("缓冲区里没有产品了，消费者%d等待中\n", index);
			pthread_cond_wait(&condPro, &mutex);
			sleep(5);
		}
		--g_count;
		printf("消费者%d消费1个产品，缓冲区现有%d个产品\n", index, g_count);
		pthread_cond_signal(&condCon);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}
