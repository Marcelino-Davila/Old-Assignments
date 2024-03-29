#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "cnum.h"


float PI = 3.14159265359;
float pi = 3.14159265359;

void help(char *func){
	
}

void printAll(list l){
	
}

list createList(char* name){
	list numlist = malloc(sizeof(list));
	numlist->name = malloc(100*sizeof(char));
	polar->name = name;
	int size=0;
	comp->data = malloc(100*sizeof(comp));
	return list;
}

void addList(list l, comp cnum){
	l->data[l->size]=cnum;
	l->size++;
}

void printCnum(comp number){
	printf("name: %s\n",number->name);
	printf("cartesian: %.04lf + j%.04lf\n",number->real,number->imag);
	printf("polar: mag - %.04lf angle - j%.04lf",number->mag,number->ang);
}

comp createPolar(char *name, float magnitude, float angle){
	comp polar = malloc(sizeof(comp));
	polar->name = malloc(100*sizeof(char));
	polar->name = name;
	polar->mag = magnitude; polar->ang = angle;
	polar->real = magnitude*cos(angle*PI/180);
	polar->imag = magnitude*sin(angle*(PI/180));
	return polar;
}

comp createCartesian(char *name, float real, float imag){
	comp cart = malloc(sizeof(comp));
	cart->name = malloc(100*sizeof(char));
	cart->name = name;
	cart->real = real; cart->imag = imag;
	cart->mag = sqrt(pow(real,2)+pow(imag,2));
	cart->ang = atan(imag/real)*180/pi;
	return cart;
}

comp add(comp num1, comp num2, char *name){
	float r = num1->real + num2->real;
	float i = num1->imag + num2->imag;
	comp addnum = createCartesian(name,r,i);
	return addnum;
}

comp sub(comp num1, comp num2, char *name){
	float r = num1->real - num2->real;
	float i = num1->imag - num2->imag;
	comp subnum = createCartesian(name,r,i);
	return subnum;
}

comp mul(comp num1, comp num2, char *name){
	float m = num1->mag * num2->mag;
	float a = num1->ang + num2->ang;
	comp mulnum = createPolar(name,m,a);
	return mulnum;
}

comp divide(comp num1, comp num2, char *name){
	float m = num1->mag / num2->mag;
	float a = num1->ang - num2->ang;
	comp divnum = createPolar(name,m,a);
	return divnum;
}