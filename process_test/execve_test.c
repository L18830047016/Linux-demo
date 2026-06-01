#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    //跳转之前
    char* name = "erlang";
    printf("我是%s，编号%d,我现在还在一楼！\n", name, getpid());

    //执行跳转
    /**
     * const char *pathname：要执行的程序的路径
     * char *const argv[]：一个字符串数组，对应执行程序main的第二个参数
     *      (1):第一个参数argv[0]通常是程序的名称->执行程序的路径
     *      (2):argv[1]、argv[2]等是传递给程序的参数，
     *      (3):必须以NULL结尾
     * char *const envp[]：一个字符串数组，包含了执行程序的环境变量
     *      (1):每个环境变量以"KEY=VALUE"的形式表示
     *      (2):必须以NULL结尾
     * return:成功时不返回，失败时返回-1
     * 跳转前后只有进程号不变，其他参数都被新程序替换掉了
     * int execve(const char *pathname, char *const argv[], char *const envp[]);
     */
    char* args[] = {"/home/lst/Linux/process_test/erlou",name, NULL}; //argv数组
    char* envs[] = {"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin", NULL}; //环境变量数组
     int re=execve(args[0], args, envs);
     if(re==-1){
        perror("execve");
        return 1;
     }

     //此处的代码不会被执行，因为execve成功后当前进程的代码会被新程序替换掉，只有当execve失败时才会继续执行下面的代码

    
    return 0;
}