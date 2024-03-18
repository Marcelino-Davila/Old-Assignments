
#include <stdio.h>
 
 double CarsOver100(double, double);

  //Start of main function
  int main (void) {
	  
	  //Variables to get the above and below 100 mph (intergers)
  double Above100;
  double Below100;
	  //Constants to set number of days and time zones
const int days = 7;
const int timezones = 24 / 6; 
	  //Loop iteration variables
int i;
int j;
	
	  //Variable to store the percentage (double)
	double Over100Percent = 0;
	  //Variable to store the cummulative above and below per day
	double TotalCars = 0;
	double DayBelow = 0;  
	double DayAbove = 0;
	double DaysOf25 = 0;
	double Avg;
	  //Variable to track if 25% or more cars were above 100 mph
	int twenty5 = 0;
	  //DO NOT FORGET to Initialize the variables
	  //Loop : iterate through number of days
for (i=0; i<days; i++) {
		  //Set/Reset the cummulative variables to zero
	Over100Percent = 0; 
	TotalCars = 0; 
	DayBelow = 0; 
	DayAbove = 0;
		  //Loop: iterate through number of time zones
		for (j=0; j<timezones; j++) {
			fflush(stdout);
			scanf("%d", &Below100);
			fflush(stdout);
			scanf("%d", &Above100);
			TotalCars = Below100 + Above100;
			  //Calculate the percentage: Call the function
			Over100Percent = CarsOver100(Above100, TotalCars);
			  //check if #cars are 25% or above
			if (Over100Percent >= 25) {
				  //increment the track variable
				twenty5++;
}

			  //Add the cummulative for the day
			DayBelow += Below100;
			DayAbove += Above100;
}  //end inner loop here
		  //Check if for the entire day, the above 100 was 25% or above
			Avg = CarsOver100(DayAbove, (DayBelow + DayAbove));
			if (Avg >= 25) {
				DaysOf25++;
			  //increment the day
			}
		
}	
printf("%d zones are over 25%% limit\n", twenty5);
	//Outside loop body, check if pilot program can be initiated
 	if (DaysOf25 >=3) {
		printf("Initiate pilot program");
	}
	else 
		printf("Pilot program not required");
	  		//Print appropriate message
	
	  //End main function with return
return 0;
  }
  
double CarsOver100(double Cars100, double totCars) {
	double percent;
	
	percent = (Cars100 / totCars) * 100;
	
	return percent;
}