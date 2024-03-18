#ifndef CREATURE_H
#define CREATURE_H

#include <stdbool.h>
#include "geometry.h"
#include "world.h"
#include "species.h"

typedef struct creatureType *creature;

typedef struct worldType *world; // forward declaration

creature newCreature(int n,species s,world w,point p,direction d);
// returns a new creature with id n of species s in world w at point p facing direction d
void freeCreature(creature); 

int  getId(creature);
void setId(creature,int);

world getWorld(creature);
void  setWorld(creature,world);

point getPoint(creature);
void  setPoint(creature,point);

direction getDirection(creature);
void      setDirection(creature,direction);

species getSpecies(creature);
void    setSpecies(creature,species);

int getPC(creature);  // get current program counter
// each creature will need to keep track of the next instruction in its
// code that will be executed in its turn
bool isRunning(creature); // true if code is currently running
void takeTurn(creature);
// calling this will execute the next instruction for a creature IF
// the creature is currently running. Sets creature to not running
// once it executes a command that halts its code

char *toCreatureString(creature); // format: "(mongrol,#1,(row:5,col:10),north)"

#endif
