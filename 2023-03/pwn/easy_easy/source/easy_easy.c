#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stderr, 0LL, 2, 0LL);
    char *flag = malloc(0x400000);
    *flag = 1;
    printf("%p\n",flag);
    unsigned long  nameLength;
    puts("Please input your name length");
    scanf("%lu", &nameLength);
    puts("Please input your name then you can get flag");
    char *name = malloc(nameLength);
    read(0, name, nameLength-1);
    name[nameLength-1] = '\x00';
    if(!(*flag)){
        system("/bin/sh\x00");
    }
    puts("So pitty you not get flag");
    return 0;
}
