#include<stdio.h>
#include<stdlib.h>

#define ANSI_RED    "\x1b[1;31m"
#define ANSI_RESET  "\x1b[0m"

int check_arguments(int argnum, int num);

int main(int argc, char* argv[])
{
    if(check_arguments(argc,4)!=0) return -1;

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

// usage: check_argument(<number>)
// use it to specific argument number is correct
/* 若使用者在程式後加的參數並非四個，則程式終止 */
int check_arguments(int argnum, int num)
{
    if (argnum != (num+1) ) {
        printf( ANSI_RED "Please input at least %d interger as arguments. :)" ANSI_RESET "\n",num);
        return -1;
    } else {
        return 0;
    }
}
