#ifndef WORLDMAP_H
#define WORLDMAP_H

#include "geometry.h"

void initWorldMap(int rows, int cols);
void displaySquare(point,char,direction);
int  getNumRows();
int  getNumCols();
void run();
char pauseForKeyStroke();
void pauseForTime(int millisecs);

// console output routines:
void writeStr(char* fmt,char*); // 2nd arg can be NULL 
void writeInt(char* fmt,int);
void writeChar(char* fmt,char);
void writeFloat(char* fmt,float);

#endif
