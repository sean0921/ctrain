#include <stdio.h>

int test3(void)
{
    int i;
    for(i=1;i<=10;i++)
    {
        printf("\x1b[5;1;%dm%d\x1b[m\n",(i%7)+30,i*i);
    }
    return 0;
}

