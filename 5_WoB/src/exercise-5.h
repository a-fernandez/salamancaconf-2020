// WoB Exercise

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define DIM 3
#define EMPTY "\x00\x00\x00\x00\x00\x00\x00\x00"

void println(char*);
void banner();
void get_postition(int, long int *, long int *);
void print_state(char [DIM][DIM][8], char [2][8]);
int check_line(char *, char *, char *);
int check_game(char [DIM][DIM][8]);
char* get_winner(char [DIM][DIM][8]);
void clear_state(char [DIM][DIM][8]);
void open_shell();