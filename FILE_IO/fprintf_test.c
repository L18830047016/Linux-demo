#include <stdio.h>



int main(int argc, char const *argv[])
{
        /**
     * const char *__restrict__ __filename:字符串表示要打开的文件名称
     * const char *__restrict__ __modes：访问模式
     * （1）r:只读模式，如果不存在报错
     * （2）w:只写模式，如果文件存在清空文件，如果不存在创建新文件
     * （3）a:只追加写模式，如果文件存在末尾追加写，如果文件不存在创建新文件
     * （4）r+：读写模式：文件必须存在，写入是从头一个一个覆盖
     * （5）w+：读写模式，如果文件存在清空文件，如果不存在创建新文件
     * （6）a+：读追加写模式，如果文件存在末尾追加写，如果文件不存在，创建新文件
     * return：FILE*结构体指针，表示一个文件
     *      报错返回NULL
     * 
     * FILE *fopen(const char *__restrict__ __filename, 
     * const char *__restrict__ __modes)
     */
    char *filename="io.txt";
    FILE* ioFile=fopen(filename,"a");
    if(ioFile==NULL){
        printf("failed 打开文件失败\n");
    }else{
        printf("success打开文件成功\n");
    }
/**
 * FILE *__restrict__ __stream:打开的文件
 * const char *__restrict__ __format：带格式化的长字符串
 * ...可变参数：填入格式化的长字符串
 * return:成功返回写入的字符的个数，不包括换行符，失败返回EOF
 * int fprintf(FILE *__restrict__ __stream, const char *__restrict__ __format, ...)
 */
    char *name="大海";
    int fprintfR=fprintf(ioFile,"诶呀\n东方\n升起\n\t\t%s",name);
    if(fprintfR==EOF){
        printf("写入失败\n");
    }else{
        printf("字符串%d写入成功\n",fprintfR);
    }
/**FILE *__stream:需要关闭的文件
 * return：成功返回0,失败返回EOF（负数）通常关闭文件失败会直接报错
 * 
 * int fclose (FILE *__stream)
 */
    int res=fclose(ioFile);
    if(res==EOF){
        printf("关闭文件失败\n");
    }else if(res==0){
        printf("关闭文件成功\n");
    }
    return 0;
}