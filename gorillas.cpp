//=======================================
// The kinematics of the game, "Gorillas" on Qbasic have been explored through this program.
//The game was originally published by IBM corporation.
//program created by- Abhijeet Pande (19th September 2018)
//=======================================

#include <iostream>
#include <cmath>

// start of declarations

double horizontal_velocity(double launch_velocity,double launch_angle);
double vertical_velocity(double launch_velocity, double launch_angle);
double gravity();
double computed_range(double launch_velocity, double launch_angle, double height);

#ifndef MARMOSET_TESTING

int main();

#endif
// end of declarations, start of definitions

#ifndef MARMOSET_TESTING

int main() {
	// START OF PART A
	double list_of_angles[12] = {10,20,25.5,30,40,50,55.5,60,70,75.5,80,90};
	//All of the angles we are testing the formula for
	double list_of_ranges[12];
	//All of the ranges resulting from the formula will be stored in above array
	for (int i = 0; i <= 11; i++){

		list_of_ranges[i] = computed_range(600,list_of_angles[i],10); //computing all of the range values

	}

	for(int j = 0; j <= 11; j++) {
		std::cout << "The range the banana reaches for the launch angle of " << list_of_angles[j]
	              << " degrees is " << list_of_ranges[j];
		std::cout << std::endl;
		// releases the output to the display console
	}
}
#endif

double horizontal_velocity(double launch_velocity, double launch_angle){
	double final_horizontal;

	final_horizontal = (launch_velocity)*(cos((launch_angle)*((M_PI)/(180))));
	return final_horizontal;
	// returns the horizontal value of the launch velocity
}

double vertical_velocity(double launch_velocity, double launch_angle) {
	double final_vertical;

		final_vertical = (launch_velocity)*(sin((launch_angle)*((M_PI)/(180))));
		return final_vertical;
		// returns the vertical value of the launch velocity
}

double gravity() {
return 9.80665;
// returns the value of the gravitational force on earth
}

double computed_range(double launch_velocity, double launch_angle, double height) {
	double final_range;
	double Y; // VELOCITY IN THE Y DIRECTION
	double X; // VELOCITY IN THE X DIRECTION
	double g; // gravity

	X = horizontal_velocity(launch_velocity,launch_angle);
	Y = vertical_velocity(launch_velocity,launch_angle);
	g = gravity();

	final_range = ((X*Y) / (g) ) + ( (X)*( (sqrt((Y*Y + 2*g*height)) / g )));
	return final_range;
// computes the final distance the banana covers in the horizontal direction.
}
