//Marcelino Davila 
//  9/14/22       EGRE 246

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	char cell;
	int r;
	int c;
} forest;

int fireTest(int* currentGen[],int x, int y) {
	int i,j;
	for(i=0;i<y;i++) {
		for(j=0;j<x;j++) {
			if(currentGen[j][i]==2) return 1;
		}
	}
	return 0;
}


void forestInput(forest *input, FILE *fp) {
	forest out;
	fscanf(fp,"%c", &out.cell);
	fscanf(fp, "%d", &out.r);
	fscanf(fp, "%d", &out.c);
	input->cell = out.cell;
	if(out.cell=='Q') return;
	if(out.cell=='A') return;
	input->r=out.r;
	input->c=out.c;	
}

void printForest(int* gen[], int x, int y) {
	int i, j;
	int count10 = 1;
	int c10 = 1;
	int count = 0;
printf("   ");
	for(i=1;i<x;i++) {
		if (count10 == 10) {
			printf("%d", c10);
			c10++; 
			count10 = 1;
		}
		else {
			printf(" ");
			count10++;
		}
	}
	printf("\n   ");
	for(i=0;i<x-2;i++) {
		count++;
		if (count == 10) {
			count = 0;
		}
		printf("%d", count);
	}
	printf("\n  +");
	for(i=1;i<x-1;i++) {
		printf("-");
	}
	printf("+");
	printf("\n");
	for(i=1;i<y-1;i++){
		if(i<10) printf(" ");
		printf("%d|",i);
		for(j=1;j<x-1;j++) {
			if(gen[j][i] == 0) {
				printf(".");
			}
			else if(gen[j][i] == 1) {
				printf("T");
			}
			else if(gen[j][i] == 2) {
				printf("F");
			}
		}
		printf("|");
		if(i<10) printf(" ");
		printf("%d", i);
		printf("\n");
	}
		printf("  +");
	for(i=1;i<x-1;i++) {
		printf("-");
	}
	printf("+\n   ");
	count = 0;
		for(i=0;i<x-2;i++) {
		count++;
		if (count == 10) {
			count = 0;
		}
		printf("%d", count);
	}
	printf("\n   ");
	count10=1;
	c10=1;
		for(i=1;i<x;i++) {
		if (count10 == 10) {
			printf("%d", c10);
			c10++; 
			count10 = 1;
		}
		else {
			printf(" ");
			count10++;
		}
	}
		printf("\n");
}

int cellAuto(int* currentGen[], int x, int y, int prob, int seed) {
	//------------------------------INITIALIZATION----------------------------------------------
	int* nextGen[x]; 
	float rn;
	int i,j;
	float p = (float)prob/(float)100;
	srand(seed);
	int Treeb=0;
		for(i=0;i<x;i++) {
		nextGen[i] = (int*) malloc(y*sizeof(int));
	}
	//------------------------------------ALGORITHM--------------------------------------------
	for(i=0;i<y;i++) {
		for(j=0;j<x;j++) {
					rn = (float)rand()/(float)RAND_MAX;

	if(currentGen[j][i]==1 && (currentGen[j+1][i] == 2 || currentGen[j-1][i] == 2 || currentGen[j][i+1] == 2 || currentGen[j][i-1] == 2)&&(p>=rn)){
				nextGen[j][i] = 2;
				
			}
			else if(currentGen[j][i] == 2) {
				nextGen[j][i] = 0;
				Treeb++;
			}
			else {
				nextGen[j][i] = currentGen[j][i];
			}	
		}
	}
		for(i=0;i<y;i++) {
			for(j=0;j<x;j++) {
				currentGen[j][i] = nextGen[j][i];
			}
		}
	return Treeb;
}

int main(int argc, char *argv[]) {
	//---------------------------------------FILE-----------
	printf("Marcelino Davila 9/14\n");
	FILE *fp;
	char fileName[20];
	
	if (argc > 1) {
		strcpy(fileName,argv[1]);
	} else {
		printf("Error - no file given on command line\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(fileName, "r");
	//---------------------------------INITIALIZATION----------------------------------
	int isFire;
	int x,y,a,b;
	int seed;
	int prob;
	int i,j;
	int time = 0;
	int Treei=0;
	int Treef=0;
	int Treeb=0;
	float TreeP;
	float TreePF;
	fscanf(fp, "%d", &b);
		fscanf(fp, "%d", &a);
			fscanf(fp, "%d", &seed);
				fscanf(fp, "%d", &prob);
	forest *in = (forest*) malloc(sizeof(forest));
	x=a+2;
	y=b+2;
	int* currentGen[x];
	for(i=0;i<x;i++) {
		currentGen[i] = (int*) malloc(y*sizeof(int));
	}
	for(i=0;i<y;i++) {
		for(j=0;j<x;j++) {
			currentGen[j][i] = 0;
			}
		}
//-------------------------------------INPUT--------------------------
	do{
	forestInput(in,fp);
	if(in->cell=='A') {
		for(i=1;i<y-1;i++) {
			for(j=1;j<x-1;j++) {
				currentGen[j][i] = 1;
			}
		}
	}
	
	if(in->cell=='E'){
		currentGen[in->c][in->r] = 0;
	}
	if(in->cell=='F'){
		currentGen[in->c][in->r] = 2;
	}
	if(in->cell=='T'){
		currentGen[in->c][in->r] = 1;
	}
	}
	while(in->cell != 'Q');
	printf("\n");
	for(i=0;i<y;i++) {
		for(j=0;j<x;j++) {
			if(currentGen[j][i] == 1) Treei++;
		}
	}
	free(in);
//---------------------------BURNING-------------------------------	
		printf("rows: %d \n", a);
		printf("cols: %d \n", b);
		printf("trees: %d \n", Treei);
		printf("seed: %d \n", seed);
		printf("probability: %d\%\n", prob);
		printf("\nTIME: %d\n", time);
	printForest(currentGen,x,y);
	TreeP = (float) (Treeb/Treei)*100;
	printf("\ntotal burned: %d (%.01f\%)", Treef, TreeP);
	i=0;
	do {
	Treeb+=cellAuto(currentGen,x,y,prob,seed);
	isFire = fireTest(currentGen,x,y);
	time++;
	}
	while (isFire != 0);
	for(i=0;i<y;i++) {
		for(j=0;j<x;j++) {
			if(currentGen[j][i] == 1) Treef++;
		}
	}
		TreePF = (float) (Treeb/ (float)Treei)*100;
	printf("\n<<< Final Forest >>>\n");
	printf("TIME: %d\n",time);
	printForest(currentGen,x,y);
	printf("total burned: %d \(%.01f\%\)\n",Treeb,TreePF);
	printf("trees left: %d",Treef);
	fclose(fp);
	return 0;
}
//STUDENT
//Marcelino Davila
//AUTOGRADER SCORE
//0.0 / 0.0
//QUESTION 2
//Manual
//- / 20.0 pts