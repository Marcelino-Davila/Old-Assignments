//Frank Kengni 
//Programming Project #1 Simulating a Forest Fire/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///print the array

typedef struct {
    char in;
    int r;
    int c;
} forest;


void getInput(forest *input, FILE *fp) {
	Amazon out;
	fscanf(fp,"%c", &out.in);
	fscanf(fp, "%d", &out.r);
	fscanf(fp, "%d", &out.c);
	input->in = out.in;
	//if(out.cell=='Q') return;
	//if(out.cell=='A') return;
	input->r=out.r;
	input->c=out.c;	
	return;
}


/*
void forestInput(forest *input, FILE *fp) {
	forest out;
	fscanf(fp,"%c", &out.cell);
	fscanf(fp, "%d", &out.r);
	fscanf(fp, "%d", &out.c);
	input->cell = out.cell;
	input->r=out.r;
	input->c=out.c;	
	return;
}
	*/
	
	


int main(int argc, char *argv[]) {
//printf("Programming Project #1 Simulating a Forest Fire\nAuthor:Frank Kengni\n"); //prints project number and my name

////////////////////////////gets the input
    forest *main = (forest*) malloc(sizeof(forest));

  FILE *fp;

  char fileName[20];

  if (argc > 1) {
    strcpy(fileName,argv[1]);
  }else {
    printf("Error - no file given on command line\n");
    exit(EXIT_FAILURE);
  }
  fp = fopen(fileName,"r");
  int rowsize, columnsize, randSeed, prob, holder, i;

        fscanf(fp, "%d", &rowsize);
        fscanf(fp, "%d", &columnsize);
        fscanf(fp, "%d", &randSeed);
        fscanf(fp, "%d", &prob);

        printf("%d %d %d %d", rowsize, columnsize, randSeed, prob);

    getInput(main, fp);
    printf("%c %d %d", main->in, main->c, main->r);


    fclose(fp);
    return 0;
}