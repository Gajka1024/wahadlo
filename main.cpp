#include <iostream>



#define FRICTION_CAR 0.0005  //g
#define FRICTION_HINGE 0.000002
#define GRAVITY 9.8

//masses and lengths
#define CART_MASS 1.0
#define POLE_MASS 0.1
#define TOTAL_MASS (MASSPOLE + MASSCART)
#define POLE_LENGTH_HALF 0.25
#define POLE_MASS_LENGTH (POLE_MASS * POLE_LENGTH)

#define TAU 0.02		  /* czas miedzy krokami */

//initial math values
#define FAILANGLE 12
#define MIN_FORCE 0.04
#define MAX_FORCE 10
#define MAX_CART_POSITION 2.4
#define INITIAL_POLE_ANGLE 4
#define INITIAL_CART_POSITION 0
#define INITIAL_CART_ACCELLERATION 0
#define TRIES 10000

/*#define FOURTHIRDS 1.3333333333333*/
#define sqr(x) ( (x) * (x) )

using namespace std;

int main(int argc, char** argv) {

	/* algorytm
	1. zainicjalizuj wozek i tyczke
	2. powtorz TRIES razy
		a. oblicz stan ukladu
		b. jesli tyczka sie przewrocila, albo wozek wyjechal, zresetuj wozek i tyczke (NIE siec!) i zacznij od nowa - podaj do sieci informacje o failure
		c. podaj stan ukladu na ANN - funkcja calcAnn
		d. wez od ANN odpowiedz (force na lewo albo na prawo - plus lub minus)
	3. sprawdz, czy siec sie nauczyla - odpal ja i zobacz czy tyczka sie przewroci
	*/
	return 0;
}

/*
calculate pole accelleration
* @param double Force - force on cart
* @param double cart_velocity - predkosc wozka
* @param double pole_angle - kat tyczki
* @param double Oip - velocity of the pole - predkosc tyczki
* @return double pole accelleration
*/
double poleAccelleration(double Force, double cart_velocity, double pole_angle, double Oip){

	double a = -0.75 * POLE_LENGTH_HALF;
	double b = cartAccelleration(Force, cart_velocity, pole_angular_velocity) * cos(pole_angle);
	double c = GRAVITY * sin(pole_angle);
	double d = ( upi() * Oip ) / (POLE_MASS * POLE_LENGTH_HALF);

	double result = a * (b + c + d);
	return result;
}

/*
calculate cart accelleration
* @param double Force - sila dzialajaca na wozek
* @param double cart_velocity - predkosc wozka
* @param double pole_angular_velocity - predkosc katowa tyczki
* @param double cart accelleration
*/
double cartAccelleration(double Force, double cart_velocity, double pole_angular_velocity){
	double a = Force - uc(cart_velocity) + Fic(POLE_MASS, POLE_LENGTH_HALF, pole_angular_velocity, FRICTION_HINGE);
	double b = CART_MASS +  Mic(POLE_MASS, pole_accelleration);

	double accell = up/down;
	return accell;
}

/*
force on i-th pole
* @param double Mi - mass of the ith pole
* @param double Li - half of the pole lenght
* @param double Oi - pole angle
* @param double Oip - pole angular velocity
* @param double Upi - pole friction
* @return double forceonthe i-th pole
*/
double Fic(double Mi, double Li, double Oi, double Oip, double Upi) {
	double a = Mi* Li * Oi* Oi * sin(Oi);
	double b = 0.75 * Mi * cos(Oi);
	double c = (Upi * Oip) / (Mi * Li);
	double d = GRAVITY * sin(Oi);

	double result = a + (b * (c + d));
	return result;
}

/*
mass on the i-th pole
* @param double mi - mass on the ith pole
* @param double Oi - pole angle
* @return double mass on the ith pole
*/
double Mic(double mi, double Oi){
	double result = mi * ( 1 - (0.75) * cos(Oi) * cos (Oi));
	return result;
}
/*
calculate coeffficient of friction of cart on track
* @param double velocity_cart predkosc wozka
* @return double coefficient wspolczynnik
*/
double uc(double velocity_cart){
	return FRICTION_CAR;
}

/*
calculate coeffficient of friction of pole
* @param double velocity_cart predkosc wozka
* @return double coefficient wspolczynnik
*/
double upi(){
	return FRICTION_HINGE;
}

/*
//the position of the cart, the velocity of the cart, the angle of the pole, and the angular velocity of the pole.
* @param double cart_position pozycja wozka
* @param double cart_velocity predkosc wozka
* @param double pole_angle kat nachylenia tyczki
* @param double pole_velocity predkosc katowa tyczki
* @return double sila z jaka nalezy zadzialac na wozek (+/- oznacza kierunek dzialania sily)
*/
double calcAnn(double cart_position, double cart_velocity, double pole_angle, double pole_velocity){

	return 0.0;
}


