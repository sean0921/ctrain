/* Adds two fractions */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("\x1b[1;31mPlease input at least 2 interger as arguments. :)\x1b[0m\n");
        return 0;
    }

    int noi, nop;

/* replace scanf ways by using argv and "a to i" ways */
//  printf("Enter first fraction: ");
//  scanf("%d/%d", &num1, &denom1);
    noi = atoi(argv[1]);
    nop = atoi(argv[2]);

    printf("You Set N = %d , P = %d \n", noi, nop);
    return 0;
}

