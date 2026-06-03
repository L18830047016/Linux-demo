#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    // char* shm_name="unnamed_sem_shm";
    // //创建共享内存
    // int fd=shm_open(shm_name,O_CREAT|O_RDWR,0666);
    // //调整共享内存大小
    // ftruncate(fd,sizeof(sem_t));
    // //完成映射
    // sem_t *sem=mmap(NULL,sizeof(sem_t),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

    // //初始化信号量
    // sem_init(sem,1,0);

    //初始化有名信号量
    char* sem_name="/named_sem";
    sem_t *sem=sem_open(sem_name,O_CREAT,0666,0);

    //创建父子进程
    pid_t pid=fork();

    if(pid<0){
        perror("fork");
    }else if(pid==0){
        sleep(1);
        printf("子进程\n");
        sem_post(sem);
    }else{
        //sem_wait sem=0,无法-1,阻塞，等子进程执行到sem_post(sem)，之后才会解除阻塞
        sem_wait(sem);
        printf("父进程\n");
        waitpid(pid,NULL,0);
    }

    //回收资源
    if(sem_close(sem)==-1){
        perror("sem_close");
    }
    if(pid>0){
        if(sem_unlink(sem_name)==-1){
            perror("sem_unlink");
        }
    }
        return 0;
}
