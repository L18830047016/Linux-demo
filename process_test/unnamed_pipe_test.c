#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char const* argv[]){
    //将程序传进来的第一个命令行参数通过管道传递给子进程
    if(argc!=2){
        fprintf(stderr,"%s:请填写需要传递的信息\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    //创建管道
    int pipefd[2];
    if(pipe(pipefd)==-1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    //复制父子进程
    pid_t cpid;
    cpid=fork();
    if(cpid==-1){
        perror("fork");
        exit(EXIT_FAILURE);
    }else if(cpid==0){
        //子进程
       close(pipefd[1]);//关闭写端
       printf("子进程：正在从管道读取信息...\n");
       char buf[100];
       while(read(pipefd[0],buf,sizeof(buf))>0){
        printf("子进程：从管道读取到的信息是：%s\n",buf);
       }
         close(pipefd[0]);//读取完成，关闭读端
         _exit(EXIT_SUCCESS);
    }else{
        //父进程，写入管道数据，提供给子程序读
        close(pipefd[0]);//关闭读端
        //将命令行参数写入管道
        printf("父进程：正在将信息写入管道...\n");
        write(pipefd[1],argv[1],strlen(argv[1]));
        close(pipefd[1]);//写入完成，关闭写端
        waitpid(cpid,NULL,0);//等待子进程结束
        exit(EXIT_SUCCESS);
    }

}