// Canary Exercise

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef struct Contact {
   char  name[50];
   char  phone[30];
} contact;

void println(char* str){
  printf("%s\n", str);
}

int menu(){
  int o;
  char buffer[100];
  do{
    println("");
    println(" ---- MENU ---- ");
    println("");
    println("1) Add new contact.");
    println("2) List contacts");
    println("3) Delete contact");
    println("4) Exit");
    println("");
    println("Option: ");
    fgets(buffer, 99, stdin);
    o = atoi(buffer);
  } while(o<1 || o>4);
  return o;
}

void add_contact(contact* c, char * owner){
  char phone[30] = {0};
  char name[50] = {0};
  printf(owner);
  println("Add contact");
  println("Name: ");
  gets(name);
  println("Phone: ");
  gets(phone);
  strcpy(c->name, name);
  strcpy(c->phone, phone);
  println("");
}

void list_contacts(contact* array, int number, char * owner){
  printf(owner);
  println("List of contacts");
  for(int i=0; i<number; i++){
    printf("%s -> %s", array[i].name, array[i].phone);
  }
  println("");
}

void contactcpy(contact * dest, contact * origin){
  strcpy(dest->name, origin->name);
  strcpy(dest->phone, origin->phone);
}

void contactclear(contact * dest){
  strcpy(dest->name, "");
  strcpy(dest->phone, "");
}

void delete_contact(contact* array, int * number, char * owner){
  int item;
  char buffer[100];
  printf(owner);
  println("Delete contact.");
  println("Item: ");
  fgets(buffer, 99, stdin);
  item = atoi(buffer);
  if(item >= 0 && item < *number){
    for(int i=item; i<*number-1; i++){
      contactcpy(&(array[i]), &(array[i+1]));
    }
    contactclear(&(array[*number]));
    (*number) = (*number)-1;
  }
}

int main(int argc, char **argv){
  contact array[254];
  int number = 0;
  char owner[512];

  int option = -1;
  println("Name of owner: ");
  fgets(owner, 490, stdin);
  strcat(owner, "'s agenda\n");
  do{
    option = menu();
    if(option == 1){
      if(number < 252){
        add_contact(&(array[number]), owner);
        number++;
      }
    }
    else if(option == 2){
      if(number > 0){
        list_contacts(array, number, owner);
      }
    }
    else if(option == 3){
      if(number > 0){
        delete_contact(array, &number, owner);
      }
    }
  } while (option != 4);
  return 0;
}
