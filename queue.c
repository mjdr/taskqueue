#include "queue.h"

#define STORE_FILE "queue.bin"
#define NOTES_MAX_SIZE 1024

Note queue[NOTES_MAX_SIZE];
int queueIndex;

void initQueue() {
 printf("Init new queue\n");
 queueIndex = -1;
}

void pushNote(Note note){
 queue[++queueIndex] = note;
}
Note popNote(){
 return queue[queueIndex--];
}
Note pullNote(){
 return queue[queueIndex];
}

Note getNote(int index){
 return queue[queueIndex-index];
 
}


void printList(){
  printf("Notes(%d): \n",queueSize());
 int i,c = 0;
 for(i = 0;i <= queueIndex;i++){
  printf("%3d ", queueIndex - c);
  printShortNote(&queue[i]);
  c++;
 }
}

int queueSize(){
 return queueIndex + 1;
}

int loadQueue() {
 FILE* f;
 f = fopen(STORE_FILE, "r");
 if(!f){
  printf("Can not load queue\n");
  return 0;
 }
 fread(&queueIndex,sizeof(int),1,f);
 fread(queue,sizeof(Note),queueIndex + 1,f);
 
 fclose(f);
 if(queueIndex < -1 || queueIndex >= NOTES_MAX_SIZE)
  return 0;

 printf("Queue loaded\n");
 return 1;
}

void storeQueue() {
 FILE* f;
 
 f = fopen(STORE_FILE, "w");
 if(!f){
  printf("Can not store queue");
  return;
 }
 fwrite(&queueIndex,sizeof(int),1,f);
 fwrite(queue,sizeof(Note),queueIndex + 1,f);
 
 fclose(f);
}

