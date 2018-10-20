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
    trans_mode = atoi(argv[1]);

    switch( trans_mode ) {
        case 1:
            for(i=0;i<32;i++) {
                printf("%c",argv[2][i]);
                thtw[i]=argv[2][i]-'0';
            }

            printf("\n");
            printf("interger: ");

            int a;

            for(i=0;i<32;i++) {
                //printf("%d",thtw[i]);
                
            }
           
            printf("\n");
            break;
        case 2:
            printf("case 2\n");
            break;
        case 3:
            printf("case 3\n");
            break;
        case 4:
            printf("case 4\n");
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

