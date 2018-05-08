#include <stdio.h>

int test1(void)
{
	int test1num = 1;
	printf("\x1b[1;33mtest%d!\x1b[m\n",test1num);
	return 0;
}
