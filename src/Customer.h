#ifndef CUSTOMER_H 
#define CUSTOMER_H
#include <iostream>
#include <random>
using namespace std;

class Customer {

	public:

	Customer () {}

	Customer (int inSimTime) {

		// Define data members
		instantiation = inSimTime;
		transact = getRandomNumber(5,25);
		finish = transact + inSimTime;
		money = getRandomNumber(1,1000);

		// Set a reason for visit
		string visitReasons[4] = {"open account", "deposit money", "close account", "withdraw money"};
		visitReason = visitReasons[getRandomNumber(0,3)];
	}

	// Accessors
	int getInstantiation() {return instantiation;}
	int getFinish() {return finish;}
	int getMoney() {return money;}
	char getInitial() {return lastInitial;}

	// Mutators
	void setFinish(int inFinish) {finish = inFinish;}

	private:
	int getRandomNumber(int min, int max) {

		// Create rng device
		random_device dev;
		mt19937 rng(dev());
		uniform_int_distribution<mt19937::result_type> dist(min,max);

		// Create random number
		int number = dist(rng);

		// Ensure number is in range
		if (number > max) number = max;
		else if (number < min) number = min;

		// Return
		return number;
	}

	// Data Members
	int instantiation = 0;
	int transact;
	int finish = -1;
	int money; 
	string visitReason;
	char lastInitial = 65 + getRandomNumber(0,25);

};

#endif