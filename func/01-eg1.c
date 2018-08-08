#include <stdio.h>
void sharp(void);

int main(void)
{
    sharp();
    printf("\x1b[1;31mWelcome to test this program!!\x1b[m\n");
    sharp();
    return 0;
}

void sharp(void)
{
    printf("********************************\n");
    return;	
}
