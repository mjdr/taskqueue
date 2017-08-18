#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct {
 char title[256];
 char description[1024*16];
} Note;

void fillNote(Note* note,char*,char*);
void printShortNote(Note*);
void printNote(Note*);
void setupNote(Note*);
void changeNote(Note*);
