/*******************************************************************************
* encoding: UTF-8
* 編譯方式：gcc -o hw1 hw1.c
* 執行方式：./hw1
* 程式功能：輸入代表各自分子分母的參數，將兩分數加總，並以最簡分數的形式呈現
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
/* 若使用者在程式後加的參數並非四個，則程式終止 */
    if (argc != 5) 
    {
        printf("\x1b[1;31mPlease input at lease 4 interger as arguments. :)\x1b[0m\n");
        return 0;
    }

/* 宣告整數形態並將相關所需值賦值，最大公因數預設為一*/
    int num1, denom1, num2, denom2, result_num, result_denom, sim_result_num, sim_result_denom,i;
    int com=1,max=0,min=0; /* set variable for finding max. common factor */

/* replace scanf ways by using argv and "a to i" ways */
    num1 = atoi(argv[1]);
    denom1 = atoi(argv[2]);

/* replace scanf ways by using argv and "a to i" ways */
    num2 = atoi(argv[3]);
    denom2 = atoi(argv[4]);

    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;

/* 比較分子分母大小 */
    if(result_num > result_denom)
    {
        max = result_num;
        min = result_denom;
    }
    else
    {
        min = result_num;
        max = result_denom;
    }

/* 將較小數字遞減，利用 % 求餘數為0的方式找出兩分數的最大公因數 */
    for(i=min;i>1;i--)
    {
        if(min%i==0)
        {
            if(max%i==0)
            {
                com = i;
                break;
            }
        }
    }

/* 分子分母同除以最大公因數 */
    sim_result_num = result_num / com;
    sim_result_denom = result_denom / com ;    

/* 印出結果 */
    printf("%d/%d\n",sim_result_num, sim_result_denom);

    return 0;
}

