#include <stdio.h>

int add_two(int *a) {
    *a = *a + 2;
    printf("num: %d\n", *a);
}

//int array_add_two (int *array)

int main(void) {
    int a;

    a = 5;

    printf("a: %d\n", a);

    add_two(&a);

    printf("a after add_two: %d\n", a);
    return 0;
}
