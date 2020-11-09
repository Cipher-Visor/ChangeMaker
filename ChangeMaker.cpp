/*
This program calculates the lowest number of coins it will take to make change. EX. 35 would be 2 (1 quarter and 1 dime).
2020 (c) Cipher Visor https://github.com/Cipher-Visor
*/
#include <iostream>

int	cents = 0; //number of cents input
int	coins = 0; //current number of coins
int	coinIncrement = 0; //the amount that the coins will increase during the current check
//counts for indexing the contents of the coin minimum 
int	quarterCount;
int	dimeCount;
int	nickelCount;
int	pennyCount;

//being executed program
int main () {
	while (true) { //beign a loop 
		std::cout << "Please input your cents" << std::endl;
		std::cout << ">"; //cool looking little user input thing
		std::cin >> cents;
		while (cents > 0) { //with every check, and index of coins the current number of cents lowers till their is none left to be calculated
			if (cents >= 25) { //check max number of quarters that fit (3 more checks to come)
				coinIncrement = cents / 25;
				quarterCount = coinIncrement;
				cents = cents % 25;
				coins += coinIncrement;
			}
			if (cents >= 10) { 
				coinIncrement = cents / 10;
				dimeCount = coinIncrement;
				cents = cents % 10; 
				coins += coinIncrement;
			}
			if (cents >= 5) {
				coinIncrement = cents / 5;
				nickelCount = coinIncrement;
				cents = cents % 5;
				coins += coinIncrement;
			}
			if (cents >= 1) {
				coinIncrement = cents / 1;
				pennyCount = coinIncrement;
				cents = cents % 1;
				coins += coinIncrement;
			}
		} //being output process
		std::cout << "Your coin minimum is: " << coins << std::endl;
		if (quarterCount > 0) { //you'll probably tell me there is a more sophisticated way formatting the output but hey this works
			std::cout << "            Quarters: " << quarterCount << std::endl;
		}
		if (dimeCount > 0) {
			std::cout << "               Dimes: " << dimeCount << std::endl;
		}
		if (nickelCount > 0) {
			std::cout << "             Nickels: " << nickelCount << std::endl;
		}
		if (pennyCount > 0) {
			std::cout << "             Pennies: " << pennyCount << std::endl;
		}
		//reset all variables to stop errors from occuring next time
		cents = 0;
		coins = 0;
		coinIncrement = 0;
		quarterCount = 0;
		dimeCount = 0; 
		nickelCount = 0;
		pennyCount = 0;
	}
	return 0;
}