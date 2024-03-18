#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intSet.h"

#define EXAPANSION_SIZE 10
#define SHRINK_SIZE 5

void iCopy(intSet,intSet,int,int);
int size(intSet);
void resize(intSet);
//intSet shrink(intSet);


struct intsetType {
	int size;
	int items;
	int* list;
};


intSet createSet(){
	printf("in create\n");
	int i;
	intSet cSet=(intSet) malloc(sizeof(struct intsetType));
	cSet->size=EXAPANSION_SIZE;
	cSet->items=0;
	cSet->list=(int*) malloc(cSet->size*sizeof(int)); 
	for(i=0;i<cSet->size;i++) {
		cSet->list[i]=NULL;
	}
	return cSet;
}
int size(intSet in) { return in->size; }
int items(intSet in) { return in->items; }

intSet createCopy(intSet in) {
	intSet copySet = createSet();
	 iCopy(in,copySet,0,in->items);
	return copySet;
}

void resize(intSet in) {
	if(in->size <= in->items) {
		expand(in);
	}
	if(in->size > in->items+SHRINK_SIZE) {
		shrink(in);
	}
}
	

void expand(intSet in, int nItems) {
	int i;
	in->size+=EXAPANSION_SIZE;
	in->list=(int*) malloc(in->size*sizeof(int));
		for(i=in->items;i<in->size;i++) {
		in->list[i]=NULL;
	}
}

void shrink(intSet in) {
	int i;
	in->size-=SHRINK_SIZE;
	in->list=(int*) malloc(in->size*sizeof(int));
	for(i=in->items;i<in->size;i++) {
		in->list[i]=NULL;
	}
}


int card(intSet in) { printf("in card\n"); return in->items; }

void iCopy(intSet original, intSet copy, int start, int end) {
	int i;
	//while(original->items > copy->size) 
		//copy=resize(copy);
	//
	for(i=start;i<end;i++) {
		copy->list[i] = original->list[i];
	}
	copy->items=original->items;
}


void destroySet(intSet o) { 
free(o->list);
free(o); 
}

void clear(intSet in) {
	printf("in clear\n");
	int i;
	in->items = 0;
	resize(in);
	
}


bool equals(const intSet s1,const intSet s2) {
	printf("in equals\n");
	if(card(s1)!=card(s2)) return false;
	if((isEmpty(s1)==true) && isEmpty(s2)==true) return true;
	if((isEmpty(s1)==false) && isEmpty(s2)==true) return false;
	if((isEmpty(s1)==true) && isEmpty(s2)==true) return false;
	int i;
	for(i=0;i<card(s1);i++) {
		if(s1->list[i]!=s2->list[i]) return false;
	}
	return true;
}
	// returns true if 2 sets are equal, false
                                        // otherwise; two sets are equal if they contain
                                        // all of the same values
bool contains(const intSet s,int item) {
	printf("in contains\n");
	int i;
	for(i=0;i<s->size;i++) {
		printf("%d\n",i);
		if(s->list[i]==item) { return true; }
	}
	return false;
}
	// retuns true if argument is in set, false otherwise
int largest(const intSet in) {
	printf("\n%d\n",in->items);
	int s;
	if(isEmpty(in)==true) {
		printf("error set is empty");
		return -1;
	}
	sort(in);
	s=in->list[in->items-1];
	return s;
}	
                             // and exits if set is empty
int smallest(const intSet in) {
	int s;
	if(isEmpty(in)==true) {
		printf("error set is empty");
		return -1;
	}
	sort(in);
	s=in->list[0];
	return s;
}	
		// returns the smallest item in the set; prints error message
                             // and exits if set is empty
							 
void sort(intSet s) {
	if(s->items>2) {
	int i=0;
	int si;
	int j=0;
	int b=i+1;
	int t;
	while(i<s->items) {
		if(s->list[b]<s->list[i]) {
			si=i;
			for(j=b;j>-1;j--) {
				if(s->list[j]<s->list[si]) {
					
				t = s->list[si];
				s->list[si] = s->list[j];
				s->list[j] = t;
				si--;
				}
			}
		}
		i++;
	}
	}
}

void add(intSet s,int item) {
	printf("in add\n");
	if(contains(s,item)!=true) {
	int i;
	s->items++;
	resize(s);
			s->list[s->items-1]=item;
	printf("new list:\n");
	for(i=0;i<s->size;i++) {
		printf("%d ",s->list[i]);
	}
	printf("\nitems: %d\n",s->items);
	}
}
	
	int find(intSet s, int item) {
		int i;
		for(i=0;i<s->items;i++) {
			if(s->list[i]==item) return i;
		}
		printf("not in set\n");
		return -1;
	}
		
	
void remove_(intSet s,int item) {
	printf("in remove\n");
	int f=find(s,item);
	int i;
	if(f>=0) {
		s->list[f]=(int) NULL;
		for(i=f;i<s->items;i++) {
			s->list[i]=s->list[i+1];
		}
		for(i=s->items;i<s->size;i++) {
			s->list[i]=(int) NULL;
		}
	}
	//sort(s);
}
		
intSet union_(const intSet s1, const intSet s2) {
	intSet out = createSet();
	int l,i;
	if(s1->items<s2->items) l=s2->items;
	if(s1->items>s2->items) l=s1->items;
	for(i=0;i<l;i++) {
		if(s1->list[i]!=(int) NULL) { 
		add(out,s1->list[i]);
		}
		if(s2->list[i]!=(int) NULL) { 
		add(out,s2->list[i]); 
		}
	}
	resize(out);
	sort(out);
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
	resize(out);
	sort(out);
	return out;
}
	
	
intSet diff(const intSet s1, const intSet s2) { // set difference, i.e. s1 - s2
  intSet out = createCopy(s1);
  int i;
  for(i=0;i<s1->items;i++) {
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
	sort(in);
	for(i=0;i<in->items;i++) {
		iarray[i] = in->list[i];
	}
	return iarray;
}
	
	// returns an array representation of the set in
                              // ascending order
char *toString(const intSet in) {
	if(isEmpty(in)==true) { return "{}"; }
	int* iarr = toArray(in);
	int bS=500;
	int i,j,bI=0;
	char* buff = (char*) malloc(bS*sizeof(char));
	buff[bI] = '{';
	bI++;
	for(i=0;i<in->items;i++) {
			char* currentItem = (char*) malloc(30*sizeof(char));
			sprintf(currentItem, "%d", iarr[i]);
			for(j=0;j<strlen(currentItem);j++) {
				buff[bI]=currentItem[j];
				bI++;
			}
			if(i < in->items-1) {
				buff[bI] = ',';
				bI++;
			}
			free(currentItem);
	}
	buff[bI] = '}';
	return buff;
}

// returns a string representation of the set in
                              // ascending order;  e.g. an empty set returns "{}", and
                              // a non-empty set containing the values 9,-52,17 would
                              // return the string "{-52,9,17}"
							  
							  
							  
							  
							  
	if(isEmpty(in)==true) { return "{}"; }
	int* iarr = toArray(in);
	int bS=500;
	int i,j,bI=0;
	char* buff = (char*) malloc(bS*sizeof(char));
	buff[bI] = '{';
	bI++;
	for(i=0;i<in->items;i++) {
			char* currentItem = (char*) malloc(30*sizeof(char));
			sprintf(currentItem, "%d", iarr[i]);
			for(j=0;j<strlen(currentItem);j++) {
				buff[bI]=currentItem[j];
				bI++;
			}
			if(i < in->items-1) {
				buff[bI] = ',';
				bI++;
			}
			free(currentItem);
	}
	buff[bI] = '}';
	