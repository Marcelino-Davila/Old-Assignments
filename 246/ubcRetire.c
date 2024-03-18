#include <stdio.h>
#include <math.h>

int main(void)
{
	float desireAmount = 0;
	float investment = 0;
	int years = 0;
	int months = 0;
	float totalTime = 0;
	
	printf("  ,_____ ,         /$$   /$$ /$$$$$$$   /$$$$$$ \n");
	printf("  ,._ ,_. 7\\      | $$  | $$| $$    $$ /$$    $$ \n");
	printf(" j `-'     /      | $$  | $$| $$    $$| $$ \n");
	printf(" |o_, o    \\      | $$  | $$| $$$$$$$ | $$ \n");
	printf(".`_y_`-,'   !     | $$  | $$| $$    $$| $$ \n");
	printf("|/   `, `._ `-,   | $$  | $$| $$    $$| $$     $$\n");
	printf("|_     \\   _.'*\\  |  $$$$$$/| $$$$$$$ |  $$$$$$/ \n");
	printf("  >--,-'`-'*_*'``  \\______/ |_______/  \\______/ \n");
	printf("            \"Our Barker Guards Your Future\" \n");
	

	printf("How much whould you like in your retirement account when you retire? \n");
	fflush(stdout);
	scanf("%d", &desireAmount);
	
	printf("How much would you like to invest into your retirement? \n");
	fflush(stdout);
	scanf("%d", &investment);

	totalTime = (log(desireAmount) - log(investment)) / log(1 + 0.05);
	years = floor(totalTime);
	months = ceil((totalTime - years) * 12);
	printf("Your desired amount is reached in %d years and %d months", years, months);

return 0;
}