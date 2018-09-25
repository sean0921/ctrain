#include <stdio.h>

int a=20000, b=40000;
int i,com;

int main(void)
{
    for(i=a;i>2;i--)
    {
        if(a%i==0)
        {
            if(b%i==0)
            {
                com = i;
		break;
	    }
        }	
    }
    printf("%d\n",com);
    return 0;
}
