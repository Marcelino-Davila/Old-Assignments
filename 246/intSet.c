#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intSet.h"

#define EXAPANSION_SIZE 10

static int size(intSet);
static int items(intSet);
static void expand(intSet);

struct intsetType {
	int size;
	int items;
	int* list;
};


intSet createSet(){
	int i;
	intSet cSet=(intSet) malloc(sizeof(struct intsetType));
	cSet->size=1;
	cSet->items=0;
	cSet->list=(int*) malloc(cSet->size*sizeof(int)); 
	return cSet;
}
static int size(intSet in) { return in->size; }
static int items(intSet in) { return in->items; }

static void expand(intSet in) {
	int i;
	if(in->size <= in->items) {
	intSet EList = createSet();
	EList->list = (int*) malloc((2*in->size)*sizeof(int));
	for(i=0;i<in->items;i++) {
		EList->list[i] = in->list[i];
	}
	in->size+=EXAPANSION_SIZE;
	in->list=(int*) malloc(in->size*sizeof(int));
		for(i=0;i<in->items;i++) {
		in->list[i] = EList->list[i];
	}
	destroySet(EList);
}
}



int card(intSet in) { return in->items; }

void destroySet(intSet o) { 
free(o->list);
free(o); 
}

void clear(intSet in) {
	in->items = 0;
	free(in->list);
	in->list=(int*) malloc(in->size*sizeof(int));
}


bool equals(const intSet s1,const intSet s2) {
	if(s1->items!=s2->items) return false;
	if((isEmpty(s1)==true) && isEmpty(s2)==true) return true;
	if((isEmpty(s1)==false) && isEmpty(s2)==true) return false;
	if((isEmpty(s1)==true) && isEmpty(s2)==false) return false;
	int i;
	for(i=0;i<card(s1);i++) {
		if(s1->list[i]!=s2->list[i]) return false;
	}
	return true;
}

bool contains(const intSet s,int item) {
	int i;
	for(i=0;i<s->size;i++) {
		if(s->list[i]==item) return true; 
	}
	return false;
}
	// retuns true if argument is in set, false otherwise
int largest(const intSet in) {
	int s;
	if(isEmpty(in)==true) {
		printf("error set is empty");
		return -1;
	}
	return in->list[in->items-1];
}	
                             // and exits if set is empty
int smallest(const intSet in) {
	int s;
	if(isEmpty(in)==true) {
		printf("error set is empty");
		return -1;
	}
	s=in->list[0];
	return s;
}	


void add(intSet s,int item) {

	if(contains(s,item)!=true) {
	s->items++;
	expand(s);
	s->list[s->items-1]=item;
//-----------------------------sort-------------------------
	int min=s->list[0];
	int i,j,z;
	for(i=0;i<s->items;i++) {
		min=s->list[i];
		z=i;
		for(j=i+1;j<s->items;j++) {
			if(s->list[j] < min){
				min = s->list[j];
				z=j;
			}
		}
		s->list[z] = s->list[i];
		s->list[i] = min;
	}
}
}
	
static	int find(intSet s, int item) {
		int i;
		for(i=0;i<s->items;i++) {
			if(s->list[i]==item) return i;
		}
		return -1;
	}
		
	
void remove_(intSet s,int item) {
	if(contains(s,item)==true) {
	s->items--;
	int f=find(s,item);
	int i;
		s->list[f]=s->list[f+1];
		for(i=f;i<s->items;i++) {
			s->list[i]=s->list[i+1];
	}
	}
}
		
intSet union_(const intSet s1, const intSet s2) {
	intSet out = createSet();
	int i;
	for(i=0;i<s1->items;i++) {
		add(out,s1->list[i]);
	}
	for(i=0;i<s2->items;i++) {
	add(out,s2->list[i]); 
	}
	expand(out);
	return out;
}
	
	
	
	
intSet intersect(const intSet s1, const intSet s2) {
	intSet out = createSet();
	int i;
	for(i=0;i<s1->items;i++) {
		if(contains(s2,s1->list[i])==true) { 
		add(out,s1->list[i]); 
		}
	}
	expand(out);
	return out;
}
	
	
intSet diff(const intSet s1, const intSet s2) { // set difference, i.e. s1 - s2
	intSet out = createSet();
	int i;
	for(i=0;i<s1->items;i++) {
		add(out,s1->list[i]);
		if(contains(s2,s1->list[i])==true) {
			remove_(out,s1->list[i]);
		}
	}
	return out;
}
  
bool isEmpty(const intSet in) { 
	if(in->items==0) { 
	return true; 
	}
	return false;
}
	// returns true if the set is empty, false otherwise

int *toArray(const intSet in) {
	if(isEmpty(in) == true) return NULL;
	int* iarray = (int*) malloc(in->items*sizeof(int));
	int i;
	for(i=0;i<in->items;i++) {
		iarray[i] = in->list[i];
	}
	return iarray;
}
	
	// returns an array representation of the set in
                              // ascending order
char *toString(const intSet in) {
	if(isEmpty(in)==true) { return "{}"; }
	int buffSize=10;
	int* iarr = toArray(in);
	int i,j,z;
	char* buff = (char*) malloc(buffSize*sizeof(char));
	sprintf(buff,"{");
	for(i=0;i<in->items;i++) {
			char* currentItem = (char*) malloc(30*sizeof(char));
			if(buffSize<strlen(buff) + 3) {
				buffSize*=2;
				char* tmp=(char*) malloc(buffSize*sizeof(char));
				strcpy(tmp,buff);
				free(buff);
				char* buff = (char*) malloc(buffSize*sizeof(char));
				strcpy(buff,tmp);
				free(tmp);
			}
				
			sprintf(currentItem, "%d", iarr[i]);
			strcat(buff,currentItem);
		
			if(i < in->items-1) {
			strcat(buff,",");
			}
			free(currentItem);
	}
	strcat(buff,"} ");
	char *tString = (char*) malloc((strlen(buff))*sizeof(char));
	strcpy(tString,buff);
	free(buff);
	free(iarr);
	return tString;
}
