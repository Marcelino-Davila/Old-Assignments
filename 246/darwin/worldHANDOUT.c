#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "creature.h"
#include "world.h"
#include "geometry.h"

struct worldType {
  char *name;
  // will need to define more fields!
};

world newWorld(char *name,int h,int w) {
  world wrld = malloc(sizeof(struct worldType));
  wrld->name = malloc(strlen(name)+1);
  strcpy(wrld->name,name);
  // this function is incomplete!
  return wrld;
}

void freeWorld(world w) { }

char *toWorldString(world w) { return NULL; }


int getWidth(world w) { return -1; }
int getHeight(world w) { return -1; }
char *getName(world w) { return w->name; }

bool inRange(world w,point p) { return false; }

void setContents(world w,point p,creature c, direction d) { }

creature getContents(world w,point p) { return NULL; }



