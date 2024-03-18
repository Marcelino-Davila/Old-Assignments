#ifndef WORLD_H
#define WORLD_H

#include <stdbool.h>
#include "geometry.h"
#include "creature.h"

#define MINSPECIES 1       /* minimum number of species in world */
#define MAXSPECIES 10      /* maximum number of species in world */
#define MAXSPECIES_NAME 50 /* maximum length of species name */
#define MAXCREATURES 100   /* maximum number of creatures in world */
#define MAXPROGRAM 250     /* maximum # of lines in each creature's program */
#define INITIALNUMBER 10   /* initial number of creatures per species */

typedef struct worldType *world;

world newWorld(char* name,int h,int w); // returns world name of height h and width w
void freeWorld(world);

char *getName(world);
int getWidth(world);
int getHeight(world);

bool inRange(world,point);

typedef struct creatureType *creature; // forward declaration
void setContents(world,point,creature,direction);
creature getContents(world,point);

char *toWorldString(world);
#endif
