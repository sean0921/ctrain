/* Adds two fractions */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int num1, denom1, num2, denom2, result_num, result_denom;

//  printf("Enter first fraction: ");
//  scanf("%d/%d", &num1, &denom1);
  num1 = atoi(argv[1]);
  denom1 = atoi(argv[2]);


//  printf("Enter second fraction: ");
//  scanf("%d/%d", &num2, &denom2);
  num2 = atoi(argv[3]);
  denom2 = atoi(argv[4]);

  result_num = num1 * denom2 + num2 * denom1;
  result_denom = denom1 * denom2;
  printf("The sum is %d/%d\n",result_num, result_denom);

  return 0;
}

