#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

sem_t *full;
sem_t *empty;

int shard_num;

int rand_num(){
    srand(time(NULL));
    return rand();
}
void* consumer(void* arg){
    for(size_t i=0;i<5;i++){
        //获取信号量
        //full初始化是0，不能wait（-1）
        sem_wait(full);
        printf("\n第%ld轮消费者开始读数据",i+1);
        sleep(1);
        printf("\n接收到的数据是%d\n",shard_num);

        //释放信号量
        sem_post(empty);//empty+=1;
    }
}
void* producer(void* arg){
    for(size_t i=0;i<5;i++){
        //获取信号量
        //empty初始是1,可以wait（-1）
        sem_wait(empty);
        printf("\n第%ld轮数据传输\n",i+1);
        sleep(1);
        shard_num=rand_num();
        //释放信号量
        sem_post(full);//post（full）=>full+=1
    }

}
int main(int argc, char const *argv[])
{
    full=malloc(sizeof(sem_t));
    empty=malloc(sizeof(sem_t));
    //初始化信号量
    sem_init(empty,0,1);
    sem_init(full,0,0);

    //创建生产者和消费者线程
    pthread_t producer_id,consumer_id;
    pthread_create(&producer_id,NULL,producer,NULL);
    pthread_create(&consumer_id,NULL,consumer,NULL);

    pthread_join(producer_id,NULL);
    pthread_join(consumer_id,NULL);


    sem_destroy(full);
    sem_destroy(empty);
    return 0;
}
