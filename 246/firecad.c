#include <stdio.h>
#include <math.h>
#include <string.h>

double Calcdistance(double,double,double,double);
	


int main (void)
{

printf("This program will tell you the fire department with the quickest arrival time \n");


char category;
double BrentDistance = 32;
double CamdenDistance = 323;
double EnfieldDistance = 232;
double BrentTime = 32;
double CamdenTime = 32;
double EnfieldTime = 23;
double X, Y;
double BrentHour, EnfieldHour, CamdenHour;
printf("Enter the X coordinate, the Y coordinate, and category, of the place you need dispatch to\n");
fflush(stdout);
scanf("%lf %lf %c", &X, &Y, &category);


	BrentDistance = Calcdistance(X, Y, 69.0, 36.0);
	EnfieldDistance = Calcdistance(X, Y, 79.0, 53.0); 
	CamdenDistance = Calcdistance(X, Y, 89.0, 37.0);
	BrentHour= (BrentDistance / 20.0);
	EnfieldHour= (EnfieldDistance / 17.5);
	CamdenHour= (CamdenDistance / 15.7);
	BrentTime =  (int)(ceil(BrentHour * 60));
	EnfieldTime = (int)(ceil(EnfieldHour * 60));
	CamdenTime = (int)(ceil(CamdenHour * 60)); 
	
if (category == 'A') {
	
	
	if (BrentHour<EnfieldHour) {
		if (BrentDistance<=15) {
			fflush(stdout);
			printf("Brent dispatch. ETA %f minutes \n", BrentTime);
		}
		else  {
			fflush(stdout);
		printf("No Category A units in range \n"); 
		}
	}
		else if (EnfieldDistance<=15) {
			fflush(stdout);
			printf("Enfield dispatch. ETA %f minutes \n", EnfieldTime);
		}
	
		else {
			fflush(stdout);
		printf("No Category A units in range \n"); 
		}
	
}
	


else if (category == 'B') {
	
		if (CamdenDistance<=15) {
			fflush(stdout);
			printf("Camden dispatch. ETA %f minutes \n", CamdenTime);
		}
		else{
				fflush(stdout);
				printf("No Category B units in range \n");
			}
		}
	


else 
{
	fflush(stdout);
	printf("Invalid Category");
}
		

return 0;
}
    double Calcdistance(double EmergencyX, double EmergencyY, double BoroughX, double BoroughY)
	{
	double distance;
	distance = sqrt(pow((EmergencyX - BoroughX), 2) + pow((EmergencyY - BoroughY), 2));
	return distance;
}

