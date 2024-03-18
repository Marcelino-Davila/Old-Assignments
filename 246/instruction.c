// Dan Resler 10/22

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "instruction.h"

struct instructionType { opcode rator; int rand; };

instruction createInstruction() {
  instruction ip = malloc(sizeof(struct instructionType));
  ip->rator = NOP; ip->rand=-1;
  return ip;
}
void freeInstruction(instruction ip) { free(ip); }

opcode getOperator(instruction ip) { return ip->rator; }
void setOperator(instruction ip,opcode op) { ip->rator = op; } 

opcode getOperand(instruction ip) {return ip->rand; }
void setOperand(instruction ip,int n) { ip->rand = ((n>0)?n:-1); }

char *toInstructionString(instruction ip) {
  char *s = malloc(strlen("ifrandom")+5);  
  strncpy(s,toOperatorString(ip->rator),strlen("ifrandom")+4);
  if(hasOperand(ip->rator)) strncat(s,toOperandString(ip->rand),strlen("ifrandom")+4);
  return s;
}

bool hasOperand(opcode inst) {
  return (!(inst==HOP || inst==LEFT || inst==RIGHT || inst==NOP || inst==END));
}

char *toOperatorString(opcode ins) {
  char *ts = calloc(strlen("ifrandom")+1,sizeof(char));
  switch(ins) {
  case HOP:      strcpy(ts,"hop");      break;
  case LEFT:     strcpy(ts,"left");     break;
  case RIGHT:    strcpy(ts,"right");    break;
  case INFECT:   strcpy(ts,"infect");   break;
  case IFEMPTY:  strcpy(ts,"ifempty");  break;
  case IFWALL:   strcpy(ts,"ifwall");   break;
  case IFSAME:   strcpy(ts,"ifsame");   break;
  case IFENEMY:  strcpy(ts,"ifenemy");  break;
  case IFRANDOM: strcpy(ts,"ifrandom"); break;
  case GO:       strcpy(ts,"go");       break;
  case NOP:      strcpy(ts,"nop");      break;
  case END:      strcpy(ts,"end");      break;
  default:
    printf("Error -- illegal instruction in toOperatorString\n");
    exit(EXIT_FAILURE);
    break;
  }
  return ts;
}

char *toOperandString(int rand) {
  char *s=calloc(6,sizeof(char));
  snprintf(s,5,"%d",rand);
  return s;
}  

static char *toLowercase(char *s) {
  char *ts = malloc(sizeof(s)+1);
  strcpy(ts,s);
  for(int i = 0; ts[i] != '\0'; i++)
    ts[i] = tolower(ts[i]);
  return ts;
}

opcode toOperator(char *s) {
  char *ts = toLowercase(s);
  if (strcmp(ts,"hop")==0)          return HOP;
  else if(strcmp(ts,"left")==0)     return LEFT;
  else if(strcmp(ts,"right")==0)    return RIGHT;
  else if(strcmp(ts,"infect")==0)   return INFECT;
  else if(strcmp(ts,"ifempty")==0)  return IFEMPTY;
  else if(strcmp(ts,"ifwall")==0)   return IFWALL;
  else if(strcmp(ts,"ifsame")==0)   return IFSAME;
  else if(strcmp(ts,"ifenemy")==0)  return IFENEMY;
  else if(strcmp(ts,"ifrandom")==0) return IFRANDOM;
  else if(strcmp(ts,"go")==0)       return GO;
  else if(strcmp(ts,"nop")==0)      return NOP;
  else if(strcmp(ts,"end")==0)      return END;
  else                              return NOP;
}
