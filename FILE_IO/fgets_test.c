#include <stdio.h>

int main(int argc, char const *argv[])
{
    //打开文件
    FILE* ioFile=fopen("io.txt","r");
    if(ioFile==NULL){
        printf("不能用只读模式打开不存在的文件\n");
    }
    //读取文件内容
    /**
     * char *__restrict__ __s:接收读取到的字符串
     * int __n：接收数据的长度
     * FILE *__restrict__ __stream：打开要读取的文件
     * return:成功返回字符 失败返回NULL 可以直接使用while
     * char *fgets(char *__restrict__ __s, int __n, FILE *__restrict__ __stream)
     */
    char buffer[100];
    while(fgets(buffer,sizeof(buffer),ioFile)){
        printf("%s",buffer);
    }

    
    //关闭文件
    int fcloseR=fclose(ioFile);
    if(fcloseR==EOF){
        printf("关闭文件失败\n");
    }else{
        printf("关闭文件成功\n");
    }
    return 0;
}
