#include <stdio.h>

int main(void)
{
    int i,yaya[6];
    for(i=0;i<6;i=i+1)
    {
        printf("Please enter value of yaya[%d]:",i);
	scanf("%d",&yaya[i]);
    }
    for(i=0;i<6;i=i+1)
        printf("yaya[%d]=%d\n",i,yaya[i]);

    return 0;
}
