// updated 10/28/22
//
// gcc unity.c speciesUnity.c species.c instruction.c

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "species.h"

FILE *fp;

void setUp(void){
  fp = fopen("mongrols","w");
  fprintf(fp,"created by speciesUnity.c\n");
  fclose(fp);
}

void tearDown(void){ remove("mongrols"); }

void createSpecies_(void) {
  species s = createSpecies("mongrols");
  TEST_ASSERT_NOT_NULL_MESSAGE(s,"createSpecies #1 failed");
}

void freeSpecies_(void) {
  freeSpecies(createSpecies("mongrols"));
}

void getFilePtr_(void) {
  species s = createSpecies("mongrols");
  FILE *fp = getFilePtr(s);
  TEST_ASSERT_NULL_MESSAGE(fp,"getFilePtr #1 failed");
}

void setFilePtr_(void) {
  species s = createSpecies("mongrols");
  setFilePtr(s,fp);
  FILE *p = getFilePtr(s);
  TEST_ASSERT_NOT_NULL_MESSAGE(p,"setFilePtr #1 failed");
}

void getFileName_(void) {
  species s = createSpecies("mongrols");
  char *name = getFileName(s);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("mongrols",name,"getFileName #1 failed");  
}

void setFileName_(void) {
  species s = createSpecies("mongrols");
  setFileName(s,"klingons");
  char *name = getFileName(s);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("klingons",name,"setFileName #1 failed");  
}

void getSpeciesName_(void){
  species s = createSpecies("mongrols");
  char *name  = getSpeciesName(s);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("",name,"getSpeciesName #1 failed");  
}

void setSpeciesName_(void) {
  species s = createSpecies("mongrols");
  setSpeciesName(s,"klingons");
  char *name  = getSpeciesName(s);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("klingons",name,"setSpeciesName #1 failed");  
}

void addANDgetInstruct(void) {
  species s = createSpecies("mongrols");
  instruction ins1 = createInstruction();  
  addInstruct(s, ins1);
  instruction ins2 = getInstruct(s,1);
  opcode oper = getOperator(ins2);
  TEST_ASSERT_EQUAL_INT_MESSAGE(NOP,oper,"addANDgetInstruct #1 failed");
  int opc = getOperand(ins2);
  TEST_ASSERT_EQUAL_INT_MESSAGE(-1,opc,"addANDgetInstruct #2 failed");  
}

void addAndsetANDgetInstruct(void){
  species s = createSpecies("mongrols");
  instruction ins1 = createInstruction();  
  addInstruct(s, ins1);
  setOperator(ins1,IFENEMY); setOperand(ins1,2);
  setInstruct(s,ins1,1);
  instruction ins2 = getInstruct(s,1);  
  opcode oper = getOperator(ins2);
  TEST_ASSERT_EQUAL_INT_MESSAGE(IFENEMY,oper,"addAndsetANDgetInstruct #1 failed");
  int opc = getOperand(ins2);
  TEST_ASSERT_EQUAL_INT_MESSAGE(2,opc,"addAndsetANDgetInstruct #2 failed");   
}

void getLinesOfCode_(void){
  species s = createSpecies("mongrols");
  instruction ins1 = createInstruction();  
  addInstruct(s, ins1);
  int n = getLinesOfCode(s);
  TEST_ASSERT_EQUAL_INT_MESSAGE(1,n,"getLinesOfCode #2 failed");   
}

void toSpeciesString_(void){
  species s = createSpecies("mongrols");
  char *str = toSpeciesString(s);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("([empty],lines:0)",str,"toSpeciesString #1 failed");
  setSpeciesName(s,"mongrols");
  str = toSpeciesString(s);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("(mongrols,lines:0)",str,"toSpeciesString #2 failed");
}

int main ( void ){
  UNITY_BEGIN();
  RUN_TEST(createSpecies_);
  RUN_TEST(freeSpecies_);
  RUN_TEST(getFilePtr_);
  RUN_TEST(setFilePtr_);
  RUN_TEST(getFileName_);
  RUN_TEST(setFileName_);
  RUN_TEST(getSpeciesName_);
  RUN_TEST(setSpeciesName_);
  RUN_TEST(addANDgetInstruct);
  RUN_TEST(addAndsetANDgetInstruct);    
  RUN_TEST(getLinesOfCode_);    
  RUN_TEST(toSpeciesString_);    
  return UNITY_END();
}
   
