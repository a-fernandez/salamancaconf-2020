// WoB Exercise

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define DIM 3

void println(char*);
void banner();
void get_postition(char *, long int *, long int *);
void print_state(char [DIM][DIM][256], char [2][256]);
int check_line(char *, char *, char *);
int check_game(char [DIM][DIM][256]);
char* get_winner(char [DIM][DIM][256]);
void clear_state(char [DIM][DIM][256]);
