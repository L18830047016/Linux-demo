#include <stdio.h>
#include <stdlib.h>

int main(){
    //使用标准库函数创建子进程
    /**
     * const char *command: 使用Linux命令直接创建一个子进程
     * 返回值：成功返回0；失败返回失败编号。
     * int system(const char *command);
     */
    //-c表示发送指定次数的ping请求
    //10表示发送10次ping请求
    int result = system("ping -c 10 www.baidu.com");
    if(result !=0){
        perror("system");
        exit(EXIT_FAILURE);
    }
    return 0;
}