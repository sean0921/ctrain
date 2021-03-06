#include<stdio.h>
#include<stdlib.h>

#define ANSI_RED    "\x1b[1;31m"
#define ANSI_RESET  "\x1b[0m"
#define MAX_NUMBER (100)
#define OUTPUT_FILEMANE "05.out"

int check_arguments(int argnum, int num);
int bucket_union(unsigned int bucket_item, unsigned int bucker_size, unsigned int max_number, unsigned int seed, unsigned int array[][MAX_NUMBER]);

int main(int argc, char* argv[])
{
    if(check_arguments(argc,4)!=0) return -1;

    int i,j;
    unsigned int n, m, d, s;
    unsigned int array1[MAX_NUMBER][MAX_NUMBER];

    n = atoi(argv[1]);
    m = atoi(argv[2]);
    d = atoi(argv[3]);
    s = atoi(argv[4]);

    printf("n=%d, m=%d, d=%d, s=%d \n\n", n, m, d, s);

    bucket_union(n,m,d,s,array1);
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


int bucket_union(unsigned int bucket_item, unsigned int bucker_size, unsigned int max_number, unsigned int seed, unsigned int array[][MAX_NUMBER])
{
    int i,j;
    int generate_number_of_elements_in_a_bucket;
    int generate_a_random_num;
    FILE* file;

    srand(seed);
    file = fopen(OUTPUT_FILEMANE,"w");

    printf("\n%d\n\n",bucker_size);
    fprintf(file,"%d\n\n",bucker_size);
    for(i=0;i<bucket_item;i++) {
        printf("%2d / ",i);
        fprintf(file,"%2d / ",i);
        generate_number_of_elements_in_a_bucket = (rand()%bucker_size) + 1;
        //printf("generate_number_of_elements_in_a_bucket: %d \n", generate_number_of_elements_in_a_bucket);
        for(j=0;j<generate_number_of_elements_in_a_bucket;j++) {
            generate_a_random_num = (rand()%max_number);
            //printf("generate_a_random_num: %d \n", generate_a_random_num);
            array[i][j] = generate_a_random_num;
            printf("%d ",array[i][j]);
            fprintf(file,"%d ",array[i][j]);
        }
        printf("\n");
        fprintf(file,"\n");
    }
    fclose(file);
}
