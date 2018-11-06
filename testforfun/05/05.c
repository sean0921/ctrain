#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    int n, m, d, s;
    int generate_number_of_elements_in_a_bucket;
    int generate_a_random_num;

    n = atoi(argv[1]);
    m = atoi(argv[2]);
    d = atoi(argv[3]);
    s = atoi(argv[4]);

    printf("n=%d, m=%d, d=%d, s=%d \n", n, m, d, s);
    srand(s);
    generate_number_of_elements_in_a_bucket = (rand()%m) + 1;
    printf("generate_number_of_elements_in_a_bucket: %d \n", \
    generate_number_of_elements_in_a_bucket);
    generate_a_random_num = (rand()%d);
    printf("generate_a_random_num: %d \n", generate_a_random_num);
    return 0;
}
