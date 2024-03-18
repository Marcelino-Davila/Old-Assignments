#ifndef SPECIES_H
#define SPECIES_H
#include <stdio.h>
#include "instruction.h"

typedef struct speciesType *species;

species createSpecies(char* file); // passed the file name of the species file 
void freeSpecies(species);         // frees up all memory used for species 
  
FILE *getFilePtr(species);      // returns FILE pointer for species
void setFilePtr(species,FILE*); // sets FILE pointer for species
char *getFileName(species);
void setFileName(species,char*);
char *getSpeciesName(species);
void setSpeciesName(species,char*);

void addInstruct(species s, instruction ins);    /* 1st line == 0 */
// adds instruction ins to end of species code
void setInstruct(species s,instruction ins,int n);
// set instruction #n to ins in species s
instruction getInstruct(species s,int n);
// returns instruction #n for species s

int getLinesOfCode(species); /* 1st line == 0 */

char *toSpeciesString(species); /* format: "(name,lines:0)" */

#endif
