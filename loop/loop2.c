#include <stdio.h>
#include <stdlib.h>          /* rand() is declared in here */

int main(void)
{
    int k;
    int counttime = 0;

    for(k=1;k<=100000;k=k+1)
        if ((rand()%6+1)==3)
            counttime = counttime + 1 ;

    printf("dice %d times, showing three %d times.\n",k,counttime);
    printf("the probability is %.3f\n", (float)counttime/k);

    return 0;
}
