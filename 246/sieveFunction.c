#include <stdio.h>

int *sieve( int *inlist, int inSize. int n, int *outSize);
	int i;
	int j = 0;
	int oSize;
	//*outSize = 0;
	//oSize = malloc(sizeof(int));
	for(i=0;i<inSize;i++){
		if(*inlist[i] >= n){
			*outsize[j] = *inlist[i];
			j+=1;
		}
	}
			
	return *outSize;
}