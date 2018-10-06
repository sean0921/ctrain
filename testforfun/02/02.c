//
// test case:
//
// python3 -c 'print ("3 "*100000 + "\n" + "3 "*100000)'|./a.out 3 100000
//

#include <stdio.h>
#include <stdlib.h>

//#define DEBUG  //temporary use printf() function to detect the value

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("\x1b[1;31mPlease input at least 2 interger as arguments. :)\x1b[0m\n");
        return 0;
    }

    int maxi, nop, legal=0; //max interger, number of position, if it is legal (1: true, 0: false)

/* using argc argv and "a to i" ways */
    maxi = atoi(argv[1]);
    nop = atoi(argv[2]);

    printf("You Set N = %d , P = %d \n", maxi, nop);

    int arr[nop-1];
    int i;

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
#endif
            }
            else
            {
                legal=0;
#ifdef DEBUG
                printf("legal: %d\n",legal);
#endif
                break;
            }
        }
        else
        {
            legal=0;
#ifdef DEBUG
            printf("legal: %d\n",legal);
#endif
            break;
        }
    }

#ifdef DEBUG
    printf("so legel: %d\n",legal);
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
    printf("array: ");
    for(i=0;i<nop;i++)
        printf("%d ",arr[i]);
    printf("\n");
#endif

int gus[nop-1];
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
#endif
            }
            else
            {
                legal=0;
#ifdef DEBUG
                printf("legal: %d\n",legal);
#endif
                break;
            }
        }
        else
        {
            legal=0;
#ifdef DEBUG
            printf("legal: %d\n",legal);
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

    int h=0, x=0;

    for(i=0;i<nop;i++)
    {
        if(gus[i]==arr[i])
        {
            h++;
        }
        else
        {
            x++;
        }
    }
    printf("%dH %dX \n",h,x);
    if(h==nop)
    { 
        break;
    }
}

    return 0;
}

