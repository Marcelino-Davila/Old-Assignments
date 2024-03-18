#include "creture.h"
#include <stdbool.h>
#include "geometry.h"
#include "world.h"
#include "species.h"

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
	creature c = (creature*) malloc(sizeof(struct creatureType);
	c->id=n;
	c->s=s;
	c->wrld=w;
	c->d=d;
	return c;
// returns a new creature with id n of species s in world w at point p facing direction d
void freeCreature(creature c) {

}	

int  getId(creature c) { return c->id; }
void setId(creature c,int i) {
	c->id = i;
}

world getWorld(creature c) { return c->wrld; }
void  setWorld(creature c,world w) {
	c->wrld = w;
}
	

point getPoint(creature c) { return c->p; }
void  setPoint(creature c,point po) {
	c->p = po;
}

direction getDirection(creature c) { return c->d; }
void      setDirection(creature,direction);

species getSpecies(creature c) { return c->s; }
void    setSpecies(creature,species);

int getPC(creature c)  { return c->PC; } // get current program counter
// each creature will need to keep track of the next instruction in its
// code that will be executed in its turn
bool isRunning(creature c) {
	if(c->run==0) {
	return false;
	}
	return true;
}
void takeTurn(creature) {
	
}
// calling this will execute the next instruction for a creature IF
// the creature is currently running. Sets creature to not running
// once it executes a command that halts its code

char *toCreatureString(creature) {
	
}// format: "(mongrol,#1,(row:5,col:10),north)"

#endif
