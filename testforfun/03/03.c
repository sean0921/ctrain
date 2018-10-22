#include <stdio.h>
#include <stdlib.h> // atoi(),
#include <unistd.h> // sleep(),

//#define DEBUG

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Please input at least 2 interger as arguments. :)\x1b[0m\n");
        return 0;
    }

    int trans_mode; // mode, M=1~6
    int i,j;
    int thtw[32];
    unsigned long long sxfr[64];
    int sign;
    int exponent_orig = -127;
    float exponent = 1;
    int mantisa_orig[23];
    float mantisa_orig_float[23];
    float mantisa_float;
    unsigned int result_int = 0;
    unsigned long long result_int64 = 0;
    float result_float;
    int32_t input_int32;
    int64_t input_int64;
    float input_float;
    double input_double;
    int result_thtw[32];
    int result_sxfr[64];
    
    trans_mode = atoi(argv[1]);

    switch( trans_mode ) {
        case 1:
            /* calculate decimal integer first */
            for(i=0;i<32;i++) {
                thtw[i]=argv[2][i]-'0';
                result_int += thtw[i] << (31-i);
            }
            printf("interger: %d\n", result_int);
            float trans_bits_float;
            trans_bits_float = *((float*)&result_int);
            printf("float: %f\n", trans_bits_float);
            break;

        case 2:
            input_int32 = atoi(argv[2]);
            printf("32-bit: ");
            for(i=0;i<32;i++) {
                j = input_int32 >> (31-i);
                if(j & 1) {
                    printf("1");
                } else {
                    printf("0");
                }
            }
            printf("\n");
            break;
        case 3:
            input_float = atof(argv[2]);
            printf("32-bit: ");
            int32_t trans_bits;
            trans_bits = *((int32_t*)&input_float);
            for(i=0;i<32;i++) {
                j = trans_bits >> (31-i);
                if(j & 1) {
                    printf("1");
                } else {
                    printf("0");
                }
            }
            printf("\n");
            break;
        case 4:
            /* calculate decimal integer first */
            for(i=0;i<64;i++) {
                sxfr[i]=argv[2][i]-'0';
                result_int64 += sxfr[i] << (63-i);
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
                if(j & 1) {
                    printf("1");
                } else {
                    printf("0");
                }
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
                if(j & 1) {
                    printf("1");
                } else {
                    printf("0");
                }
            }
            printf("\n");
            break;
    }

    return 0;
}

