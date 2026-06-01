#include <unistd.h>
#include<fcntl.h>

int main(){
    /**
     * const char *__file:字符串表示要打开的文件名称
     * int __oflag:打开文件模式
     * （1）O_RDONLY:只读模式
     * （2）O_WRONLY:只写模式
     * （3）O_RDWR:读写模式
     * （4）O_APPEND:追加写模式
     * （5）O_CREAT:如果文件不存在则创建新文件
     * （6）O_TRUNC:如果文件存在则清空文件
     * ...可变参数：当使用O_CREAT模式时，必须提供第三个参数mode_t mode，表示新文件的权限，eg：0644,表示所有者可读写，组用户和其他用户可读
     * return：成功返回一个非负整数，表示文件描述符；失败返回-1，并设置全局变量errno以指示错误类型
     * int open(const char *__file, int __oflag, ...)
     */
    //Linux操作系统有文件保护权限，默认创建文件会被删除掉其他用户的写权限

    int fd = open("io1.txt",O_RDONLY|O_CREAT,0666);
    if(fd==-1){
        printf("failed 打开文件失败\n");
    }else{
        printf("success打开文件成功\n");
    }
}