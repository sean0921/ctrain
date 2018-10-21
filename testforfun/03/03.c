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
    int exp_orig = -127;
    float exp = 1;
    int mantisa_orig[23];
    float mantisa_orig_flt[23];
    float mantisa_flt;
    int result_int = 0;
    float result_flt;
    int32_t input_int;
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
#ifdef DEBUG
            printf("\x1b[1;31mexp part: \x1b[m");
#endif
            for(i=0;i<8;i++) {
                exp_orig +=  thtw[i+1] << (7-i);
#ifdef DEBUG
                printf("\x1b[1;31m%d\x1b[m",thtw[i]);
#endif
            }
#ifdef DEBUG
            printf("\n");
            printf("\x1b[1;31mexp_orig: %d \x1b[m\n",exp_orig);
#endif
            if(exp_orig<0) {
                exp = 1 << ( 0 - exp_orig );
                exp = 1 / (float) exp;
            } else {
                exp = (float) (1 << exp_orig);
            }
#ifdef DEBUG
            printf("\x1b[1;31mexp: %f \n\x1b[m",exp);
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

            result_flt = mantisa_flt * exp * sign;
            printf("float: %f \n", result_flt);

            break;

        case 2:
            printf("case 2\n");
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
            printf("case 5\n");
            break;
        case 6:
            printf("case 6\n");
            break;
    }

    return 0;
}

