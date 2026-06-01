#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    //打开文件
    int fd=open("io.txt",O_RDONLY);
    if(fd==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    /**
     * int fd:文件描述符
     * void* buf:存放数据的缓冲区
     * size_t count:要读取的字节数
     * return:成功返回实际读取的字节数，失败返回-1
     * ssize_t read(int fd, void *buf, size_t count);
     */
    ssize_t bytes_read;
    while((bytes_read=read(fd,buffer,sizeof(buffer)))>0){
        //文件描述符类型的stdin->0
        //stdout->1
        //stderr->2
        /**
         * int fd:文件描述符
         * const void* buf:要写出的数据缓冲区
         * size_t count:要写出的字节数
         * return:成功返回实际写出的字节数，失败返回-1
         * ssize_t write(int fd, const void *buf, size_t count);
         */
        write(STDOUT_FILENO, buffer, bytes_read);
        
    }  
    if(bytes_read==-1){
        perror("read");
        /**
         * 关闭打开的文件描述符
         * int fd:文件描述符          * return:成功返回0，失败返回-1
          * int close(int fd); 
         */
        close(fd);
        exit(EXIT_FAILURE);
    }
    //关闭文件描述符
    close(fd);
    return 0;
}