#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifndef CNUM_H
#define CNUM_H

struct ctype {
	char *name;
	float real,imag,mag,ang;
};

typedef struct ctype *comp;

struct ltype {
	char *name;
	comp *data;
	int size;
};

typedef struct ltype *list;

void help(char*); //explains how given fuction works

void printAll(list); //prints all of the complex numbers in the list

void printCnum(comp); //prints one complex number

list createList(char*); //makes list (make work later)

comp createPolar(char*, float, float); //creates a polar complex number

comp createCartesian(char *name, float real, float); //creates a cartesian complex nubmer

comp add(comp, comp, char *name); // adds 2 complex numbers and returns a new complex number

comp sub(comp, comp, char *name); // subtracts 2 complex numbers and returns a new complex number

comp mul(comp, comp, char *name); // multiplies 2 complex numbers and returns a new complex number

comp divide(comp, comp, char *name); // divides 2 complex numbers and returns a new complex number

#endif