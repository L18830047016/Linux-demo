#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char const* argv[]){
    //邀请之前
    char* name = "erlang";
    printf("%s %d继续在一楼吃饭\n",name,getpid());

    //邀请之后
    pid_t pid = fork();
    if(pid < 0){
        perror("fork error");
        return 1;
    }else if(pid == 0){
        //新学生
        char* new_name = "ergou";
        char* args[]={"/home/lst/process_test/erlou",new_name,NULL};
        char* envs[]={NULL};
        int exR=execve(args[0],args,envs);
        if(exR==-1){
            perror("execve error");
            return 1;
        }
    }else{
        //老学生
        printf("%s %d继续在一楼吃饭\n",name,getpid());
        //永久挂起，等待输入一个字符后才结束
        char by= fgetc(stdin);
    }
    return 0;
} 