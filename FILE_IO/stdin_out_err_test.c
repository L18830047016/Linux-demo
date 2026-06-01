#include <stdio.h>
#include <stdlib.h>

int main(){
    char* ch=malloc(100);
    //从标准输入中读取数据
    fgets(ch,100,stdin);
    printf("从标准输入中读取的数据是：%s\n",ch);

    //标准输出
    fputs(ch,stdout);
    printf("\n");

    //错误输出
    fputs(ch,stderr);
    printf("\n");

    free(ch);
    ch=NULL;
    return 0;
}