#include <stdio.h>

int main(int argc, char *argv[]) {
    fopen("nonexistent_file.txt", "r");

    perror("This is an error message");
    return 0;
}