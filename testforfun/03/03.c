#include <stdio.h>
#include <stdlib.h> // atoi(),
#include <unistd.h> // sleep(),

//#define DEBUG

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("\x1b[1;31mPlease input at least 2 interger as arguments. :)\x1b[0m\n");
        return 0;
    }

    int trans_mode; // mode, M=1~6
    int i,j;
    int thtw[32];
    int sxfr[64];
    int exponent_orig = -127;
    float exponent = 1;
    int mantisa_orig[23];
    float mantisa_orig_flt[23];
    float mantisa_flt;
    int result_int = 0;
    float result_flt;
    int32_t input_int32;
    int64_t input_int64;
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

            /* calculate float */
            /* calculate exponent part */
#ifdef DEBUG
            printf("\x1b[1;31mexponent part: \x1b[m");
#endif
            for(i=0;i<8;i++) {
                exponent_orig +=  (thtw[i+1] << (7-i));
#ifdef DEBUG
                printf("\x1b[1;31m%d\x1b[m",thtw[i+1]);
#endif
            }
#ifdef DEBUG
            printf("\n");
            printf("\x1b[1;31mexponent_orig: %d \x1b[m\n",exponent_orig);
#endif

            if(exponent_orig<0) {
                exponent = 1 << ( 0 - exponent_orig );
                exponent = 1 / ( (float) exponent );
            } else {
                exponent = (float) (1 << exponent_orig);
            }

#ifdef DEBUG
            printf("\x1b[1;31mexponent: %f \n\x1b[m",exponent);
#endif

            for(i=0;i<23;i++) {
                mantisa_orig[i] =  thtw[i+9] << (i+1);
                if(mantisa_orig[i]!=0) {
                    mantisa_orig_flt[i] = 1 / (float)(mantisa_orig[i]);
                } else {
                    mantisa_orig_flt[i] = 0;
                }
#ifdef DEBUG
                printf("\x1b[1;31m%f \x1b[m",mantisa_orig_flt[i]);
#endif
                mantisa_flt += mantisa_orig_flt[i];
            }
#ifdef DEBUG
            printf("\n\x1b[1;31mmantisa_flt = %f\x1b[m \n", mantisa_flt);
#endif

            int sign;
            if(thtw[0]==1){
                sign = -1;
            } else {
                sign = 1;
            }

            result_flt = ( 1.000 + mantisa_flt ) * exponent * sign;
            printf("float: %f \n", result_flt);

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
            printf("case 3\n");
            break;
        case 4:
            for(i=0;i<64;i++) {
                sxfr[i]=argv[2][i]-'0';
            }
            printf("interger: ");

            for(i=0;i<64;i++) {
                result_int += sxfr[i] << (63-i);
            }
            printf("%d", result_int);
            printf("\n");
            break;
        case 5:
            input_int64 = atoi(argv[2]);
            printf("64-bit: ");
            for(i=0;i<63;i++) {
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
            printf("case 6\n");
            break;
    }

    return 0;
}

