#include<stdio.h>

int fact(int n)
{
    if ( n <=1 ) return 1;
    else return n*fact(n-1);
}

int main(void)
{
    int a=0;
    a=fact(3);
    return 0;
}
