#include "species.h"
#include <stdlib.h>
#include "instruction.h"
#include <string.h>

/*Marcileno Devila
Frank Kengni
project 4*/

struct speciesType {
	FILE* file;
	char* fname;
	char* sname;
	int numLines;
	instruction ins [100];
};             

species createSpecies(char* file) {
	int i;
	species s = malloc(sizeof(struct speciesType));
	s->file = malloc(sizeof(FILE));
	s->file = NULL;
	char* buff = malloc(1000*sizeof(char));
	sprintf(buff,"%s",file);
	s->fname = malloc(strlen(buff)*sizeof(char));

	strcpy(s->fname,buff);
	for (i=0;i<100;i++) {
		s->ins[i] = createInstruction();
	}
	s->numLines=0;
	s->sname = malloc(10*sizeof(char));
	s->sname = NULL;
	return s;
}	// passed the file name of the species file 
void freeSpecies(species s) {
	free(s->sname);
	free(s->fname);
	int i;
	for(i=0;i<s->numLines;i++) {
		freeInstruction(s->ins[i]);
	}
	free(s);
}	// frees up all memory used for species 
  
FILE *getFilePtr(species x) { return x->file; }

void setFilePtr(species x,FILE* f) {
	x->file=f;
}

char *getFileName(species x) {                          
return x->fname; 
}

void setFileName(species x,char* n) {
	free(x->fname);
	x->fname = malloc(strlen(n)*sizeof(char));
	strcpy(x->fname,n);
}
	
char *getSpeciesName(species x) {
if (x->sname == NULL) {
	return "";
}
return x->sname;
}

void setSpeciesName(species x,char* s) {
	free(x->sname);
	x->sname = malloc(strlen(s)*sizeof(char));
	strcpy(x->sname,s);
}

void addInstruct(species s, instruction ins) {
	setOperator(s->ins[s->numLines], getOperator(ins));
	setOperand(s->ins[s->numLines],getOperand(ins));
	s->numLines++;
}	/* 1st line == 0 */
// adds instruction ins to end of species code
void setInstruct(species s,instruction ins,int n) {
	setOperator(s->ins[n], getOperator(ins));
	setOperand(s->ins[n],getOperand(ins));	
}
// set instruction #n to ins in species s
instruction getInstruct(species s,int n) { return s->ins[n]; }
// returns instruction #n for species s

int getLinesOfCode(species x) { return x->numLines; } 

char *toSpeciesString(species x) {
	if (x->sname == NULL) {
		char* buff = (char*) malloc(100*sizeof(char));
		sprintf(buff,"([empty],lines:%d)",x->numLines);
		char* string = malloc(strlen(buff)*sizeof(char));
		strcpy(string,buff);
		free(buff);
		return string;
	}
	char* buff = malloc(strlen(x->sname)*4*sizeof(char));
	sprintf(buff, "(%s,lines:%d)",x->fname,x->numLines);
	char* str = malloc(strlen(buff)*sizeof(char));
	strcpy(str,buff);
	free(buff);
	return str;
}
	/* format: "(name,lines:0)" */