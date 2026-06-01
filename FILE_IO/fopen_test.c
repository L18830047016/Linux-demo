#include <stdio.h>


int main(int argc, char const *argv[]) {

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
    FILE* ioFile=fopen(filename,"w");
    if(ioFile==NULL){
        printf("failed 打开文件失败\n");
    }else{
        printf("success打开文件成功\n");
    }

    return 0;
}