#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* task(void* arg){
    printf("thread strated\n");
    sleep(2);
    printf("thread finished\n");
    return NULL;
}
int main(int argc, char const *argv[])
{
    //创建线程
    pthread_t tid;
    pthread_create(&tid,NULL,task,NULL);

    // 用于将线程设置为分离状态（detached state），这样线程结束时会自动释放资源
    pthread_detach(tid);

    //主线程运行完成比创建的子线程慢
    printf("main thread continues\n");

    sleep(3);//因为主线程不会在pthread_detach的呢古代，如果父线程先结束，会强制杀死子线程

    printf("main ending\n");
    return 0;
}
