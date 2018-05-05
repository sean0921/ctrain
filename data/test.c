#include <stdio.h>
#include <sys/stat.h> //mkdir()
#include <unistd.h>   //access()

int main(void)
{
    if( access("testtesttest", F_OK) != -1 )
    {
        printf("Directory Exists!\n");
    }
    else
    {
        mkdir("testtesttest",0700);
        printf("New Directory Maded!\n");
    }
    return 0;
}
