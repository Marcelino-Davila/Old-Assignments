#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define STACK_ESIZE 100

// Marcelino Davila, Frank Kengni Project 5
//12/2


struct stackType {
	int* data;
	int trace, pc, top, size;
};

typedef struct stackType *stack;

stack cStack(){
	stack s = malloc(sizeof(struct stackType));
	s->data = (int*) malloc(STACK_ESIZE*sizeof(int));
	s->size = STACK_ESIZE;
	s->trace = 0;
	s->top = -1;
	s->pc = 0;
	return s;
}

void HALT(stack s) { 
if(s->trace==1) printf("[machine halted]\n");
exit(EXIT_FAILURE); 
}

void destroyStack(stack s) {
	free(s->data);
	free(s);
}

void LDC(int n, stack s) {
	if(s->top+1==s->size) {
		int i;
		s->size =s->size+STACK_ESIZE;
		int* temp = (int*) malloc(s->size*sizeof(int));
		for(i=0;i<s->top+1;i++) {
			temp[i] = s->data[i];
		}
		free(s->data);
		s->data = temp;
		free(temp);
	}
s->top++;
s->data[s->top] = n;
}

void OUT(stack s) {
			if(isEmpty(s)) {
		printf("[error - empty stack]\n");
		HALT(s);
	}
	printf("output: %d\n",s->data[s->top]);
	s->top--;
}
	
void TRA(stack s) {
	if(s->trace == 1) {
		s->trace = 0;
		return;
	}
	s->trace = 1;
}

void CLR(stack s) { s->top = -1; }

void ADD(stack s) {
			if(isEmpty(s)) {
		printf("[error - empty stack]\n");
		HALT(s);
	}
	int n = s->data[s->top] + s->data[s->top-1];
	s->top--;
	s->top--;
	LDC(n,s);
}

void SUB(stack s) {
				if(isEmpty(s)) {
		printf("[error - empty stack]\n");
		HALT(s);
	}
	int n = s->data[s->top] - s->data[s->top-1];
	s->top--;
	s->top--;
	LDC(n,s);
}

void MUL(stack s) {
				if(isEmpty(s)) {
		printf("[error - empty stack]\n");
		HALT(s);
	}
	int n = s->data[s->top] * s->data[s->top-1];
	s->top--;
	s->top--;
	LDC(n,s);
}

void DIV(stack s) {
				if(isEmpty(s)) {
		printf("[error - empty stack]\n");
		HALT(s);
	}
		if (s->data[s->top-1]==0) {
		printf("[error - division by zero]\n");
		HALT(s);
	}
	int n = s->data[s->top] / s->data[s->top-1];
	s->top--;
	s->top--;
	LDC(n,s);
}
void INP(stack s) {
	int n;
	printf("input: ");
	scanf("%d", &n);
	LDC(n,s);
}
void DUP(stack s) {
		if(isEmpty(s)) {
		printf("[error - empty stack]\n");
		HALT(s);
	}
	LDC(s->data[s->top],s);
}

void NEG(stack s) {
					if(isEmpty(s)) {
		printf("[error - empty stack]\n");
		HALT(s);
	}
	s->data[s->top] *=-1;
}

void SWAP(stack s) {
					if(isEmpty(s)) {
		printf("[error - empty stack]\n");
		HALT(s);
	}
	int x = s->data[s->top];
	s->data[s->top] = s->data[s->top-1];
	s->data[s->top-1] = x;
}

char *tString(stack s) {
	int buffSize = 10000;
	char *buff = malloc(10000*sizeof(char));
	sprintf(buff,"[");
	for(int i=0;i<s->top+1;i++) {
		char *num = malloc(100*sizeof(char));
		sprintf(num,"%d",s->data[i]);
		if(buffSize<strlen(buff)+111) {
			buffSize*=2;
			char *temp = malloc(buffSize*sizeof(char));
			for (int b = 0; b < buffSize; b++) {
				temp[b] = buff[b];
			}
			free(buff);
			buff= temp;
			free(temp);
		}
		strcat(buff,num);
		if(i<s->top) strcat(buff,",");
		free(num);
		
	}
	strcat(buff,"](top)");
	char* str = malloc((strlen(buff)+1)*sizeof(char));
	strcpy(str,buff);
	free(buff);
	return str;
}

void DBG(stack s) {
	if(isEmpty(s)) {
		printf("[error - empty stack]\n");
		HALT(s);
	}
	printf("DEBUG: %s\n",tString(s));
}

void JMP(int n, FILE *fp) {
	rewind(fp);
	char *tag = malloc(100*sizeof(char));
	sprintf(tag,"%d:",n);
	char *jump = malloc(100*sizeof(char));
	while(!feof(fp)){
		fscanf(fp,"%s",jump);
		if (strcmp(jump,"%") == 0) {
			fscanf(fp,"%*[^\n]");
		}
		if(strcmp(jump,tag)==0) {
		fscanf(fp,"%*[^\n]");
			break;
		}
	}
	free(tag);
	free(jump);
}

void JMPZ(int n, FILE *fp, stack s) {
	if(s->data[s->top]==0) {
		JMP(n,fp);
	}
	s->top--;
}

void LDA(stack s, int n) {
	LDC(s->data[n-1],s);
}

void STO(int n,stack s) {
	s->data[n-1] = s->data[s->top];
	s->top--;
}

void EQ(stack s) {
	if(s->data[s->top]==s->data[s->top-1]) {
			s->top--;
				s->top--;
				LDC(1,s);
	}
	else {
			s->top--;
			s->top--;
			LDC(0,s);
	}
}

void GTR(stack s) {
	int x = s->data[s->top];
	s->top--;
	int i = s->data[s->top];
	s->top--;
		if(i>x) {
			LDC(0,s);
	}
	else {
			LDC(1,s);
}
}

void LESS(stack s) {
	int x = s->data[s->top];
	s->top--;
	int i = s->data[s->top];
	s->top--;
		if(i<x) {
			LDC(0,s);
	}
	else {
			LDC(1,s);
}
}

void NOT(stack s) {
	s->data[s->top]*=-1;
}
	
int main(int argc, char *argv[]) {
	int i;
	printf("Marcelino Davila, Frank Kengni \n Project 5 11/16\n\n");
	FILE *fp;
	char fileName[20];
	if (argc > 1) {
		strcpy(fileName,argv[1]);
	} else {
		printf("Error - no file given on command line\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(fileName, "r");
	stack s = cStack();
	//-----------------------------------------------------------------------------------------------------------------
while(!feof(fp)){
	char* ins = (char*) malloc(100*sizeof(char));
	char wrongIns[100];
	fscanf(fp, "%s", ins);
	for( int m = 0; m<strlen(ins); m++) {
	wrongIns[m] = ins[m];
	}
	for( int d = 0; d<strlen(ins); d++) {
		if(wrongIns[d] >= 65 && wrongIns[d] <=122) {
			if(wrongIns[d] >= 97 && wrongIns[d] <=122) {
				ins[d] = wrongIns[d] - 32;
			}
		}
	}
	if (ins[0] == '%') {
		fscanf(fp,"%*[^\n]");
	}
	else if(strcmp(ins,"LDC") == 0) {
		char* ldcnum = (char*) malloc(100*sizeof(char));
		fscanf(fp, "%s", ldcnum);
		int num = 0; int notnum = 0;
		for (int q = 0; q <strlen(ldcnum); q++) {
			if((ldcnum[q] > 47 && ldcnum[q] < 58)||(ldcnum[q] == '-')) {num++;}
			else {notnum++;}
		}
		if(notnum !=0) {
				printf("[warning - illegal input ignored]\n");
		}
		else {
		int c = atoi(ldcnum);
							s->pc++;
		LDC(c,s);
		if(s->trace==1) printf("[trace - pc %d: %s %d; stack %s] \n",s->pc,ins,c,tString(s));
		}
	free(ldcnum);
	}
	else if(strcmp(ins,"ADD") == 0) {
		s->pc++;
		ADD(s);
		if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"SUB") == 0) {
		s->pc++;
		SUB(s);
		if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"MUL") == 0) {
		s->pc++;
		MUL(s);
		if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"DIV") == 0) {
		s->pc++;
		DIV(s);
		if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"TRA") == 0) {
		s->pc++;
		TRA(s);
		if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"CLR") == 0) {
		s->pc++;
		if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
		CLR(s);
	}
	else if(strcmp(ins,"SWAP") == 0) {
		s->pc++;
		SWAP(s);
		if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"NEG") == 0) {
		s->pc++;
		NEG(s);
		if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"DUP") == 0) {
		s->pc++;
		DUP(s);
		if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"INP") == 0) {
		s->pc++;
		INP(s);
		if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"OUT") == 0) {
		s->pc++;
		OUT(s);
		if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"DBG") == 0) {
		s->pc++;
		DBG(s);
		if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"HALT") == 0) {
		s->pc++;
		HALT(s);
	}
	else if(ins[0] <=57 && ins[0] >= 48) {
		char* op = malloc(5*sizeof(char));
		int g=0;
		fscanf(fp,"%s",op);
		for(i=0;i<5;i++) {
			if(op[i] > 90) {
				op[i] -=32;
			}
		}
		for(int l=0;l<strlen(ins);l++) {
			if(ins[l]==':') g++;
		}
		if(g==1&&strcmp(op,"NOP") == 0) {
			s->pc++;
					if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,op,tString(s));
		}
		else {
			printf("[error - illegal labeled instruction]\n");
			HALT(s);
		}
		free(op);
	}
	else if(strcmp(ins,"NOT")==0) {
		s->pc++;
		NOT(s);
				if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"GTR")==0) {
		s->pc++;
		GTR(s);
				if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"LESS")==0) {
		s->pc++;
		LESS(s);
				if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"EQ")==0) {
		s->pc++;
		EQ(s);
				if(s->trace==1) printf("[trace - pc %d: %s; stack %s]\n",s->pc,ins,tString(s));
	}
	else if(strcmp(ins,"LDA")==0) {
		char* ldcnum = (char*) malloc(100*sizeof(char));
		fscanf(fp, "%s", ldcnum);
		int num = 0; int notnum = 0;
		for (int q = 0; q <strlen(ldcnum); q++) {
			if((ldcnum[q] > 47 && ldcnum[q] < 58)||(ldcnum[q] == '-')) {num++;}
			else {notnum++;}
		}
		if(notnum !=0) {
				printf("[warning - illegal input ignored]\n");
		}
		else {
		int c = atoi(ldcnum);
							s->pc++;
		LDA(s,c);
		if(s->trace==1) printf("[trace - pc %d: %s %d; stack %s] \n",s->pc,ins,c,tString(s));
		}
		free(ldcnum);
	}
	else if(strcmp(ins,"JMPZ")==0) {
		char* ldcnum = (char*) malloc(100*sizeof(char));
		fscanf(fp, "%s", ldcnum);
		int num = 0; int notnum = 0;
		for (int q = 0; q <strlen(ldcnum); q++) {
			if((ldcnum[q] > 47 && ldcnum[q] < 58)||(ldcnum[q] == '-')) {num++;}
			else {notnum++;}
		}
		if(notnum !=0) {
				printf("[warning - illegal input ignored]\n");
		}
		else {
		int c = atoi(ldcnum);
							s->pc++;
		JMPZ(c,fp,s);
		if(s->trace==1) printf("[trace - pc %d: %s %d; stack %s] \n",s->pc,ins,c,tString(s));
		}
		free(ldcnum);
	}
	else if(strcmp(ins,"STO")==0) {
		char* ldcnum = (char*) malloc(100*sizeof(char));
		fscanf(fp, "%s", ldcnum);
		int num = 0; int notnum = 0;
		for (int q = 0; q <strlen(ldcnum); q++) {
			if((ldcnum[q] > 47 && ldcnum[q] < 58)||(ldcnum[q] == '-')) {num++;}
			else {notnum++;}
		}
		if(notnum !=0) {
				printf("[warning - illegal input ignored]\n");
		}
		else {
		int c = atoi(ldcnum);
		s->pc++;
		STO(c,s);
		if(s->trace==1) printf("[trace - pc %d: %s %d; stack %s] \n",s->pc,ins,c,tString(s));
		}
		free(ldcnum);
	}
	else if(strcmp(ins,"JMP")==0) {
		char* ldcnum = (char*) malloc(100*sizeof(char));
		fscanf(fp, "%s", ldcnum);
		int num = 0; int notnum = 0;
		for (int q = 0; q <strlen(ldcnum); q++) {
			if((ldcnum[q] > 47 && ldcnum[q] < 58)||(ldcnum[q] == '-')) {num++;}
			else {notnum++;}
		}
		if(notnum !=0) {
				printf("[warning - illegal input ignored]\n");
		}
		else {
		int c = atoi(ldcnum);
		s->pc++;
		JMP(c,fp);
		if(s->trace==1) printf("[trace - pc %d: %s %d; stack %s] \n",s->pc,ins,c,tString(s));
		}
		free(ldcnum);
	}
	else {
		printf("[error - illegal command '%s']\n", wrongIns);
		HALT(s);
	}
			fscanf(fp,"%*[^\n]");
	free(ins);
	}
	printf("[warning - no HALT instruction]\n");
	//-----------------------------------------------------------------------------------------------------------------------
	fclose(fp);
	return 0;
}