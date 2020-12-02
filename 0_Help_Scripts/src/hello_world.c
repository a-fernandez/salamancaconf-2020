
#include <stdlib.h>
#include <stdio.h>

int main()
{
	hello("Hello world!\n", 3);
	return 0;
}

int hello(char *mes, int N)
{
	for (int i = 0; i < N; i++)
	{
		printf(mes);
	}
}
