#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    char *shm_value_name="unnamed_sem_shm_value";

    //创建共享内存对象
    int value_fd=shm_open(shm_value_name,O_CREAT|O_RDWR,0666);
    //调整内存共享对象的大小
    ftruncate(value_fd,sizeof(int));
    //将内存共享对象映射到共享内存区域
    int* value=mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,value_fd,0);

    //初始化共享变量的值
    *value=0;

    int pid=fork();

    if(pid>0){
        //父进程
        int tmp=*value+1;
        sleep(1);
        *value=tmp;

        //等待子进程执行完毕
        waitpid(pid,NULL,0);
        printf("this is father,child finished\n");
        printf("the final value is %d\n",*value);
    }else if(pid==0){
        //子进程
        int tmp=*value+1;
        sleep(1);
        *value=tmp;
    }else{
        perror("fork");
    }
    //父子进程解除共享内存映射
    if(munmap(value,sizeof(int))==-1){
        perror("munmap value");
    }
    if(close(value_fd)==-1){
        perror("close value");
    }

    //如果调用时被的进程仍在使用共享对象，则等待所有进程释放资源后，才会销毁相关资源
    if(pid>0){
        if(shm_unlink(shm_value_name)==-1){
            perror("father shm_unlink shm_value_name");
        }
    }

    return 0;

}