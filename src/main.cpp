#include <iostream>
#include "SimulationManager.h"
using namespace std;


int main()
{
	SimulationManager manager;
	
	cout << "          Bank Simulation" << endl
		<<      "___________________________________" << endl << endl

		<<      "Press enter to run simulation... ";

	cin.ignore();
	manager.runSimulation();

}
