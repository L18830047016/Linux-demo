#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int num=0;

int main(int argc,char const *argv[]){
    __pid_t pid=fork();
    if(pid<0){
        perror("fork error");
        exit(EXIT_FAILURE);
    }else if(pid==0){
        //child process
        num=1;
        printf("child process num=%d\n",num);
    }else{
        //parent process
        sleep(1);
        printf("parent process num=%d\n",num);
    }
    return 0;
}