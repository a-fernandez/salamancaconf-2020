// WoB Exercise

#include "exercise-5.h"

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

void get_postition(char * player, long *row, long *column){
  println("");
  printf("PLAYER %s POS (ROW): ", player);
  scanf("%ld", row);
  printf("PLAYER %s POS (COLUMN): ", player);
  scanf("%ld", column);
  println("");
}

void clear_state(char state[DIM][DIM][256]){
  for(int i=0; i<DIM; i++){
    for(int j=0; j<DIM; j++){
      strcpy(state[i][j], "");
    }
  }
}

void print_state(char state[DIM][DIM][256], char ids[2][256]){
  printf("\n-------------\n");
  for(int i=0; i<DIM; i++){
    printf("|");
    for(int j=0; j<DIM; j++){
      if(strcmp(state[i][j], "") == 0){
        printf("   ");
      }
      else if(strcmp(state[i][j], ids[0]) == 0){
        printf(" O ");
      }
      else if(strcmp(state[i][j], ids[1]) == 0){
        printf(" X ");
      }
      printf("|");
    }
    printf("\n-------------\n");
  }
}

int check_line(char * pos1, char * pos2, char * pos3){
  if(strcmp(pos1, "") == 0 || strcmp(pos2, "") == 0 || strcmp(pos3, "") == 0){
    return 0;
  }
  else if(strcmp(pos1, pos2) == 0 && strcmp(pos1, pos3) == 0){
    return 1;
  }
  return 0;
}

int check_game(char state[DIM][DIM][256]){
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

char* get_winner(char state[DIM][DIM][256]){
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

int main(int argc, char **argv){
  char array[DIM][DIM][256];
  char ids[2][256];
  int turn = 0;
  int player = 0;
  long int r,c;
  int win;
  clear_state(array);
  banner();
  println("");
  printf("PLAYER 1 NAME: ");
  scanf("%255s", ids[0]);
  printf("PLAYER 2 NAME: ");
  scanf("%255s", ids[1]);
  println("");
  do{
    turn++;
    player = (turn % 2);
    print_state(array, ids);
    get_postition(ids[player], &r, &c);
    strcpy(array[r][c], ids[player]);
    win = check_game(array);
  } while (win == 0);
  printf("The player with id %s win the game.\n", get_winner(array));
  return 0;
}
