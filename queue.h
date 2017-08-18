#pragma once

#include "note.h"

void initQueue();
void pushNote(Note);
Note popNote();
Note pullNote();
Note getNote(int);

void printList();
int queueSize();


int loadQueue();
void storeQueue();

