#include <stdio.h>
#include <stdlib.h> // atoi(),

#define ANSI_RED    "\x1b[1;31m"
#define ANSI_RESET  "\x1b[0m"

int i,j;

// usage: int check_argument(<number>)
// use it to specific
int check_arguments(int argnum, int num)
{
    if (argnum != (num+1) ) {
        printf( ANSI_RED "Please input at least %d interger as arguments. :)" ANSI_RESET "\n",num);
        return -1;
    } else {
        return 0;
    }
}

int check_last_bit(int bitnum)
{
    if(bitnum & 1) {
        printf("1");
    } else {
        printf("0");
    }
}

int trans_bit_to_int_float(char* argument, int bits)
{
    unsigned int result_int = 0;
    float trans_bits_float;
    /* calculate decimal integer first */
    for(i=0;i<bits;i++) result_int += (argument[i]-'0') << (bits-i-1);
    trans_bits_float = *((float*)&result_int);
    printf("interger: %d\n", result_int);
    printf("float: %f\n", trans_bits_float);
}

int trans_int_to_bit(char* argument, int bits)
{
    long long int input_int;
    input_int = atoi(argument);
    printf("%d-bit: ", bits);
    for(i=0;i<bits;i++) {
        j = input_int >> (bits-1-i);
        check_last_bit(j);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int trans_mode; // mode, M=1~6
    unsigned long long result_int64 = 0;
    float input_float;
    double input_double;
    
    if(check_arguments(argc,2)!=0) return -1;

    trans_mode = atoi(argv[1]);

    switch( trans_mode )
    {
        case 1:
            trans_bit_to_int_float(argv[2],32);
            break;

        case 2:
            trans_int_to_bit(argv[2],32);
            break;
        case 3:
            input_float = atof(argv[2]);
            printf("32-bit: ");
            int32_t trans_bits;
            trans_bits = *((int32_t*)&input_float);
            for(i=0;i<32;i++) {
                j = trans_bits >> (31-i);
                check_last_bit(j);
            }
            printf("\n");
            break;
        case 4:
            /* calculate decimal integer first */
            for(i=0;i<64;i++) {
                result_int64 += (argv[2][i]-'0') << (63-i);
            }
            printf("interger: %llu\n", result_int64);
            double trans_bits_double;
            trans_bits_double = *((double*)&result_int64);
            printf("double: %lf\n", trans_bits_double);
            break;

        case 5:
            input_int64 = atoi(argv[2]);
            printf("64-bit: ");
            for(i=0;i<64;i++) {
                j = input_int64 >> (63-i);
                check_last_bit(j);
            }
            printf("\n");
            break;
        case 6:
            input_double = atof(argv[2]);
            printf("64-bit: ");
            unsigned long long trans_bits64;
            trans_bits64 = *((unsigned long long*)&input_double);
            for(i=0;i<64;i++) {
                j = trans_bits64 >> (63-i);
                check_last_bit(j);
            }
            printf("\n");
            break;
    }

    return 0;
}

