typedef int bool;

#include "queue.h"
#include "note.h"




int main(int argc, char* argv[]){
 if(!loadQueue())
  initQueue();
 if(argc != 2){
  printf("Invalid number of arguments\n Use note help\n");
  return 0;
 }
 if(!strcmp(argv[1],"add")){
  Note* note = (Note*) malloc(sizeof(Note));
  setupNote(note);
  pushNote(*note);
  storeQueue();
 }
 else if(!strcmp(argv[1],"list")){
  printList();
 }
 else if(!strcmp(argv[1],"done")){
  Note n = popNote();
  printNote(&n);
  storeQueue();
  printf("Done\n");
 }
 else if(!strcmp(argv[1],"last")){
  Note n = getNote(0);
  printNote(&n);
 }
 else if(!strcmp(argv[1],"finished")){
  printf("Finished tasks : %d \n", getFinishedCount());
 }
 else if(!strcmp(argv[1],"help")){
  printf("Commands:\n  add\n  list\n  done\n  last\n  finished\n  help\n");
 }
 else {
  printf("Invalid argument\n Use note help\n");
  return 0;
 }
 return 0;
}
