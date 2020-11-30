
#include "heapmons.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HeapMon {
	char* name;
	int attack;
	int defense;
	int sp_atta;
	int sp_defe;
};

int chunks = 0;
struct HeapMon* team[6] = {NULL, NULL, NULL, NULL, NULL, NULL};

int main()
{
	int n, i;
	char trainer[16];

	read_trainer(trainer);
	while (1) {
		menu(trainer);
		n = read_int(6);
		puts("");
		switch (n) {
			case 0:
				puts("¿En qué posición de tu equipo quieres guardar tu nuevo heapmon?");
				i = read_int(5);
				add_heapmon(i);
				break;
			case 1:
				puts("¿En qué posición de tu equipo está el heapmon a editar?");
				i = read_int(5);
				edi_heapmon(i);
				break;
			case 2:
				puts("¿En qué posición de tu equipo está el heapmon a borrar?");
				i = read_int(5);
				del_heapmon(i);
				break;
			case 3:
				puts("¿En qué posición de tu equipo está el heapmon que quieres ver?");
				i = read_int(5);
				see_heapmon(i);
				break;
			case 4:
				print_all();
				break;
			case 6:
				_debug_info();
				break;
			default:
				exit(0);
		}
	}
}

void read_trainer(char* trainer)
{
	puts("¿Como te llamas?");
	printf("> ");
	fgets(trainer, sizeof(trainer), stdin);
	trainer[strlen(trainer)-1] = '\0';
}

void menu(char* name)
{
	puts("");
	puts(name);
	puts("Selecciona una opción:");
	puts("\t0. Añadir un heapmon");
	puts("\t1. Editar un heapmon");
	puts("\t2. Borrar un heapmon");
	puts("\t3. Ver un heapmon");
	puts("\t4. Ver todos tus heapmon");
	puts("\t5. Salir");
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

void add_heapmon(int i)
{
	puts("¡¡¡Vamos a añadir un Heapmon!!!");
	team[i] = malloc(sizeof(struct HeapMon));
	team[i]->name = malloc(16);
	edi_heapmon(i);
	chunks++;
}

void edi_heapmon(int i)
{
	if (team[i]) {
		printf("Nombre: ");
		gets(team[i]->name);

		printf("Ataque: ");
		scanf("%d", &team[i]->attack);
		printf("Defensa: ");
		scanf("%d", &team[i]->defense);
		printf("Ataque especial: ");
		scanf("%d", &team[i]->sp_atta);
		printf("Defensa especial: ");
		scanf("%d", &team[i]->sp_defe);
		while(getchar() != '\n');
	}
}

void see_heapmon(int i)
{
	if (team[i]) {
		puts("");
		printf("Tu Heapmon %s mola mucho\n", team[i]->name);
		puts("Habilidades:");
		printf("\t· Ataque: %d\n", team[i]->attack);
		printf("\t· Defensa: %d\n", team[i]->defense);
		printf("\t· Ataque especial: %d\n", team[i]->sp_atta);
		printf("\t· Defensa especial: %d\n", team[i]->sp_defe);
	}
}

void del_heapmon(int i)
{
	if (team[i]) {
		free(team[i]->name);
		free(team[i]);
		team[i] = NULL;
		chunks--;
	}
}

void print_all()
{
	for (int i = 0; i < 6; i++) {
		see_heapmon(i);
	}
}

void _debug_info()
{
	printf("Array of chunks: %p\n", team);
	printf("Total number of active chunks: %d\n\n\n", chunks);
	for (int i = 0; i < 6; i++) {
		if (team[i]) {
			printf("\tChunk heapmon address: %p\n", team[i]);
			printf("\tChunk heapmon size: %d\n\n", sizeof(struct HeapMon));

			printf("\tChunk name address: %p\n", team[i]->name);
			printf("\tChunk name size: %d\n", 16);
			printf("\tChunk name content: %s\n\n", team[i]->name);
			puts("---");
		}
	}
}
