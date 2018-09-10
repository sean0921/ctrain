#include <stdio.h>

int main(void)
{
    double data[4];  /* declare */
    printf("size of component of array: %ld\n",sizeof(data[0]));
    printf("size of whole array: %ld\n",sizeof(data));
    printf("how many components in an array: %ld\n",sizeof(data)/sizeof(double));

    return 0;
}
