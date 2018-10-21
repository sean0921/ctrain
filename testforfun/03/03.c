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
    int sxfr[32];
    int exp_orig = -127;
    float exp = 1;
    int result_int = 0;
    float result_flt = 0;
    trans_mode = atoi(argv[1]);

    switch( trans_mode ) {
        case 1:
            for(i=0;i<32;i++) {
                thtw[i]=argv[2][i]-'0';
            }

#ifdef DEBUG
            for(i=0;i<32;i++) {
                printf("%d",thtw[i]);
            }
            printf("\n");
#endif

            printf("interger: ");
#ifdef DEBUG
            printf("\n");
#endif
            for(i=0;i<32;i++) {
                result_int += thtw[i] << (31-i);
#ifdef DEBUG
                printf("\x1b[1;31mresult: %d\x1b[0m\n",result_int);
#endif
            }
            printf("%d\n", result_int);

            printf("float: ");
            for(i=1;i<=8;i++) {
                exp_orig +=  thtw[i] << (9-i);
#ifdef DEBUG
                printf("\x1b[1;31morig exp: %d\x1b[0m\n",exp_orig);
#endif
            }
            printf("\n");
#ifdef DEBUG
            for(i=1;i<=8;i++) {
                printf("\x1b[1;31m%d\x1b[m",thtw[i]);
            }
            printf("\n");
            exp = 1 << exp_orig;
            printf("2 ^ %d = %f\n",exp_orig,exp);
#endif

            break;
        case 2:
            printf("case 2\n");
            break;
        case 3:
            printf("case 3\n");
            break;
        case 4:
/*
            for(i=0;i<64;i++) {
                printf("%c",argv[2][i]);
                sxfr[i]=argv[2][i]-'0';
            }
            printf("\n");
*/
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

