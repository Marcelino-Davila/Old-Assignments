#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdbool.h>

typedef enum {HOP,LEFT,RIGHT,INFECT,IFEMPTY,IFWALL,IFSAME,IFENEMY,IFRANDOM,GO,NOP,END} opcode;
typedef struct instructionType *instruction;

instruction createInstruction(); /* creates NOP with operand of -1 */
void freeInstruction(instruction);

opcode getOperator(instruction);
void setOperator(instruction,opcode);

opcode getOperand(instruction);
void setOperand(instruction,int);
bool hasOperand(opcode);

opcode toOperator(char*);
char *toInstructionString(instruction);
char *toOperatorString(opcode);
char *toOperandString(int);

#endif
