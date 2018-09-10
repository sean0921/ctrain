#include <stdio.h>

#define	MAX	10

int main(void)
{
    int score[MAX];
    int i=0,num;
    int sum=0;

    printf("Please input scores, input -1 to exit this program:\n");
    do
    {
        printf("Please input score:");
        scanf("%d",&score[i]);
    }while(score[i++]>=0);
    num=i-1;
    for(i=0;i<num;i++)
        sum+=score[i];
    printf("avg score is %.2f\n",(float)sum/num);
    return 0;
}
