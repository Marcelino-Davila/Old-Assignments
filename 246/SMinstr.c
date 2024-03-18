#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "SMinstr.h"

#define NUM_OPCODES 29 /*count of class opc's opcodes array defined below*/

struct instrType {
  int label, rator, rand;
  char *strRand;
};

static char *opcodes[NUM_OPCODES]=
  { // part 1 opcodes
    "CLR","HALT","NEG","DUP","ADD","SUB","MUL","DIV","LDC",        /* count: 9 */
    "INP","OUT","DBG","TRA","SWAP",                                /* count: 5 */
    // part 2 opcodes
    "LDA","STO","EQ","LESS","GTR","NOT","JMP","JMPZ","NOP",        /* count: 9 */
    // part 3 opcodes
    "CALL","RET","ARGS",                                           /* count: 3 */
    // experimental
    "OUTS","NLN","TRAS"                                            /* count: 3 */ 
  };

//-------------------------------------------------------------

static void _strupr(char *s) { while(*s) { *s = toupper(*s); s++; } }

static char *ots(int i) {
  if(i<0 || i>=NUM_OPCODES) return "ILLEGAL";
  return opcodes[i];
}

static int sto(char* s) {
  char tmp[7];
  strcpy(tmp,s); _strupr(tmp);
  for(int i=0; i< NUM_OPCODES; i++)
    if(strcmp(opcodes[i],tmp)==0)
      return i;
  return NOTHING;
}

static char *_strrev(char *s) {
  int len = strlen(s), begin, end;
  char *r = malloc(len+1);
  end = len - 1;
  for (begin = 0; begin < len; begin++) {
    r[begin] = s[end];
    end--;
  }
  r[begin] = '\0';
  return r;
}

// from K&R I think
static char *intoa(int n){
  int i, sign;
  char *s = malloc(30);
  if ((sign = n) < 0) n = -n; 
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  return _strrev(s);
 }

//================================================================  

instr createSMinstr(char* s) {
  int opc = toOpcodeNum(s);
  if(opc == NOTHING) return NULL;
  instr i = malloc(sizeof(struct instrType));
  i->rator = toOpcodeNum(s);
  i->label = i->rand = NOTHING;
  i->strRand = NULL;
  return i; 
}

void freeSMinstr(instr i) { free(i->strRand); free(i); }

// getters/setters
int getRator(instr i) { return i->rator; }
int getRand(instr i) { return i->rand; }
char *getStrRand(instr i) { return i->strRand; }
int getLabel(instr i) { return i->label; }
void setRator(instr i,int opc) {
  if(opc >= 0 && opc < NUM_OPCODES) i->rator = opc;
}
void setRand(instr i, int rand) { i->rand = rand; }
void setStrRand(instr i, char *s) {
  strcpy(i->strRand = malloc(strlen(s)+1),s);
}
void setLabel(instr i,int l) { i->label = l; }

char *toString(instr i){
  char *buff = malloc(80);
  if(i==NULL) strcpy(buff,"NULL");
  else {
    bool hasLab = hasLabel(i->rator),
      hasStrOper = hasStringOperand(i->rator),
      hasRand = hasOperand(i->rator);
    sprintf(buff,"%s%s%s%s%s%s%s%s",
            hasLab?intoa(i->label):"",
            hasLab?": ":"",
            ots(i->rator),
            hasStrOper?" \"":"",
            hasStrOper?i->strRand:"",
            hasStrOper?"\"":"",
            hasRand?" ":"",
            hasRand?intoa(i->rand):"");
  }
  char *str = malloc(strlen(buff)+1);
  strcpy(str,buff);
  free(buff);
  return str;
}

bool hasOperand(int n) {
    return ( n==toOpcodeNum("LDC")  || n==toOpcodeNum("LDA") ||
	     n==toOpcodeNum("STO")  || n==toOpcodeNum("JMP") ||
	     n==toOpcodeNum("JMPZ") || n==toOpcodeNum("CALL")||
             n==toOpcodeNum("OUTS") );
  }
bool hasLabel(int n) { return (n==toOpcodeNum("NOP")); }
bool hasStringOperand(int n) { return (n==toOpcodeNum("OUTS")); }

int numOpCodes() { return NUM_OPCODES; }
bool isInstr(char *s) { return (toOpcodeNum(s) != NOTHING); }

char *toOpcodeStr(int n) { return ots(n); }
int toOpcodeNum(char *s) { return sto(s); }

