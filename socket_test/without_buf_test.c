#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    FILE* file=fopen("/home/lst/Linux/socket_test/testfile.txt","w");
    if(file==NULL){
        perror("fopen");
        return 1;
    }

    //修改刷写模式
    if(setvbuf(file,NULL,_IOLBF,0)!=0){
        perror("setbvf");
    }
    //文件写入默认是全缓冲，等待缓冲区满或手动刷写
    fprintf(file,"hello\n");
    // //可以使用手动刷写
    // fflush(file);

    char* args[]={"/usr/bin/ping","-c","10","www.baidu.com",NULL};
    char* envs[]={NULL};
    execve(args[0],args,envs);//进程跳转，通过观测是否成功写入文件数据，验证各个缓冲模式

    //如果跳转失败
    perror("execve");

    return 0;
}
