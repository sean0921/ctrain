#include <stdio.h>

int main(void) {
    float a = 111;
    int *x;
    x = &a;
    printf("test %d %d\n",x, *x);
    return 0;
}
