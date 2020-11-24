
#include "cesar.h"

#include <stdio.h>
#include <ctype.h>

#define LENGTH 32

int main()
{
	int k;
	char msg[LENGTH];

	puts("¿Qué mensaje quieres cifrar? Solo letras minusculas");
	printf("msg> ");
	gets(msg);

	puts("¿Cuál es tu clave?");
	printf("K> ");
	k = read_int(26);

	encrypt(k, msg);

	puts("Tu mensaje cifrado es:");
	puts(msg);
}

void encrypt(int k, char *str)
{
	const char* abc = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < LENGTH; i++) {
		if (islower(str[i]))
				str[i] = abc[(int)((str[i] - 'a') + k) % 26];
	}
}

int read_int(int max)
{
	int i;
	printf("> ");
	scanf("%d", &i);
	while(getchar() != '\n');
	if (i < 0) return 0;
	if (i > max) return max;
	return i;
}
