#ifndef TELLER_H 
#define TELLER_H
#include <iostream>
#include "Customer.h"

class Teller {

	
	
	public:

	Teller () {}

	// Start processing a new customer
	void processCustomer(Customer inCustomer) {
		customer = inCustomer;
	}

	Customer popCustomer() {
		Customer outCustomer = customer;
		customer.setFinish(-1); // Signifies that the version of the customer stored by the teller should not be used
		return outCustomer;
	}

	bool isFinished(int inSimTime) {
		if (customer.getFinish() != -1 && inSimTime >= getCustomer().getFinish()) return true;
		else return false;
	}

	// Accessor
	Customer getCustomer() {return customer;}

	private:
	// Data Member
	Customer customer = Customer();

};
#endif