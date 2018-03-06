#include <stdio.h>

int main(void)
{
    int k = 3, k0 = 3;            /* Initial Value */
    int sum = 20;                 /* Initial Value */
    int max = 60;
    while(sum <= max)
    {
        sum = sum + k;
	printf("from number %d add to %d is %d\n",k0,k,sum);
	k = k + 1 ;
    }
    printf("must add to %d that sum will larger than %d\n", k-1, max);
    return 0;
}

