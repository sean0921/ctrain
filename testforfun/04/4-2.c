//
// test case:
//
// python3 -c 'print ("3 "*100000 + "\n" + "3 "*100000)'|./a.out 3 100000
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //for sleep() function

#define ANSI_RED    "\x1b[1;31m"
#define ANSI_RESET  "\x1b[0m"

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

int main(int argc, char *argv[])
{

    if( check_arguments(argc,2) != 0) {
        return -1;
    }

    int maxi, nop, legal=0; //max interger, number of position, if it is legal (1: true, 0: false)
    int arr[nop];
    int i;

/* using argc argv and "a to i" ways */
    maxi = atoi(argv[1]);
    nop = atoi(argv[2]);

    printf("You Set N = %d , P = %d \n", maxi, nop);

while(1)
{
    printf("ans: ");
    for(i=0;i<nop;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<nop;i++)
    {
        if(arr[i]>0)
        {
            if(arr[i]<=maxi)
            {
                legal=1;
#ifdef DEBUG
                printf("legal: %d\n",legal);
                sleep(1);
#endif
            }
            else
            {
                legal=0;
#ifdef DEBUG
                printf("legal: %d\n",legal);
                sleep(1);
#endif
                break;
            }
        }
        else
        {
            legal=0;
#ifdef DEBUG
            printf("legal: %d\n",legal);
            sleep(1);
#endif
            break;
        }
    }

#ifdef DEBUG
    printf("so legel: %d\n",legal);
    sleep(1);
#endif

    if(legal==1)
    {
        break;
    }
    else
    {
        printf("The answer is illegal, please reset the answer.\n");
        fflush(stdin);
    }
}

#ifdef DEBUG
    printf("ok! ans: ");
    for(i=0;i<nop;i++)
        printf("%d ",arr[i]);
        sleep(1);
    printf("\n");
#endif

int gus[nop];
legal=0; //reset legal value for prepare checking next array

while(1)
{
    printf("guess: ");
    for(i=0;i<nop;i++)
    {
        scanf("%d",&gus[i]);
    }

    for(i=0;i<nop;i++)
    {
        if(gus[i]>0)
        {
            if(gus[i]<=maxi)
            {
                legal=1;
#ifdef DEBUG
                printf("legal: %d\n",legal);
                sleep(1);
#endif
            }
            else
            {
                legal=0;
#ifdef DEBUG
                printf("legal: %d\n",legal);
                sleep(1);
#endif
                break;
            }
        }
        else
        {
            legal=0;
#ifdef DEBUG
            printf("legal: %d\n",legal);
            sleep(1);
#endif
            break;
        }
    }

#ifdef DEBUG
    printf("so legel: %d\n",legal);
#endif

    if(legal==0)
    {
        printf("The answer is illegal, please reset the answer.\n");
        continue;
    }

    int h=0, x=0, ish[nop], isx[nop];
    int j;

    for(i=0;i<nop;i++)
    {
        if(gus[i]==arr[i])
        {
            h++;
            ish[i]=1;
            isx[i]=0;
        }
        else
        {
            ish[i]=0;
            isx[i]=0;
        }
    }

    for(i=0;i<nop;i++)
    {
        for(j=0;j<nop;j++)
        {
#ifdef DEBUG
            printf("gus[%d]=%d, arr[%d]=%d, ish[%d]=%d, isx[%d]=%d.\n",i, gus[i], j, arr[j], j, ish[j], j, isx[j]);
            sleep(1);
#endif
            if(gus[i]==arr[j] && ish[i]==0 && isx[i]==0 && ish[j]==0 && isx[j]==0 )
            {
                x++;
                isx[j]=1;
            }
        }
    }

    printf("%dH %dX \n",h,x);
#ifdef DEBUG
    printf("well, ans: ");
    for(i=0;i<nop;i++)
        printf("%d ",arr[i]);
        sleep(1);
    printf("\n");
#endif

    if(h==nop)
    { 
        break;
    }
}

    return 0;
}

