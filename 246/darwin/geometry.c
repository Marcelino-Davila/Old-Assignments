// Dan Resler 10/22

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geometry.h"

struct pointType {
  int x, y;
};

point createPoint(int yval,int xval) {
  if(xval <= 0 || yval <= 0) {
    printf("ERROR - point %d,%d is illegal.\n",xval,yval);
    exit(EXIT_FAILURE);
  }
  point t = malloc(sizeof(struct pointType));
  t->x = xval; t->y = yval;
  return t;
};
void freePoint(point p) { free(p); }

int getRow(point p) { return p->y; }
int getCol(point p) { return p->x; }

point adjacentPoint(point p,direction d) {
  int xval = p->x, yval = p->y;
  switch(d) {
  case NORTH: yval--; break;
  case EAST:  xval++; break;
  case SOUTH: yval++; break;
  case WEST:  xval--; break;
  case NONE:
  default:
    printf("Internal error - adjacentPoint: bad direction\n");
    exit(EXIT_FAILURE);
  }
  return createPoint(xval,yval);
};

direction leftFrom(direction d) {
  switch(d) {
  case NORTH: return WEST;
  case EAST:  return NORTH;
  case SOUTH: return EAST;
  case WEST:  return SOUTH;
  case NONE:
  default:
    printf("Internal error - adjacentPoint: bad direction\n");
    exit(EXIT_FAILURE);
  }
}

direction rightFrom(direction d) {
  switch(d) {
  case NORTH: return EAST;
  case EAST:  return SOUTH;
  case SOUTH: return WEST;
  case WEST:  return NORTH;
  case NONE:
  default:
    printf("Internal error - adjacentPoint: bad direction\n");
    exit(EXIT_FAILURE);
  }
}
char *toDirectionString(direction d) {
  char *ds = malloc(6);
  switch(d) {
  case NORTH: strncpy(ds,"north",6);  break;
  case EAST:  strncpy(ds,"east",6);   break;
  case SOUTH: strncpy(ds,"south",6);  break;
  case WEST:  strncpy(ds,"west",6);   break;
  default:    strncpy(ds,"[none]",6); break;
  }
  return ds;
}

char *toPointString(point p) {
  if(p==NULL) return "NULL";
  char *ps = malloc(25);
  strncpy(ps,"(row:",25);
  char buff[5];
  snprintf(buff,4,"%d",p->y);
  strncat(ps,buff,25);
  strncat(ps,",col:",25);
  snprintf(buff,4,"%d",p->x); 
  strncat(ps,buff,25);
  strncat(ps,")",25);
  return ps;
}


