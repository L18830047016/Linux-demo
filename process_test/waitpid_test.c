#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc,char const* argv[]){
    int subprocess_status;
    //fork之前
    printf("before fork\n");

    pid_t pid = fork();
    if(pid < 0){
        perror("fork error");
        exit(1);
    }else if(pid == 0){
        //child process
        char *args[]={"/usr/bin/ping","-c","10","www.baidu.com",NULL};
        char *envs[]={NULL};
        int ret = execve(args[0],args,envs);
        if(ret < 0){
            perror("execve error");
            exit(1);
        }
    }else{
        //parent process
       printf("parent process %d waiting for child process %d\n",getpid(),pid);
       /**
        * pid_t pid: 需要等待的子进程的PID
        * int *stat_loc: 用于存储子进程的退出状态信息的指针
        * int options: 选项参数，通常为0，表示阻塞等待子进程结束
        * pid_t waitpid(pid_t __pid, int *__stat_loc, int __options);
        */
       waitpid(pid,&subprocess_status,0);
    }

    printf("parent process waiting for child process %d finished\n",pid);
    return 0;
}