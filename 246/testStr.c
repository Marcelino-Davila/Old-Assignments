#include <stdio.h>

int main(void) {
	char c;
	
	printf("in\n");
	fflush(stdout);
	scanf("%c", &c);
	printf("%c", c);
	fflush(stdout);
	scanf("%c", &c);
	printf("%c", c);
	
	return 0;
}