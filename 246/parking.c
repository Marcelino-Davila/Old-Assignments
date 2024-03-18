#include <stdio.h>

int main(void) {

	int carTime;
	int i, j;
	int overLimit;
	int zoneLim;
	int totalCarsLimit = 0;
	int zonesOverLimit = 0;
	
	
	for (i=0;i<4;i++) {
		overLimit = 0;
		scanf("%d", &zoneLim);
		for(j = 0;j<10;j++) {
			scanf("%d", &carTime);
			if (carTime > zoneLim) {
				overLimit++;
		}}
		if (overLimit >= 5) {
			zonesOverLimit++;
		}
		totalCarsLimit += overLimit;
	}
	printf("%d cars are over the limit\n", totalCarsLimit);
	if (zonesOverLimit >= 2) {
		printf("A campaign is necessary");
	}
	else {
		printf("A campaign is not necessary");
	}
	return 0;
}