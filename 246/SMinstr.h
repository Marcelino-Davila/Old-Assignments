#include <stdbool.h>
#include <limits.h>

#ifndef SMINSTR_H
#define SMINSTR_H

#define NOTHING (INT_MIN+1) /* must be < 0 */ 

typedef struct instrType *instr;

instr createSMinstr(char*); // is passed opcode mnemonic, e.g. "LDC"; sets
                            // operand and label values to NOTHING, operand
                            // string to NULL
void freeSMinstr(instr);

int   getRator(instr i);   // returns opcode number of i
int   getRand(instr i);    // returns operand value of i
char *getStrRand(instr i); // returns string operand of i
int   getLabel(instr i);   // returns label value of i
void  setRator(instr i,int opc);    // sets opcode in i to opc
void  setRand(instr i, int rand);   // sets operand in i to rand
void  setStrRand(instr i, char *s); // sets string operand in i to s
void  setLabel(instr i,int l);      // sets label in i to l

int   numOpCodes(); // returns number of opcodes, with 0 <= legalOp < numOpCodes()

char *toString(instr i); // returns string representation of instruction
bool  isInstr(char*);    // returns true if argument is a legal instruction
bool  hasOperand(int);   // returns true if opcode needs/has an operand
bool  hasLabel(int);     // returns true if opcode needs/has a label 
bool  hasStringOperand(int); // returns true if opcode needs/has a string operand
char *toOpcodeStr(int);  // when passed an opcode, returns string mnemonic
                         // or "ILLEGAL" if not legal opcode
int   toOpcodeNum(char*);// returns opcode for mnemonic, NOTHING value
                         // if not legal opcode

#endif
