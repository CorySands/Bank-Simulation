#ifndef SIMULATIONMANAGER_H 
#define SIMULATIONMANAGER_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <vector>
#include "Teller.h"
#include "Customer.h"
using namespace std;


class SimulationManager {

	public:
	SimulationManager() {}

	void runSimulation() {
		int customerStart = 0;
		int customerInterval = getRandomNumber(1, 4);
		while (simulationTime <= 180) {

			// Add customer
			if (simulationTime >= customerInterval + customerStart) {
				Customer newCustomer(simulationTime);
				customersWaiting.push(newCustomer); 
				customerStart = simulationTime;
				customerInterval = getRandomNumber(1,4);
			}

			// Determine which tellers to manage
			if (customersWaiting.size() >= 8)
				manageTeller(teller3);
			
			if(customersWaiting.size() >= 4)
				manageTeller(teller2);

			manageTeller(teller1);

			// Display values
			displayValues();

			// Increase time by 1
			incrementTime();

			// Record customers waiting
			customersWaitingData.push_back(customersWaiting.size());
		}

		// Display final results
		displayReport();
	}


	private:
	
	void manageTeller(Teller &inTeller) {

		// If a teller is idle and customers are waiting, process customer
		if (inTeller.getCustomer().getFinish() == -1 && customersWaiting.size() > 0) {
			totalWaitingTime += simulationTime - inTeller.getCustomer().getInstantiation();
			inTeller.processCustomer(customersWaiting.front());
			customersWaiting.pop();
		}

		// If customer is done with transaction, move them to processedCustomers
		if( inTeller.getCustomer().getFinish() != -1 && inTeller.isFinished(simulationTime)) {
			processedCustomers.push_back(inTeller.popCustomer()); // Move customer to processedCustomers
		}
	}

	void incrementTime() {
		int start = time(NULL);
		while(time(NULL)==start) {} // Wait until time has increased
		simulationTime++; // Increase simulation time by 1
	}
	
	void displayTeller(Teller &inTeller, int number) {

		// Applys visual effect to processing text
		if (timeSnapshot < simulationTime) {
			if (processingPostfix.size() >= 3) processingPostfix = "";
			else processingPostfix+=".";
			timeSnapshot = simulationTime;
		}

		// Determine if teller is processing or idle
		string status = (inTeller.getCustomer().getFinish() != -1)? "Processing" : "Idle";

		// Add postfix if processing
		if (status == "Processing") status += processingPostfix;

		// Display teller status
		cout << "Teller " << number << ": " << status <<  "\n";
	}

	void displayValues() {
		clearScreen();
		string blink = (simulationTime%2==0)? "-" : " "; // Creates a blinking effect around the time
		cout << "          Running Bank Simulation     " << blink << formattedTime(simulationTime) << blink << endl
		<<      "___________________________________________" << endl << endl

		<< "Customers Waiting: " << customersWaiting.size() << "\n\n";

		displayTeller(teller1, 1);
		displayTeller(teller2, 2);
		displayTeller(teller3, 3);

		cout << "\nCustomers Processed: " << processedCustomers.size() << endl << endl;
	}

	void displayReport() {
		clearScreen();

		// Calculate average waiting time
		float averageWaitingTime = totalWaitingTime / processedCustomers.size();

		// Calculate average customers waiting
		int sum = 0;
		for(int data : customersWaitingData)
			sum += data;

		float averageCustomersWaiting = sum / customersWaitingData.size();

		// Display Report
		cout << "          Report" << endl
		<<      "__________________________" << endl << endl

		<<      "Average Waiting Time: " << averageWaitingTime << endl
		<<      "Average Number of Customers Waiting: " << averageCustomersWaiting << endl << endl;

		cout << "Last Initial | Money Involved | Time of Arrival" << endl
		<<      "____________________________________________" << endl;
		for (Customer customer: processedCustomers) {
			cout << customer.getInitial() << ". | $" << customer.getMoney() << " | " << formattedTime(customer.getInstantiation()) << endl;
		}
	}
	
	// Convert simulation time format to hour and minute format 
	string formattedTime(int inTime) {
		string time = "";
		int hour = 10 + (inTime/60);
		if (hour > 12) hour -= 12;
		int seconds = inTime%60;
		string extraZero = (seconds < 10)? "0":"";
		time += to_string(hour) + ":" + extraZero + to_string(seconds);

		return time;
	}

	void clearScreen() {
		#ifdef WINDOWS
			system("cls");
		#else
			system("clear");
		#endif
	}

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
	int simulationTime = 0;
	int timeSnapshot = 0;
	string processingPostfix = "";
	int totalWaitingTime = 0;

	Teller teller1 = Teller(), teller2 = Teller(), teller3 = Teller();
	vector<Customer> processedCustomers;

	queue<Customer> customersWaiting;
	vector<int> customersWaitingData;


};
#endif