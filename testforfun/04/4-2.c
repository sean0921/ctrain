//
// test case:
//
// python3 -c 'print ("3 "*100000 + "\n" + "3 "*100000)'|./a.out 3 100000
//

#include <stdio.h>
#include <stdlib.h>

#define ANSI_RED    "\x1b[1;31m"
#define ANSI_RESET  "\x1b[0m"

int i;

// usage: int check_argument(<number>)
// use it to specific
int check_arguments(int argnum, int num) {
    if (argnum != (num+1) ) {
        printf( ANSI_RED "Please input at least %d interger as arguments. :)" ANSI_RESET "\n",num);
        return -1;
    } else {
        return 0;
    }
}

int check_legal(int array[], int array_number, int max_integer, int legal_label) 
{
    for(i=0;i<array_number;i++) {
        if(array[i]>0) {
            if(array[i] <= max_integer) legal_label=1; 
            else {
                legal_label=0;
                break;
            }
        } else {
            legal_label=0;
            break;
        }
    }
    return legal_label;
}

#if 0
int compare_match(int* array1[], int* array2[], int* ish[], int* isx[], int array_position) {
        for(i=0;i<array_position;i++) {
            if(array1[i]==array2[i]) {
                h++;
                ish[i]=1;
                isx[i]=0;
            } else {
                ish[i]=0;
                isx[i]=0;
            }
        }
#endif

int main(int argc, char *argv[])
{

    int maxi, nop; 
    int legal=0; //max interger, number of position, if it is legal (1: true, 0: false)
    int arr[nop];

    if( check_arguments(argc,2) != 0) {
        return -1;
    }

/* using argc argv and "a to i" ways */
    maxi = atoi(argv[1]);
    nop = atoi(argv[2]);

    printf("You Set N = %d , P = %d \n", maxi, nop);

    while(1)
    {
        printf("ans: ");
        for(i=0;i<nop;i++) {
            scanf("%d",&arr[i]);
        }
    
        legal = check_legal(arr,nop,maxi,legal);
    
        if(legal==1) {
            break;
        } else {
            printf("The answer is illegal, please reset the answer.\n");
        }
    }
    
    int gus[nop];
    legal=0; //reset legal value for prepare checking next array
    
    while(1)
    {
        printf("guess: ");
        for(i=0;i<nop;i++) {
            scanf("%d",&gus[i]);
        }
    
        legal = check_legal(gus,nop,maxi,legal);
    
        if(legal==0) {
            printf("The answer is illegal, please reset the answer.\n");
            continue;
        }
    
        int h=0, x=0, ish[nop], isx[nop];
        int j;
    
//        compare_match(int array1[], int array2[], int array_position) {

#if 0
            int b;
            int a[10];
            a[0];
            *(a+0);
            a[1];
            (a+1)=&b;
#endif

//        h = compare_match_value(arr,gus,&ish,&isx,nop);
        for(i=0;i<nop;i++) {
            if(gus[i]==arr[i]) {
                h++;
                ish[i]=1;
                isx[i]=0;
            } else {
                ish[i]=0;
                isx[i]=0;
            }
        }
    
//        x = compare_nomatch_value(arr,gus,&ish,&isx,nop);
        for(i=0;i<nop;i++) {
            for(j=0;j<nop;j++) {
                if(gus[i]==arr[j] && ish[i]==0 && isx[i]==0 && ish[j]==0 && isx[j]==0 ) {
                    x++;
                    isx[j]=1;
                }
            }
        }
    
        printf("%dH %dX \n",h,x);
        if(h==nop) { 
            break;
        }
    }

    return 0;
}
