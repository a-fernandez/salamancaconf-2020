
#include "eco.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char msg[200];

	printf("> ");
	gets(msg);

	puts("");
	sleep(1);
	puts(msg);

	sleep(1.5);
	puts(msg);

	sleep(2);
	puts(msg);
}
