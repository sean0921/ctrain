#include <stdio.h>

int test2(void)
{
    int i;
    for(i=1;i<=10;i++)
    {
        printf("\x1b[1;%dm%d\x1b[m\n",(i%7)+30,i);
    }
    return 0;
}

