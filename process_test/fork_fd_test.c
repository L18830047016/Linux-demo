#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
    //fork之前
    //打开一个文件
    int fd = open("io.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if(fd == -1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    char buffer[1024];//缓冲区
    pid_t pid =fork();
    if(pid < 0){
        perror("fork");
        close(fd);
        exit(EXIT_FAILURE);
    }else if(pid == 0){
        //子进程
        strcpy(buffer, "This is the child process.\n");
    }else{
        //父进程
       sleep(1);//确保子进程先写入
        strcpy(buffer, "This is the parent process.\n");
    }

    //父子进程都使用同一个文件描述符写入文件
    ssize_t bytes_written = write(fd, buffer, strlen(buffer));

    if(bytes_written == -1){
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Process %d wrote to file: %s", getpid(), buffer);
    
    //使用完毕后关闭文件描述符
    close(fd);

    if(pid==0){
        printf("Child process wrote to file finished,and the file descriptor is closed.\n");
    }else{
        printf("Parent process wrote to file finished,and the file descriptor is closed.\n");
    }

    return 0;
}