#include <stdio.h>
#include <stdlib.h> // atoi(), 

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("\x1b[1;31mPlease input at least 2 interger as arguments. :)\x1b[0m\n");
        return 0;
    }

    int trans_mode; // mode, M=1~6
    int i,j;
    int thtw[32];
    int sxfr[32];
    int first_int;
    trans_mode = atoi(argv[1]);

    switch( trans_mode ) {
        case 1:
/*
            for(i=0;i<32;i++) {
                printf("%c",argv[2][i]);
                thtw[i]=argv[2][i]-'0';
            }
            printf("\n");
*/
            printf("interger: ");

            for(i=0;i<32;i++) {
                first_int += thtw[i] << (31-i);    
            }
            printf("%d", first_int);
            printf("\n");

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
                first_int += sxfr[i] << (63-i);    
            }
            printf("%d", first_int);
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

