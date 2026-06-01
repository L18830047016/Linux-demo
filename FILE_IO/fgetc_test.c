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
     * FILE *__stream:打开的文件
     * return: 读取到的第一个字节，如果出错或者到文件的末尾EOF
     * int fgetc(FILE *__stream)
     */
    char c=fgetc(ioFile);
    while(c!=EOF){
       printf("%c",c); 
       c=fgetc(ioFile);
    }
    printf("\n");
    
    //关闭文件
    int fcloseR=fclose(ioFile);
    if(fcloseR==EOF){
        printf("关闭文件失败\n");
    }else{
        printf("关闭文件成功\n");
    }
    return 0;
}
