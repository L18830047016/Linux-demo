#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* task(void* arg){
    printf("thread strated\n");
    //默认取消类型是异步
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);

    printf("working..\n");
    int i=0;
    while(1){
        printf("%d\n",i++);
    }
    // //人为调用取消点函数
    // pthread_testcancel();
    printf("after cancelled\n");
    return NULL;
}
int main(int argc, char const *argv[])
{
    //创建线程
    pthread_t tid;
    pthread_create(&tid,NULL,task,NULL);

    // 取消子线程
    if(pthread_cancel(tid)!=0){
        perror("pthread_cancel");
    }
    void* res;
    //pthread_cancel只是发出一个停止的命令
    //join会挂起，一直等待子线程运行结束
    pthread_join(tid,&res);

    if(res==PTHREAD_CANCELED){
        printf("线程被取消\n");
    }else{
        printf("线程还没有取消 exit code %d",(int)res);
    }
    return 0;
}
