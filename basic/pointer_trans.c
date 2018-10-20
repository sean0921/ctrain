#include <stdio.h>

int main(void) {
    float a = 111;
    int *x;
    x = &a;
    int* x2 = &a;
    int y = (int)(a);
    printf("float value = %f, address = %d, integer value = %d\n",a, x, *x);
    printf("float value = %f, address = %d, integer value = %d\n",a, x2, *x2);
    printf("float value = %f, address = %d, integer value = %d\n",a, &y, y);
    return 0;
}
