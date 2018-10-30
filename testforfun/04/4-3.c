/*******************************************************************************
* encoding: UTF-8
* 編譯方式：gcc -o hw4_3 hw4_3.c
* 執行方式：./hw4_3 <第M個模式> <32/64 bit pattern或整數或浮點數>
* 程式功能：將 32/64 bit pattern 與 整數/浮點數 互相轉換
********************************************************************************/

#include <stdio.h>
#include <stdlib.h> // atoi(),
#include <stdint.h>

#define ANSI_RED    "\x1b[1;31m"
#define ANSI_RESET  "\x1b[0m"

int i,j;

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

// usage: check_last_bit32(<integer>)
// use it to check last bit of binary number is correct
void check_last_bit32(uint32_t integer_pattern)
{
    if(integer_pattern & 1) {
        printf("1");
    } else {
        printf("0");
    }
}

// usage: check_last_bit(<integer>)
// use it to check last bit of binary number is correct
void check_last_bit64(uint64_t integer_pattern)
{
    if(integer_pattern & 1) {
        printf("1");
    } else {
        printf("0");
    }
}

// usage: trans_bits_work32(<variable>)
// use it to trans input variable to bit pattern
void trans_bits_work32(uint32_t a)
{
    for(i=0;i<32;i++) {
        j = a >> (31-i);
        check_last_bit32(j);
    }
}


// usage: trans_bits_work64(<variable>)
// use it to trans input variable to bit pattern
void trans_bits_work64(uint64_t a)
{
    for(i=0;i<64;i++) {
        j = a >> (63-i);
        check_last_bit64(j);
    }
}

// usage: trans_bit_to_int_float(<argument(argv[number])>)
// use it to trans bit pattern to integer or float variable
void trans_bit_to_int_float(char* argument)
{
    uint32_t result_int = 0;
    float trans_bits_float;
    /* calculate decimal integer first */
    for(i=0;i<32;i++) result_int += (argument[i]-'0') << (31-i);
    trans_bits_float = *((float*)&result_int);
    printf("interger: %d\n", result_int);
    printf("float: %f\n", trans_bits_float);
}

// usage: trans_bit_to_int_double(<argument(argv[number])>)
// use it to trans bit pattern to integer or double variable
void trans_bit_to_int_double(char* argument)
{
    uint64_t result_int = 0;
    double trans_bits_double;
    /* calculate decimal integer first */
    for(i=0;i<64;i++) result_int += (argument[i]-'0') << (63-i);
    trans_bits_double = *((double*)&result_int);
    printf("interger: %lu\n", result_int);
    printf("double: %lf\n", trans_bits_double);
}

// usage: trans_bit_to_int_float(<argument(argv[number])>)
// use it to check last bit of binary number is correct
void trans_int_to_bit32(char* argument)
{
    uint32_t input_int;
    input_int = atoi(argument);
    printf("32-bit: ");
    trans_bits_work32(input_int);
    printf("\n");
}

void trans_int_to_bit64(char* argument)
{
    uint64_t input_int;
    input_int = atoi(argument);
    printf("64-bit: ");
    trans_bits_work64(input_int);
    printf("\n");
}

// usage: int trans_bit_to_int_float(<argument(argv[number])>)
// use it to check last bit of binary number is correct
void trans_float_to_bit(char* argument)
{
    float input_float;
    uint32_t trans_bits;
    input_float = atof(argument);
    printf("32-bit: ");
    trans_bits = *((uint32_t*)&input_float);
    trans_bits_work32(trans_bits);
    printf("\n");
}

// usage: int trans_bit_to_int_float(<argument(argv[number])>)
// use it to check last bit of binary number is correct
void trans_double_to_bit(char* argument)
{
    double input_double;
    uint64_t trans_bits64;
    input_double = atof(argument);
    printf("64-bit: ");
    trans_bits64 = *((uint64_t*)&input_double);
    trans_bits_work64(trans_bits64);
    printf("\n");
}

int main(int argc, char *argv[])
{
    int trans_mode; // mode, M=1~6
    
    if(check_arguments(argc,2)!=0) return -1;
    trans_mode = atoi(argv[1]);
    switch( trans_mode )
    {
        case 1:
            trans_bit_to_int_float(argv[2]);
            break;
        case 2:
            trans_int_to_bit32(argv[2]);
            break;
        case 3:
            trans_float_to_bit(argv[2]);
            break;
        case 4:
            trans_bit_to_int_double(argv[2]);
            break;
        case 5:
            trans_int_to_bit64(argv[2]);
            break;
        case 6:
            trans_double_to_bit(argv[2]);
            break;
    }
    return 0;
}
