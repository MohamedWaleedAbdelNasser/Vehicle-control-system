
#include <stdio.h>
#include <stdlib.h>
int SENSORS(){
	int sensor;
	printf("Sensors set menu\n");
	printf("1.Turn off the engine\n");
	printf("2.Set the traffic light color\n");
	printf("3.Set the room temperature\n");
	printf("4.Set the engine temperature\n");
	fflush(stdout);
	scanf("%d",&sensor);
	return sensor;
}
int choices(){
	int choice;
	printf("What do you want? \n");
	printf(" 1.turn on the vehicle \n");
	printf(" 2.turn off vehicle engine \n");
	printf(" 3.quit the system \n");
	fflush(stdout);
	scanf(" %d",&choice);
	return choice;
}
void states(int Enginestate, int AC, int Vehiclespeed, int Roomtemp, int   EngController, int Enginetemp){
	if (Enginestate==0){
		printf("The engine is OFF\n");
		fflush(stdout);
	}
	else
		printf("The Engine is ON\n");
		if (AC==0){
			printf("AC:OFF\n");}
		else
		printf("AC:ON\n");

		printf("Vehicle speed = %d \n", Vehiclespeed);
		printf("Room temperature = %d \n", Roomtemp);

		if(EngController ==1){
			printf("Engine Controller state is ON\n");

		}
		else printf("Engine Controller is OFF\n");

		printf("Engine temperature is %d\n ", Enginetemp);

		}



int main(void) {

int choice=choices();
int sensor;
int choice3;
char TrafficLightData;
int Roomtemp=35;
int AC=0;
int Enginetemp=90;
int EngController=0;
int Vehiclespeed=0;
int Enginestate=0;
while(1){
if (choice == 3){
	printf("Quit the system\n");
	fflush(stdout);

	exit;
}
else if (choice == 2){
	printf("Engine is OFF\n");
	choice=choices();

}
else if (choice == 1){
	printf("Engine is ON\n");
	fflush(stdout);

	printf("Sensors set menu\n");
	printf("1.Turn off the engine\n");
	printf("2.Set the traffic light color\n");
	printf("3.Set the room temperature\n");
	printf("4.Set the engine temperature\n");
	fflush(stdout);
	scanf("%d",&sensor);
	Enginestate=1;
	if(sensor==1){
		printf("Engine is OFF\n");
			choice=choices();
	}
	if (sensor==2){
		printf(" Enter the traffic light data (G,O,R) \n");
		fflush(stdout);
		scanf(" %s", &TrafficLightData);

		if ( TrafficLightData=='G'){
			printf("If the traffic light is ‘G’ set vehicle speed to 100 km/hr\n");
			Vehiclespeed=100;
			states(Enginestate,AC,Vehiclespeed,Roomtemp,EngController,Enginetemp);


		}
		else if (TrafficLightData== 'O'){
			printf("If the traffic light is ‘O’ set vehicle speed to 30 km/hr\n");
			Vehiclespeed=30;
			if (Vehiclespeed==30){
				AC=1;
				Roomtemp=(Roomtemp*(1.25))+1;
				EngController=1;
				Enginetemp=(Enginetemp*(1.25))+1;
			}
			states(Enginestate,AC,Vehiclespeed,Roomtemp,EngController,Enginetemp);

		}
		else if( TrafficLightData== 'R'){
			printf("If the traffic light is ‘R’ set vehicle speed to 0 km/hr\n");
			Vehiclespeed=0;
			states(Enginestate,AC,Vehiclespeed,Roomtemp,EngController,Enginetemp);

		}
	SENSORS();
	}
	else if (sensor==3){
		printf("Enter room temperature\n");
		fflush(stdout);
		scanf(" %d",&Roomtemp);

		if(Roomtemp<10){
			printf("AC turned ON and set to 20c\n");
			AC=1;
			Roomtemp=20;
			states(Enginestate,AC,Vehiclespeed,Roomtemp,EngController,Enginetemp);

		}
		else if(Roomtemp>30){
			printf("AC turned ON and set to 20c\n");
			AC=1;
			Roomtemp=20;
			states(Enginestate,AC,Vehiclespeed,Roomtemp,EngController,Enginetemp);

		}
		else if(Roomtemp>10 || Roomtemp<30){
			printf("AC is turned OFF\n");
			AC=0;
			states(Enginestate,AC,Vehiclespeed,Roomtemp,EngController,Enginetemp);

		}
	SENSORS();
	}
	else if (sensor==4){
		printf("Enter engine temperature\n");
		fflush(stdout);
		scanf(" %d",&Enginetemp);

		if (Enginetemp<100){
			printf("Engine temperature controller is ON and temperature set to 125 \n");
			Enginetemp=125;
			EngController=1;
			states(Enginestate,AC,Vehiclespeed,Roomtemp,EngController,Enginetemp);

		}
		else if (Enginetemp>150){
			printf("Engine temperature controller is ON and temperature set to 125 \n");
			Enginetemp=125;
			EngController=1;
			states(Enginestate,AC,Vehiclespeed,Roomtemp,EngController,Enginetemp);

		}
		else {
			printf("Temperature controller is OFF ");
			EngController=0;
			states(Enginestate,AC,Vehiclespeed,Roomtemp,EngController,Enginetemp);

		}
	SENSORS();
	}
	if (Vehiclespeed==30){
		AC=1;
		Roomtemp=(Roomtemp*(1.25))+1;
		EngController=1;
		Enginetemp=(Enginetemp*(1.25))+1;
	}

	states(Enginestate,AC,Vehiclespeed,Roomtemp,EngController,Enginetemp);


	}

 }

}
