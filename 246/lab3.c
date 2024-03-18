#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for strcpy
#include <ctype.h>   // for isspace

#define TEXT_LENGTH 250  
#define MAX_DB_SIZE 1000
#define MAX_DESCRIPTION_SIZE 160

typedef struct wType {
  int id; // widget id number
  int num; // number in stock
  float cost; // our unit cost
  char *des;  // description of item
} widget;

void initDB(widget *[],int); // initialize database (db) to all NULL
int count(widget *[],int); // returns count of actual items in db
widget *newItem(int, int, float, char *); // creates and returns a new db item
void printItem(widget *); // prints a single db item
void printDB(widget*[],int); // prints all db items

widget *newItem(int new_id, int new_num, float new_cost, char *new_des) {
	widget *tmp = malloc(sizeof(widget));
	tmp->id = new_id;
	tmp->num = new_num;
	tmp->cost = new_cost;
	tmp->des = malloc(strlen(new_des)+1);
	strcpy(tmp->des,new_des);
	return tmp;
}

void printItem(widget *item) {
	printf("stock number: %d\n", item->id);
	printf("# in stcok: %d\n", item->num);
	printf("unit cost %lf\n", item->cost);
	printf("description: %s\n", item->des);
}

void initDB(widget *list[], int n) {
	if(n<1) return;
	int i;
	for(i=0;i<n;i++) {
		list[i] = NULL;
	}
}

int count(widget *list[], int n) {
	if(n<=0) return 0;
	int c = 0;
	int i;
	for(i=0;i<n;i++) {
		if(list[i] != NULL) c++;
	}
	return c;
}

void printDB(widget *db[], int size) {
	int c = size;
	if (c<=0) {
		printf("database empty\n");
		return;
	}
	int i;
	for(i=0;i<c;i++) {
		printf("item # %d\n", i+1);
		printItem(db[i]);
	}
}
///////////////////////////////////////

int main(void){
  widget *db[MAX_DB_SIZE];
  int total;
 /* widget *test = newItem(1,2,3,"test");
  printItem(test);*/
  
  initDB(db,MAX_DB_SIZE);
  printf("# items in database: %d\n",count(db,MAX_DB_SIZE));
  printf("enter how many items? ");
  fflush(stdout);
  scanf("%d", &total);
  if(total <= 0) exit(EXIT_SUCCESS);

  int id,num; float cost; char des[MAX_DESCRIPTION_SIZE], ch;
  des[0] = '\0';
  for(int i = 0; i < total; i++) {
    printf("Item #%d\n",i+1);
    printf("  stock number: "); 
	fflush(stdout);
	scanf("%d",&id);
    printf("  # in stock: ");
	fflush(stdout);
	scanf("%d",&num);
    printf("  unit cost: ");
fflush(stdout);
    scanf("%f",&cost); 
    printf("  description: ");
    while(isspace(ch=getchar())) ; // see notes in handout on this
    ungetc(ch,stdin);
	fflush(stdout);
    scanf("%[^\n]",des); 
    db[i] = newItem(id,num,cost,des);
  }

  printf("\nDatabase contents:\n");
  printDB(db,total);
  return 0;
}
