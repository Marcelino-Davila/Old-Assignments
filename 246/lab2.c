#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

int *sieve( int *inList, int inSize, int n, int *outSize){
	outSize = 0;
	int o = *outSize;
	
		if(inList[inSize] > n) {
			outSize++;
		}
	
return inList;
}

int main(void) {
	printf("i");
	int n;
	int m;
		scanf("%d", &m);
	int i;
	int* p = (int*) malloc(m*sizeof(int));
	int endSize;
	int* outSize;
	int outList[endSize];
	fflush(stdout);
	scanf("%d", &n);
	printf("n value %d", n);
	for(i=0;i<m;i++) {
		scanf("%d", &m);
	}
	for(i=0;i<m;i++) {
		outList[endSize] = *sieve(&p[i], i, n, outSize);
		printf("%d\n", outList[endSize]);
	}
	free(p);
		
return 0;
}