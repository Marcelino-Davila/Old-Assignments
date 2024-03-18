// gcc unity.c instructionUnity.c instruction.c

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "instruction.h"

void setUp(void){  /* set stuff up here */ }
void tearDown(void){ /* clean stuff up here */ }

void createInstruction_(void) {
  instruction i = createInstruction();
  TEST_ASSERT_NOT_NULL_MESSAGE(i,"createInstruction #1 failed");  
}

void freeInstruction_(void) {
  freeInstruction(createInstruction());
}

void getOperator_(void) {
  instruction i = createInstruction();
  TEST_ASSERT_EQUAL_INT_MESSAGE(NOP,getOperator(i),"getOperator #1 failed");
}

void setOperator_(void) {
  instruction i = createInstruction();
  setOperator(i,GO);
  opcode opc = getOperator(i);
  TEST_ASSERT_EQUAL_INT_MESSAGE(GO,opc,"setOperator #1 failed");
}

void getOperand_(void) {
  instruction i = createInstruction();
  int r = getOperand(i);
  TEST_ASSERT_EQUAL_INT_MESSAGE(-1,r,"getOperand #1 failed");
}

void setOperand_(void) { 
  instruction i = createInstruction();
  setOperand(i,100);
  int r = getOperand(i);
  TEST_ASSERT_EQUAL_INT_MESSAGE(100,r,"setOperand #1 failed");
}

void hasOperand_(void) {
  TEST_ASSERT_TRUE_MESSAGE(hasOperand(GO),"hasOperand #1 failed");
  TEST_ASSERT_FALSE_MESSAGE(hasOperand(NOP),"hasOperand #2 failed");
}

void toOperator_(void) {
  opcode opr = toOperator("LEFT");
  TEST_ASSERT_EQUAL_INT_MESSAGE(LEFT,opr,"toOperator #1 failed");
  opr = toOperator("right");
  TEST_ASSERT_EQUAL_INT_MESSAGE(RIGHT,opr,"toOperator #2 failed");
}

void toInstructionString_(void) {
  instruction i = createInstruction();
  char *s = toInstructionString(i);
  TEST_ASSERT_EQUAL_STRING_MESSAGE(s,"nop","toInstructionString #1 failed");
}

void toOperatorString_(void){
  char *s = toOperatorString(INFECT);
  TEST_ASSERT_EQUAL_STRING_MESSAGE(s,"infect","toOperatorString #1 failed");
}

void toOperandString_(void){
  char *s = toOperandString(-999);
  TEST_ASSERT_EQUAL_STRING_MESSAGE(s,"-999","toOperandString #1 failed");
}

int main ( void ){
  UNITY_BEGIN();
  RUN_TEST(createInstruction_);
  RUN_TEST(freeInstruction_);
  RUN_TEST(getOperator_);
  RUN_TEST(setOperator_);
  RUN_TEST(getOperand_);
  RUN_TEST(setOperand_);
  RUN_TEST(hasOperand_);
  RUN_TEST(toOperator_);
  RUN_TEST(toInstructionString_);
  RUN_TEST(toOperatorString_);
  RUN_TEST(toOperandString_);
 return UNITY_END();
}
   
