/* Adds two fractions */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 5) 
    {
        printf("\x1b[1;31mPlease input at lease 4 interger as arguments. :)\x1b[0m\n");
        return 0;
    }

    int num1, denom1, num2, denom2, result_num, result_denom, sim_result_num, sim_result_denom,i;
    int com=1,max=0,min=0; /* set variable for finding max. common factor */

/* replace scanf ways by using argv and "a to i" ways */
//  printf("Enter first fraction: ");
//  scanf("%d/%d", &num1, &denom1);
    num1 = atoi(argv[1]);
    denom1 = atoi(argv[2]);

/* replace scanf ways by using argv and "a to i" ways */
//  printf("Enter second fraction: ");
//  scanf("%d/%d", &num2, &denom2);
    num2 = atoi(argv[3]);
    denom2 = atoi(argv[4]);

    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;


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

    sim_result_num = result_num / com;
    sim_result_denom = result_denom / com ;    

    printf("The sum is %d/%d\n",sim_result_num, sim_result_denom);

    return 0;
}

