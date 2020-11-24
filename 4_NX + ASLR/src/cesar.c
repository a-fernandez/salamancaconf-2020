
#include "cesar.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LENGTH 32

int main(int argc, char **argv) {
	int k;
	char msg[LENGTH];
	if(argc == 2 && strcmp(argv[1], "debug") == 0){
		printf("printf at %016p\n", (void*)printf);
	}

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
