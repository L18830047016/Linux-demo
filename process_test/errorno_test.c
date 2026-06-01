#include <stdio.h>
#include <errno.h>

int main(int argc,char *argv[]) {
    fopen("/opt","a+");
    printf("errno: %d\n", errno);
    perror("Error message");
    return 0;
}