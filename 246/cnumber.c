#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
#include "cnum.h"

int main(void) {
	comp test = createPolar("test",1,4);
	printCnum(test);
	comp test2 = createCartesian("test2",1,4);
	printf("\n\n\n\n\n\n");
	printCnum(test2);
	printf("\n\n\n\n");
	printf("test1 imag %.03lf test 2 imag %.03lf \n\n\n\n\n", test->imag, test2->imag);
	comp test3 = add(test,test2,"test3");
	printCnum(test3);
	return 0;
}