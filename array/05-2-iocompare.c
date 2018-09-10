#include <stdio.h>

int main(void)
{
    int S[6],i,j,k,min,max;

    for(i=0;i<6;i++)
    {
        printf("Please enter S[%d]:",i);
        scanf("%d",&S[i]);
    }

    printf("\n");

    for(j=0;j<6;j++)
    {
        printf("S[%d]=%d\n",j,S[j]);
    }

    printf("\n");
    min=max=S[0];   /* give a value */

    for(k=0;k<6;k++)
    {
        if(S[k]>max)
	{
            max=S[k];
	}
	if(S[k]<min)
	{
            min=S[k];
	}
    }

    printf("maximum value is: %d, minimux value is: %d.\n",max,min);
    return 0;
}
