#include <stdio.h>

int main(void)
{
    int S[5]={35,23,64,34,16};
    int i,min,max;
    min=max=S[0];    /* let the first component of array be the maximum and minimum */

    for(i=0;i<5;i++)
    {
        if(S[i]>max)
            max=S[i];
	if(S[i]<min)
            min=S[i];
    }

    printf("the maximum component in this array is %d\n",max);
    printf("the minimum component in this array is %d\n",min);

    return 0;
}
