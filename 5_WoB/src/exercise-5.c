// WoB Exercise

#include "exercise-5.h"

char array[DIM][DIM][8];

void println(char* str){
  printf("%s\n", str);
}

void banner(){
  println("");
  println(" OH MAMA! TIC TAC TOE. ");
  println("");
  println("TWO PLAYERS.");
  println("");
  println("START THE GAME!");
  println("");
}

void get_postition(int player, long *row, long *column){
  println("");
  printf("PLAYER %d POS (ROW): \n", player);
  scanf("%ld", row);
  printf("PLAYER %d POS (COLUMN): \n", player);
  scanf("%ld", column);
  println("");
}

void clear_state(char state[DIM][DIM][8]){
  for(int i=0; i<DIM; i++){
    for(int j=0; j<DIM; j++){
      memcpy(state[i][j], EMPTY, 8);
    }
  }
}

void print_state(char state[DIM][DIM][8], char ids[2][8]){
  printf("\n-------------\n");
  for(int i=0; i<DIM; i++){
    printf("|");
    for(int j=0; j<DIM; j++){
      if(memcmp(state[i][j], EMPTY, 8) == 0){
        printf("   ");
      }
      else if(memcmp(state[i][j], ids[0], 8) == 0){
        printf(" O ");
      }
      else if(memcmp(state[i][j], ids[1], 8) == 0){
        printf(" X ");
      }
      printf("|");
    }
    printf("\n-------------\n");
  }
}

int check_line(char * pos1, char * pos2, char * pos3){
  if(memcmp(pos1, EMPTY, 8) == 0 || memcmp(pos2, EMPTY, 8) == 0 || memcmp(pos3, EMPTY, 8) == 0){
    return 0;
  }
  else if(memcmp(pos1, pos2, 8) == 0 && memcmp(pos1, pos3, 8) == 0){
    return 1;
  }
  return 0;
}

int check_game(char state[DIM][DIM][8]){
  //ROWS
  if(check_line(state[0][0], state[0][1], state[0][2])) {
    return 1;
  }
  else if(check_line(state[1][0], state[1][1], state[1][2])) {
    return 1;
  }
  else if(check_line(state[2][0], state[2][1], state[2][2])) {
    return 1;
  }
  //COLUMNS
  else if(check_line(state[0][0], state[1][0], state[2][0])) {
    return 1;
  }
  else if(check_line(state[0][1], state[1][1], state[2][1])) {
    return 1;
  }
  else if(check_line(state[0][2], state[1][2], state[2][2])) {
    return 1;
  }
  //Diagonals
  else if(check_line(state[0][0], state[1][1], state[2][2])) {
    return 1;
  }
  else if(check_line(state[2][0], state[1][1], state[0][2])) {
    return 1;
  }
  return 0;
}

char* get_winner(char state[DIM][DIM][8]){
  //ROWS
  if(check_line(state[0][0], state[0][1], state[0][2])) {
    return state[0][0];
  }
  else if(check_line(state[1][0], state[1][1], state[1][2])) {
    return state[1][0];
  }
  else if(check_line(state[2][0], state[2][1], state[2][2])) {
    return state[2][0];
  }
  //COLUMNS
  else if(check_line(state[0][0], state[1][0], state[2][0])) {
    return state[0][0];
  }
  else if(check_line(state[0][1], state[1][1], state[2][1])) {
    return state[0][1];
  }
  else if(check_line(state[0][2], state[1][2], state[2][2])) {
    return state[0][2];
  }
  //Diagonals
  else if(check_line(state[0][0], state[1][1], state[2][2])) {
    return state[0][0];
  }
  else if(check_line(state[2][0], state[1][1], state[0][2])) {
    return state[0][2];
  }
  return "";
}

void open_shell(){
  system("/bin/sh");
}

int main(int argc, char **argv){
  char ids[2][8];
  int turn = -1;
  int player = 0;
  long int r,c;
  int win;
  char buff[10];
  clear_state(array);
  banner();
  println("");
  println("PLAYER 1 NAME:");
  fgets(buff, 10, stdin);
  memcpy(ids[0], buff, 8);
  println("PLAYER 2 NAME:");
  fgets(buff, 10, stdin);
  memcpy(ids[1], buff, 8);
  println("");
  do{
    turn++;
    player = (turn % 2);
    print_state(array, ids);
    get_postition((player+1), &r, &c);
    memcpy(array[r][c], ids[player], 8);
    win = check_game(array);
  } while (win == 0);
  printf("The player with id %s win the game.\n", get_winner(array));
  return 0;
}
