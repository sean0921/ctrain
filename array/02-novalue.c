#include <stdio.h>

int main(void)
{
    int i, score[5];

    score[0]=65;
    score[1]=55;
//    score[2]=43; /* try not to give value here */
    score[3]=77;
    score[4]=100;

    for(i=0;i<=5;i++) /* try add more out of range of i array */
        printf("score[%d]=%d\n",i,score[i]);

    return 0;
}
