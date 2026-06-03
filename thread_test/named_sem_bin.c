#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>

int main(){
    char *shm_value_name="named_sem_shm_value";
    char* sem_name="/named_sem_shm";

    //创建共享内存对象
    int value_fd=shm_open(shm_value_name,O_CREAT|O_RDWR,0666);

    //初始化有名信号量
    sem_t* sem=sem_open(sem_name,O_CREAT,0666,1);
    //调整内存共享对象的大小
    ftruncate(value_fd,sizeof(int));

    //将内存共享对象映射到共享内存区域
    int* value=mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,value_fd,0);

    //初始化共享变量的值
    *value=0;

    int pid=fork();

    if(pid>0){
        //父进程
        sem_wait(sem);
        int tmp=*value+1;
        sleep(1);
        *value=tmp;

        sem_post(sem);
        //等待子进程执行完毕
        waitpid(pid,NULL,0);
        printf("this is father,child finished\n");
        printf("the final value is %d\n",*value);
    }else if(pid==0){
        //子进程
        sem_wait(sem);
        int tmp=*value+1;
        sleep(1);
        *value=tmp;
        sem_post(sem);
    }else{
        perror("fork");
    }


    //父子进程解除共享内存映射,并关闭文件描述符
    if(munmap(value,sizeof(int))==-1){
        perror("munmap value");
    }


    if(close(value_fd)==-1){
        perror("close value");
    }

    if(sem_close(sem)==-1){
        perror("sem_close");
    }

    //如果调用时被的进程仍在使用共享对象，则等待所有进程释放资源后，才会销毁相关资源
    //父进程调用shm_unlink
    if(pid>0){
        if(shm_unlink(shm_value_name)==-1){
            perror("father shm_unlink shm_value_name");
        }
                if(sem_unlink(sem_name)==-1){
            perror("father shm_unlink shm_sem");
        }
        }


    return 0;

}