#ifndef GEOMETRY_H
#define GEOMETRY_H

#define MINROWS 5   /* minimum number of rows in world */
#define MAXROWS 15  /* maximum number of rows in world */
#define MINCOLS 5   /* minimum number of columns in world */
#define MAXCOLS 30  /* maximum number of columns in world */

// upper left corner point is specified as row 1, column 1 for the geometry module

typedef struct pointType *point;

typedef enum {NORTH, EAST, SOUTH, WEST, NONE} direction;

point createPoint(int row,int col);
void freePoint(point);

point adjacentPoint(point,direction); 

int getRow(point);
int getCol(point);

direction leftFrom(direction d);  // returns direction if you turn left
                                  // from direction d
direction rightFrom(direction d); // returns direction if you turn right
                                  // from direction d

char *toDirectionString(direction);
char *toPointString(point);

#endif
