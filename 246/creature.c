#include "creature.h"
#include <stdbool.h>
#include <stdlib.h>
#include "geometry.h"
#include "world.h"
#include "species.h"
#include "instruction.h"
#include <string.h>

/*Marcileno Devila
Frank Kengni
project 4*/

struct creatureType {
	int id;
	direction d;
	world wrld;
	species s;
	int PC;
	point p;
	int run;
};
typedef struct worldType *world; // forward declaration

creature newCreature(int n,species s,world w,point p,direction d) {
	creature c =  malloc(sizeof(struct creatureType));
	c->id=n;
	c->run = 0;
	c->PC = 1;
	c->s=s;
	c->wrld=w;
	c->d=d;
	c->p = p;
	return c;
}
// returns a new creature with id n of species s in world w at point p facing direction d
void freeCreature(creature c) {
	freeSpecies(c->s);
	freePoint(c->p);
	freeWorld(c->wrld);
	free(c);
}	

int  getId(creature c) { return c->id; }
void setId(creature c,int i) {
	c->id = i;
}

world getWorld(creature c) { return c->wrld; }
void  setWorld(creature c,world w){
	c->wrld = w;
}
	
	

point getPoint(creature c) { return c->p; }
void  setPoint(creature c,point po) {
	c->p = po;
}

direction getDirection(creature c) { return c->d; }
void      setDirection(creature c,direction d){
	c->d = d;
}


species getSpecies(creature c) { return c->s; }
void    setSpecies(creature c,species s) {
	c->s = s;
}

int getPC(creature c)  { return c->PC; } // get current program counter
// each creature will need to keep track of the next instruction in its
// code that will be executed in its turn
bool isRunning(creature c) {
	if(c->run==0) {
	return false;
	}
	return true;
}
void takeTurn(creature c) {
	if(!isRunning(c)){
		c->run=1;
		return;
	}
	c->run = 0;
	return;
}
// calling this will execute the next instruction for a creature IF
// the creature is currently running. Sets creature to not running
// once it executes a command that halts its code

char *toCreatureString(creature c) {
	
		char *buff;
	buff = (char *)malloc(sizeof(char)*600);
	char *point= toPointString(c->p);
		char *name = getSpeciesName(c->s);
		char *direction = toDirectionString(c->d);
	if(getSpeciesName(getSpecies(c))[0] == '\0') {
		sprintf(buff, "(\"\",#%d,%s,%s)",c->id,point,direction);
		char* str = malloc(strlen(buff)*sizeof(char));
		strcpy(str,buff);
		free(buff);
		return str;
	}
	sprintf(buff, "(%s,#%d,%s,%s)",name,c->id,point,direction);
	char *string = malloc(strlen(buff)*sizeof(char));
	strcpy(string,buff);
	free(buff);
	return string;
}
// format: "(mongrol,#1,(row:5,col:10),north)"


