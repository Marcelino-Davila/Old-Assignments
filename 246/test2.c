#include <stdio.h>
#include <math.h>

int main(void)
{
	int retireGoal = 0;
	int startingAmount = 0;
	int years = 0;
	int months = 0;
	int totalTime = 0;
	
printf("  ,_____ ,         /$$   /$$ /$$$$$$$   /$$$$$$ \n");
printf("  ,._ ,_. 7\\      | $$  | $$| $$    $$ /$$    $$ \n");
printf(" j `-'     /      | $$  | $$| $$    $$| $$ \n");
printf(" |o_, o    \\      | $$  | $$| $$$$$$$ | $$ \n");
printf(".`_y_`-,'   !     | $$  | $$| $$    $$| $$ \n");
printf("|/   `, `._ `-,   | $$  | $$| $$    $$| $$     $$\n");
printf("|_     \\   _.'*\\  |  $$$$$$/| $$$$$$$ |  $$$$$$/ \n");
printf("  >--,-'`-'*_*'``  \\______/ |_______/  \\______/ \n");
printf("            \"Our Barker Guards Your Future\" \n");
	
	printf("What is your retirement target \n");
	fflush(stdout);
	scanf("%d", &retireGoal);
	printf("How much would you like to invest \n");
	fflush(stdout);
	scanf("%d", &startingAmount);
	totalTime = (log(retireGoal / startingAmount) / log(1 + 0.05));
	printf("total time = %d", totalTime);
	

return 0;
}
