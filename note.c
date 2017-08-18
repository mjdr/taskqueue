#include "note.h"

void fillNote(Note* note,char* title, char* description){
 memcpy(&note->title, title, strlen(title) + 1);
 memcpy(&note->description, description, strlen(description) + 1);
}

void printNote(Note* note){
 printf("Title: %s\n", note->title);
 printf("Description: %s\n",note->description);
}
void printShortNote(Note* note){
 printf("%30s\n", note->title);
}
void setupNote(Note* note){
 char* title = malloc(sizeof(char) * 256);
 char* description = malloc(sizeof(char) * 1024 * 16);

 printf("Title: ");
 gets(title);
 printf("Description: ");
 gets(description);
 
 fillNote(note,title,description);
}

void changeNote(Note* note) {
 char* title = malloc(sizeof(char) * 256);
 char* description = malloc(sizeof(char) * 8 * 256);

 printf("Title[%s]: ", note->title);
 gets(title);
 printf("Description[%s]: ", note->description);
 gets(description);
 

 if(strlen(title) != 0)
  memcpy(note->title, title, strlen(title) + 1);
 if(strlen(description) != 0)
  memcpy(note->description, description, strlen(description) + 1);
 
 free(title);
 free(description);
 
}
