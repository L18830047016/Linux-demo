#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

//定义结构体接收线程结果
    typedef struct Result{
        char* p;
        int len;
    }Result;

    //如果一个进程的多个线程同时使用到标准的输入输出，会造成冲突的问题，导致只能有一个线程使用到标准的输入输出
//红线程执行函数
void* red_thread(void* arg){
    //初始化result结构体
    Result *result=malloc(sizeof(Result));
    //解析传递的参数
    char code =*((char*)arg);
    //声明存放读取消息的字符串
    char* ans=malloc(101);
    while(1){
        fgets(ans,100,stdin);
        if(ans[0]==code){
            free(ans);
            printf("红离开了\n");
            char* redans=strdup("红纽约\n");
            result->p=redans;
            result->len=strlen(redans);
            //结束线程，返回故事结果
            pthread_exit((void*)result);
        }else{
            printf("红等\n");
        }
    }
}

//bai线程执行函数
void* white_thread(void* arg){
    //初始化result结构体
    Result *result=malloc(sizeof(Result));
    //解析传递的参数
    char code =*((char*)arg);
    //声明存放读取消息的字符串
    char* ans=malloc(101);
    while(1){
        fgets(ans,100,stdin);
        if(ans[0]==code){
            free(ans);
            printf("白离开了\n");
            char* redans=strdup("白纽约\n");
            result->p=redans;
            result->len=strlen(redans);
            //结束线程，返回故事结果
            pthread_exit((void*)result);
        }else{
            printf("白等\n");
        }
    }

}
int main(int argc, char const *argv[])
{
    //海格回复红和白为依据
    //创建两个线程->红线程和白线程
    pthread_t pid_red;
    pthread_t pid_white;
    char red_code='r';
    char white_code ='w';
    Result *red_result=NULL;
    Result *white_result=NULL;
    //创建红线程
    pthread_create(&pid_red,NULL,red_thread,&red_code);

    //创建白线程
    pthread_create(&pid_white,NULL,white_thread,&white_code); 
    
    //获取红线程结果
    pthread_join(pid_red,(void**)&red_result);
    printf("红结局%d是：%s\n",red_result->len,red_result->p);
    //释放内存
    free(red_result->p);
    free(red_result);
    //获取bai线程结果
    pthread_join(pid_white,(void**)&white_result);   
    printf("白结局%d是：%s\n",white_result->len,white_result->p);
    //释放内存
    free(white_result->p);
    free(white_result);  

    return 0;
}
