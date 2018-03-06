/* loop1.c: for loop */
#include <stdio.h>
int main(void)
{
    int k, sum=0;
    for(k=0;k<=65535;k=k+1)
        sum = sum + k;
    printf("0+1+...65535=%d\n",sum);

    return 0;
}
