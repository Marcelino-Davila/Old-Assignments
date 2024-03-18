#include <stdio.h>
#include <stdbool.h>
#include "intSet.h"

int main(void) {
  intSet is2,is1;
  is1 = createSet();
  is2 = createSet();
  
  clear(is1);
  card(is1);
  if( equals(is1,is2)==true) printf("true\n");
  if(contains(is1,100)==false) printf("false\n");
  remove_(is1,100);
  add(is1,100);
  printf("\n\n%d\n\n",largest(is1));
  printf("\n\nsmall%d\n\n",smallest(is1));
  union_(is1,is2);
  intersect(is1,is2);

  diff(is1,is2);
  isEmpty(is1);
 
  toArray(is1);
  toString(is1);
  destroySet(is1);
  printf("=== program compiled and ran ok ===\n");
  return 0;
}


// returns a string representation of the set in
                              // ascending order;  e.g. an empty set returns "{}", and
                              // a non-empty set containing the values 9,-52,17 would
                              // return the string "{-52,9,17}"
			
					
						  
#include "intSet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct intsetType {
int* data; // internal array to represent set
int capacity; // size of internal array
int count; // number of element in array
};

intSet createSet() {
// create a set with default capacity 5
intSet s = (intSet)malloc(sizeof(struct intsetType));
s->capacity = 5;
s->count = 0; // initialy no item in set
s->data = (int*)malloc(sizeof(int) * s->capacity);
return s;
}

void destroySet(intSet s) {
// first remove internal array of set
free(s->data);
// remove set
free(s);
}

void clear(intSet s) {
// set number of item in set to 0
s->count = 0;
}

int card(const intSet s) {
return s->count;
}

bool equals(const intSet s1, const intSet s2) {
// both set to be equal must have same number of elements in set
if (card(s1) == card(s2)) {
// set does not contains same elements so loop over one set
// and find element in other set if all elements are found then
// both sets are equal
for (int i = 0; i < card(s1); i++) {
// get each elemnt from s1 and check if they are in s2
int item = s1->data[i];
if (!contains(s2, item)) {
return false;
}
}
return true;
}
return false;
}

bool contains(const intSet s, int item) {
// loop over set to check if has given item
for (int i = 0; i < card(s); i++) {
if (s->data[i] == item) {
return true;
}
}
return false;
}

int largest(const intSet s) {
if (isEmpty(s)) {
printf("ERROR : can not call largest() on empty set!\n");
exit(EXIT_FAILURE);
}
int max = s->data[0]; // initialy set first item as largest
// loop over set to find largest item
for (int i = 1; i < card(s); i++) {
if(s->data[i] > max){
max = s->data[i];
}
}
return max;
}

int smallest(const intSet s) {
// check for empty set
if (isEmpty(s)) {
printf("ERROR : can not call samllest() on empty set!\n");
exit(EXIT_FAILURE);
}
int min = s->data[0]; // initialy set first item as samllest
// loop over set to find samllest item
for (int i = 1; i < card(s); i++) {
if (s->data[i] < min) {
min = s->data[i];
}
}
return min;
}

void add(intSet s, int item) {
if (!contains(s, item)) {
if (s->count == s->capacity) {
s->capacity = s->capacity * 2;
int* temp = (int*)malloc(sizeof(int) * s->capacity);
for (int i = 0; i < card(s); i++) {
temp[i] = s->data[i];
}
free(s->data);
s->data = temp;
}
s->data[s->count] = item;
s->count++;
}
}

void remove_(intSet s, int item) {
// loop over set to find the given item
for (int i = 0; i < card(s); i++) {
if (s->data[i] == item) {
// to remove item from set
// move every element from set one spot left
for (int j = i + 1; j < card(s); j++) {
s->data[j - 1] = s->data[j];
}
// decrase item counts
s->count--;
// break the loop when item is removed
break;
}
}
}

intSet union_(const intSet s1, const intSet s2) {
// create a new set as union of both set
intSet u = createSet();
// add all items from s1 and s2
for (int i = 0; i < card(s1); i++) {
add(u, s1->data[i]);
}
for (int i = 0; i < card(s2); i++) {
add(u, s2->data[i]);
}
// return resulting set
return u;
}

intSet intersect(const intSet s1, const intSet s2) {
// create a new set for intersection of both set
intSet n = createSet();
// add all items from s1 that are in s2
for (int i = 0; i < card(s1); i++) {
if (contains(s2, s1->data[i])) {
add(n, s1->data[i]);
}
}
// return resulting set
return n;
}

intSet diff(const intSet s1, const intSet s2) {
// create a new set as copy of set1
intSet d = createSet();
for (int i = 0; i < card(s1); i++) {
add(d, s1->data[i]);
}
// remove each item from set1 that are in set2
for (int i = 0; i < card(s1); i++) {
if (contains(s2, s1->data[i])) {
remove_(d, s1->data[i]);
}
}
// return resulting set
return d;
}

bool isEmpty(const intSet s) {
return card(s) == 0;
}

int* toArray(const intSet s) {
// check for empty array
if (card(s) == 0) {
return NULL;
}
// create an arary to return
int* arr = (int*)malloc(sizeof(int) * card(s));
// copy the data from set
for (int i = 0; i < card(s); i++) {
arr[i] = s->data[i];
}
// use selection sort
for (int i = 0; i < card(s); i++) {
int min = arr[i]; // current minimum
int index = i; // index of minimum item in array
// find minimum from remaining array data
for (int j = i+1; j < card(s); j++) {
if (arr[j] < min) {
min = arr[j];
index = j;
}
}
// swap elements
arr[index] = arr[i];
arr[i] = min;
}
// return sorteed array
return arr;
}

char* toString(const intSet s) {
// 1000 is initial buffer capacity
int buffer_cap = 1000;
// create a buffer char array to hold string
char* buffer = (char*)malloc(sizeof(char) * buffer_cap);
int index = 0; // index to write in buffer
// first add {
buffer[index] = '{';
index++;
// get items from set as array of integer
int* items = toArray(s);
// write each item from set to buffer
for (int i = 0; i < card(s); i++) {
char* number = (char*)malloc(sizeof(char) * 15);
sprintf(number, "%d", items[i]);
int size = strlen(number);
for (int j = 0; j < size; j++) {
if (buffer_cap < index + 3) { // last 2 index for "}" and "\0"
buffer_cap = buffer_cap * 2;
char* temp = (char*)malloc(sizeof(char) * buffer_cap);
// copy the array
for (int b = 0; b < index; b++) {
temp[b] = buffer[b];
}
// remove old buffer
free(buffer);
// re assign buffer
buffer = temp;
}
buffer[index] = number[j];
index++;
}
// add comma
if (i < card(s) - 1) {
buffer[index] = ',';
index++;
}
// free number memory
free(number);
}
// add last }
buffer[index] = '}';
index++;
buffer[index] = '\0';
// create a new char array to return
char* str = (char*)malloc(sizeof(char) * strlen(buffer));
strcpy(str, buffer);
// free allocated memory
free(items);
free(buffer);
return str;
}

char *toString(const intSet in) {
	if(isEmpty(in)==true) { return "{}"; }
	int* iarr = toArray(in);
	int bS=500;
	int i,j,z,bI=0;
	char* buff = (char*) malloc(bS*sizeof(char));
	buff[bI] = '{';
	bI++;
	for(i=0;i<in->items;i++) {
			char* currentItem = (char*) malloc(30*sizeof(char));
			sprintf(currentItem, "%d", iarr[i]);
			for(j=0;j<strlen(currentItem);j++) {
				if(bS < bI+3) {
					bS*=1.5;
					char *bigBuff = (char*) malloc(bS*sizeof(char));
					for(z=0;z<bI;z++) {
						bigBuff[z] = buff[z];
					}
					free(buff);
					buff = (char*) (bS*sizeof(char));
					strcpy(bigBuff,buff);
				}
				if(currentItem[j]==0) {
					buff[bI] = '0';
				}
				else if(currentItem[j]!=0) {
				buff[bI] = currentItem[j];
				}
				bI++;
			}
			if(i < in->items-1) {
				buff[bI] =',';
				bI++;
			}
			free(currentItem);
	}
	buff[bI] = '}';
	bI++;
	buff[bI] = '\0';
	char *tString = (char*) malloc((strlen(buff))*sizeof(char));
	strcpy(tString,buff);
	free(buff);
	free(iarr);
	return tString;
}
