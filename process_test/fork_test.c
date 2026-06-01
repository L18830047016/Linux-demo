#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char const *argv[]){
    //调用fork之前，代码都在父进程中运行
    printf("海格教老学员%d\n",getpid());

    //调用fork函数创建子进程
    /**
     * 不需要传参，
     * 返回值：int 进程号
     *      父进程返回子进程的PID；
     *      子进程返回0；
     *      失败返回-1。
     * pid_t fork(void);
     */
    pid_t pid = fork();

    //从这里开始，代码在父进程和子进程中都运行
    printf("%d\n",pid);

    if(pid<0){
        perror("fork");
        return -1;
    }else if(pid==0){//子进程
        printf("子进程运行，PID为%d,其父进程是%d\n",getpid(),getppid());
    }else{//父进程
        printf("父进程运行，PID为%d,子进程PID为%d\n",getpid(),pid);
    }
    return 0;
}