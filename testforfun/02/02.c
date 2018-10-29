/*******************************************************************************
* encoding: UTF-8
* 編譯方式：gcc -o hw2 hw2.c
* 執行方式：./hw2
* 程式功能：猜數字遊戲
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//#define DEBUG  /* 定義除錯模式 */

#ifdef DEBUG
#include <unistd.h>  /* 除錯模式中 sleep() 函數會用到 */
#endif

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("\x1b[1;31mPlease input at least 2 interger as arguments. :)\x1b[0m\n");
        return 0;
    }

    int maxi, nop, legal=0; /* 最大整數, 可填入整數的空位, 數值是否合法 */

/* 將參數字串轉換成整數形態 */
    maxi = atoi(argv[1]);
    nop = atoi(argv[2]);

    printf("You Set N = %d , P = %d \n", maxi, nop);

    int arr[nop];
    int i;

/* 製作迴圈, 條件成立後才可離開 */
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
legal=0; /* 重新假設答案都不合法, 直到確定合法 */

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

/* 先判斷同位置數值是否一樣, 即完全猜對 */
    for(i=0;i<nop;i++)
    {
        if(gus[i]==arr[i])
        {
            h++;
            ish[i]=1; /* 若猜對, 給其判斷陣列該位置 1 的值 */
            isx[i]=0; /* 不論如何先填 0 在下一個才要用到的判斷陣列 */
        }
        else
        {
            ish[i]=0; /* 不對的話則給0 */
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
/* 排除掉重複, 已經符合 h 條件的情況 */
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

